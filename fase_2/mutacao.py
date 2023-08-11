n,d = map(int, input().split())
matrix = []
ans = [[0]*n for _ in range(n)]

for _ in range(n):
    matrix.append(list(map(int, input().split())))

d = d%4


for i in range(n//2):
    for j in range(n):
        if d==1:
            ans[i][i] = matrix[n-i-1][i]
            ans[n-i-1][i]= matrix[n-i-1][n-i-1]
            ans[n-i-1][n-i-1]= matrix[i][n-i-1]
            ans[i][n-i-1] = matrix[i][i]
   

for row in matrix:
    print(*row, sep=" ")