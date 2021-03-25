import requests
url='http://www.baidu.com'
headers={'user-agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Safari/537.36 Core/1.70.3756.400 QQBrowser/10.5.4039.400'}
params={ 'wd':'长城','c':'b'}   #添加关键词
response=requests.get(url,headers=headers,params=params) #伪装headers

#三行    网页码获取
#print(response.text)          #自动推测解码
#print(response.content)         #二进制输出
#print(response.content.decode())   #utf-8解码

#print(response.status_code)       #返回状态码 200==成功

#print(response.request.headers)    #返回user-agent

