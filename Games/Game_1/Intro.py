#Questo gioco è dedicato a Vicky pazza SGRAVATA

import pgzrun
from pgzero.builtins import Actor, animate, keyboard
import random

penguin = Actor('penguin', bottomleft=(0, 600))

RED = 150, 0, 0
GREEN = 0, 128, 0
bg = RED

WIDTH = 800
HEIGHT = 600

score= 0

eep= tone.create("E4", 0.5)

def draw():
    screen.clear()
    screen.fill(bg)
    penguin.draw()

def update():
    if keyboard.left:
        penguin.x-=1
        set_penguin_left()
    elif keyboard.right:
        penguin.x+=1
        set_penguin_normal()
    if keyboard.up:
        penguin.y-=1
    elif keyboard.down:
        penguin.y+=1

def on_mouse_down(pos):
    global score
    if penguin.collidepoint(pos):
        set_penguin_hit()
        score += 1
        print("Eek")
    else:
        score -= 1
        print("Nothing here bu")
    print(score)

def set_penguin_hit():
    penguin.image = 'penguin_hurt'
    eep.play()
    #sounds.eep.play()
    clock.schedule_unique(set_penguin_normal, 0.5)
 
def set_penguin_normal():
    penguin.image = "penguin"
    
def set_penguin_left():
    penguin.image = "penguin_left"

pgzrun.go()