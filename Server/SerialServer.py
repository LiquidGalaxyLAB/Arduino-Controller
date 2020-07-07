import argparse
import pynput
import time
import serial

#from pymouse import PyMouse
#m = PyMouse()

from pynput.mouse import Button, Controller as MouseController
mouse = MouseController()
from pynput.keyboard import Key, Controller as KeyboardController
keyb = KeyboardController()

comport = serial.Serial('COM3',9600)

def Position_Controller(dataRec):
    data = int(dataRec)
    if data == 1:
       # mouse.position = ((width / 2), (height / 2))
        mouse.scroll(0, 1)  # zoom in
    if data == 2:
       # mouse.position = ((width / 2), (height / 2))
        mouse.scroll(0, -1)  # zoom out
    if data == 3:
        keyb.press(Key.right)  # RIGHT
    #   time.sleep(.1)
    else:
        keyb.release(Key.right)
    if data == 4:
        keyb.press(Key.left)  # LEFT
    #     time.sleep(.1)
    else:
        keyb.release(Key.left)
    if data == 5:
        keyb.press(Key.up)  # UP
    #   time.sleep(.1)
    else:
        keyb.release(Key.up)
    if data == 6:
        keyb.press(Key.down)  # DOWN
    #    time.sleep(.1)
    else:
        keyb.release(Key.down)


if __name__ == "__main__":
    #width, height = m.screen_size()
    while True:
        valor = comport.readline().decode()
        Position_Controller(valor)

#comport.close()