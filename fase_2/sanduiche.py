import sys
sys.setrecursionlimit(2**31-1)
n, m = map(int, input().split())
graph = [[] for _ in range(n)]
vis = [False]*n
total = 0


def dfs(i, p):
    global total
    if i==n:
        if p>0:
            total +=1

    dfs(i+1, p)

    val = True
    for j in range(n):
        if (not graph[i][j]): val=False
    if val:
        vis[i]=True
        dfs(i+1, p+1)
        vis[i]=False



for _ in range(m):
    a , b = map(int, input().split())
    a, b = a-1, b-1
    graph[a].append(b)
    graph[b].append(a)


dfs(1, 0)

print(total)
