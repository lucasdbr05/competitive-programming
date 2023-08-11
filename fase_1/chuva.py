

l, c = map(int , input().split())

matrix = [[] for _ in range(l)]

for i in range(l):
    matrix[i] = list(input())
   
dirs = [(0,1), (0,-1)]
def dfs(y,x):
    matrix[y][x]="o"

    if y+1>=l:
        return
    
    else:
        if matrix[y+1][x]=='#':
            for ii, jj in dirs:
                if 0<=x+jj<c:
                    if matrix[y+ii][x+jj]=='.':
                        dfs(y+ii,x+jj)
        elif matrix[y+1][x]==".":
            dfs(y+1, x)



for i in range(c):
    if matrix[0][i]=="o":
        dfs(0,i)



# print(matrix)
# print()
for row in matrix:
    print(*row, sep="")

