ia, ib, fa, fb = map(int,input().split())
# ia,ib,fa,fb = bool(ia),bool(ib),bool(fa),bool(fb)
ans = (fa, fb)

height = 0
states = {(ia,ib):0}

tree = [(ia,ib)]

while tree:
    # print(tree, height, ans, states)
    a,b =  tree.pop(0)
    s = (a,b)

    if s == ans:
        print(states[s])
        break

    c1 = (1- a, b)
    c2 = (1- a, 1- b )
    # c1 = (not a, b)
    # c2 = (not a, not b )

    dist = states[s]
    
    if not c1 in states.keys():
        states[c1] = dist + 1
        tree.append(c1)
    if not c2 in states.keys():
        states[c2] = dist + 1
        tree.append(c2)
    





