object frmModifyQty: TfrmModifyQty
  Left = 348
  Top = 162
  Width = 305
  Height = 323
  Caption = 'Modify Quantity'
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
    Left = 16
    Top = 8
    Width = 265
    Height = 209
    TabOrder = 0
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
      Top = 69
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
    object Label5: TLabel
      Left = 24
      Top = 114
      Width = 61
      Height = 16
      Caption = 'Quantity:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object txtQty: TEdit
      Left = 96
      Top = 112
      Width = 41
      Height = 24
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '0'
    end
    object txtStockID: TEdit
      Left = 96
      Top = 24
      Width = 145
      Height = 22
      BevelInner = bvNone
      BevelOuter = bvNone
      Color = clBtnFace
      Ctl3D = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 1
    end
    object txtStockName: TEdit
      Left = 96
      Top = 68
      Width = 145
      Height = 22
      BevelInner = bvNone
      BevelOuter = bvNone
      Color = clBtnFace
      Ctl3D = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentCtl3D = False
      ParentFont = False
      TabOrder = 2
    end
    object btnSave: TBitBtn
      Left = 96
      Top = 160
      Width = 75
      Height = 34
      Caption = 'Save'
      TabOrder = 3
      OnClick = btnSaveClick
    end
    object UpDown: TUpDown
      Left = 137
      Top = 112
      Width = 16
      Height = 24
      Associate = txtQty
      Min = 1
      Max = 10000
      Position = 1
      TabOrder = 4
      Wrap = False
    end
  end
  object btnClose: TBitBtn
    Left = 112
    Top = 240
    Width = 75
    Height = 34
    Caption = 'Close'
    TabOrder = 1
    OnClick = btnCloseClick
  end
end
