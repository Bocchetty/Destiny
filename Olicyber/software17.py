from pwn import remote

r = remote ("software-17.challs.olicyber.it", 13000)

r.recvlines(6)
r.recvuntil(b" ...")
r.sendline(b"a")
for i in range (10):
    r.recvline()
    lista = [int(_) for _ in r.recvline(False).decode().strip("[").strip("]").split(", ")]
    #False toglie /n alla fine, decode passa da byte a stringa, strip per togliere le parentesi prima aperta e poi chiusa, split divide tutto con una virgola-spazio
    #print(lista)
    #Tutte queste liste sono i miei numeri, uso int per passare da stringa a numero in base10, uso _ per usare il for in una riga
    somma = sum(lista)
    r.recvuntil(b": ")
    #print(somma)
    #Devo mandare la somma al server remoto, trasfmormo l'intero in stringa "n" e poi la stringa in byte con .encode
    r.sendline (str(somma).encode())
print(r.recvline())
#r.interactive()