//---------------------------------------------------------------------------

#ifndef Rpt_StockGeneralH
#define Rpt_StockGeneralH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TfrmRpt_StockGeneral : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRLabel *QRLabel1;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel3;
        TQRLabel *QRLabel4;
        TQRLabel *QRLabel5;
        TQRLabel *QRLabel6;
        TQRLabel *QRLabel7;
        TQRLabel *QRLabel8;
        TQRLabel *QRLabel9;
        TQRLabel *QRLabel10;
        TQRLabel *QRLabel11;
        TQRDBText *txtName;
        TQRDBText *txtStockID;
        TQRDBText *txtCategory;
        TQRDBText *txtUnitType;
        TQRDBText *txtCalBal;
        TQRDBText *txtUnitPrice;
        TQRDBText *txtActBal;
        TQRDBText *txtActTotalPrice;
        TQRDBText *txtAlertBal;
        TQRDBText *txtDesc;
        TQRLabel *txtDateTime;
private:	// User declarations
public:		// User declarations
        __fastcall TfrmRpt_StockGeneral(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmRpt_StockGeneral *frmRpt_StockGeneral;
//---------------------------------------------------------------------------
#endif
