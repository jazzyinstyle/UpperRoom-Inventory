//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main.cpp", frmMain);
USEFORM("StockMaster.cpp", frmStockMaster);
USEFORM("CategoryMaster.cpp", frmCategoryMaster);
USEFORM("UnitTypeMaster.cpp", frmUnitType);
USEFORM("DataModules.cpp", frmDataModules);
USEFORM("Search.cpp", frmSearch);
USEFORM("About.cpp", frmAbout);
USEFORM("Rpt_StockGeneral.cpp", frmRpt_StockGeneral);
USEFORM("ModifyQty.cpp", frmModifyQty);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TfrmMain), &frmMain);
                 Application->CreateForm(__classid(TfrmStockMaster), &frmStockMaster);
                 Application->CreateForm(__classid(TfrmCategoryMaster), &frmCategoryMaster);
                 Application->CreateForm(__classid(TfrmUnitType), &frmUnitType);
                 Application->CreateForm(__classid(TfrmDataModules), &frmDataModules);
                 Application->CreateForm(__classid(TfrmSearch), &frmSearch);
                 Application->CreateForm(__classid(TfrmAbout), &frmAbout);
                 Application->CreateForm(__classid(TfrmRpt_StockGeneral), &frmRpt_StockGeneral);
                 Application->CreateForm(__classid(TfrmModifyQty), &frmModifyQty);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
