import serial
import re
import csv
import matplotlib.pyplot as plt
import requests


boardID = "2"
s = serial.Serial("/dev/cu.usbserial-1440", 9600)
print('1')
s.flushInput()
a=1000
x = []
y = []
z = []
threshold = 15

x_avg = 0

try:
    for i in range (100):
        ser_bytes = s.readline()
        decoded_bytes = (ser_bytes[0:len(ser_bytes)-2])
        decoded_bytes = (decoded_bytes.decode("utf-8"))
        vs1 = decoded_bytes.split(',')
        x_avg = x_avg + (int(vs1[1]))
except Exception as err:
    print(err)
x_avg = x_avg/100
count = 0
out = []
print("Starting")
while True:
    try:
        #print("entered try")
        ser_bytes = s.readline()
        decoded_bytes = (ser_bytes[0:len(ser_bytes)-2])
        #print(type(decoded_variable))

        decoded_bytes = (decoded_bytes.decode("utf-8"))
        vs = decoded_bytes.split(',')
        #print(vs)
        x.append(abs(int(vs[0]) - x_avg) + x_avg)
        y.append(abs(int(vs[1]) - x_avg))
        z.append(int(vs[2]))

        if abs(int(vs[1]) - x_avg)>threshold:
            count = 20
            out = y[-20:]
        elif count > 1:
            out.append(abs(int(vs[1]) - x_avg))
            count = count - 1
        elif count == 1:
            print(out)
            # plt.plot(range(len(out)),out)
            # plt.show()
            out = []
            count = count - 1
            # r = requests.post("https://potmon.azurewebsites.net/api/addevent/", json={"id": boardID})
            r = requests.post("https://potmon-api.tdom.dev/log", json={"id": boardID})
            print(r)
    except Exception as err:
        print(err)

#plt.plot(x)
plt.plot(range(len(y)),y)
#plt.plot(z)
plt.show()
