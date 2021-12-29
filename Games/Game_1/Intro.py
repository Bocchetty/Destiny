#Questo gioco è dedicato a Vicky pazza SGRAVATA

import pgzrun
import pygame
from pgzero.builtins import Actor, animate, keyboard
from pygame.locals import *

penguin = Actor('penguin', bottomleft = (0, 600))
penguin2 = Actor('penguin2', (700, 550))
rock = Actor('rock', (400, 550))

background = pygame.image.load("Games\Game_1\Images\\background.png")

WIDTH = 800
HEIGHT = 600

penguin.speed = 5

score= 0

eep= tone.create("C6", 0.5)

def draw():
    screen.clear()
    screen.blit(background, (0, 0))
    penguin.draw()
    penguin2.draw()
    rock.draw()

def update():
    if keyboard.left or keyboard.a:
        penguin.x-=1
        set_penguin_walk_left()
    elif keyboard.right or keyboard.d:
        penguin.x+=1
        set_penguin_walk()
    if keyboard.up or keyboard.w:
        penguin.y-=1
    elif keyboard.down or keyboard.s:
        penguin.y+=1

def on_mouse_down(pos):
    global score
    if penguin.collidepoint(pos):
        set_penguin_hit()
        score += 1
        #draw.text("Eek",[penguin.pos], color= "black")
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
    
def set_penguin_walk():
    penguin.image = "penguin_walk"
    clock.schedule_unique(set_penguin_walk_2, 0.3)
    
def set_penguin_walk_2():
    penguin.image = "penguin_walk_2"
    clock.schedule_unique(set_penguin_walk_3, 0.3)
    
def set_penguin_walk_3():
    penguin.image = "penguin_walk_3"
    clock.schedule_unique(set_penguin_walk_4, 0.3)

def set_penguin_walk_4():
    penguin.image = "penguin_walk_4"
    clock.schedule_unique(set_penguin_walk, 0.3)

def set_penguin_walk_left():
    penguin.image = "penguin_walk_left"
    clock.schedule_unique(set_penguin_walk_2_left, 0.3)
    
def set_penguin_walk_2_left():
    penguin.image = "penguin_walk_2_left"
    clock.schedule_unique(set_penguin_walk_3_left, 0.3)
    
def set_penguin_walk_3_left():
    penguin.image = "penguin_walk_3_left"
    clock.schedule_unique(set_penguin_walk_4_left, 0.3)
    
def set_penguin_walk_4_left():
    penguin.image = "penguin_walk_4_left"
    clock.schedule_unique(set_penguin_walk_left, 0.3)

def set_penguin_left():
    penguin.image = "penguin_left"

pgzrun.go()