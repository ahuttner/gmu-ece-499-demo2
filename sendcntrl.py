import socket

UDP_IP = "10.159.253.209" #IP of device to send to
UDP_PORT = 5006

print "UDP target IP:", UDP_IP
print "UDP target port:", UDP_PORT

while(1):
        dir = raw_input('Choose Direction (w,a,s,d,e,r,f,q,1,2,3) :')

        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

        sock.sendto(dir, (UDP_IP, UDP_PORT))
