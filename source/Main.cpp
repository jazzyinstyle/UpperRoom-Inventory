//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"              
#include "StockMaster.h"
#include "CategoryMaster.h"
#include "UnitTypeMaster.h"
#include "DataModules.h"
#include "Search.h"
#include "About.h"
#include "Rpt_StockGeneral.h"
#include "ModifyQty.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
    InitialSetting();
}


void TfrmMain::RestoreMain()
{
    LoadStockBrowse("");
    LoadFirstRec();
}

void TfrmMain::InitialSetting()
{
    m_iStatusLevel = 0;
    m_iTitleLevel = 0;
    m_iPage = 1;

    TitleTimer->Enabled = true;

    this->Left = 0;
    this->Top = 0;
    this->Width = 1032;
    this->Height = 542;

    LoadStockBrowse("");
    LoadFirstRec();
}


void TfrmMain::LoadStockBrowse(AnsiString Sql)
{
    AnsiString strSql = " SELECT stock_id FROM STOCK ";

    char * pch1 = strstr(Sql.c_str(), " WHERE ");

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

    dbgStockID->Columns->Items[0]->Title->Caption = "Stock ID";    
}


void TfrmMain::LoadFirstRec()
{
    AnsiString strStockID = dbgStockID->Columns->Items[0]->Field->AsString;
    AnsiString strStockName, strCatID, strUnitID, strUnitPrice, strDesc;
    int iBal, iAlertBal;

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
        iBal = frmDataModules->StockQuery->FieldByName("stock_bal")->AsInteger;
        iAlertBal = frmDataModules->StockQuery->FieldByName("stock_alert_bal")->AsInteger;
        strDesc = frmDataModules->StockQuery->FieldByName("description")->AsString;
        strCatID = frmDataModules->StockQuery->FieldByName("category_id")->AsString;
        strUnitID = frmDataModules->StockQuery->FieldByName("unit_id")->AsString;

        txtID->Caption           = strStockID;
        txtName->Caption         = strStockName;
        txtPrice->Caption        = strUnitPrice;
        txtCalQty->Caption       = IntToStr(iBal);
        txtCategory->Caption     = GetCategoryInfo(strCatID, "");
        txtType->Caption         = GetTypeInfo(strUnitID, NULL);
        txtDesc->Caption         = strDesc;

        if(iBal <= iAlertBal)
        {
            txtCritical->Caption = "Critical Level!";
        }
        else
        {
            txtCritical->Caption = "";
        }
    }

    m_dCalPrice = iBal * StrToFloat(txtPrice->Caption);
    m_iCalQty = iBal;
    
    lblTotalBalPrice->Caption = "(RM " + FloatToStr(m_dCalPrice) + ")";

    LoadActBal(strStockID);
}


bool TfrmMain::LoadStock(AnsiString strID)
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
  
    txtID->Caption              = strID;
    txtName->Caption            = strName;
    txtPrice->Caption           = strUnit_Price;
    txtCalQty->Caption          = IntToStr(iBal);
    txtCategory->Caption        = GetCategoryInfo(strCat_Id, "");
    txtType->Caption            = GetTypeInfo(strUnit_Id, NULL);
    txtDesc->Caption            = strDesc;

    if(iBal <= iAlertBal)
    {
        txtCritical->Caption    = "Critical Level!";
    }
    else
    {
        txtCritical->Caption = "";
    }

    m_dCalPrice = iBal * StrToFloat(txtPrice->Caption);
    m_iCalQty = iBal;

    lblTotalBalPrice->Caption = "(RM " + FloatToStr(m_dCalPrice) + ")";

    LoadActBal(strID);

    return true;
}


