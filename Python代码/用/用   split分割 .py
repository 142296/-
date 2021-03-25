line=0
name=input('请输入要打开的文件名:')
f=open(name)
out=input('请输入需要打印的行数\n例5,10:')
(a,b)=out.split(',')
a=int(a)
b=int(b)
if a==1 and b==-1:
    list='全文'
elif a==1:
    list='从开始到%d行'%b
elif b==-1:
    list='从%d行到最后'%a
else :
    list='从%d到%d行'%(a,b)
print('%s%s内容如下:'%(name,list))
for each in f:
    if a<=line and b==-1:
        print(each)
        continue
    line+=1
    if a<=line<=b:
        print(each)
f.close()
