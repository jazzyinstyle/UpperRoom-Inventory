//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DataModules.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmDataModules *frmDataModules;
//---------------------------------------------------------------------------
__fastcall TfrmDataModules::TfrmDataModules(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDataModules::FormCreate(TObject *Sender)
{
    AnsiString strPath = GetCurrentDir();
    AnsiString strFullPath = strPath + "\\Upperoom.mdb";
    AnsiString strConnectStr =
    "Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source="
    + strFullPath + ";Mode=Share Deny None;Extended Properties="";"
    "Persist Security Info=False;Jet OLEDB:System database="";"
    "Jet OLEDB:Registry Path="";Jet OLEDB:Database Password="";"
    "Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking Mode=1;"
    "Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;"
    "Jet OLEDB:New Database Password="";Jet OLEDB:Create System Database=False;"
    "Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;"
    "Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False;";
    
    UpperoomConn->Connected = false;
    UpperoomConn->ConnectionString = strConnectStr;
    UpperoomConn->Connected = true;

}
//---------------------------------------------------------------------------

