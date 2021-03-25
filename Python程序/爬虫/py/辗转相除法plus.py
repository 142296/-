def ee(a,b):
        R,S,T=a,1,0
        R1,S1,T1=b,0,1
        while(R1!=0):
                q=R//R1
                Temp1,Temp2,Temp3=R-q*R1,S-q*S1,T-q*T1;
                R,S,T=R1,S1,T1
                R1,S1,T1=Temp1,Temp2,Temp3
        print("%d=%d*%d+%d*%d"%(R,S,a,T,b));

a=int(input("a:"))
b=int(input("b:"))
ee(a,b)