void TfrmMain::LoadActBal(AnsiString strID)
{
    TDateTime dtDateTime;
    int iActBal = 0;
    txtActBalQty->Text = "";

    lblActTotalBalPrice->Caption = "";
    txtTotalPrice->Caption = "";
    txtLastUpdate->Caption = "";
    
    AnsiString SQL = " SELECT * FROM STOCK_BALANCE "
                        " WHERE stock_id = '" + strID + "' "
                        " ORDER BY [date] DESC";

    frmDataModules->StockActQuery->Active = false;
    frmDataModules->StockActQuery->SQL->Clear();
    frmDataModules->StockActQuery->SQL->Add(SQL);
    frmDataModules->StockActQuery->Active = true;

    int iRecCount = frmDataModules->StockActQuery->RecordCount;

    if(iRecCount > 0)
    {
        dtDateTime = frmDataModules->StockActQuery->FieldByName("date")->AsDateTime;
        iActBal = frmDataModules->StockActQuery->FieldByName("actual_stock_bal")->AsInteger;

        double dCalPrice = m_dCalPrice;
        double dActPrice = iActBal * StrToFloat(txtPrice->Caption);
        double dDiff = 0;

        AnsiString strDiff = "";

        if(dCalPrice > dActPrice)
        {
            dDiff = dCalPrice - dActPrice;

            strDiff = "- " + FloatToStr(dDiff);
        }
        else if(dCalPrice < dActPrice)
        {
            dDiff = dActPrice - dCalPrice;

            strDiff = "+ " + FloatToStr(dDiff);
        }
        else
        {
            strDiff = "0.00";
        }

        txtLastUpdate->Caption = dtDateTime.FormatString("dd mmm yyyy");
        txtActBalQty->Text = IntToStr(iActBal);
        lblActTotalBalPrice->Caption = "(RM " + FloatToStr(dActPrice) + ")";
        txtTotalPrice->Caption = strDiff;
    }
}


bool TfrmMain::SaveActBal(AnsiString strID)
{
    if(!VerifyNumericInput(txtActBalQty->Text, QTY_INPUT))
    {
        ShowMessage("Invalid quantity input. Please re-enter.");
        return false;
    }

    AnsiString strDate = Now().FormatString("dd mmm yyyy");
    int iActBal = StrToInt(txtActBalQty->Text);
    AnsiString strLoss = "0";
    int iDiff = 0;

    if(m_iCalQty > iActBal)
    {
        strLoss = "1";

        iDiff = m_iCalQty - iActBal;
    }
    else
    {
        iDiff = iActBal - m_iCalQty;
    }


    AnsiString SQL = " SELECT * FROM STOCK_BALANCE "
                        " WHERE stock_id = '" + strID + "' "
                        " AND [date] = #" + strDate + "# ";

    frmDataModules->StockActQuery->Active = false;
    frmDataModules->StockActQuery->SQL->Clear();
    frmDataModules->StockActQuery->SQL->Add(SQL);
    frmDataModules->StockActQuery->Active = true;

    int iRecCount = frmDataModules->StockActQuery->RecordCount;

    if(iRecCount > 0)
    {
        SQL = " UPDATE STOCK_BALANCE SET actual_stock_bal = " + IntToStr(iActBal) + ", "
                " loss_qty = " + strLoss + ", diff_qty = " + IntToStr(iDiff) + " " 
                " WHERE stock_id = '" + strID + "' "
                " AND [date] = #" + strDate + "# ";
    }
    else
    {
        SQL = " INSERT INTO STOCK_BALANCE (stock_id, [date], actual_stock_bal, loss_qty, diff_qty) "
                " VALUES ('" + strID + "', '" + strDate + "', " + IntToStr(iActBal) + ", " +
                strLoss + ", " + IntToStr(iDiff) + ")";
    }

    frmDataModules->StockActQuery->Active = false;
    frmDataModules->StockActQuery->SQL->Clear();
    frmDataModules->StockActQuery->SQL->Add(SQL);

    if(frmDataModules->StockActQuery->ExecSQL() <= 0)
    {
        ShowMessage("An unexpected error has occured. Unable to save record.");
        return false;
    }
    else
    {
        ShowMessage("Record saved");
    }

    return true;
}


AnsiString TfrmMain::GetCategoryInfo(AnsiString strID, AnsiString strName)
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


AnsiString TfrmMain::GetTypeInfo(AnsiString strID, AnsiString strName)
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


