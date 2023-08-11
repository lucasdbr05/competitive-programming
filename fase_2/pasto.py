import sys

sys.setrecursionlimit(2*31-1)

n, m = map(int, input().split())

V = 0
K = 0
pasto = []
nx = [1,0,-1,0]
ny = [0,1,0,-1]
vis = [[False]*m for _ in range(n)]
for _ in range(m):
    x = list(input())
    pasto.append(x)
    
def dfs(y,x):
    global k, v
    vis[y][x]= True
    if pasto[y][x]=="k":
        k+= 1
    if pasto[y][x]=="v":
        v+= 1
    for l in range(4):
        ay = y + ny[l] 
        ax = x + nx[l] 
        if 0<=ax<m and 0<=ay<n and pasto[ay][ax]!="#":
            dfs(ay, ax)
            


for i in range(n):
    for j in range(m):
        v = 0
        k = 0
        if pasto[i][j]== "." and not vis[i][j]:
            dfs(i,j)

        if v>=k:
            V+= v
        else:
            K+= k
print(K, V)