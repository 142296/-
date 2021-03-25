from PIL import Image
def zifutu():
    a=input("请输入文件名")
    im=Image.open(a)
    im=im.convert('L')
    width,height=im.size
    x=int(input("缩小X倍，输入x(int型):"))
    im=im.resize((int(width/x),int(height/(x*1.5))))
    width,height=im.size
    txt="@MHBE&#YPk*+=-;:,. " 
    lenth=len(txt)-1
    ima=''
    for i in range(height):
        for j in range(width):
            gray=im.getpixel((j,i))
            ima+=txt[gray*lenth//255]
        ima+='\n'
    with open('字符图.txt','w',encoding='UTF-8') as f:
        f.write(ima)
if __name__=='__main__':
    zifutu()

        
