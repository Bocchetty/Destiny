from Crypto.Cipher import DES
from Crypto.Util.Padding import pad 

#Tutto lavora in bytes
key = bytes.fromhex("974ac810716390b3")

#Cipher = DES
#Mode of operation = CBC
cipher = DES.new(key, DES.MODE_CBC)

plaintext = "La lunghezza di questa frase non è divisibile per 8"

encoded = plaintext.encode()

#Padding scheme = x923
#Devo usare la tipologia di padding scheme data, 8 è quanto è grosso il byte del blocco di DES
#Posso usare cipher.block_size per saperlo
padded = pad(encoded, 8, "x923")

#len(padded)

#Devo encryptare tutto in esadecimale
cipher.encrypt(padded).hex()

cipher.iv
cipher.iv.hex()

print(cipher.encrypt(padded).hex())
print()
print(cipher.iv.hex())