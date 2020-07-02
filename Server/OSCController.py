import argparse
import pynput
import time

from pymouse import PyMouse
m = PyMouse()

from pynput.mouse import Button, Controller as MouseController
mouse = MouseController()

from pynput.keyboard import Key, Controller as KeyboardController
keyb = KeyboardController()

from pythonosc import dispatcher

from pythonosc import osc_server

def Position_Controller(unused_addr, args, data):
    if data == 1:
     mouse.position = ((width/2),(height/2))
     mouse.scroll(0,1) #zoom in
    if data == 2:
     mouse.position = ((width/2),(height/2))
     mouse.scroll(0,-1) #zoom out
    if data == 3:
     keyb.press(Key.right) # RIGHT
 #   time.sleep(.1)
    else: keyb.release(Key.right)
    if data == 4:
     keyb.press(Key.left) #LEFT
 #     time.sleep(.1)
    else: keyb.release(Key.left)
    if data == 5:
     keyb.press(Key.up) #UP
 #   time.sleep(.1)
    else: keyb.release(Key.up)
    if data == 6:
     keyb.press(Key.down) #DOWN
 #    time.sleep(.1)
    else:  keyb.release(Key.down)


if __name__ == "__main__":

  ip = '0.0.0.0'
  port = 5005
  width, height = m.screen_size()
  dispatcher = dispatcher.Dispatcher()

  dispatcher.map("/lg/Controller", Position_Controller,"ArduinoController")


  server = osc_server.ThreadingOSCUDPServer((ip, port), dispatcher)

  print("Serving on {}".format(server.server_address))

  server.serve_forever()
