import requests

#Inserisco l'url
url = ("http://pincode.challs.olicyber.it")

n = list(range(1000, 10000))

#print(str(n))

payload = {"pincode" : n}

#Richiesta post
r = requests.post(url, data = payload)

#Per avere il testo faccio .text
print(r.text)