bool TfrmMain::VerifyNumericInput(AnsiString strText, int iOpt)
{
    char chText[200] = "\0";
    char chComp[10] = "\0";
    char * pch1 = NULL;
    char * pch2 = NULL;

    sprintf(chText, "%s", strText);
    pch1 = chText;

    if(iOpt == PRICE_INPUT)
    {
        for(int i = 0; i < strlen(chText); i++)
        {
            pch2 = pch1 + 1;

            memset(chComp, 0, sizeof(chComp));
            strncpy(chComp, pch1, pch2 - pch1);

            if(!isdigit(*chComp) && strcmp(chComp, ".") != 0)
            {
                return false;
            }

            pch1 = pch2;
        }
    }
    else if(iOpt == QTY_INPUT)
    {
        for(int i = 0; i < strlen(chText); i++)
        {
            pch2 = pch1 + 1;

            memset(chComp, 0, sizeof(chComp));
            strncpy(chComp, pch1, pch2 - pch1);

            if(!isdigit(*chComp))
            {
                return false;
            }

            pch1 = pch2;
        }
    }
}


void TfrmMain::LoadCategory(TComboBox * cboCat, AnsiString strCatID)
{
    AnsiString SQL = "SELECT * FROM CATEGORY ";
    int iIndex = -1;

    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(SQL);
    frmDataModules->CategoryQry->Active = true;

    int iRecCnt = frmDataModules->CategoryQry->RecordCount;

    frmDataModules->CategoryQry->First();

    cboCat->Clear();

    for(int i = 0; i < iRecCnt; i++)
    {
        AnsiString strCategoryID = frmDataModules->CategoryQry->FieldByName("category_id")->AsString;
        AnsiString strCategoryName = frmDataModules->CategoryQry->FieldByName("category_name")->AsString;
        
        cboCat->Items->Add(strCategoryName);

        cboCat->ItemIndex = i;
        if(strCategoryID == strCatID)
        {
            iIndex = i;
        }

        frmDataModules->CategoryQry->Next();
    }

    cboCat->ItemIndex = iIndex;
}


void TfrmMain::LoadUnitType(TComboBox * cboType, AnsiString strUnitID)
{
    AnsiString SQL = "SELECT * FROM UNITTYPE ";
    int iIndex = -1;

    frmDataModules->UnitTypeQry->Active = false;
    frmDataModules->UnitTypeQry->SQL->Clear();
    frmDataModules->UnitTypeQry->SQL->Add(SQL);
    frmDataModules->UnitTypeQry->Active = true;

    int iRecCnt = frmDataModules->UnitTypeQry->RecordCount;

    frmDataModules->UnitTypeQry->First();

    cboType->Clear();

    for(int i = 0; i < iRecCnt; i++)
    {
        AnsiString strUnitTypeID = frmDataModules->UnitTypeQry->FieldByName("unit_id")->AsString;
        AnsiString strUnitType = frmDataModules->UnitTypeQry->FieldByName("unit_type")->AsString;

        cboType->Items->Add(strUnitType);

        cboType->ItemIndex = i;
        if(strUnitTypeID == strUnitID)
        {
            iIndex = i;
        }

        frmDataModules->UnitTypeQry->Next();
    }

    cboType->ItemIndex = iIndex;
}


