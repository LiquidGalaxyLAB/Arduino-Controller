import argparse
import math
import clipboard
import pyautogui
import keyboard

from pythonosc import dispatcher
from pythonosc import osc_server

def print_volume_handler(unused_addr, args, volume):
  #print("[{0}] ~ {1}".format(args[0], volume))
  print(volume)
  keyboard.press_and_release('up')
def print_compute_handler(unused_addr, args, volume):
  try:
    print("[{0}] ~ {1}".format(args[0], args[1](volume))) 
  except ValueError: pass

if __name__ == "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--ip",
      default="192.168.0.5", help="The ip to listen on")
  parser.add_argument("--port",
      type=int, default=5005, help="The port to listen on")
  args = parser.parse_args()

  dispatcher = dispatcher.Dispatcher()
  dispatcher.map("/1/push1", print)
  dispatcher.map("/filter", print)
  #dispatcher.map("/1/push2", print_volume_handler, "Volume")
  dispatcher.map("/1/push3", print_volume_handler, "Texto")
  dispatcher.map("/logvolume", print_compute_handler, "Log volume", math.log)

  server = osc_server.ThreadingOSCUDPServer(
      (args.ip, args.port), dispatcher)
  print("Serving on {}".format(server.server_address))
  server.serve_forever()