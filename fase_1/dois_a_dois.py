qtt = int(input())

arr = list(map(int, input().split()))

big = 0
ans = 0
for i in arr:
    ans += i
    big = max(big, i)

if ans%2== 0 and big <= (ans-big):
    print("Sim")
else:
    print("Nao") 

"""
l, r = 0, qtt-1

aux_sum = arr[r]-arr[l]

while r-1>l:
    if aux_sum<0:
        r-=1
        aux_sum+= arr[r]
    else:
        l+=1
        aux_sum -=arr[l]
       
       
if aux_sum ==0:
    print('SIM')
else:
    print('NAO')
"""