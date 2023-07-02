n,m = map(int, input().split())
casas = [int(x) for x in input().split()]
orders = [int(x) for x in input().split()]



idx = {}
for i in range(n):
    idx[casas[i]] = i
    
time = 0
pos = 0
for x in orders:
    i = idx[x]
    time+= abs(pos - i)
    pos = i
    
print(time)