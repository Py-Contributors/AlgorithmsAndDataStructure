import pygame, sys, random


def Bubble_Sort_Animation(min_val, max_val, size_of_array, delay=20):
    WHITE = (255, 255, 255)
    BLACK = (0, 0, 0)

    WIDTH = size_of_array * 4
    HEIGHT = max_val
    win_size = (WIDTH, HEIGHT)

    pygame.init()

    win = pygame.display.set_mode(win_size)
    pygame.display.set_caption('Bubble Sort')
    clock = pygame.time.Clock()

    n = 4

    w = int(WIDTH/n)

    h_arr = []
    states = []

    for i in range(w):
        height = random.randint(min_val, max_val)
        h_arr.append(height)
        states.append(1)

    counter = 0

    while True:
        win.fill(BLACK)
        
        #Exit event
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
        #Condition for outer Loop
        if counter < len(h_arr):
            #Inner loop
            for j in range(len(h_arr) - 1 - counter):
                if h_arr[j] > h_arr[j+1]:
                    states[j] = 0
                    states[j+1] = 0
                    temp = h_arr[j]
                    h_arr[j] = h_arr[j+1]
                    h_arr[j+1] = temp
                else:
                    states[j] = 1
                    states[j+1] = 1
        else:
            pass
        #Counter for the outer loop
        counter += 1
        
        #Checking if the bar is in the correct place
        if len(h_arr) - counter >= 0:
            states[len(h_arr) - counter] = 2
            
        #Applying Colors
        for i in range(len(h_arr)):
            if states[i] == 0:
                color = (255, 0, 0)
            elif states[i] == 2:
                color = (0, 255, 0)
            else:
                color = WHITE
            pygame.draw.rect(win, color, pygame.Rect(int(i*n), HEIGHT - h_arr[i], n, h_arr[i]))

        
        #Update
        clock.tick(delay)
        pygame.display.flip()

# MAIN PART

print("Enter the size of the array")
s = int(input())

print("Enter the minimum value")
minval = int(input())

print("Enter the maximum value")
maxval = int(input())

print("Enter the clock tick value value")
t = int(input())

Bubble_Sort_Animation(minval,maxval,s,t)