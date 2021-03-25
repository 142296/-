import openpyxl
wb=openpyxl.Workbook()    #创建一个Excel文件
ws=wb.active             #创建一个sheet
ws['A1']=520                #单个赋值
ws.append([520,1314])       #一行赋值一对一框
ws.append([1314,520])
wb.save('new.xlsx')       #导出Excel表格
