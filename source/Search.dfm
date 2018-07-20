object frmSearch: TfrmSearch
  Left = 237
  Top = 152
  Width = 558
  Height = 587
  Caption = 'Search Options'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 12
    Top = 15
    Width = 517
    Height = 434
    Caption = 'Enter Selection Criteria:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 40
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
      Top = 82
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
      Top = 124
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
      Top = 166
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
      Top = 251
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
      Top = 209
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
      Top = 293
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
      Top = 336
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
      Top = 40
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
      Top = 82
      Width = 121
      Height = 24
      TabOrder = 1
    end
    object cboCategory: TComboBox
      Left = 152
      Top = 124
      Width = 145
      Height = 24
      ItemHeight = 16
      TabOrder = 2
    end
    object cboType: TComboBox
      Left = 152
      Top = 166
      Width = 145
      Height = 24
      ItemHeight = 16
      TabOrder = 3
    end
    object txtPrice: TEdit
      Left = 196
      Top = 208
      Width = 121
      Height = 24
      TabOrder = 4
    end
    object txtQty: TEdit
      Left = 196
      Top = 249
      Width = 121
      Height = 24
      TabOrder = 5
    end
    object txtCritical: TEdit
      Left = 196
      Top = 290
      Width = 121
      Height = 24
      TabOrder = 6
    end
    object txtDesc: TEdit
      Left = 152
      Top = 336
      Width = 313
      Height = 24
      TabOrder = 7
    end
    object btnSearch: TBitBtn
      Left = 382
      Top = 373
      Width = 82
      Height = 42
      Caption = 'Look Up'
      TabOrder = 8
      OnClick = btnSearchClick
    end
    object cboCompare1: TComboBox
      Left = 152
      Top = 208
      Width = 43
      Height = 24
      ItemHeight = 16
      TabOrder = 9
      Text = 'cboCompare1'
      Items.Strings = (
        '='
        '<'
        '>'
        '<='
        '>='
        '!=')
    end
    object cboCompare2: TComboBox
      Left = 152
      Top = 249
      Width = 43
      Height = 24
      ItemHeight = 16
      TabOrder = 10
      Text = 'cboCompare1'
      Items.Strings = (
        '='
        '<'
        '>'
        '<='
        '>='
        '!=')
    end
    object cboCompare3: TComboBox
      Left = 152
      Top = 291
      Width = 43
      Height = 24
      ItemHeight = 16
      TabOrder = 11
      Text = 'cboCompare1'
      Items.Strings = (
        '='
        '<'
        '>'
        '<='
        '>='
        '!=')
    end
  end
  object GroupBox2: TGroupBox
    Left = 11
    Top = 456
    Width = 518
    Height = 81
    TabOrder = 1
    object btnClose: TBitBtn
      Left = 268
      Top = 21
      Width = 82
      Height = 42
      Caption = 'Close'
      TabOrder = 0
      OnClick = btnCloseClick
    end
    object btnAll: TBitBtn
      Left = 168
      Top = 21
      Width = 82
      Height = 42
      Caption = 'Select All'
      TabOrder = 1
      OnClick = btnAllClick
    end
  end
end