//---------------------------------------------------------------------------
void __fastcall TfrmMain::mnuFileExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::DateTimeTimerTimer(TObject *Sender)
{
    txtDateTime->Caption = TDateTime::CurrentDateTime().FormatString("dd MMM yyyy hh:nn:ss am/pm");
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::StatusBarTimerTimer(TObject *Sender)
{
    StatusBarTimer->Interval = 100;

    if(m_iStatusLevel == 0)
    {
        StatusBar->SimpleText = "W";
    }
    else if(m_iStatusLevel == 1)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "e";
    }
    else if(m_iStatusLevel == 2)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "l";
    }
    else if(m_iStatusLevel == 3)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "c";
    }
    else if(m_iStatusLevel == 4)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "o";
    }
    else if(m_iStatusLevel == 5)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "m";
    }
    else if(m_iStatusLevel == 6)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "e";
    }
    else if(m_iStatusLevel == 7)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + " t";
    }
    else if(m_iStatusLevel == 8)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "o";
    }
    else if(m_iStatusLevel == 9)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + " U";
    }
    else if(m_iStatusLevel == 10)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "p";
    }
    else if(m_iStatusLevel == 11)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "p";
    }
    else if(m_iStatusLevel == 12)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "e";
    }
    else if(m_iStatusLevel == 13)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "r";
    }
    else if(m_iStatusLevel == 14)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "o";
    }
    else if(m_iStatusLevel == 15)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "o";
    }
    else if(m_iStatusLevel == 16)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "m";
    }
    else if(m_iStatusLevel == 17)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + " I";
    }
    else if(m_iStatusLevel == 18)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "n";
    }
    else if(m_iStatusLevel == 19)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "v";
    }
    else if(m_iStatusLevel == 20)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "e";
    }
    else if(m_iStatusLevel == 21)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "n";
    }
    else if(m_iStatusLevel == 22)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "t";
    }
    else if(m_iStatusLevel == 23)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "o";
    }
    else if(m_iStatusLevel == 24)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "r";
    }
    else if(m_iStatusLevel == 25)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "y";
    }
    else if(m_iStatusLevel == 26)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + " S";
    }
    else if(m_iStatusLevel == 27)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "y";
    }
    else if(m_iStatusLevel == 28)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "s";
    }
    else if(m_iStatusLevel == 29)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "t";
    }
    else if(m_iStatusLevel == 30)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "e";
    }
    else if(m_iStatusLevel == 31)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + "m";
    }
    else if(m_iStatusLevel == 32)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + ".";
    }
    else if(m_iStatusLevel == 33)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + ".";
    }
    else if(m_iStatusLevel == 34)
    {
        AnsiString strText = StatusBar->SimpleText;
        StatusBar->SimpleText = strText + ".";

        m_iStatusLevel = -1;

        StatusBarTimer->Interval = 5000;
    }

    m_iStatusLevel++;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::TitleTimerTimer(TObject *Sender)
{
    TitleTimer->Interval = 100;

    //Load 'Stock Entry' text
    if(m_iPage == 1)
    {
        if(m_iTitleLevel == 0)
        {
            MainTitle->Caption = "S";
        }
        else if(m_iTitleLevel == 1)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "T";
        }
        else if(m_iTitleLevel == 2)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "O";
        }
        else if(m_iTitleLevel == 3)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "C";
        }
        else if(m_iTitleLevel == 4)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "K";
        }
        else if(m_iTitleLevel == 5)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + " E";
        }
        else if(m_iTitleLevel == 6)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "N";
        }
        else if(m_iTitleLevel == 7)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "T";
        }
        else if(m_iTitleLevel == 8)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "R";
        }
        else if(m_iTitleLevel == 9)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "Y";

            m_iTitleLevel = -1;

            TitleTimer->Enabled = false;
        }

        m_iTitleLevel++;
    }
    else if(m_iPage == 2)
    {
        if(m_iTitleLevel == 0)
        {
            MainTitle->Caption = "S";
        }
        else if(m_iTitleLevel == 1)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "T";
        }
        else if(m_iTitleLevel == 2)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "O";
        }
        else if(m_iTitleLevel == 3)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "C";
        }
        else if(m_iTitleLevel == 4)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "K";
        }
        else if(m_iTitleLevel == 5)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + " M";
        }
        else if(m_iTitleLevel == 6)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "A";
        }
        else if(m_iTitleLevel == 7)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "S";
        }
        else if(m_iTitleLevel == 8)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "T";
        }
        else if(m_iTitleLevel == 9)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "E";
        }
        else if(m_iTitleLevel == 10)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "R";

            m_iTitleLevel = -1;

            TitleTimer->Enabled = false;
        }

        m_iTitleLevel++;
    }
    else if(m_iPage == 3)
    {
        if(m_iTitleLevel == 0)
        {
            MainTitle->Caption = "C";
        }
        else if(m_iTitleLevel == 1)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "A";
        }
        else if(m_iTitleLevel == 2)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "T";
        }
        else if(m_iTitleLevel == 3)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "E";
        }
        else if(m_iTitleLevel == 4)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "G";
        }
        else if(m_iTitleLevel == 5)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "O";
        }
        else if(m_iTitleLevel == 6)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "R";
        }
        else if(m_iTitleLevel == 7)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "Y";
        }
        else if(m_iTitleLevel == 8)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + " M";
        }
        else if(m_iTitleLevel == 9)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "A";
        }
        else if(m_iTitleLevel == 10)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "S";
        }
         else if(m_iTitleLevel == 11)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "T";
        }
         else if(m_iTitleLevel == 12)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "E";
        }
        else if(m_iTitleLevel == 13)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "R";

            m_iTitleLevel = -1;

            TitleTimer->Enabled = false;
        }

        m_iTitleLevel++;
    }
    else if(m_iPage == 4)
    {
        if(m_iTitleLevel == 0)
        {
            MainTitle->Caption = "U";
        }
        else if(m_iTitleLevel == 1)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "N";
        }
        else if(m_iTitleLevel == 2)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "I";
        }
        else if(m_iTitleLevel == 3)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "T";
        }
        else if(m_iTitleLevel == 4)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + " T";
        }
        else if(m_iTitleLevel == 5)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "Y";
        }
        else if(m_iTitleLevel == 6)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "P";
        }
        else if(m_iTitleLevel == 7)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "E";
        }
        else if(m_iTitleLevel == 8)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + " M";
        }
        else if(m_iTitleLevel == 9)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "A";
        }
        else if(m_iTitleLevel == 10)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "S";
        }
         else if(m_iTitleLevel == 11)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "T";
        }
         else if(m_iTitleLevel == 12)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "E";
        }
        else if(m_iTitleLevel == 13)
        {
            AnsiString strText = MainTitle->Caption;
            MainTitle->Caption = strText + "R";

            m_iTitleLevel = -1;

            TitleTimer->Enabled = false;
        }

        m_iTitleLevel++;
    }
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::mnuMasterStockClick(TObject *Sender)
{
    m_iPage = 2;
    m_iTitleLevel = 0;
    TitleTimer->Enabled = true;

    frmStockMaster->ShowModal();
    
    m_iPage = 1;
    m_iTitleLevel = 0;
    TitleTimer->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::mnuMasterUnitTypeClick(TObject *Sender)
{
    m_iPage = 4;
    m_iTitleLevel = 0;
    TitleTimer->Enabled = true;

    frmUnitType->ShowModal();

    m_iPage = 1;
    m_iTitleLevel = 0;
    TitleTimer->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mnuMasterCategoryClick(TObject *Sender)
{
    m_iPage = 3;
    m_iTitleLevel = 0;
    TitleTimer->Enabled = true;

    frmCategoryMaster->ShowModal();

    m_iPage = 1;
    m_iTitleLevel = 0; 
    TitleTimer->Enabled = true;           
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::dbgStockIDCellClick(TColumn *Column)
{
    AnsiString strStockID = dbgStockID->Columns->Items[0]->Field->AsString;

    LoadStock(strStockID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::dbgStockIDKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    AnsiString strStockID = dbgStockID->Columns->Items[0]->Field->AsString;

    LoadStock(strStockID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::dbgStockIDMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    AnsiString strStockID = dbgStockID->Columns->Items[0]->Field->AsString;

    LoadStock(strStockID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnSearchClick(TObject *Sender)
{
    frmSearch->LaunchSearch(dbgStockID);

    LoadFirstRec();
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::mnuHelpAboutClick(TObject *Sender)
{
    frmAbout->ShowModal();        
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::btnSaveClick(TObject *Sender)
{
    AnsiString strID = txtID->Caption;

    if(!SaveActBal(strID))
    {
        return;
    }

    LoadFirstRec();
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::StockGeneralClick(TObject *Sender)
{
/*
    Query_StockGenReport();

    frmDataModules->StockGenRpt_Table->Active = false;
    frmDataModules->StockGenRpt_Table->Active = true;

    frmRpt_StockGeneral->txtDateTime->Caption = Now().FormatString("dd mmm yyyy hh:nn:ss");
    frmRpt_StockGeneral->QuickRep1->Preview();
*/
}
//---------------------------------------------------------------------------


void TfrmMain::Query_StockGenReport()
{
//    AnsiString SQL = " SELECT
//    frmDataModules->StockGenRpt_Query->Active = false;
//    frmDataModules->StockGenRpt_Query->Active = true;
}


void __fastcall TfrmMain::BitBtn2Click(TObject *Sender)
{
    frmModifyQty->LaunchModifyQty(txtID->Caption, txtName->Caption, StrToInt(txtCalQty->Caption), ADD_OPT);

    LoadFirstRec();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::BitBtn3Click(TObject *Sender)
{
    frmModifyQty->LaunchModifyQty(txtID->Caption, txtName->Caption, StrToInt(txtCalQty->Caption), MINUS_OPT);

    LoadFirstRec(); 
}
//---------------------------------------------------------------------------

