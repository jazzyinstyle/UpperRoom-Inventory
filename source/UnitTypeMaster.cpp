//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitTypeMaster.h"
#include "DataModules.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmUnitType *frmUnitType;
//---------------------------------------------------------------------------
__fastcall TfrmUnitType::TfrmUnitType(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TfrmUnitType::FormShow(TObject *Sender)
{
    InitialSetting();
}

void TfrmUnitType::InitialSetting()
{
    this->Left = 0;
    this->Top = 90;
    this->Width = 1032;
    this->Height = 630;

    m_bEdit = false;

    LoadTypeBrowse("");
    LoadFirstRec();

    DisableInput();

    ShowViewControl();
}


void TfrmUnitType::DisableInput()
{
    txtID->ReadOnly = true;
    txtName->ReadOnly = true;
}


void TfrmUnitType::EnableInput()
{
    txtID->ReadOnly = false;
    txtName->ReadOnly = false;
}


void TfrmUnitType::ShowViewControl()
{
    dbgridType->Enabled = true;
    btnAdd->Enabled = true;
    btnEdit->Enabled = true;
    btnDelete->Enabled = true;
    btnSave->Enabled = false;
    btnCancel->Enabled = false;

    lblModeText->Caption = "View Record";    
}


void TfrmUnitType::ClearTypeInput()
{
    txtID->Text = "";
    txtName->Text = "";
}


void TfrmUnitType::LoadTypeBrowse(AnsiString Sql)
{
    AnsiString strSql = " SELECT unit_id FROM UNITTYPE ";

    char * pch1 = strstr(Sql.c_str(), " WHERE ");

    if(pch1 != NULL)
    {
        AnsiString strSearch = pch1;
        strSql = strSql + strSearch;
    }

    strSql += " ORDER BY unit_id ";

    frmDataModules->BrowseQry->Active = false;
    frmDataModules->BrowseQry->SQL->Clear();
    frmDataModules->BrowseQry->SQL->Add(strSql);
    frmDataModules->BrowseQry->Active = true;

    dbgridType->Columns->Items[0]->Title->Caption = "Unit Type ID";    
}


void TfrmUnitType::LoadFirstRec()
{
    AnsiString strTypeID = dbgridType->Columns->Items[0]->Field->AsString;
    AnsiString strTypeName;
    
    AnsiString SQL = "SELECT * FROM UNITTYPE ";

    if(strTypeID.Length() > 0)
    {
        SQL += " WHERE unit_id = '" + strTypeID + "' ";
    }

    frmDataModules->CategoryQry->Active = false;
    frmDataModules->CategoryQry->SQL->Clear();
    frmDataModules->CategoryQry->SQL->Add(SQL);
    frmDataModules->CategoryQry->Active = true;

    int iRecCnt = frmDataModules->CategoryQry->RecordCount;

    if(iRecCnt > 0)
    {
        strTypeName = frmDataModules->CategoryQry->FieldByName("unit_type")->AsString;

        txtID->Text           = strTypeID;
        txtName->Text         = strTypeName;
    }
}


bool TfrmUnitType::LoadType(AnsiString strID)
{
    AnsiString strTypeID, strName;

    AnsiString Sql;

    if(strID.Length() > 0)
    {
        Sql = " SELECT * FROM UNITTYPE "
              " WHERE unit_id = '" + strID + "' ";
    }
    else
    {
        Sql = " SELECT * FROM UNITTYPE ";
    }

    frmDataModules->UnitTypeQry->Active = false;
    frmDataModules->UnitTypeQry->SQL->Clear();
    frmDataModules->UnitTypeQry->SQL->Add(Sql);
    frmDataModules->UnitTypeQry->Active = true;

    int iRecCount = frmDataModules->UnitTypeQry->RecordCount;

    if(iRecCount <= 0)
    {
        return false;
    }

    strTypeID = frmDataModules->UnitTypeQry->FieldByName("unit_id")->AsString;
    strName = frmDataModules->UnitTypeQry->FieldByName("unit_type")->AsString;

    txtID->Text = strID;
    txtName->Text = strName;

    return true;
}


void __fastcall TfrmUnitType::btnAddClick(TObject *Sender)
{
    HandleAdd();        
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitType::btnEditClick(TObject *Sender)
{
    HandleEdit();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitType::btnSaveClick(TObject *Sender)
{
    HandleSave();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitType::btnCancelClick(TObject *Sender)
{
    HandleCancel();
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitType::btnDeleteClick(TObject *Sender)
{
    HandleDelete();
}
//---------------------------------------------------------------------------


void TfrmUnitType::HandleAdd()
{
    lblModeText->Caption = "Add Record";

    EnableInput();

    dbgridType->Enabled = false;
    btnAdd->Enabled = false;
    btnEdit->Enabled = false;
    btnDelete->Enabled = false;
    btnSave->Enabled = true;
    btnCancel->Enabled = true;

    ClearTypeInput();
}


void __fastcall TfrmUnitType::dbgridTypeCellClick(TColumn *Column)
{
    AnsiString strTypeID = dbgridType->Columns->Items[0]->Field->AsString;

    LoadType(strTypeID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitType::dbgridTypeKeyUp(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    AnsiString strTypeID = dbgridType->Columns->Items[0]->Field->AsString;

    LoadType(strTypeID);
}
//---------------------------------------------------------------------------

void __fastcall TfrmUnitType::dbgridTypeMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    AnsiString strTypeID = dbgridType->Columns->Items[0]->Field->AsString;

    LoadType(strTypeID);
}
//---------------------------------------------------------------------------


void TfrmUnitType::HandleEdit()
{
    lblModeText->Caption = "Edit Record";

    m_bEdit = true;

    EnableInput();

    dbgridType->Enabled = false;
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


void TfrmUnitType::HandleSave()
{
    if(!m_bEdit)
    {
        AddType();
    }
    else
    {
        m_bEdit = false;

        EditType();
    }

    txtID->Enabled = true;

    DisableInput();

    ShowViewControl();

    LoadTypeBrowse("");
    LoadFirstRec();
}


void TfrmUnitType::HandleCancel()
{
    txtID->Enabled = true;

    LoadTypeBrowse("");

    DisableInput();

    ShowViewControl();

    LoadTypeBrowse("");
    LoadFirstRec();
}


void TfrmUnitType::HandleDelete()
{
    DeleteType();
}

void __fastcall TfrmUnitType::btnCloseClick(TObject *Sender)
{
    Close();

    frmMain->RestoreMain();        
}
//---------------------------------------------------------------------------


bool TfrmUnitType::AddType()
{
    AnsiString strNo = txtID->Text;
    AnsiString strName = txtName->Text;

    AnsiString Sql = " SELECT * FROM UNITTYPE "
                     " WHERE unit_id = '" + strNo + "' ";

    frmDataModules->UnitTypeQry->Active = false;
    frmDataModules->UnitTypeQry->SQL->Clear();
    frmDataModules->UnitTypeQry->SQL->Add(Sql);
    frmDataModules->UnitTypeQry->Active = true;

    int iRecCount = frmDataModules->UnitTypeQry->RecordCount;

    if(iRecCount > 0)
    {
        ShowMessage("Duplicate record found. Operation aborted");
        return false;
    }

    Sql =  " INSERT INTO UNITTYPE "
           " (unit_id, unit_type) "
           " VALUES ('" + strNo + "', "
           " '" + strName + "')";

    frmDataModules->UnitTypeQry->Active = false;
    frmDataModules->UnitTypeQry->SQL->Clear();
    frmDataModules->UnitTypeQry->SQL->Add(Sql);

    if(frmDataModules->UnitTypeQry->ExecSQL() > 0)
    {
        ShowMessage("Record Added");

        LoadTypeBrowse("");
        LoadFirstRec();

        return true;
    }

    ShowMessage("Operation Unsuccessful");

    return false;
}

bool TfrmUnitType::EditType()
{
    AnsiString strNo = txtID->Text;
    AnsiString strName = txtName->Text;
    
    AnsiString Sql =  " UPDATE UNITTYPE "
                      " SET unit_type = '" + strName + "' ";
                      
    Sql = Sql + " WHERE unit_id = '" + strNo + "' ";

    frmDataModules->UnitTypeQry->Active = false;
    frmDataModules->UnitTypeQry->SQL->Clear();
    frmDataModules->UnitTypeQry->SQL->Add(Sql);

    if(frmDataModules->UnitTypeQry->ExecSQL() > 0)
    {
        ShowMessage("Record Updated");

        LoadTypeBrowse("");
        LoadFirstRec();

        return true;
    }

    ShowMessage("Operation Unsuccessful");

    return false;
}

bool TfrmUnitType::DeleteType()
{
    AnsiString strNo = txtID->Text;

    AnsiString Sql = " DELETE * FROM UNITTYPE "
                     " WHERE unit_id = '" + strNo + "' ";

    frmDataModules->UnitTypeQry->Active = false;
    frmDataModules->UnitTypeQry->SQL->Clear();
    frmDataModules->UnitTypeQry->SQL->Add(Sql);

    if(frmDataModules->UnitTypeQry->ExecSQL() > 0)
    {
        ShowMessage("Record deleted.");

        LoadTypeBrowse("");
        LoadFirstRec();

        return true;
    }

    return false;
}


void __fastcall TfrmUnitType::TypeTimerTimer(TObject *Sender)
{
//        
}
//---------------------------------------------------------------------------

