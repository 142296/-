def power(x,y):               #次方函数
    if y <=0:
        return 1
    else:
        return power(x,y-1)*x
def gcd(x,y):               #最大公约数
    if x>y:
        x,y=y,x
    temp=y%x
    y=x
    x=temp
    if temp!=0:
        y=gcd(x,y)
    return y
def bin1(x):                    #转换为二进制1
    if x >1:
        bin1(x//2)
    print(x%2,end='')
def bin2(x):                    #转换为二进制2
    a=1<<32
    while a>0:
        print(1 if x&a else 0,end='')
        a=a>>1
def hwl():        #判断回文联
        #global a   将a设为全局变量
        a=input('请输入一段话:')
        c=1
        lenth=len(a)
        for i in range(0,(lenth//2)+1):
                if a[i]!=a[-i-1]:
                        c=0
        if c:
                print('是回文联')
        else:
                print('不是回文联')





    
        
    
