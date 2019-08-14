import time
import serial

fileName = "the_entertainer_rxn.txt"
# file format: time(ms),key,on/off


def time_since(t):
    return time.time() - t  # seconds


arduino = serial.Serial('/dev/tty.HC-05-DevB', 9600)
time.sleep(2)  # give arduino time to reboot
start_time = time.time()
with open(fileName, "r") as file:
    line = file.readline()
    while not "eof" in line:
        lst = line.split(",")
        t = time_since(start_time)
        while t * 1000 < int(lst[0]):
            t = time_since(start_time)
        arduino.write((lst[1] + "\n").encode())
        #print(lst[1] + "\n")
        arduino.flush()
        line = file.readline()
arduino.close()
