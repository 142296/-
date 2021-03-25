from PIL import Image
import os
import sys
import subprocess
def zifutu():
    a=input("请输入文件名")
    b=1;
    while(b<2701):
        im=Image.open(a+'\\'+str(b)+".jpg")
        im=im.convert('L')
        width,height=im.size
        x=8
        im=im.resize((int(width/x),int(height/(x*1.5))))
        width,height=im.size
        txt="@MHBE&#YPk*+=-;:,. " 
        lenth=len(txt)-1
        ima=''
        #os.system("cls")
        #subprocess.call("cls",shell=True)
        for i in range(height):
            for j in range(width):
                gray=im.getpixel((j,i))
                ima+=txt[-(gray*lenth//255+1)]
            ima+='\n'
        print(ima)
        b+=1
      #  with open('字符图.txt','w',encoding='UTF-8') as f:
       #     f.write(ima)
if __name__=='__main__':
    zifutu()
    input()

        
