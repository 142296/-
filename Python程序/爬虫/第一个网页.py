import requests
import re
url='https://www.mzitu.com/'
header={"user-agent":"Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Mobile Safari/537.36",
        'Referer':'https://m.mzitu.com/'}
response=requests.get(url,headers=header)
#正则表达式 .*匹配多个字符 ()只保存括号里面  ?早结束 
image_url=re.findall("data-original='(.*)' alt='(.*?)'",response.text)
for each in image_url:
        print(each[0])
        with open('图片/'+each[1]+'.jpg','wb') as im:
                image=requests.get(each[0],headers=header)
                im.write(image.content)
                
 
