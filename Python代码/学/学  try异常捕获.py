try:        
    f=open("文件名.txt")
    print(f.read())
    f.close()
except(OSError,TypeError):   #这样一对多
    print('出错了')
finally:                     #无论如何都会运行的代码
    print("我一直都在")

#第二种用法
try:
    sum=1+'i'
    f=open("文件名.txt")
    print(f.read())
    f.close()
except OSError as reason:         #捕获错误原因
    print('文件出错了,原因是：'+str(reason))
except TypeError:       #还可以一try对多except
    print('类型出错了')


#图简单用法(不推荐！！！)
try:
    sum=1+'i'
    f=open("文件名.txt")
    print(f.read())
    f.close()
except :
    print('出错了')
