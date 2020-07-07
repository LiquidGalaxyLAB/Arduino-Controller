import argparse
import pynput
import time
import serial

# from pymouse import PyMouse
# m = PyMouse()

from pynput.mouse import Button, Controller as MouseController

mouse = MouseController()
from pynput.keyboard import Key, Controller as KeyboardController

keyb = KeyboardController()

comport = serial.Serial('/dev/ttyUSB0',9600)
#comport = serial.Serial('COM3', 9600)


def Position_Controller(dataRec):
    data = int(dataRec)
    print(data)
    if data == 1:
        # mouse.position = ((width / 2), (height / 2))
        mouse.scroll(0, 1)  # zoom in
    if data == 2:
        # mouse.position = ((width / 2), (height / 2))
        mouse.scroll(0, -1)  # zoom out
    if data == 3:
        keyb.press(Key.right)  # RIGHT
    else:
        keyb.release(Key.right)
    if data == 4:
        keyb.press(Key.left)  # LEFT
    else:
        keyb.release(Key.left)
    if data == 5:
        keyb.press(Key.up)  # UP
    else:
        keyb.release(Key.up)
    if data == 6:
        keyb.press(Key.down)  # DOWN
    else:
        keyb.release(Key.down)
        
    if data == 7:
        keyb.press(Key.shift)
        keyb.press(Key.right)
    else:
        keyb.release(Key.shift)
        keyb.release(Key.right)
    if data == 8:
        keyb.press(Key.shift)
        keyb.press(Key.left)
    else:
        keyb.release(Key.shift)
        keyb.release(Key.left)
    if data == 9:
        keyb.press(Key.shift)
        keyb.press(Key.up)  # UP Tilt
    else:
        keyb.release(Key.shift)
        keyb.release(Key.up)
    if data == 10:
        keyb.press(Key.shift)
        keyb.press(Key.down)  # DOWN Tilt
    else:
        keyb.release(Key.shift)
        keyb.release(Key.down)


if __name__ == "__main__":
    # width, height = m.screen_size()
    while True:
        valor = comport.readline().decode()
        print(valor)
        Position_Controller(valor)

# comport.close()
