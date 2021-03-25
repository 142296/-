f=open('1.txt',encoding='utf-8')
num=0
b=[]
a=[]
member=[]
for each in f:             #拿数据
        num+=1
        b.append(each)
f.close()
for i in range(0,num):          #取签到的人
        if '[群签到]' in b[i]:
                a.append(b[i-1])
b=[]
for each in a:                  #查重
        if each[0:10] in b:
                continue
        else:
                b.append(each[0:9])
for each in b:
        while ' ' in each[-2:]:
                each=each[0:-1]
        member.append(each)
