//---------------------------------------------------------------------------

#ifndef UnitTypeMasterH
#define UnitTypeMasterH
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
class TfrmUnitType : public TForm
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
        TLabel *lblModeText;
        TLabel *lblMode;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TDBGrid *dbgridType;
        TEdit *txtName;
        TEdit *txtID;
        TTimer *TypeTimer;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall btnAddClick(TObject *Sender);
        void __fastcall btnEditClick(TObject *Sender);
        void __fastcall btnSaveClick(TObject *Sender);
        void __fastcall btnCancelClick(TObject *Sender);
        void __fastcall btnDeleteClick(TObject *Sender);
        void __fastcall btnCloseClick(TObject *Sender);
        void __fastcall dbgridTypeCellClick(TColumn *Column);
        void __fastcall dbgridTypeKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgridTypeMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall TypeTimerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmUnitType(TComponent* Owner);

        void InitialSetting();
        void LoadFirstRec();
        void LoadTypeBrowse(AnsiString sql);
        bool LoadType(AnsiString strID);
        void DisableInput();
        void EnableInput();
        void ClearTypeInput();
        void ShowViewControl();

        void HandleAdd();
        void HandleEdit();
        void HandleSave();
        void HandleCancel();
        void HandleDelete();

        bool AddType();
        bool EditType();
        bool DeleteType();

        bool m_bEdit;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmUnitType *frmUnitType;
//---------------------------------------------------------------------------
#endif
