import requests

#Inserisco l'url
url = ("")

payload = {"pincode" : "numeri da 1000 a 9999"}

#Richiesta post
r = requests.post(url, data = payload)

#Per avere il testo faccio .text
print(r.text)