import requests

#Inserisco l'url
url = ("http://web-05.challs.olicyber.it/flag")

#Devo mandare un cookie al server
#Formato (nome = valore)
cookies = dict(password = "admin")

#Richiesta get
r = requests.get(url, cookies = cookies)

#Per avere il testo faccio .text
print(r.text)