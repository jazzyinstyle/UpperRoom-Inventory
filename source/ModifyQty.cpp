//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ModifyQty.h"
#include "Main.h"
#include "DataModules.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmModifyQty *frmModifyQty;
//---------------------------------------------------------------------------
__fastcall TfrmModifyQty::TfrmModifyQty(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void TfrmModifyQty::LaunchModifyQty(AnsiString strID, AnsiString strName, int iQty, int iOpt)
{
    m_strID = strID;
    m_strName = strName;

    m_iOpt = iOpt;
    m_iQty = iQty;

    if(m_iOpt == ADD_OPT)
    {
        this->Caption = "ADD Stock Quantity";
    }
    else if(m_iOpt == MINUS_OPT)
    {
        this->Caption = "MINUS Stock Quantity";
    }

    txtStockID->Text = m_strID;
    txtStockName->Text = m_strName;
    txtQty->Text = "1";

    ShowModal();
}


void __fastcall TfrmModifyQty::btnSaveClick(TObject *Sender)
{
    AnsiString strQty = txtQty->Text;

    int iQty = StrToInt(strQty);

    if(m_iOpt == ADD_OPT)
    {
        m_iQty += iQty;
    }
    else if(m_iOpt == MINUS_OPT)
    {
        if(iQty > m_iQty)
        {
            ShowMessage("Invalid Quantity to subtract. Please re-enter");
            txtQty->Text = "1";
            return;
        }

        m_iQty -= iQty;
    }

    AnsiString SQL = " UPDATE STOCK SET stock_bal = " + IntToStr(m_iQty) +
                        " WHERE stock_id = '" + m_strID + "' ";

    frmDataModules->StockQuery->Active = false;
    frmDataModules->StockQuery->SQL->Clear();
    frmDataModules->StockQuery->SQL->Add(SQL);

    if(frmDataModules->StockQuery->ExecSQL() <= 0)
    {
        ShowMessage("An unexpected error has occured. Update unsuccessful.");
    }

    Close();
}
//---------------------------------------------------------------------------


void __fastcall TfrmModifyQty::btnCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------


