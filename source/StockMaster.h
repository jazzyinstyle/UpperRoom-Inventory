//---------------------------------------------------------------------------

#ifndef StockMasterH
#define StockMasterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>

//---------------------------------------------------------------------------
class TfrmStockMaster : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TDBGrid *dbgridStock;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *txtID;
        TEdit *txtName;
        TComboBox *cboCategory;
        TComboBox *cboType;
        TEdit *txtPrice;
        TEdit *txtQty;
        TEdit *txtCritical;
        TEdit *txtDesc;
        TLabel *lblMode;
        TLabel *lblModeText;
        TGroupBox *GroupBox3;
        TBitBtn *btnSearch;
        TBitBtn *btnAdd;
        TBitBtn *btnEdit;
        TBitBtn *btnDelete;
        TBitBtn *btnClose;
        TBitBtn *btnSave;
        TBitBtn *btnCancel;
        TTimer *StockTimer;
        void __fastcall btnCloseClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall dbgridStockCellClick(TColumn *Column);
        void __fastcall dbgridStockKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgridStockMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall btnSearchClick(TObject *Sender);
        void __fastcall btnAddClick(TObject *Sender);
        void __fastcall btnEditClick(TObject *Sender);
        void __fastcall btnSaveClick(TObject *Sender);
        void __fastcall btnCancelClick(TObject *Sender);
        void __fastcall btnDeleteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmStockMaster(TComponent* Owner);

        void InitialSetting();

        void LoadFirstRec();
        void LoadStockBrowse(AnsiString Sql);
    
        void HandleSearch();
        void HandleAdd();
        void HandleEdit();
        void HandleSave();
        void HandleCancel();
        void HandleDelete();

        bool AddStock();
        bool EditStock();
        bool DeleteStock();

        void SearchStock();
        void LookUpStock();
        bool LoadStock(AnsiString strID);

        AnsiString GetCategoryInfo(AnsiString strID=NULL, AnsiString strName=NULL);
        AnsiString GetTypeInfo(AnsiString strID=NULL, AnsiString strName=NULL);

        void EnableInput();
        void ShowViewControl();
        void ClearStockInput();
        void DisableInput();

        bool m_bSearch;
        bool m_bEdit;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmStockMaster *frmStockMaster;
//---------------------------------------------------------------------------
#endif
