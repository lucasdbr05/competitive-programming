n, f = map(int, input().split())
vulcao = []

for i in range(n):
    vulcao.append([int(i) for i in input()])
   
stack = [(0,0)]
dirs = [(1,0), (0,1), (-1,0), (0, -1)]
while stack:
    x, y = stack.pop()
    if vulcao[x][y]!="*" and f>= int(vulcao[x][y]):
        vulcao[x][y]= "*"
        for (dx, dy) in dirs:
            i = x+ dx
            j = y+ dy
            if i>=0 and i<n and j>=0 and j<n:
                stack.append((i,j))

for elm in vulcao:
    elm = [str(i) for i in elm]
    x = "".join(elm)
    print(x)


"""


l, force = map(int, input().split())

matrix = [[] for _ in range(l)]

for i in range(l):
    matrix[i] = [int(i) for i in list(input())]
   
queue = [(0,0)]
dirs = [(1,0), (-1,0), (0,-1), (0,1)]

processados = []
if matrix[0][0]<= force:
    while queue:
        i, j = queue.pop(0)
        # print(i,j, matrix[i][j])
        if matrix[i][j] <= force:
            matrix[i][j] = "*"
            processados.append((i,j))
            # print(processados)
           
   
       
        for (dx, dy) in dirs:
            x = i+ dx
            y = j+ dy
            if x>=0 and x<l and y>=0 and y<l :
                test = matrix[x][y]
                if (x,y) not in processados and test<= force and (x,y) not in queue:
                    queue.append((x,y))
        # print(queue)
else:
    pass
   
for elm in matrix:  
    elm = [str(i) for i in elm]
    print("".join(elm))
"""