import requests

#Oggetto di classe session
s = requests.Session()

#Prendo il cookie di sessione
s.get("http://web-06.challs.olicyber.it/token")
#Uso il cookie di sessione per accedere alla risorsa
r = s.get("http://web-06.challs.olicyber.it/flag")

print(r.text)