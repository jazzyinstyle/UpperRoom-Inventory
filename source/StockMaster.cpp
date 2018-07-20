//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StockMaster.h"
#include "DataModules.h"
#include "Search.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmStockMaster *frmStockMaster;
//---------------------------------------------------------------------------
__fastcall TfrmStockMaster::TfrmStockMaster(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TfrmStockMaster::FormShow(TObject *Sender)
{
    InitialSetting();
}

void TfrmStockMaster::InitialSetting()
{
    this->Left = 0;
    this->Top = 90;
    this->Width = 1032;
    this->Height = 630;
    
    m_bSearch = false;
    m_bEdit = false;

    LoadStockBrowse("");
    LoadFirstRec();

    DisableInput();

    ShowViewControl();
}

void TfrmStockMaster::LoadStockBrowse(AnsiString Sql)
{
    AnsiString strSql = " SELECT stock_id FROM STOCK ";

    char * pch1 = strstr(Sql.c_str(), "WHERE");

    if(pch1 != NULL)
    {
        AnsiString strSearch = pch1;
        strSql = strSql + strSearch;
    }

    strSql += " ORDER BY stock_id ";
    
    frmDataModules->BrowseQry->Active = false;
    frmDataModules->BrowseQry->SQL->Clear();
    frmDataModules->BrowseQry->SQL->Add(strSql);
    frmDataModules->BrowseQry->Active = true;

    dbgridStock->Columns->Items[0]->Title->Caption = "Stock ID";    
}


void TfrmStockMaster::LoadFirstRec()
{
    AnsiString strStockID = dbgridStock->Columns->Items[0]->Field->AsString;
    AnsiString strStockName, strCatID, strUnitID, strUnitPrice, strBalQty, strCritLevel, strDesc;

    AnsiString SQL = "SELECT * FROM STOCK ";

    if(strStockID.Length() > 0)
    {
        SQL += " WHERE stock_id = '" + strStockID + "' ";
    }

    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(SQL);
    frmDataModules->StockQuery->Active = true;

    int iRecCnt = frmDataModules->StockQuery->RecordCount;

    if(iRecCnt > 0)
    {
        strStockName = frmDataModules->StockQuery->FieldByName("stock_name")->AsString;
        strUnitPrice = frmDataModules->StockQuery->FieldByName("stock_unit_price")->AsString;
        strBalQty = frmDataModules->StockQuery->FieldByName("stock_bal")->AsString;
        strCritLevel = frmDataModules->StockQuery->FieldByName("stock_alert_bal")->AsString;
        strDesc = frmDataModules->StockQuery->FieldByName("description")->AsString;
        strCatID = frmDataModules->StockQuery->FieldByName("category_id")->AsString;
        strUnitID = frmDataModules->StockQuery->FieldByName("unit_id")->AsString;

        txtID->Text           = strStockID;
        txtName->Text         = strStockName;
        txtPrice->Text        = strUnitPrice;
        txtQty->Text          = strBalQty;
        txtCritical->Text     = strCritLevel;
        txtDesc->Text         = strDesc;
    }

    frmMain->LoadCategory(cboCategory, strCatID);
    frmMain->LoadUnitType(cboType, strUnitID);
    
}

bool TfrmStockMaster::LoadStock(AnsiString strID)
{
    AnsiString strStockID, strName, strCat_Id, strUnit_Id, strUnit_Price, strDesc;
    int iBal, iAlertBal;

    AnsiString Sql;

    if(strID.Length() > 0)
    {
        Sql = " SELECT * FROM STOCK "
              " WHERE stock_id = '" + strID + "' ";
    }
    else
    {
        Sql = " SELECT * FROM STOCK ";
    }

    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(Sql);
    frmDataModules->StockQuery->Active = true;

    int iRecCount = frmDataModules->StockQuery->RecordCount;

    if(iRecCount <= 0)
    {
        return false;
    }

    strStockID = frmDataModules->StockQuery->FieldByName("stock_id")->AsString;
    strName = frmDataModules->StockQuery->FieldByName("stock_name")->AsString;
    strCat_Id = frmDataModules->StockQuery->FieldByName("category_id")->AsString;
    strUnit_Id = frmDataModules->StockQuery->FieldByName("unit_id")->AsString;
    iBal = frmDataModules->StockQuery->FieldByName("stock_bal")->AsInteger;
    strUnit_Price = frmDataModules->StockQuery->FieldByName("stock_unit_price")->AsString;
    iAlertBal = frmDataModules->StockQuery->FieldByName("stock_alert_bal")->AsInteger;
    strDesc = frmDataModules->StockQuery->FieldByName("description")->AsString;
  
    txtID->Text = strID;
    txtName->Text = strName;
    txtPrice->Text = strUnit_Price;
    txtQty->Text = IntToStr(iBal);
    txtCritical->Text = IntToStr(iAlertBal);
    txtDesc->Text = strDesc;

    frmMain->LoadCategory(cboCategory, strCat_Id);
    frmMain->LoadUnitType(cboType, strUnit_Id);

    return true;
}


void TfrmStockMaster::LookUpStock()
{
    AnsiString strID = txtID->Text;
    AnsiString strName = txtName->Text;
    AnsiString strCat_Name = cboCategory->Text;
    AnsiString strUnit_Name = cboType->Text;

    AnsiString strPrice = txtPrice->Text;
    AnsiString strQty = txtQty->Text;
    AnsiString strCritical = txtCritical->Text;
    AnsiString strDesc = txtDesc->Text;

    AnsiString strCat_ID = GetCategoryInfo("", strCat_Name);
    AnsiString strUnit_ID = GetTypeInfo("", strUnit_Name);

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
            Sql = Sql + " AND stock_unit_price " + strPrice + " ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE stock_unit_price " + strPrice + " ";
        }
    }

    if(strQty.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND stock_bal " + strQty + " ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE stock_bal " + strQty + " ";
        }
    }

    if(strCritical.Length() > 0)
    {
        if(bAdded)
        {
            Sql = Sql + " AND stock_alert_bal " + strCritical + " ";
        }
        else
        {
            bAdded = true;

            Sql = Sql + " WHERE stock_alert_bal " + strCritical + " ";
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

    //Do Database Search
    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(Sql);
    frmDataModules->StockQuery->Active = true;

    int iRecCount = frmDataModules->StockQuery->RecordCount;

    if(iRecCount <= 0)
    {
        ShowMessage("No record found");

        LoadFirstRec();
    }
    else
    {
        frmDataModules->StockQuery->First();

        AnsiString strID = frmDataModules->StockQuery->FieldByName("stock_id")->AsString;

        LoadStock(strID);

        LoadStockBrowse(Sql);
    }
}


AnsiString TfrmStockMaster::GetCategoryInfo(AnsiString strID, AnsiString strName)
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


AnsiString TfrmStockMaster::GetTypeInfo(AnsiString strID, AnsiString strName)
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


void __fastcall TfrmStockMaster::dbgridStockCellClick(TColumn *Column)
{
    AnsiString strStockID = dbgridStock->Columns->Items[0]->Field->AsString;

    LoadStock(strStockID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockMaster::dbgridStockKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    AnsiString strStockID = dbgridStock->Columns->Items[0]->Field->AsString;

    LoadStock(strStockID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockMaster::dbgridStockMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    AnsiString strStockID = dbgridStock->Columns->Items[0]->Field->AsString;

    LoadStock(strStockID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockMaster::btnSearchClick(TObject *Sender)
{
//    HandleSearch();

    frmSearch->LaunchSearch(dbgridStock);

    LoadFirstRec();
}
//---------------------------------------------------------------------------

void TfrmStockMaster::HandleSearch()
{
    lblModeText->Caption = "Search Record";

    if(!m_bSearch)
    {
        m_bSearch = true;
    }
    else
    {
       m_bSearch = false;
    }

    if(m_bSearch)
    {
        EnableInput();

        SearchStock();

        btnSearch->Enabled = true;
        btnAdd->Enabled = false;
        btnEdit->Enabled = false;
        btnDelete->Enabled = false;
        btnSave->Enabled = false;
        btnCancel->Enabled = true;

        dbgridStock->Enabled = false;
    }
    else
    {
        LookUpStock();

        ShowViewControl();

        dbgridStock->Enabled = true;
    }
}


void TfrmStockMaster::SearchStock()
{
    ClearStockInput();
}


void TfrmStockMaster::ClearStockInput()
{
    txtID->Text = "";
    txtName->Text = "";
    txtPrice->Text = "";
    txtQty->Text = "";
    txtCritical->Text = "";
    txtDesc->Text = "";

    cboCategory->Text = "";
    cboType->Text = "";
}


void TfrmStockMaster::EnableInput()
{
    txtID->ReadOnly = false;
    txtName->ReadOnly = false;
    txtPrice->ReadOnly = false;
    txtQty->ReadOnly = false;
    txtCritical->ReadOnly = false;
    txtDesc->ReadOnly = false;
    cboCategory->Enabled = true;
    cboType->Enabled = true;
}


void TfrmStockMaster::DisableInput()
{
    txtID->ReadOnly = true;
    txtName->ReadOnly = true;
    cboCategory->Enabled = false;
    cboType->Enabled = false;
    txtPrice->ReadOnly = true;
    txtQty->ReadOnly = true;
    txtCritical->ReadOnly = true;
    txtDesc->ReadOnly = true;
}


void TfrmStockMaster::ShowViewControl()
{
    dbgridStock->Enabled = true;
    btnSearch->Enabled = true;
    btnAdd->Enabled = true;
    btnEdit->Enabled = true;
    btnDelete->Enabled = true;
    btnSave->Enabled = false;
    btnCancel->Enabled = false;
    
    lblModeText->Caption = "View Record";
}

void __fastcall TfrmStockMaster::btnAddClick(TObject *Sender)
{
    HandleAdd();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockMaster::btnEditClick(TObject *Sender)
{
    HandleEdit();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockMaster::btnSaveClick(TObject *Sender)
{
    HandleSave();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockMaster::btnCancelClick(TObject *Sender)
{
    HandleCancel();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStockMaster::btnDeleteClick(TObject *Sender)
{
    HandleDelete();
}
//---------------------------------------------------------------------------


void TfrmStockMaster::HandleAdd()
{
    lblModeText->Caption = "Add Record";

    EnableInput();

    dbgridStock->Enabled = false;
    btnSearch->Enabled = false;
    btnAdd->Enabled = false;
    btnEdit->Enabled = false;
    btnDelete->Enabled = false;
    btnSave->Enabled = true;
    btnCancel->Enabled = true;

    ClearStockInput();
}



void TfrmStockMaster::HandleEdit()
{
    lblModeText->Caption = "Edit Record";

    m_bEdit = true;

    EnableInput();

    dbgridStock->Enabled = false;
    btnSearch->Enabled = false;
    btnAdd->Enabled = false;
    btnEdit->Enabled = false;
    btnDelete->Enabled = false;
    btnSave->Enabled = true;
    btnCancel->Enabled = true;

    if(txtID->Text.Length() <= 0)
    {
        ShowMessage("Unable to edit empty record. Please select a record");
        ShowViewControl();
        return;
    }

    txtID->Enabled = false;
}


void TfrmStockMaster::HandleSave()
{
    if(!m_bEdit)
    {
        if(!AddStock())
        {
            return;
        }
    }
    else
    {
        if(!EditStock())
        {
            return;
        }

        m_bEdit = false;
    }

    txtID->Enabled = true;

    DisableInput();

    ShowViewControl();

    LoadStockBrowse("");    
    LoadFirstRec();
}


bool TfrmStockMaster::AddStock()
{
    AnsiString strNo = txtID->Text;
    AnsiString strName = txtName->Text;
    AnsiString strCat = cboCategory->Text;
    AnsiString strUnitType = cboType->Text;
    AnsiString strPrice = txtPrice->Text;
    AnsiString strQty = txtQty->Text;
    AnsiString strCritical = txtCritical->Text;
    AnsiString strDesc = txtDesc->Text;

    if(!frmMain->VerifyNumericInput(strPrice, PRICE_INPUT) ||
        !frmMain->VerifyNumericInput(strQty, QTY_INPUT) ||
        !frmMain->VerifyNumericInput(strCritical, QTY_INPUT))
    {
        ShowMessage("Invalid input for numeric field. Please re-enter.");
        return false;
    }


    AnsiString strCat_ID = GetCategoryInfo("", strCat);
    AnsiString strUnit_ID = GetTypeInfo("", strUnitType);

    AnsiString Sql = " SELECT * FROM STOCK "
                     " WHERE stock_id = '" + strNo + "' ";

    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(Sql);
    frmDataModules->StockQuery->Active = true;

    int iRecCount = frmDataModules->StockQuery->RecordCount;

    if(iRecCount > 0)
    {
        ShowMessage("Duplicate record found. Operation aborted");
        return false;
    }

    Sql =  " INSERT INTO STOCK "
           " (stock_id, stock_name, category_id, unit_id, "
           " stock_bal, stock_unit_price, stock_alert_bal, description) "
           " VALUES ('" + strNo + "', "
           " '" + strName + "', "
           " '" + strCat_ID + "', "
           " '" + strUnit_ID + "', "
           " '" + strQty + "', "
           + strPrice + ", "
           + strCritical + ", "
           " '" + strDesc + "') ";

    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(Sql);

    if(frmDataModules->StockQuery->ExecSQL() > 0)
    {
        ShowMessage("Record Added");

        LoadStockBrowse("");        
        LoadFirstRec();

        return true;
    }

    ShowMessage("Operation Unsuccessful");

    return false;
}

bool TfrmStockMaster::EditStock()
{
    AnsiString strNo = txtID->Text;
    AnsiString strName = txtName->Text;
    AnsiString strCat = cboCategory->Text;
    AnsiString strUnitType = cboType->Text;
    AnsiString strPrice = txtPrice->Text;
    AnsiString strQty = txtQty->Text;
    AnsiString strCritical = txtCritical->Text;
    AnsiString strDesc = txtDesc->Text;


    if(!frmMain->VerifyNumericInput(strPrice, PRICE_INPUT) ||
        !frmMain->VerifyNumericInput(strQty, QTY_INPUT) ||
        !frmMain->VerifyNumericInput(strCritical, QTY_INPUT))
    {
        ShowMessage("Invalid input for numeric field. Please re-enter.");
        return false;
    }

    AnsiString strCat_ID = GetCategoryInfo("", strCat);
    AnsiString strUnit_ID = GetTypeInfo("", strUnitType);

    AnsiString Sql =  " UPDATE STOCK "
                      " SET stock_name = '" + strName + "', "
                      " category_id = '" + strCat_ID + "', "
                      " unit_id = '" + strUnit_ID + "', "
                      " stock_bal = " + strQty + ", "
                      " stock_unit_price = '" + strPrice + "', "
                      " stock_alert_bal = " + strCritical + ", "
                      " description = '" + strDesc + "' ";

    Sql = Sql + " WHERE stock_id = '" + strNo + "' ";

    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(Sql);

    if(frmDataModules->StockQuery->ExecSQL() > 0)
    {
        ShowMessage("Record Updated");

        LoadStockBrowse("");
        LoadFirstRec();

        return true;
    }

    ShowMessage("Operation Unsuccessful");

    return false;
}

bool TfrmStockMaster::DeleteStock()
{
    AnsiString strNo = txtID->Text;

    AnsiString Sql = " DELETE * FROM STOCK "
                     " WHERE stock_id = '" + strNo + "' ";

    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(Sql);

    if(frmDataModules->StockQuery->ExecSQL() > 0)
    {
        ShowMessage("Record deleted.");

        LoadStockBrowse("");
        LoadFirstRec();

        return true;
    }

    return false;
}


void TfrmStockMaster::HandleCancel()
{
    txtID->Enabled = true;

    LoadStockBrowse("");

    if(m_bSearch)
    {
        m_bSearch = false;
    }

    DisableInput();

    ShowViewControl();

    LoadStockBrowse("");
    LoadFirstRec();
}


void TfrmStockMaster::HandleDelete()
{
    DeleteStock();
}

//---------------------------------------------------------------------------
void __fastcall TfrmStockMaster::btnCloseClick(TObject *Sender)
{
    Close();

    frmMain->RestoreMain();
}
//---------------------------------------------------------------------------




