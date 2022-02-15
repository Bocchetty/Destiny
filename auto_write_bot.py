import pyautogui as pg
import time

print ("Starting in 10 seconds...")
time.sleep (10)

for i in range(100):
    pg.write (" Ti amo ")
    time.sleep (0.5)
    pg.press ("Enter")