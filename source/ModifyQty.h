//---------------------------------------------------------------------------

#ifndef ModifyQtyH
#define ModifyQtyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmModifyQty : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label5;
        TEdit *txtQty;
        TEdit *txtStockID;
        TEdit *txtStockName;
        TBitBtn *btnSave;
        TBitBtn *btnClose;
        TUpDown *UpDown;
        void __fastcall btnCloseClick(TObject *Sender);
        void __fastcall btnSaveClick(TObject *Sender);
private:	// User declarations

        AnsiString m_strID, m_strName;
        int m_iOpt, m_iQty;
        
public:		// User declarations
        __fastcall TfrmModifyQty(TComponent* Owner);

        void LaunchModifyQty(AnsiString strID, AnsiString strName, int iQty, int iOpt);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmModifyQty *frmModifyQty;
//---------------------------------------------------------------------------
#endif
