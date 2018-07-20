//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <AppEvnts.hpp>
#include <Mask.hpp>

#include "stdio.h"

#define ADD_OPT         1
#define MINUS_OPT       2
#define PRICE_INPUT     1
#define QTY_INPUT       2

//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TMainMenu *MainMenu;
        TMenuItem *mnuFile;
        TMenuItem *mnuFileExit;
        TMenuItem *mnuHelp;
        TMenuItem *mnuHelpAbout;
        TMenuItem *mnuMaster;
        TMenuItem *mnuMasterStock;
        TMenuItem *mnuReport;
        TMenuItem *mnuMasterMenu;
        TBitBtn *btnSearch;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TMenuItem *StockGeneral;
        TMenuItem *StockCritical;
        TStatusBar *StatusBar;
        TStaticText *txtDateTime;
        TTimer *DateTimeTimer;
        TDBGrid *dbgStockID;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label5;
        TLabel *Label8;
        TStaticText *txtID;
        TStaticText *txtName;
        TStaticText *txtCategory;
        TStaticText *txtType;
        TStaticText *txtPrice;
        TStaticText *txtCalQty;
        TStaticText *txtCritical;
        TStaticText *txtDesc;
        TStaticText *MainTitle;
        TTimer *StatusBarTimer;
        TMenuItem *mnuMasterCategory;
        TMenuItem *mnuMasterUnitType;
        TGroupBox *GroupBox4;
        TLabel *Label9;
        TLabel *Label10;
        TStaticText *txtTotalPrice;
        TEdit *txtActBalQty;
        TBitBtn *btnSave;
        TLabel *Label7;
        TStaticText *txtLastUpdate;
        TApplicationEvents *ApplicationEvents;
        TBitBtn *btnClose;
        TTimer *TitleTimer;
        TLabel *lblTotalBalPrice;
        TLabel *lblActTotalBalPrice;
        void __fastcall mnuFileExitClick(TObject *Sender);
        void __fastcall DateTimeTimerTimer(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall StatusBarTimerTimer(TObject *Sender);
        void __fastcall mnuMasterStockClick(TObject *Sender);
        void __fastcall mnuMasterUnitTypeClick(TObject *Sender);
        void __fastcall mnuMasterCategoryClick(TObject *Sender);
        void __fastcall dbgStockIDCellClick(TColumn *Column);
        void __fastcall dbgStockIDKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgStockIDMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall btnCloseClick(TObject *Sender);
        void __fastcall btnSearchClick(TObject *Sender);
        void __fastcall TitleTimerTimer(TObject *Sender);
        void __fastcall mnuHelpAboutClick(TObject *Sender);
        void __fastcall StockGeneralClick(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall btnSaveClick(TObject *Sender);
private:	// User declarations

        int m_iStatusLevel;
        int m_iTitleLevel;
        int m_iPage;

        double m_dCalPrice;
        int m_iCalQty;


public:		// User declarations
        __fastcall TfrmMain(TComponent* Owner);

        void RestoreMain();
        void InitialSetting();
        void LoadStockBrowse(AnsiString Sql);
        void LoadCategory(TComboBox * cboCat, AnsiString strCatID);
        void LoadUnitType(TComboBox * cboType, AnsiString strUnitID);

        void LoadFirstRec();
        void LoadActBal(AnsiString strID);
        bool SaveActBal(AnsiString strID);

        void Query_StockGenReport();

        bool LoadStock(AnsiString strID);

        AnsiString GetCategoryInfo(AnsiString strID, AnsiString strName);
        AnsiString GetTypeInfo(AnsiString strID, AnsiString strName);

        bool VerifyNumericInput(AnsiString strText, int iOpt);        
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
