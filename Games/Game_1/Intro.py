#Questo gioco è dedicato a Vicky pazza SGRAVATA

import pgzrun
import pygame
from pgzero.builtins import Actor, animate, keyboard
from pygame.locals import *
from random import randint

penguin = Actor('penguin', bottomleft = (50, 580))
penguin2 = Actor('penguin2', (700, 550))
rock = Actor('rock')
rock.pos = 400, 550
heart = Actor('heart')
heart.pos = 700, 550

background = pygame.image.load("Games\Game_1\Images\\background.png")

#Window
WIDTH = 800
HEIGHT = 600

penguin.speed = 10
score = 0
game_over = False

eep = tone.create("C6", 0.5)
eek = "Eek"

def draw():
    screen.clear()
    screen.blit(background, (0, 0))
    penguin.draw()
    heart.draw()
    penguin2.draw()
    rock.draw()
    
    screen.draw.text(eek, topleft = (WIDTH / 2-30, 10), color = "black", fontsize = 22)
    screen.draw.text("Score: " + str(score), topleft=(10, 10), color = "black", fontsize = 22)

# pos = penguin.pos

def update():
    
    global score
    
    rock_collected = penguin.colliderect(rock)
    heart_appear = penguin.colliderect(penguin2)
    
    if heart_appear:
        if score >= 100:
          place_heart()
        else:
          pass #aggiungi testo
    
    if rock_collected:
        score = score + 10
        place_rock()
    
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
    if penguin.x > 800:
       penguin.x = 0
    elif penguin.x < 0:
       penguin.x = 800
    if penguin.y > 600:
       penguin.y = 0
    elif penguin.y < 0:
       penguin.y = 600

def on_mouse_down(pos):
    
    global score
    global eek
    
    if penguin.collidepoint(pos):
        set_penguin_hit()
        print("Eek")
    else:
        print("Nothing here bu")

def set_penguin_hit():
    penguin.image = 'penguin_hurt'
    eep.play()
    #sounds.eep.play() da cartella sounds
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

def place_rock():
    rock.x = randint(0, WIDTH)
    rock.y = randint(0, HEIGHT) 

def place_heart():
    heart.x = 700
    heart.y = 505

#def time_up():
    #global game_over
    #game_over = True
#clock.schedule (time_up, 30.0)

pgzrun.go()