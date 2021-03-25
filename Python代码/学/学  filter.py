#filter(判断，数列)
date=[9.7,9.5,9.5,9.3,9.2,8.8]
judge=lambda a:a>9.2
print(list(filter(judge,date)))  #为真则输出
