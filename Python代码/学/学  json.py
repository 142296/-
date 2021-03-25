import json
f=open('1.txt',encoding='utf-8')
txt=json.load(f)    #用以保存json数据
end=json.dump(txt)  #保存为json格式


