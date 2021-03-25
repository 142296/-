import requests
from bs4 import BeautifulSoup as bs
count=1
mistake=1
page=1
while page<=244:
        url='https://www.mzitu.com/page/'+str(page)
      header={ referer: 'https://wk.baidu.com/view/2458f08c534de518964bcf84b9d528ea81c72fa0?pcf=2&bfetype=new'
user-agent: 'Mozilla/5.0 (iPhone; CPU iPhone OS 11_0 like Mac OS X) AppleWebKit/604.1.38 (KHTML, like Gecko) Version/11.0 Mobile/15A372 Safari/604.1'}
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
