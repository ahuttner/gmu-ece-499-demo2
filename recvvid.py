import socket
import numpy as np
import cv2

UDP_IP = "192.168.80.128"
UDP_PORT = 5005

sock = socket.socket(socket.AF_INET,
                socket.SOCK_DGRAM)
sock.bind((UDP_IP,UDP_PORT))

while True:
        frstr, addr = sock.recvfrom(63000)
        frdata = np.fromstring(frstr,np.uint8)
        fr = np.reshape(frdata,(140,150,3))
        cv2.imshow('webcam',fr)
        cv2.waitKey(150)
