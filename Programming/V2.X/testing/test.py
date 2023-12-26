
print()
print()

value = 0b0100
port = 0b10011001


print("port: ", bin(port))
print("value: ", bin(value))

port = value | (port&0b11110000) 

print("new port: ", bin(port))


