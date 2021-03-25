a=[5,9,-52,59,36,54,21,25,52]
a=sorted(a)    #从小到大排序   不改变，有返回值
a.sort()       #从小到大排序直接改变
a.reverse()     #翻转顺序，直接改变
a.sort(reverse=True) #从大到小排序，直接改变
b={1,2,3,4,5}
zip(b,a)      #  一  一结合a和b
member=['小甲鱼','黑夜','迷途','怡静','秋舞斜阳']
number=[88,90,85,90,88]
c=zip(member,number)

