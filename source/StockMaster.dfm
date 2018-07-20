object frmStockMaster: TfrmStockMaster
  Left = 82
  Top = 294
  BorderStyle = bsNone
  Caption = 'Stock Master'
  ClientHeight = 565
  ClientWidth = 821
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object lblMode: TLabel
    Left = 16
    Top = 88
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
  object lblModeText: TLabel
    Left = 72
    Top = 88
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
  object GroupBox2: TGroupBox
    Left = 8
    Top = 126
    Width = 185
    Height = 475
    Caption = 'Browse'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object dbgridStock: TDBGrid
      Left = 16
      Top = 24
      Width = 153
      Height = 433
      Cursor = crHandPoint
      DataSource = frmDataModules.dsStock
      DragCursor = crHandPoint
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Options = [dgTitles, dgIndicator, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ParentFont = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clNavy
      TitleFont.Height = -13
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = [fsBold]
      OnCellClick = dbgridStockCellClick
      OnKeyUp = dbgridStockKeyUp
      OnMouseUp = dbgridStockMouseUp
    end
  end
  object GroupBox1: TGroupBox
    Left = 208
    Top = 128
    Width = 801
    Height = 473
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object Label1: TLabel
      Left = 24
      Top = 24
      Width = 63
      Height = 16
      Caption = 'Stock ID:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 24
      Top = 66
      Width = 46
      Height = 16
      Caption = 'Name:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 24
      Top = 108
      Width = 68
      Height = 16
      Caption = 'Category:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 24
      Top = 150
      Width = 72
      Height = 16
      Caption = 'Unit Type:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 24
      Top = 235
      Width = 122
      Height = 16
      Caption = 'Balance Quantity:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 24
      Top = 193
      Width = 109
      Height = 16
      Caption = 'Unit Price (RM):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 24
      Top = 277
      Width = 95
      Height = 16
      Caption = 'Critical Level:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 24
      Top = 320
      Width = 84
      Height = 16
      Caption = 'Description:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object txtID: TEdit
      Left = 152
      Top = 24
      Width = 121
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object txtName: TEdit
      Left = 152
      Top = 66
      Width = 121
      Height = 24
      TabOrder = 1
    end
    object cboCategory: TComboBox
      Left = 152
      Top = 108
      Width = 145
      Height = 24
      ItemHeight = 16
      TabOrder = 2
    end
    object cboType: TComboBox
      Left = 152
      Top = 150
      Width = 145
      Height = 24
      ItemHeight = 16
      TabOrder = 3
    end
    object txtPrice: TEdit
      Left = 152
      Top = 193
      Width = 121
      Height = 24
      TabOrder = 4
    end
    object txtQty: TEdit
      Left = 152
      Top = 235
      Width = 121
      Height = 24
      TabOrder = 5
    end
    object txtCritical: TEdit
      Left = 152
      Top = 277
      Width = 121
      Height = 24
      TabOrder = 6
    end
    object txtDesc: TEdit
      Left = 152
      Top = 320
      Width = 313
      Height = 24
      TabOrder = 7
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = -4
    Width = 1009
    Height = 81
    TabOrder = 2
    object btnSearch: TBitBtn
      Left = 211
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Search'
      TabOrder = 0
      OnClick = btnSearchClick
    end
    object btnAdd: TBitBtn
      Left = 292
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Add'
      TabOrder = 1
      OnClick = btnAddClick
    end
    object btnEdit: TBitBtn
      Left = 373
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Edit'
      TabOrder = 2
      OnClick = btnEditClick
    end
    object btnDelete: TBitBtn
      Left = 617
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Delete'
      TabOrder = 3
      OnClick = btnDeleteClick
    end
    object btnClose: TBitBtn
      Left = 700
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Close'
      TabOrder = 4
      OnClick = btnCloseClick
    end
    object btnSave: TBitBtn
      Left = 455
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Save'
      TabOrder = 5
      OnClick = btnSaveClick
    end
    object btnCancel: TBitBtn
      Left = 536
      Top = 24
      Width = 81
      Height = 41
      Caption = 'Cancel'
      TabOrder = 6
      OnClick = btnCancelClick
    end
  end
  object StockTimer: TTimer
    Left = 144
    Top = 96
  end
end
