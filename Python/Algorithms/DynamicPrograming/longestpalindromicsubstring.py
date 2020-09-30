
reslen=float("-infinity")
resstart = None
def asd(s='aaababaaa'):
    if len(s)<2:
        return s
    for i in range(len(s)-1):
        expand(s,i,i)
        expand(s,i,i+1)
    return s[resstart:resstart+reslen]

def expand(string,begin,end):
    while begin>=0 and end<len(string) and string[begin]==string[end]:
        begin-=1
        end+=1
        global reslen,resstart
    if (reslen < end-begin-1):
        resstart = begin+1
        reslen=end-begin-1
print(asd())