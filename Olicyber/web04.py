import requests

#Inserisco l'url
url = ("http://web-04.challs.olicyber.it/users")

#Devo fare una richiesta get con un header custom e la reltiva password
#Dict con formato: Nome Header, Valore Header 
headers = {"Accept" : "application/xml"}

#Richiesta get
r = requests.get(url, headers=headers)

#Per avere il testo faccio .text
print(r.text)