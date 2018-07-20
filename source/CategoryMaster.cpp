//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CategoryMaster.h"
#include "DataModules.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCategoryMaster *frmCategoryMaster;
//---------------------------------------------------------------------------
__fastcall TfrmCategoryMaster::TfrmCategoryMaster(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TfrmCategoryMaster::FormShow(TObject *Sender)
{
    InitialSetting();
}

void TfrmCategoryMaster::InitialSetting()
{
    this->Left = 0;
    this->Top = 90;
    this->Width = 1032;
//    this->Width = 0;
    this->Height = 630;

    m_bEdit = false;

    LoadCatBrowse("");
    LoadFirstRec();

    DisableInput();

    ShowViewControl();
}


void TfrmCategoryMaster::DisableInput()
{
    txtID->ReadOnly = true;
    txtName->ReadOnly = true;
}


void TfrmCategoryMaster::EnableInput()
{
    txtID->ReadOnly = false;
    txtName->ReadOnly = false;
}


void TfrmCategoryMaster::ShowViewControl()
{
    dbgridCat->Enabled = true;
    btnAdd->Enabled = true;
    btnEdit->Enabled = true;
    btnDelete->Enabled = true;
    btnSave->Enabled = false;
    btnCancel->Enabled = false;

    lblModeText->Caption = "View Record";
}


void TfrmCategoryMaster::ClearCatInput()
{
    txtID->Text = "";
    txtName->Text = "";
}


void TfrmCategoryMaster::LoadCatBrowse(AnsiString Sql)
{
    AnsiString strSql = " SELECT category_id FROM CATEGORY ";

    char * pch1 = strstr(Sql.c_str(), "WHERE");

    if(pch1 != NULL)
    {
        AnsiString strSearch = pch1;
        strSql = strSql + strSearch;
    }

    strSql += " ORDER BY category_id ";
    
    frmDataModules->BrowseQry->Active = false;
    frmDataModules->BrowseQry->SQL->Clear();
    frmDataModules->BrowseQry->SQL->Add(strSql);
    frmDataModules->BrowseQry->Active = true;

    dbgridCat->Columns->Items[0]->Title->Caption = "Category ID";
}


void TfrmCategoryMaster::LoadFirstRec()
{
    AnsiString strCatID = dbgridCat->Columns->Items[0]->Field->AsString;
    AnsiString strCatName;
    
    AnsiString SQL = "SELECT * FROM CATEGORY ";

    if(strCatID.Length() > 0)
    {
        SQL += " WHERE category_id = '" + strCatID + "' ";
    }

    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(SQL);
    frmDataModules->CategoryQry->Active = true;

    int iRecCnt = frmDataModules->CategoryQry->RecordCount;

    if(iRecCnt > 0)
    {
        strCatName = frmDataModules->CategoryQry->FieldByName("category_name")->AsString;

        txtID->Text           = strCatID;
        txtName->Text         = strCatName;
    }
}


bool TfrmCategoryMaster::LoadCategory(AnsiString strID)
{
    AnsiString strCatID, strName;

    AnsiString Sql;

    if(strID.Length() > 0)
    {
        Sql = " SELECT * FROM CATEGORY "
              " WHERE category_id = '" + strID + "' ";
    }
    else
    {
        Sql = " SELECT * FROM CATEGORY ";
    }

    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(Sql);
    frmDataModules->CategoryQry->Active = true;

    int iRecCount = frmDataModules->CategoryQry->RecordCount;

    if(iRecCount <= 0)
    {
        return false;
    }

    strCatID = frmDataModules->CategoryQry->FieldByName("category_id")->AsString;
    strName = frmDataModules->CategoryQry->FieldByName("category_name")->AsString;

    txtID->Text = strID;
    txtName->Text = strName;

    return true;
}


void __fastcall TfrmCategoryMaster::btnAddClick(TObject *Sender)
{
    HandleAdd();        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCategoryMaster::btnEditClick(TObject *Sender)
{
    HandleEdit();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCategoryMaster::btnSaveClick(TObject *Sender)
{
    HandleSave();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCategoryMaster::btnCancelClick(TObject *Sender)
{
    HandleCancel();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCategoryMaster::btnDeleteClick(TObject *Sender)
{
    HandleDelete();
}
//---------------------------------------------------------------------------


void TfrmCategoryMaster::HandleAdd()
{
    lblModeText->Caption = "Add Record";

    EnableInput();

    dbgridCat->Enabled = false;
    btnAdd->Enabled = false;
    btnEdit->Enabled = false;
    btnDelete->Enabled = false;
    btnSave->Enabled = true;
    btnCancel->Enabled = true;

    ClearCatInput();
}


void __fastcall TfrmCategoryMaster::dbgridCatCellClick(TColumn *Column)
{
    AnsiString strCatID = dbgridCat->Columns->Items[0]->Field->AsString;

    LoadCategory(strCatID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCategoryMaster::dbgridCatKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    AnsiString strCatID = dbgridCat->Columns->Items[0]->Field->AsString;

    LoadCategory(strCatID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCategoryMaster::dbgridCatMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    AnsiString strCatID = dbgridCat->Columns->Items[0]->Field->AsString;

    LoadCategory(strCatID);
}
//---------------------------------------------------------------------------


void TfrmCategoryMaster::HandleEdit()
{
    lblModeText->Caption = "Edit Record";

    m_bEdit = true;

    EnableInput();

    dbgridCat->Enabled = false;
    btnAdd->Enabled = false;
    btnEdit->Enabled = false;
    btnDelete->Enabled = false;
    btnSave->Enabled = true;
    btnCancel->Enabled = true;

    if(txtID->Text.Length() <= 0)
    {
        ShowMessage("Unable to edit empty record. Please select a record");
        ShowViewControl();
        return;
    }

    txtID->Enabled = false;
}


void TfrmCategoryMaster::HandleSave()
{
    if(!m_bEdit)
    {
        AddCategory();
    }
    else
    {
        m_bEdit = false;

        EditCategory();
    }

    txtID->Enabled = true;

    DisableInput();

    ShowViewControl();

    LoadCatBrowse("");    
    LoadFirstRec();
}


void TfrmCategoryMaster::HandleCancel()
{
    txtID->Enabled = true;

    LoadCatBrowse("");

    DisableInput();

    ShowViewControl();

    LoadCatBrowse("");
    LoadFirstRec();
}


void TfrmCategoryMaster::HandleDelete()
{
    DeleteCategory();
}

void __fastcall TfrmCategoryMaster::btnCloseClick(TObject *Sender)
{
    Close();

    frmMain->RestoreMain();  
}
//---------------------------------------------------------------------------


bool TfrmCategoryMaster::AddCategory()
{
    AnsiString strNo = txtID->Text;
    AnsiString strName = txtName->Text;

    AnsiString Sql = " SELECT * FROM CATEGORY "
                     " WHERE category_id = '" + strNo + "' ";

    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(Sql);
    frmDataModules->CategoryQry->Active = true;

    int iRecCount = frmDataModules->CategoryQry->RecordCount;

    if(iRecCount > 0)
    {
        ShowMessage("Duplicate record found. Operation aborted");
        return false;
    }

    Sql =  " INSERT INTO CATEGORY "
           " (category_id, category_name) "
           " VALUES ('" + strNo + "', "
           " '" + strName + "')";

    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(Sql);

    if(frmDataModules->CategoryQry->ExecSQL() > 0)
    {
        ShowMessage("Record Added");

        LoadCatBrowse("");        
        LoadFirstRec();

        return true;
    }

    ShowMessage("Operation Unsuccessful");

    return false;
}

bool TfrmCategoryMaster::EditCategory()
{
    AnsiString strNo = txtID->Text;
    AnsiString strName = txtName->Text;
    
    AnsiString Sql =  " UPDATE CATEGORY "
                      " SET category_name = '" + strName + "' ";
                      
    Sql = Sql + " WHERE category_id = '" + strNo + "' ";

    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(Sql);

    if(frmDataModules->CategoryQry->ExecSQL() > 0)
    {
        ShowMessage("Record Updated");

        LoadCatBrowse("");
        LoadFirstRec();

        return true;
    }

    ShowMessage("Operation Unsuccessful");

    return false;
}

bool TfrmCategoryMaster::DeleteCategory()
{
    AnsiString strNo = txtID->Text;

    AnsiString Sql = " DELETE * FROM CATEGORY "
                     " WHERE category_id = '" + strNo + "' ";

    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(Sql);

    if(frmDataModules->CategoryQry->ExecSQL() > 0)
    {
        ShowMessage("Record deleted.");

        LoadCatBrowse("");
        LoadFirstRec();

        return true;
    }

    return false;
}

void __fastcall TfrmCategoryMaster::Cat_TimerTimer(TObject *Sender)
{
    if(this->Width == 900)
    {
        this->Width = 1032;

        Cat_Timer->Enabled = false;
    }
    else
    {
        this->Width += 300;
    }
}
//---------------------------------------------------------------------------

