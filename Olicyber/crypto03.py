import base64

dati0 = "ZmxhZ3t3NDF0XzF0c19hbGxfYjE="
dati1 = 664813035583918006462745898431981286737635929725

#base64 è in bytes quindi lo trasformo in string
flag0 = base64.b64decode(dati0.encode())
print(flag0)

n = dati1
flag1 = ""
while n>0:
    #con % prendo la parte meno significativa quindi quella a destra
    flag1 = chr(n%256) + flag1
    n = n // 256
print(flag1)