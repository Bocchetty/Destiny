#Questo gioco è dedicato a Vicky pazza SGRAVATA

import pgzrun
from pgzero.builtins import Actor, animate, keyboard

penguin = Actor('icon_penguin')
#penguin.topright = 0, 10

WIDTH = penguin.width + 20
HEIGHT = penguin.height + 20

def draw():
    screen.clear()
    penguin.draw()

score= 0

def on_mouse_down(pos):
    global score
    if penguin.collidepoint(pos):
        #sounds.eep.play()
        penguin.image = 'penguin_hurt'
        score += 1
        print("Eek")
    else:
        score -= 1
        print("Nothing here bu")
    print(score)
    
pgzrun.go()