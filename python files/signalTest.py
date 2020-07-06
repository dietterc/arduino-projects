import socket
from time import sleep
import datetime

new = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
new.connect(('192.168.0.178', 80))

while True:
    word = input()
    my_bytes = bytearray()

    for x in word:
        my_bytes.append(ord(x))

    new.sendall(my_bytes)

#delay before exiting
sleep(.5)