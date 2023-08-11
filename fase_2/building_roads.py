from collections import defaultdict
import sys

sys.setrecursionlimit(2**31-1)

def dfs(s):
    if vis[s]:
        return
    vis[s] = True
    for i in adj[s]:
        dfs(i)

n, m = map(int, input().split())

adj = defaultdict(list)
vis = [False]* (n+1)

for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
v = []
for i in range(1,n+1):
    if not vis[i]:
        v.append(i)
        dfs(i)

print(len(v)-1)
for i in range(1, len(v)):
    print(v[i], v[i-1])