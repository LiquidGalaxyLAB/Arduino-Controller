import serial

from pynput.keyboard import Key, Controller as KeyboardController

keyb = KeyboardController()

#comport = serial.Serial('/dev/ttyUSB0', 9600)


comport = serial.Serial('COM3', 9600)

def Position_Controller(dataRec):
    data = dataRec

    print(data)

    if "linear" in data:
        keyb.press('r')
    else:
        keyb.release('r')
    if "zOut" in data:
        keyb.press(Key.page_up)
    else:
        keyb.release(Key.page_up)
    if "zIn" in data:
        keyb.press(Key.page_down)
    else:
        keyb.release(Key.page_down)
    if "right" in data:
        keyb.press(Key.right)  # RIGHT
    else:
        keyb.release(Key.right)
    if "left" in data:
        keyb.press(Key.left)  # LEFT
    else:
        keyb.release(Key.left)
    if "up" in data:
        keyb.press(Key.up)  # UP
    else:
        keyb.release(Key.up)
    if "down" in data:
        keyb.press(Key.down)  # DOWN
    else:
        keyb.release(Key.down)
    if "CamUp" in data:
        keyb.press(Key.ctrl)
        keyb.press(Key.up)
    else:
        keyb.release(Key.ctrl)
        keyb.release(Key.up)
    if "CamDown" in data:
        keyb.press(Key.ctrl)
        keyb.press(Key.down)
    else:
        keyb.release(Key.ctrl)
        keyb.release(Key.down)
    if "CamRight" in data:
        keyb.press(Key.ctrl)
        keyb.press(Key.right)
    else:
        keyb.release(Key.ctrl)
        keyb.release(Key.right)
    if "CamLeft" in data:
        keyb.press(Key.ctrl)
        keyb.press(Key.left)
    else:
        keyb.release(Key.ctrl)
        keyb.release(Key.left)
    if "rollRight" in data:
        keyb.press(Key.shift)
        keyb.press(Key.right)
    else:
        keyb.release(Key.shift)
        keyb.release(Key.right)
    if "rollLeft" in data:
        keyb.press(Key.shift)
        keyb.press(Key.left)
    else:
        keyb.release(Key.shift)
        keyb.release(Key.left)
    if "tiltUp" in data:
        keyb.press(Key.shift)
        keyb.press(Key.up)  # UP Tilt
    else:
        keyb.release(Key.shift)
        keyb.release(Key.up)
    if "tiltDown" in data:
        keyb.press(Key.shift)
        keyb.press(Key.down)  # DOWN Tilt
    else:
        keyb.release(Key.shift)
        keyb.release(Key.down)

       # f = open("/tmp/query.txt", "w")
       # f.write(data)
       # f.close()

    data = 0


if __name__ == "__main__":

    while True:
        valor = comport.readline().decode('UTF-8')

        print(valor)

        Position_Controller(valor)

# comport.close()
