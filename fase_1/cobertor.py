n,m = map(int, input().split())

parts = [int(x) for x in input().split()]

def check_l0(arr):
    n_f=True
    for i in arr:
        if i<0:
            n_f = False
            break
    return n_f
   
if check_l0(parts[0:m]):
    x_sum = sum(parts[0:m])
else:
    x_sum = 0

maior = x_sum

for i in range(1,n-m+1):
    x_sum = x_sum- parts[i-1]+ parts[i+m-1]
    maior = max(maior, x_sum)

maior = 0 if maior <0 else maior
print(maior)
















"""
l,r= 0,m
def check_l0(arr):
    n_f=True
    for i in arr:
        if i<0:
            n_f = False
            break
    return n_f
   
if check_l0(parts[l:r]):
    x_sum = sum(parts[l:r])
else:
    x_sum = 0
   
max_sum = x_sum


while r<n:
    x_sum -= parts[l]
    l +=1
    x_sum += parts[r]
    r+=1

    if x_sum> max_sum and check_l0(parts[l:r]):
        max_sum = x_sum
   
print(max_sum)  
"""