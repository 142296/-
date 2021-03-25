import math
n=int(input(""))
p=0.006
for i in range(0,n+1):
        C=math.factorial(n)/math.factorial(n-i)/math.factorial(i)
        gailv=C*p**i*(1-p)**(n-i)
        print(f"{n}个碎片出%d个橙装概率为{gailv}"%i)
        print()
