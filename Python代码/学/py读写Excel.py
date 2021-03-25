import xlrd
import xlwt
count=1
book=xlrd.open_workbook('超市营业额2.xlsx')#读取文件打开
workbook=xlwt.Workbook()        #写入文件打开
sheet_num=book.nsheets          #sheet数
for i in range(0,sheet_num):            #sheet
        sheet=book.sheets()[i]
        name='sheet'+str(count)
        count+=1                        #更换sheet
        wsheet=workbook.add_sheet(name)
        row_num=sheet.nrows             #行数
        for j in range(0,row_num):              #行
                row=sheet.row_values(j)
                if(j>0):                        #更改工号
                        row[0]=int(row[0])
                        row[0]=row[0]%10*10000+row[0]
                col_num=sheet.ncols             #列数
                for k in range(0,col_num):      #列
                        wsheet.write(j,k,row[k])        #写入
workbook.save('超市营业额2_修改工号.xls')           #保存
