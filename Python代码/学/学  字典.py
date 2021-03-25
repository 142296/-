dictionary=dict((('F','70'),('C','67'),('h','104'),('i','105'),('s','115')))
a=dict(one=1,two=2,three=3)
b = {'one': 1, 'two': 2, 'three': 3}
c=dict(zip(['one','two','three'],[1,2,3]))
a.get('one','不存在')   #有就返回 对应值
a.get('four','不存在')   #没有就返回  '不存在'
del b['one']            #删除对应item
c.pop('two')            #删除对应item
c.popitem()             #删除最后一组item
a.update(b)             #用b 更新a
a.clear()               #清空
a=b.copy()
a['4']=('四','four')    #一对多
a[('4','四')]='four'    #多对一'
a['4'][0]               #调用四
