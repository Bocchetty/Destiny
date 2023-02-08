#La funzione prende carattere per carattere la stringa, fa lo xor carattere per caratter e li unisce in una stringa
#^ effettua l'operazione di xor, prende in input interi
#La funzione prende a e b li passa in zip(prende il minimo fra le due lunghezze)
#Le quadre mette i risultati in una lista, bytes converte i numeri contenuti in bytes
#Il singolo elemento in un lista di bytes è un intero (in memoria il tipo bytes è un intero, è per comodità)
def xor(a, b):
    return bytes([x^y for x,y in zip(a,b)])

#Prendo i messaggi
m1 = "158bbd7ca876c60530ee0e0bb2de20ef8af95bc60bdf"

m2 = "73e7dc1bd30ef6576f883e79edaa48dcd58e6aa82aa2"

#Trasformo tutto in bytes da esadecimale

m1 = bytes.fromhex("158bbd7ca876c60530ee0e0bb2de20ef8af95bc60bdf")

m2 = bytes.fromhex("73e7dc1bd30ef6576f883e79edaa48dcd58e6aa82aa2")

print(xor(m1, m2))