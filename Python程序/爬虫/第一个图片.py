import requests
url='https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1585835179630&di=e3f64575690c4badccea0ababdbec95a&imgtype=0&src=http%3A%2F%2Fup.svwsy.com%2Fuploads%2Fallimg%2Faebiauqrqdb.jpg'
response=requests.get(url)
with open('1.png','wb')as im:
        im.write(response.content)
