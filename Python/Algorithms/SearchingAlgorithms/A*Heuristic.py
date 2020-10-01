import pandas as pd

class Board:
    def __init__(self,size):
        self.size = size
        self.open = []
        self.closed = []

    def f(self,initial,goal):
        ff= 0
        ff= self.h(initial.elements,goal)+initial.l
        return ff

    def h(self,initial,goal):
        temp = 0
        for i in range(0,self.size):
            for j in range(0,self.size):
                if initial[i][j] != goal[i][j] and initial[i][j] != 'x':
                    temp += 1
        return temp

    def start(self):

        initial=[[1,2,3,4],[5,6,7,8],[9,10,'x',12],[13,14,11,15]]
        goal=[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,'x']]
        print("Initial state: ")
        ini=pd.DataFrame(initial)
        print (ini.to_string(index=False))
        print("\nGoal state: ")
        fi=pd.DataFrame(goal)
        print (fi.to_string(index=False))
        initial = Node(initial,0,0)
        initial.fval = self.f(initial,goal)
        self.open.append(initial)
        print("\n Solution--")
        while True:
            current = self.open[0]
            print("  ")
            df=pd.DataFrame(current.elements)
            print (df.to_string(index=False))
            if(self.h(current.elements,goal) == 0):
                break
            for i in current.gen_child():
                i.fval = self.f(i,goal)
                self.open.append(i)
            self.closed.append(current.elements)
            del self.open[0]

            self.open.sort(key = lambda x:x.fval,reverse=False)

board = Board(4)
board.start()

class Node:
    def __init__(self,elements,l,fval):
        self.elements = elements
        self.l = l
        self.fval = fval

    def gen_child(self):
        x,y = self.find(self.elements,'x')
        list1 = [[x,y-1],[x,y+1],[x-1,y],[x+1,y]]
        children = []
        for i in list1:
            child = self.arrange(self.elements,x,y,i[0],i[1])
            if child is not None:
                child_node = Node(child,self.l+1,0)
                children.append(child_node)
        return children
        
    def arrange(self,board,x1,y1,x2,y2):
        if x2 >= 0 and x2 < len(self.elements) and y2 >= 0 and y2 < len(self.elements):
            temp_board = []
            temp_board = self.dup(board)
            temp = temp_board[x2][y2]
            temp_board[x2][y2] = temp_board[x1][y1]
            temp_board[x1][y1] = temp
            return temp_board
        else:
            return None
            

    def dup(self,mat):
        temp = []
        for i in mat:
            t = []
            for j in i:
                t.append(j)
            temp.append(t)
        return temp    
            
    def find(self,board,x):
        for i in range(0,len(self.elements)):
            for j in range(0,len(self.elements)):
                if board[i][j] == x:
                    return i,j
