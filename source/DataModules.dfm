object frmDataModules: TfrmDataModules
  Left = 220
  Top = 157
  Width = 696
  Height = 480
  Caption = 'Data Module'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object UpperoomConn: TADOConnection
    LoginPrompt = False
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 16
    Top = 16
  end
  object StockTable: TADOTable
    Connection = UpperoomConn
    TableName = 'Stock'
    Left = 16
    Top = 56
  end
  object dsStock: TDataSource
    DataSet = BrowseQry
    Left = 16
    Top = 104
  end
  object BrowseQry: TADOQuery
    Connection = UpperoomConn
    Parameters = <>
    Left = 64
    Top = 104
  end
  object StockQuery: TADOQuery
    Connection = UpperoomConn
    Parameters = <>
    Left = 16
    Top = 144
  end
  object CategoryQry: TADOQuery
    Connection = UpperoomConn
    Parameters = <>
    Left = 64
    Top = 16
  end
  object UnitTypeQry: TADOQuery
    Connection = UpperoomConn
    Parameters = <>
    Left = 64
    Top = 56
  end
  object dsCat: TDataSource
    DataSet = BrowseQry
    Left = 64
    Top = 144
  end
  object dsType: TDataSource
    DataSet = BrowseQry
    Left = 112
    Top = 16
  end
  object StockGenRpt_Table: TADOTable
    Connection = UpperoomConn
    Left = 112
    Top = 56
  end
  object StockGenRpt_Query: TADOQuery
    Connection = UpperoomConn
    Parameters = <>
    Left = 112
    Top = 104
  end
  object StockActQuery: TADOQuery
    Connection = UpperoomConn
    Parameters = <>
    Left = 112
    Top = 144
  end
end
