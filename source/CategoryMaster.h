//---------------------------------------------------------------------------

#ifndef CategoryMasterH
#define CategoryMasterH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmCategoryMaster : public TForm
{
__published:	// IDE-managed Components
        TStatusBar *StatusBar1;
        TGroupBox *GroupBox3;
        TBitBtn *btnAdd;
        TBitBtn *btnEdit;
        TBitBtn *btnDelete;
        TBitBtn *btnClose;
        TBitBtn *btnSave;
        TBitBtn *btnCancel;
        TLabel *lblMode;
        TLabel *lblModeText;
        TGroupBox *GroupBox1;
        TDBGrid *dbgridCat;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *txtName;
        TEdit *txtID;
        TTimer *Cat_Timer;

        void __fastcall FormShow(TObject *Sender);
        void __fastcall btnAddClick(TObject *Sender);
        void __fastcall dbgridCatCellClick(TColumn *Column);
        void __fastcall dbgridCatKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgridCatMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall btnEditClick(TObject *Sender);
        void __fastcall btnSaveClick(TObject *Sender);
        void __fastcall btnCancelClick(TObject *Sender);
        void __fastcall btnDeleteClick(TObject *Sender);
        void __fastcall btnCloseClick(TObject *Sender);
        void __fastcall Cat_TimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmCategoryMaster(TComponent* Owner);

        void InitialSetting();
        void LoadFirstRec();
        void LoadCatBrowse(AnsiString sql);
        bool LoadCategory(AnsiString strID);
        void DisableInput();
        void EnableInput();
        void ClearCatInput();
        void ShowViewControl();

        void HandleAdd();
        void HandleEdit();
        void HandleSave();
        void HandleCancel();
        void HandleDelete();

        bool AddCategory();
        bool EditCategory();
        bool DeleteCategory();

        bool m_bEdit;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCategoryMaster *frmCategoryMaster;
//---------------------------------------------------------------------------
#endif
