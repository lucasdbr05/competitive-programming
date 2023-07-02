n, k = map(int, input().split())

arr = list(map(int,input().split()))

dict_sum = {}

psum = [0]*n
psum[0]=arr[0]

for i in range(1,n):
    psum[i]= arr[i]+ psum[i-1]

ans = 0
for i in range(n):
    if psum[i]==k:
        ans+=1

    if (psum[i]-k) in dict_sum.keys():
        ans += dict_sum[psum[i]-k]
    
    if not psum[i] in dict_sum.keys():
        dict_sum[psum[i]] = 0
    dict_sum[psum[i]] += 1

print(ans)