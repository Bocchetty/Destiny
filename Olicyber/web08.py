import requests

#Inserisco l'url
url = ("http://web-08.challs.olicyber.it/login")

payload = {"username": "admin", "password": "admin"}

#Richiesta post
r = requests.post(url, data = payload)

#Per avere il testo faccio .text
print(r.text)