//---------------------------------------------------------------------------

#ifndef SearchH
#define SearchH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TfrmSearch : public TForm
{
__published:	// IDE-managed Components
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
        TGroupBox *GroupBox2;
        TBitBtn *btnClose;
        TBitBtn *btnAll;
        TBitBtn *btnSearch;
        TComboBox *cboCompare1;
        TComboBox *cboCompare2;
        TComboBox *cboCompare3;
        void __fastcall btnCloseClick(TObject *Sender);
        void __fastcall btnSearchClick(TObject *Sender);
        void __fastcall btnAllClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmSearch(TComponent* Owner);

        void InitialSetting();
        void LaunchSearch(TDBGrid * dbgrd);
        void LookUpStock();
        void LoadStockBrowse(AnsiString Sql);

        AnsiString GetCategoryInfo(AnsiString strID=NULL, AnsiString strName=NULL);
        AnsiString GetTypeInfo(AnsiString strID=NULL, AnsiString strName=NULL);

        TDBGrid * m_DBGrid;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSearch *frmSearch;
//---------------------------------------------------------------------------
#endif
