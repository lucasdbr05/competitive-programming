n, k = map(int, input().split())
 
counter = 0
lectures = list(map(int, input().split()))
 
sleep = list(map(int, input().split()))
 
 
for i in range(n):
    if sleep[i]:
        counter += lectures[i]
        lectures[i] = 0
 
p_sum = [0]*(n-k+1)
p_sum[0] = sum(lectures[:k])
for i in range(1,n-k+1):
    p_sum[i] = p_sum[i-1]+lectures[i+k-1]- lectures[i-1]
#print(p_sum) 
 
counter += max(p_sum)
 
print(counter)