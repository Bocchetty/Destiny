
flage = "fmcj{yo_ackyzb_ihruvcvjam}"

m = "mcjyoackyzbihruvcvjam"

def cesare(m):
    mm=""
    for c in m:
        mm+=chr(ord(c)-1)
    return mm

print(cesare(m))