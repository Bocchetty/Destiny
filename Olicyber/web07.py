import requests

#Inserisco l'url
url = ("http://web-07.challs.olicyber.it/")

#Richiesta head
r = requests.head(url)

print(r.headers)