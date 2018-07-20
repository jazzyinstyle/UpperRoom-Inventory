//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "About.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAbout *frmAbout;
//---------------------------------------------------------------------------
__fastcall TfrmAbout::TfrmAbout(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAbout::FormShow(TObject *Sender)
{
    this->Width = 320;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAbout::btnCloseClick(TObject *Sender)
{
    Close();         
}
//---------------------------------------------------------------------------
void __fastcall TfrmAbout::btnBackClick(TObject *Sender)
{
    this->Left = 350; 
    this->Width = 320;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAbout::btnAuthorClick(TObject *Sender)
{
    this->Left = 240;
    this->Width = 578;        
}
//---------------------------------------------------------------------------
