nf=input('输入文件名:')
fr=open(nf,'r')
repeat=input('要换:')
new=input('换成:')
nfile=[]
count=0
for each in fr:
    if repeat in each:
        each=each.replace(repeat,new)    #替换
        count+=1   
    nfile.append(each)
fr.close()
fw=open(nf,'w')
fw.writelines(nfile)
fw.close()
