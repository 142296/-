import xlrd
data=[]
book=xlrd.open_workbook('超市营业额2.xlsx')
sheet_num=book.nsheets
for i in range(0,sheet_num):
        sheet=book.sheets()[i]
        row_num=sheet.nrows
        for j in range(0,row_num):
                row=sheet.row_values(j)
                data.append(row)
                
                
        
