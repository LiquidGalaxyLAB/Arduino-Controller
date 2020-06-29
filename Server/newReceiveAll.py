from pythonosc.dispatcher import Dispatcher
from pythonosc.osc_server import BlockingOSCUDPServer


def print_handler(address, *args):
#print(f"{address}: {args}")
    print(address)


def default_handler(address, *args):
    print(f"DEFAULT {address}: {args}")


dispatcher = Dispatcher()
dispatcher.map("/1/push1", print_handler)
dispatcher.set_default_handler(default_handler)

ip = "192.168.0.5"
port = 5005

server = BlockingOSCUDPServer((ip, port), dispatcher)
server.serve_forever()  # Blocks forever