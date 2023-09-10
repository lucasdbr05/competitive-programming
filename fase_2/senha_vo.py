n, m , k = map(int, input().split())
parse = (k//2)+(k%2)
pw = list(input())
f_space = [i for i in range(n-1,-1, -1) if pw[i]=="#"]
arr = []
for i in range(m):
    x = input().strip()
    arr.append(sorted(x))

# print(f_space, arr)
p = int(input())-1
bin_p = bin(p)[2:]

bin_p = bin_p.zfill(m*(parse))
# print(bin_p)
# i=0
# for l in range(0,len(bin_p), parse):
#     idx = int(bin_p[l:l+parse], 2)
#     # print(idx, bin_p[l:l+parse])
#     pw[f_space[i]]= arr[i][idx]
#     i+=1

i = m-1
for idx in f_space:
    pw[idx]= arr[i][p%k]
    p = p//k
    i-=1

pw = "".join(pw)
print(pw)
