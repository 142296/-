a=[['千与千寻',9.3],['阿甘正传',9.5],['肖申克的救赎',9.7],['龙猫',9.2],['你的名字',8.4]]
a.append(['星游记',9.5])
grade=lambda a :a[1]   #sort原传入整个a[1]改变为a[1][1]
a.sort(key=grade,reverse=True)
