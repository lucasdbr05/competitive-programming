v, n, m = map(int, input().split())
adj = [[] for _ in range(n)]
memo = [[float('inf')]*(v+1) for _ in range(n)]

for _ in range(m):
    a, b, t, p = map(int, input().split())
    a, b = a-1, b-1
    adj[a].append((b, t, p))
    adj[b].append((a, t, p))

x,y = map(int, input().split()) 
x,y = x-1, y-1


for c in range(v+1):
    for j in range(n):
        if c==0:
            memo[j][c]=0
        memo[x][c]=0
        for (node, time, price) in adj[j]:
            if c-price>=0 and price!=0:
                memo[node][c] = min(memo[node][c], (memo[j][c-price]+time))

    s = set()
    for j in range(n):
        s.add((memo[j][c], j))

    while s:
        pt = s.pop()
        s.discard(pt)
        for (node, time, price) in adj[pt[1]]:
            if price!=0 : continue

            if (memo[node][c]> memo[pt[1]][c-price]+time):
                s.discard((memo[node][c], node))
                memo[node][c]= memo[pt[1]][c-price]+time
                s.add((memo[node][c], node))


if memo[y][v]< float('inf'):
    print(memo[y][v])
else:
    print(-1)
    