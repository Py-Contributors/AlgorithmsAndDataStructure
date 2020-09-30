def movetower(height, fromtower, totower, withtower):
    if height == 1:
        print(fromtower + '-->' + totower)
        return True
    print('Executing 1, height of tower: {}'.format(height))
    movetower(height-1, fromtower,withtower,totower)
    print(fromtower + '-->' + totower)
    print('Executing 2, height of tower: {}'.format(height))
    movetower(height-1, withtower, totower, fromtower)
print(movetower(3,'a','c','b'))