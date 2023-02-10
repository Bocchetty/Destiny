
m = "fmcj{yo_ackyzb_ihruvcvjam}"

#m = "fmcjyoackyzbihruvcvjam"

def cesare(m):
    mm=""
    array = []
    for i in range(len(m)):
        if(m[i] != '{' and m[i] != '}' and m[i] != '_'):
        
        
            array.append(ord(m[i])-i)
            print((ord(m[i])-ord('a')-i)%22)
            mm+=chr( ((ord(m[i])-ord('a')-i)%26)+ ord('a') )
        else:
            mm += m[i]
   # print(array)
    return mm

print(cesare(m))