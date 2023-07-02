n = int(input())


matrix = [""  for i in range(n)]
for l in range(n):
    matrix[l] = input()
    matrix[l] = [i for i in matrix[l]]

q = []
for row in range(n):
    for col in range(n):
        if matrix[row][col]=='0':
          q.append((row,col))

while q:

  x, y = q[0]
  q = q[1:] 

  dirs = [(0,1), (0,-1),(1,0),(-1,0)]

  for i in dirs:
    dx, dy = i
    u = x +dx
    v = y+dy
    if u>=0 and u<n and v>=0 and v<n and matrix[u][v]=='*':
      str_s= min(int(matrix[x][y])+1, 9)
      matrix[u][v] = matrix[u][v].replace('*', str(str_s))
      q.append((u,v))

for row in matrix:
  print("".join(row))

