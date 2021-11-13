import pgzrun
import random
 
WIDTH = 800
HEIGHT = 600
penguin_hurt = Actor('penguin_walk01', midbottom=(WIDTH // 2, HEIGHT))
penguin = Actor('penguin_hurt')
penguin.topright = 100, 10
 
 
def draw():
    screen.fill('blue')
    penguin.draw()
    penguin_hurt.draw()
 
 
xpos = random.randint(0, 800)
 
 
def update():
    global xpos
    penguin.y += 5
    if keyboard.left:
        penguin.x -= 5
    if keyboard.right:
        penguin.x += 5
    if penguin_hurt.colliderect(penguin):
        print('you win')
        penguin.y = 0
        xpos = random.randint(0, 800)
        penguin.x = xpos
    if penguin.y > 600:
        print("you lose")
        penguin. y = 0
        xpos = random.randint(0, 800)
        penguin.x = xpos
 
score=0

def on_mouse_down(pos):
    global score
    if penguin.collidepoint(pos):
        set_penguin_hit()
        score += 1
        print(score)
    else:
        score -= 1
        print(score)
 
 
def set_penguin_hit():
    penguin.image = 'penguin_hurt'
    #sounds.eep.play()
    clock.schedule_unique(set_penguin_normal, 0.5)
 
 
def set_penguin_normal():
    penguin.image = "penguin_walk01"
 
 
pgzrun.go()