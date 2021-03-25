file1=input('请输入需要比较的第一个文件名:')
file2=input('请输入需要比较的第二个文件名:')
count=[]
f1tell=f2tell=1
line=0
f1=open('C:\\Users\\14229\\Desktop\\'+file1)
f2=open('C:\\Users\\14229\\Desktop\\'+file2)
end1=f1.seek(0,2)
end2=f2.seek(0,2)
f1.seek(0,0)
f2.seek(0,0)
while f1.tell()!=end1 and f2.tell()!=end2:
        if f1.readline()==f2.readline():
                line+=1
        else:
                line+=1
                count.append(line)
print('两个文件共有【%d】处不同:'%len(count))
for each in count:
        print('第【%d】行不一样'%each)
f1.close()
f2.close()

