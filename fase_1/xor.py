n,k =map(int, input().split())
arr = list(map(int, input().split()))

psum = [0]*(n+1)

for i in range(1,n+1):
    psum[i] = psum[i-1] ^ arr[i]

#print(psum)
for i in range(k):
    x,y = map(int, input().split())
    print(psum[x-1]^psum[y])
    
