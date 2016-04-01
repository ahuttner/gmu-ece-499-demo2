import time
import cv2
import numpy as np
import io
import sys
import os
import socket
import time

UDP_IP = "laptop-5eeg2bjq.byod.gmu.edu"
UDP_PORT = 5005

webcap = cv2.VideoCapture(0)

while True:
        ret, frame = webcap.read()
        fr = cv2.resize(frame,(150,140))
        frstr = fr.tostring()

        sock = socket.socket(socket.AF_INET, #Internet
                        socket.SOCK_DGRAM) #UDP
        sock.sendto(frstr, (UDP_IP,UDP_PORT))
