n, m = map(int, input().split())

adjm = [[] for i in range(n)]
for i in range(m):
    i,y = map(int, input().split())
    adjm[i-1].append(y)
    adjm[y-1].append(i)

d = {i:0 for i in range(1,n+1)}
central = []
for i in adjm:
    for j in i:
        d[j]+=1

#print(adjm, d, sep="\n")

def is_circular(nodo):
    global adjm, central
    if d[nodo]==1:
        return False
    
    if d[nodo]==2:
        fst = adjm[nodo-1][0]
        snd = adjm[nodo-1][1]
        if (fst or snd)>=5:
            return False
        
        if 2<d[fst]<5  and 2<d[snd]<5:
            return True
        elif 2< d[fst]< 5 and d[snd]!=1:
            is_circular(snd)
        elif 2< d[snd]< 5 and snd!=1:
            is_circular(fst)

    if 3<= d[nodo]<=4:
        return True
    
    

    

for i in range(1, n+1):
    if is_circular(i):
        central.append(i)      














            
            
print(len(central))

