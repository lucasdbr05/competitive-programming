l, c = map(int , input().split())

matrix = ["" for _ in range(l)]

for i in range(l):
    matrix[i] = input()
    matrix[i] = [j for j in matrix[i]]

dirs = [(0,1), (0,-1)]
q = []

for i in range(c):
    if matrix[0][i]=="o":
        q.append((0,i))

while q:
    x, y = q.pop(0)

    if x == l-1:
        continue

    if x+1<l and matrix[x+1][y] == ".":
        matrix[x+1][y] = "o"
        q.append((x+1,y))
    else:
        for elem in dirs:
            i, j =elem
            dx = x+ i
            dy = y+ j
            if (dx>=0 and dx < l-1) and (dy >= 0 and dy< c) and matrix[dx][dy]==".":
                matrix[dx][dy]= "o"
                q.append((dx,dy))









# print(matrix)

for row in matrix:
    print("".join(row))

