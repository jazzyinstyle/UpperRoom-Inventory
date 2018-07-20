object frmMain: TfrmMain
  Left = -4
  Top = -4
  Width = 1032
  Height = 746
  Caption = 'Upperoom Inventory System'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poDesktopCenter
  WindowState = wsMaximized
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 40
    Width = 1009
    Height = 81
    Color = clBtnFace
    ParentColor = False
    TabOrder = 1
    object btnSearch: TBitBtn
      Left = 347
      Top = 16
      Width = 75
      Height = 49
      Caption = 'Search'
      TabOrder = 0
      OnClick = btnSearchClick
    end
    object BitBtn2: TBitBtn
      Left = 427
      Top = 16
      Width = 75
      Height = 49
      Caption = 'Add Qty'
      TabOrder = 1
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 507
      Top = 16
      Width = 75
      Height = 49
      Caption = 'Minus Qty'
      TabOrder = 2
      OnClick = BitBtn3Click
    end
    object btnClose: TBitBtn
      Left = 587
      Top = 16
      Width = 75
      Height = 49
      Caption = 'Close'
      TabOrder = 3
      OnClick = btnCloseClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 128
    Width = 185
    Height = 537
    Caption = 'Browse'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    object dbgStockID: TDBGrid
      Left = 8
      Top = 24
      Width = 169
      Height = 497
      Cursor = crHandPoint
      DataSource = frmDataModules.dsStock
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Options = [dgTitles, dgRowLines, dgRowSelect]
      ParentFont = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clNavy
      TitleFont.Height = -13
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = [fsBold]
      OnCellClick = dbgStockIDCellClick
      OnKeyUp = dbgStockIDKeyUp
      OnMouseUp = dbgStockIDMouseUp
    end
  end
  object GroupBox3: TGroupBox
    Left = 200
    Top = 128
    Width = 817
    Height = 537
    TabOrder = 3
    object Label1: TLabel
      Left = 36
      Top = 24
      Width = 73
      Height = 24
      Caption = 'Stock ID:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 36
      Top = 74
      Width = 56
      Height = 24
      Caption = 'Name:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 36
      Top = 124
      Width = 80
      Height = 24
      Caption = 'Category:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 36
      Top = 174
      Width = 85
      Height = 24
      Caption = 'Unit Type:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 36
      Top = 225
      Width = 131
      Height = 24
      Caption = 'Unit Price (RM):'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 36
      Top = 275
      Width = 239
      Height = 24
      Caption = 'Calculated Balance Quantity:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 36
      Top = 325
      Width = 99
      Height = 24
      Caption = 'Description:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object lblTotalBalPrice: TLabel
      Left = 506
      Top = 280
      Width = 110
      Height = 24
      Caption = 'total bal price'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object txtID: TStaticText
      Left = 360
      Top = 21
      Width = 62
      Height = 28
      Caption = 'D0001'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object txtName: TStaticText
      Left = 360
      Top = 71
      Width = 50
      Height = 28
      Caption = 'Steak'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object txtCategory: TStaticText
      Left = 360
      Top = 122
      Width = 45
      Height = 28
      Caption = 'Meat'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object txtType: TStaticText
      Left = 360
      Top = 173
      Width = 61
      Height = 28
      Caption = 'Pieces'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
    end
    object txtPrice: TStaticText
      Left = 360
      Top = 223
      Width = 49
      Height = 28
      Caption = '34.50'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
    object txtCalQty: TStaticText
      Left = 360
      Top = 280
      Width = 14
      Height = 28
      Caption = '2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object txtCritical: TStaticText
      Left = 648
      Top = 282
      Width = 56
      Height = 24
      Caption = 'critical'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object txtDesc: TStaticText
      Left = 360
      Top = 325
      Width = 126
      Height = 28
      Caption = 'No description'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
    end
    object GroupBox4: TGroupBox
      Left = 16
      Top = 368
      Width = 785
      Height = 153
      TabOrder = 8
      object Label9: TLabel
        Left = 20
        Top = 20
        Width = 203
        Height = 24
        Caption = 'Actual Balance Quantity:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 20
        Top = 62
        Width = 303
        Height = 24
        Caption = 'Total Balance Price Difference (RM):'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label7: TLabel
        Left = 20
        Top = 105
        Width = 145
        Height = 24
        Caption = 'Last Updated On:'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlue
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object lblActTotalBalPrice: TLabel
        Left = 488
        Top = 20
        Width = 164
        Height = 24
        Caption = 'actual total bal price'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object txtTotalPrice: TStaticText
        Left = 344
        Top = 60
        Width = 14
        Height = 28
        Caption = '1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object txtActBalQty: TEdit
        Left = 344
        Top = 20
        Width = 97
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object btnSave: TBitBtn
        Left = 680
        Top = 88
        Width = 75
        Height = 49
        Caption = 'Save'
        TabOrder = 2
        OnClick = btnSaveClick
      end
      object txtLastUpdate: TStaticText
        Left = 344
        Top = 101
        Width = 220
        Height = 28
        Caption = '25 June 2005 10:00 PM'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
      end
    end
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 673
    Width = 1024
    Height = 19
    Panels = <>
    ParentShowHint = False
    ShowHint = True
    SimplePanel = True
    SimpleText = 'Welcome to Upperoom Inventory System...'
  end
  object txtDateTime: TStaticText
    Left = 803
    Top = 8
    Width = 4
    Height = 4
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object MainTitle: TStaticText
    Left = 400
    Top = 3
    Width = 152
    Height = 42
    Caption = 'Stock Entry'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -29
    Font.Name = 'Palatino Linotype'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object MainMenu: TMainMenu
    object mnuFile: TMenuItem
      Caption = 'File'
      object mnuFileExit: TMenuItem
        Caption = 'Exit'
        OnClick = mnuFileExitClick
      end
    end
    object mnuMaster: TMenuItem
      Caption = 'Master'
      object mnuMasterStock: TMenuItem
        Caption = 'Stock'
        OnClick = mnuMasterStockClick
      end
      object mnuMasterCategory: TMenuItem
        Caption = 'Category'
        OnClick = mnuMasterCategoryClick
      end
      object mnuMasterUnitType: TMenuItem
        Caption = 'Unit Type'
        OnClick = mnuMasterUnitTypeClick
      end
      object mnuMasterMenu: TMenuItem
        Caption = 'Menu'
      end
    end
    object mnuReport: TMenuItem
      Caption = 'Report'
      object StockGeneral: TMenuItem
        Caption = 'Stock General'
        OnClick = StockGeneralClick
      end
      object StockCritical: TMenuItem
        Caption = 'Stock Critical'
      end
    end
    object mnuHelp: TMenuItem
      Caption = 'Help'
      object mnuHelpAbout: TMenuItem
        Caption = 'About'
        OnClick = mnuHelpAboutClick
      end
    end
  end
  object DateTimeTimer: TTimer
    OnTimer = DateTimeTimerTimer
    Left = 32
  end
  object StatusBarTimer: TTimer
    Interval = 100
    OnTimer = StatusBarTimerTimer
    Left = 64
  end
  object ApplicationEvents: TApplicationEvents
    Left = 128
  end
  object TitleTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = TitleTimerTimer
    Left = 96
  end
end
