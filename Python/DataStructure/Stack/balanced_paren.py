#BALANCED PARENTHESIS CHECK

def check(s):
    if len(s)%2 !=0:
        return False
    opening = set('{[(')
    matching = set([('(',')'),('{','}'),('[',']')])
    stack = []

    for paren in s:
        if paren in opening:
            stack.append(paren)
        else:
            if len(stack)==0:
                return False
            last_open = stack.pop()
            if (last_open,paren) not in matching:
                return False
    return True
print(check('([(())])'))