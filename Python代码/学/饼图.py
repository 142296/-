import xlrd
import matplotlib.pyplot as plt
import numpy as np
柜台=dict()
book=xlrd.open_workbook('超市营业额2.xlsx')
sheet=book.sheets()[0]
row_num=sheet.nrows
for j in range(0,row_num):
        row=sheet.row_values(j)
        if j > 0:
                if row[5] in 柜台:
                        if row[4]=='':
                                row[4]=0
                        柜台[row[5]]+=row[4]
                else:
                        柜台[row[5]]=0
plt.figure(figsize=(6,9)) #调节图形大小
colors = ['red','yellowgreen','lightskyblue','yellow'] #每块颜色定义
explode = (0,0,0,0) #将某一块分割出来，值越大分割出的间隙越大
patches,text1,text2 = plt.pie(柜台.values(),
                      explode=explode,
                      labels=柜台.keys(),
                      colors=colors,
                      autopct = '%3.2f%%', #数值保留固定小数位
                      shadow = False, #无阴影设置
                      startangle =90, #逆时针起始角度设置
                      pctdistance = 0.6) #数值距圆心半径倍数距离
#patches饼图的返回值，texts1饼图外label的文本，texts2饼图内部的文本
# x，y轴刻度设置一致，保证饼图为圆形
plt.axis('equal')
plt.show()





        
