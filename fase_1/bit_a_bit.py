n, k = map(int, input().split())
tam = n//k
matrix = []
ans = []

for i in range(n):
    matrix.append([int(i) for i in input().split()])


sum_k = 0
matrix_l = 0
matrix_c = 0
x=0
while x<n:
    for i in range(matrix_l, matrix_l+k):
        for j in range(matrix_c, matrix_c+k):
            sum_k +=matrix[i][j]
           
    ans.append(str((sum_k)//(k**2)))
       
   
    matrix_c+= k
    if matrix_c>=n:
        matrix_c = 0
        matrix_l = k
        x+=k
    sum_k = 0
   
#print(ans)  
for x in range(0,k**2,k):
    elm =ans[x:x+k]
    x = " ".join(elm)
    print(x)

