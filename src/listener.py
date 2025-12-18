import serial
import pyautogui

SERIAL_PORT = "COM4"
pyautogui.FAILSAFE = True

ser = serial.Serial(SERIAL_PORT, 9600, timeout=1)

print("Listening...")



while True:
    line = ser.readline().decode(errors='ignore').strip()
    print(line)

    if line == "TRIGGER":
        print("Triggered")
        pyautogui.hotkey('alt', 'tab') 
    
