#One-Time Pad

def xor(a, b):
    return bytes([x^y for x,y in zip(a,b)])

ciphertext = bytes.fromhex("104e137f425954137f74107f525511457f5468134d7f146c4c")

#La chiave è lunga un byte e si ripete
#Un byte è uguale a 256 bit

for i in range(256):
    #Ripeto l'operazione per ogni carattere del testo cifrato
    key = bytes([i] * len(ciphertext))
    #print(xor(key))
    #Devo filtrare la chiave
    plaintext = xor(key, ciphertext)

#Metto b per trasformare _ in byte
#Con questo prendo solo le stringhe contenenti _
if b"_" in plaintext:
    print(plaintext)