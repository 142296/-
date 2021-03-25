name=input('请输入要打开的文件:')
f1=open('C:\\Users\\14229\\Desktop\\'+name,encoding='UTf8')
for each in f1:
    if each !='\n':
        print(each)


