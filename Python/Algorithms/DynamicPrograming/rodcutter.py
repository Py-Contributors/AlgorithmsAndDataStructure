def rodcutter(cost):
    rod = [0]*len(cost)
    rod[0] = 0
    for i in range(1,len(rod)):
        max_pro = float('-infinity')
        for j in range(1,i+1):
            max_pro = max(max_pro,cost[j]+rod[i-j])
        rod[i] = max_pro
    return rod[-1]
print(rodcutter([0,2,4,5,7]))