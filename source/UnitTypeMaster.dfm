object frmUnitType: TfrmUnitType
  Left = 0
  Top = 238
  BorderStyle = bsNone
  Caption = 'Unit Type Master'
  ClientHeight = 466
  ClientWidth = 720
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblModeText: TLabel
    Left = 224
    Top = 112
    Width = 45
    Height = 20
    Caption = 'TEST'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblMode: TLabel
    Left = 168
    Top = 112
    Width = 55
    Height = 20
    Caption = 'Mode: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 447
    Width = 720
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = -4
    Width = 1009
    Height = 81
    TabOrder = 1
    object btnAdd: TBitBtn
      Left = 260
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Add'
      TabOrder = 0
      OnClick = btnAddClick
    end
    object btnEdit: TBitBtn
      Left = 341
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Edit'
      TabOrder = 1
      OnClick = btnEditClick
    end
    object btnDelete: TBitBtn
      Left = 586
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Delete'
      TabOrder = 2
      OnClick = btnDeleteClick
    end
    object btnClose: TBitBtn
      Left = 668
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Close'
      TabOrder = 3
      OnClick = btnCloseClick
    end
    object btnSave: TBitBtn
      Left = 423
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Save'
      TabOrder = 4
      OnClick = btnSaveClick
    end
    object btnCancel: TBitBtn
      Left = 504
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Cancel'
      TabOrder = 5
      OnClick = btnCancelClick
    end
  end
  object GroupBox1: TGroupBox
    Left = 164
    Top = 152
    Width = 697
    Height = 441
    TabOrder = 2
    object Label1: TLabel
      Left = 215
      Top = 43
      Width = 91
      Height = 16
      Caption = 'Unit Type ID:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 215
      Top = 91
      Width = 46
      Height = 16
      Caption = 'Name:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object dbgridType: TDBGrid
      Left = 27
      Top = 31
      Width = 150
      Height = 386
      Cursor = crHandPoint
      DataSource = frmDataModules.dsStock
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Options = [dgTitles, dgIndicator, dgColumnResize, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
      ParentFont = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clNavy
      TitleFont.Height = -13
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = [fsBold]
      OnCellClick = dbgridTypeCellClick
      OnKeyUp = dbgridTypeKeyUp
      OnMouseUp = dbgridTypeMouseUp
    end
    object txtName: TEdit
      Left = 318
      Top = 88
      Width = 275
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object txtID: TEdit
      Left = 317
      Top = 40
      Width = 132
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
  end
  object TypeTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = TypeTimerTimer
    Left = 16
    Top = 104
  end
end
