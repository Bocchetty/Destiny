import requests

argomenti = {"id" : "flag"}
risorsa = requests.get("http://web-02.challs.olicyber.it/server-records", params = argomenti)

print(risorsa.text)