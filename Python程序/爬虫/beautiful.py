import requests
from bs4 import BeautifulSoup as bs
count=1
mistake=1
page=1
while page<=244:
        url='https://www.mzitu.com/page/'+str(page)
        header={"user-agent":"Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Mobile Safari/537.36",
                'Referer':'https://m.mzitu.com/'}
        response=requests.get(url,headers=header)
        html_doc=response.text
        soup=bs(html_doc,"html.parser")
        for link in soup.find_all('img'):
                #if link.get('alt')=="妹子图":
                 #       continue
                try:
                        with open(link.get('alt')+'.jpg','wb') as image:
                                web=link.get('data-original')
                                img=requests.get(web,headers=header)
                                image.write(img.content)
                        print(link.get('alt'))
                        count+=1
                except:
                        print("出错")
                        mistake+=1
        page+=1
        print('第%d页'%page)
print('一共%d个'%count)
