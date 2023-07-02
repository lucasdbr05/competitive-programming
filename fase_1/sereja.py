n,m = map(int, input().split())
 
arr = list(map(int, input().split()))
 
psum = [0]*(n+1)
processados = {}
 
for i in arr:
    processados[i]= False
 
for i in range(n-1, -1, -1):
    psum[i]= psum[i+1]
    if not processados[arr[i]]:
        psum[i]+= 1
        processados[arr[i]]= True

 
for i in range(m):
    q = int(input())
    print(psum[q-1])
