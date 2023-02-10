import requests

#Devo fare una richiesta get
risorsa = requests.get("http://headache.challs.olicyber.it/")
#risorsa.encoding = 'ISO-8859-1'

#Per avere il testo faccio .text
print(risorsa.text)
print(risorsa.encoding)
print(risorsa.content)