import requests

#Inserisco l'url
url = ("http://web-03.challs.olicyber.it/flag")

#Devo fare una richiesta get con un header custom e la reltiva password
#Dict con formato: Nome Header, Valore Header 
headers = {"X-Password" : "admin"}

#Richiesta get
r = requests.get(url, headers=headers)

#Per avere il testo faccio .text
print(r.text)
