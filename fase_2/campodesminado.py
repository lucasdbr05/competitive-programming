n,m,k = map(int, input().split())

matrix = []

ans = [[0]*m for _ in range(n)]

for _ in range(n):
    matrix.append(list(input()))

counter = 0
pts = []
for i in range(n):
    for j in range(m):
        if matrix[i][j]==".":
            pts.append((i,j))
            continue
        else:
            counter += 1
            if counter > k:
                ans[i][j]= "*"
            else:
                matrix[i][j]="."
                pts.append((i,j))


dirs = [ (0,1), (0, -1), (1,0), (-1,0),(1,1), (-1, -1), (1, -1), (-1, 1)]
while pts:
    (a,b)= pts.pop()
    c=0
    
    for (x,y) in dirs:
        dx = a+x
        dy = b+y
        if 0<=dx<n and 0<=dy<m and ans[dx][dy]=="*":
            c += 1
            #print(dy, dx, c, end=" / ")
    ans[a][b]=c
#print()

for line in ans:
    print(*line)


