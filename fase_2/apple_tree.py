z = int(input())

for _ in range(z):
    n = int(input())
    tree = [[]*(n+1) for _ in range(n+1)]
    for _ in range(n-1):
        x,y = map(int, input().split())
        tree[x].append(y)
        tree[y].append(x)
    q = [(1,0,0)]
    dict_ = {}
    print(tree)
    while q:
        print(q)
        o,t,f = q.pop()
        if t==0:
            q.append((o,1,f))
            for p in tree[o]:
                if p!=f:
                    q.append((p,0,o))
        else:
            if tree[o]==[f]:
                dict_[o]=1
            else:
                dict_[o]= sum(dict_[p] for p in tree[o] if p!=f)
    print(dict_)
    reqs = int(input())
    for _ in range(reqs):
        a,b = map(int, input().split())
        print(dict_[a]*dict_[b])
