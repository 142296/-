import pickle
def save():     #保存位pickle
    f=open('C:\\Users\\14229\\Desktop\\record.txt','r')
    n=open('C:\\Users\\14229\\Desktop\\record.pkl','wb')
    for each in f:
        pickle.dump(each,n)
    n.close()
    f.close()
    fen()
def fen():   #分开保存为txt
    count=1
    n=open('C:\\Users\\14229\\Desktop\\record.pkl','rb')
    end=n.seek(0,2)
    n.seek(0)
    while n.tell()<end:
            read=pickle.load(n)
            if '===' not in read:
                (name,content)=read.split(':',1)
                if name =='小甲鱼':
                    file_name='boy'+str(count)+'.txt'
                elif name =='小客服':
                    file_name='girl'+str(count)+'.txt'
                f=open('C:\\Users\\14229\\Desktop\\做\\'+file_name,'a')
                f.write(content)
            else:
                count+=1
                f.close()
save()
