//---------------------------------------------------------------------------

#ifndef DataModulesH
#define DataModulesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TfrmDataModules : public TForm
{
__published:	// IDE-managed Components
        TADOConnection *UpperoomConn;
        TADOTable *StockTable;
        TDataSource *dsStock;
        TADOQuery *BrowseQry;
        TADOQuery *StockQuery;
        TADOQuery *CategoryQry;
        TADOQuery *UnitTypeQry;
        TDataSource *dsCat;
        TDataSource *dsType;
        TADOTable *StockGenRpt_Table;
        TADOQuery *StockGenRpt_Query;
        TADOQuery *StockActQuery;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmDataModules(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDataModules *frmDataModules;
//---------------------------------------------------------------------------
#endif
