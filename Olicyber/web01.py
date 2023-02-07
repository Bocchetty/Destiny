import requests

#Devo fare una richiesta get
risorsa = requests.get("http://web-01.challs.olicyber.it/")

#Per avere il testo faccio .text
print(risorsa.text)