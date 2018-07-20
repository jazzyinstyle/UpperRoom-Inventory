//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Search.h"
#include "DataModules.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSearch *frmSearch;
//---------------------------------------------------------------------------
__fastcall TfrmSearch::TfrmSearch(TComponent* Owner)
        : TForm(Owner)
{
}


void TfrmSearch::InitialSetting()
{
    cboCompare1->ItemIndex = 0;
    cboCompare2->ItemIndex = 0;
    cboCompare3->ItemIndex = 0;

    frmMain->LoadCategory(cboCategory, "");
    frmMain->LoadUnitType(cboType, "");
}

void TfrmSearch::LaunchSearch(TDBGrid * dbgrd)
{
    m_DBGrid = dbgrd;

    InitialSetting();

    ShowModal();
}


void __fastcall TfrmSearch::btnSearchClick(TObject *Sender)
{
    LookUpStock();

    Close();
}
//---------------------------------------------------------------------------


void __fastcall TfrmSearch::btnAllClick(TObject *Sender)
{
    LoadStockBrowse("");

    Close();
}
//---------------------------------------------------------------------------


void TfrmSearch::LookUpStock()
{
    AnsiString strID = txtID->Text;
    AnsiString strName = txtName->Text;
    AnsiString strCat_Name = cboCategory->Text;
    AnsiString strUnit_Name = cboType->Text;

    AnsiString strCompare1 = cboCompare1->Text;
    AnsiString strCompare2 = cboCompare2->Text;
    AnsiString strCompare3 = cboCompare3->Text;

    AnsiString strPrice = txtPrice->Text;
    AnsiString strQty = txtQty->Text;
    AnsiString strCritical = txtCritical->Text;
    AnsiString strDesc = txtDesc->Text;

    AnsiString strCat_ID, strUnit_ID;

    if(strCat_Name.Length() > 0)
    {
        strCat_ID = GetCategoryInfo("", strCat_Name);
    }

    if(strUnit_Name.Length() > 0)
    {
        strUnit_ID = GetTypeInfo("", strUnit_Name);
    }

    AnsiString Sql = "SELECT * FROM STOCK ";
    bool bAdded = false;

    if(strID.Length() > 0)
    {
        bAdded = true;
        
        Sql = Sql + " WHERE stock_id LIKE '" + strID + "' ";
    }

    if(strName.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND stock_name LIKE '" + strName + "%' ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE stock_name LIKE '" + strName + "%' ";
        }
    }

    if(strCat_ID.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND category_id LIKE '" + strCat_ID + "%' ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE category_id LIKE '" + strCat_ID + "%' ";
        }
    }
    
    if(strUnit_Name.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND unit_id LIKE '" + strUnit_Name + "%' ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE unit_id LIKE '" + strUnit_Name + "%' ";
        }
    }

    if(strPrice.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND stock_unit_price " + strCompare1 + " " +strPrice + " ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE stock_unit_price " + strCompare1 + " " + strPrice + " ";
        }
    }

    if(strQty.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND stock_bal " + strCompare2 + " " + strQty + " ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE stock_bal " + strCompare2 + " " + strQty + " ";
        }
    }

    if(strCritical.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND stock_alert_bal " + strCompare3 + " " + strCritical + " ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE stock_alert_bal " + strCompare3 + " " + strCritical + " ";
        }
    }

    if(strDesc.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND description LIKE '" + strDesc + "%' ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE description LIKE '" + strDesc + "%' ";
        }
    }

    Sql += " ORDER BY stock_id ";
    
    //Do Database Search
    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(Sql);
    frmDataModules->StockQuery->Active = true;

    int iRecCount = frmDataModules->StockQuery->RecordCount;

    if(iRecCount <= 0)
    {
        ShowMessage("No record found");
    }
    else
    {
        frmDataModules->StockQuery->First();

        AnsiString strID = frmDataModules->StockQuery->FieldByName("stock_id")->AsString;

        LoadStockBrowse(Sql);
    }
}



AnsiString TfrmSearch::GetCategoryInfo(AnsiString strID, AnsiString strName)
{
    AnsiString SQL;
    AnsiString strQryField;

    if(strID.Length() > 0)
    {
        strQryField = "category_name";

        SQL = "SELECT " + strQryField + " FROM CATEGORY WHERE category_id = '" + strID + "' ";


    }
    else if(strName.Length() > 0)
    {
        strQryField = "category_id";

        SQL = "SELECT " + strQryField + " FROM CATEGORY WHERE category_name = '" + strName + "' ";
    }
    else
    {
        return "";
    }


    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(SQL);
    frmDataModules->CategoryQry->Active = true;

    int iRecCnt = frmDataModules->CategoryQry->RecordCount;

    frmDataModules->CategoryQry->First();

    return frmDataModules->CategoryQry->FieldByName(strQryField)->AsString;
}


AnsiString TfrmSearch::GetTypeInfo(AnsiString strID, AnsiString strName)
{
    AnsiString SQL;
    AnsiString strQryField;

    if(strID.Length() > 0)
    {
        strQryField = "unit_type";

        SQL = "SELECT " + strQryField + " FROM UNITTYPE WHERE unit_id = '" + strID + "' ";


    }
    else if(strName.Length() > 0)
    {
        strQryField = "unit_id";

        SQL = "SELECT " + strQryField + " FROM UNITTYPE WHERE unit_type = '" + strName + "' ";
    }


    frmDataModules->UnitTypeQry->Active = false;
    frmDataModules->UnitTypeQry->SQL->Clear();
    frmDataModules->UnitTypeQry->SQL->Add(SQL);
    frmDataModules->UnitTypeQry->Active = true;

    int iRecCnt = frmDataModules->UnitTypeQry->RecordCount;

    frmDataModules->UnitTypeQry->First();

    return frmDataModules->UnitTypeQry->FieldByName(strQryField)->AsString;
}


void TfrmSearch::LoadStockBrowse(AnsiString Sql)
{
    AnsiString strSql = " SELECT stock_id FROM STOCK ";

    char * pch1 = strstr(Sql.c_str(), "WHERE");

    if(pch1 != NULL)
    {
        AnsiString strSearch = pch1;
        strSql = strSql + strSearch;
    }

    frmDataModules->BrowseQry->Active = false;
    frmDataModules->BrowseQry->SQL->Clear();
    frmDataModules->BrowseQry->SQL->Add(strSql);
    frmDataModules->BrowseQry->Active = true;

    m_DBGrid->Columns->Items[0]->Title->Caption = "Stock ID";    
}


void __fastcall TfrmSearch::btnCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------


