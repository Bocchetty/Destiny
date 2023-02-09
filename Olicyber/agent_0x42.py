#Devo ottenere la chiave di decifrazione

data = "42656e76656e75746f206167656e746520307834322c206c6120636f6d756e6963617a69"
data2 = "42656e76656e75746f206167656e74652c206964656e7469666963617469206369667261"
data3 = "6c00fad8ae0d60150a"

decr = bytes.fromhex(data)
decr2 = bytes.fromhex(data2)
decr3 = bytes.fromhex(data3)

print(decr)
print(decr2)
print(decr3)