import pyautogui as pg
import time

print ("Starting in 10 seconds...")
time.sleep (10)

for i in range(50):
    pg.write (" Inserisci testo ")
    time.sleep (0.5)
    pg.press ("Enter")