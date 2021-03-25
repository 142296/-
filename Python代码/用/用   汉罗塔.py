def han(a,x='x',y='y',z='z'):
    if a !=1:
        han(a-1,x,z,y)
        print(x+'-->'+z)
        han(a-1,y,x,z)
    else:
        print(x+'-->'+z)
count=han(6)
    
