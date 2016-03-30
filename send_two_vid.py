from picamera.array import PiRGBArray
from picamera import PiCamera
import picamera
import time
import cv2
import numpy as np
import io
import sys
import os
import socket
import time

UDP_IP = "laptop-5eeg2bjq.byod.gmu.edu"
UDP_PORT1 = 5005
UDP_PORT2 = 5006
webcap = cv2.VideoCapture(0)

cam = PiCamera()

cam.vflip = True
cam.hflip = True

cam.resolution = (150,140)

while True:
        ret, frame = webcap.read()
        fr = cv2.resize(frame,(150,140))
        picap = PiRGBArray(cam)
        cam.capture(picap,format="bgr")
        im = picap.array
        frstr = fr.tostring()
        imstr = im.tostring()
        sock = socket.socket(socket.AF_INET, #Internet
                        socket.SOCK_DGRAM) #UDP
        sock.sendto(frstr, (UDP_IP,UDP_PORT1))
        sock.sendto(imstr, (UDP_IP,UDP_PORT2))
