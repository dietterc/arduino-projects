import socket
from time import sleep
import datetime

new = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
new.connect(('192.168.0.178', 80))

while True:
    word = input()
    my_bytes = bytearray()

    args = word.split(" ")

    my_bytes.append(ord(args[0]))
    my_bytes.append(int(args[1]))

    new.sendall(my_bytes)

#delay before exiting
sleep(.5)