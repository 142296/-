import requests
import re
url='https://www.uu131.net'
header={'refer':'https://m.uu131.net/'
       , 'user-agent':'Mozilla/5.0 (Linux; Android 5.0; SM-G900P Build/LRX21T) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Mobile Safari/537.36'
        }
count=1
response=requests.get(url,headers=header)
#print(response.text)
image_url=re.findall('img src="(.*?)"',response.text)
for each in image_url:
        with open('图片\图'+str(count)+'.jpg','wb') as im:
                print(count)
                image=requests.get(each)
                im.write(image.content)
                count+=1
        
