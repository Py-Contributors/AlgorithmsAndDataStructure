class KMP:
    def __init__(self,st, pat):
        self.st=st
        self.pat=pat
        g, self.pi = 0, [0] * len(pat)
        for i in range(1, len(pat)):
            while g and (pat[g] != pat[i]):
                g = self.pi[g - 1]
            self.pi[i] = g = g + (pat[g] == pat[i])        
    
    def match(self):
        g, idx = 0, []
        for i in range(len(self.st)):
            while g and self.pat[g] != self.st[i]:
                g = self.pi[g - 1]
            g += self.pat[g] == self.st[i]
            if g == len(self.pi):
                idx.append(i + 1 - g)
                g = self.pi[g - 1]
        return idx

def main():
    # KMP (text, pattern)    
    kmp=KMP()
    
    #kmp.match() returns array matching string indexes

if __name__ == "__main__":
    main()
