import requests

#Inserisco l'url
url = ("http://convenzione.challs.olicyber.it/")

verbs = requests.options(url)
print(verbs.headers['allow'])

r = requests.request("flag", url)

print(r.text)
print(r.headers)