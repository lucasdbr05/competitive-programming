from collections import deque

n,m = map(int, input().split())

matrix= []

a=None
b=None

for j in range(n):
    x = list(input().strip())
    matrix.append(x)
    for i in range(m):
        if x[i]=="A":
            a = (i,j)
        if x[i]=="B":
            b = (i,j)

queue = deque()
past_step = [["" for _ in range(m)] for _ in range(n)]
seen= [[False for _ in range(m)] for _ in range(n)]
seen[a[1]][a[0]] = True
queue.append(a)
processados = [a]

is_v=False
dirs = {'R':(1,0),'D':(0, 1),'L':(-1,0),'U':(0,-1)}
while queue and not is_v:
    
    (dx, dy)= queue.popleft()
    
    for d, (da,db) in dirs.items():
        x = dx+da
        y = dy+db

        if (0>x or x>=m) or (0>y or y>=n):
            continue
        if matrix[y][x]=="#":
            continue
        if seen[y][x]:
            continue

        seen[y][x]=True
        past_step[y][x] = d
        queue.append((x,y))
        if matrix[y][x]=="B":
            break

if seen[b[1]][b[0]]:
    print("YES")
    steps = []
    aux = b
    while aux !=a:
        p = past_step[aux[1]][aux[0]]
        steps.append(p)
        aux = (aux[0]-dirs[p][0], aux[1]-dirs[p][1])
    print(len(steps))
    steps.reverse()
    print(*steps, sep="")
else:
    print("NO")



