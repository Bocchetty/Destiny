#Questo gioco è dedicato a Vicky pazza SGRAVATA

import pgzrun
from pgzero.builtins import Actor, animate, keyboard
import random

penguin = Actor('penguin_walk01')

RED = 150, 0, 0
GREEN = 0, 128, 0
bg = RED

WIDTH = 800
HEIGHT = 600
score= 0

def draw():
    screen.clear()
    screen.fill(bg)
    penguin.draw()

xpos = random.randint(0, 600)

def update():
    global xpos
    penguin.y += 5
    if keyboard.left:
        penguin.x -= 5
    if keyboard.right:
        penguin.x += 5
    if penguin.y < 600:
        #print('you win')
        xpos = random.randint(0, 600)
        penguin.x = xpos
    if penguin.y > 600:
        #print("you lose")
        penguin. y = 0
        xpos = random.randint(0, 600)
        penguin.x = xpos
    #penguin.left += 2
    #if penguin.left > WIDTH:
        #penguin.right = 0

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
    #sounds.eep.play()
    clock.schedule_unique(set_penguin_normal, 0.5)
 
 
def set_penguin_normal():
    penguin.image = "penguin_walk01"

pgzrun.go()