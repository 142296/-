import pickle
def save():     #保存位pickle
    f=open('C:\\Users\\14229\\Desktop\\record.txt','r')
    n=open('C:\\Users\\14229\\Desktop\\record.pkl','wb')
    for each in f:
        pickle.dump(each,n)
    n.close()
    f.close()
    n=open('C:\\Users\\14229\\Desktop\\record.pkl','rb')
    end=n.seek(0,2)
    n.seek(0)
    fen(1,n,end)
def fen(count,n,end):   #分开保存为txtn.seek(0)
    boy='boy'+str(count)+'.txt'
    girl='girl'+str(count)+'.txt'
    fboy=open('C:\\Users\\14229\\Desktop\\做\\'+boy,'a')
    fgirl=open('C:\\Users\\14229\\Desktop\\做\\'+girl,'a')
    read='0'
    while '===' not in read:
            if n.tell()>=end:
                break
            read=pickle.load(n)
            if '===' not in read:
                (name,content)=read.split(':',1)   
                if name =='小甲鱼':
                    fboy.write(content)
                elif name =='小客服':
                     fgirl.write(content)
            else:
                count+=1
                fboy.close()
                fgirl.close()
                if count<4:
                    fen(count,n,end)
save()
