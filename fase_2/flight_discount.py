from heapq import heappop, heappush
from heapq import _heapify_max

n,m = map(int, input().split())
adj =[[] for _ in range(n)]
price = [float('inf') for i in range(n)]
disc = [float('inf') for i in range(n)]



 
for _ in range(m):
    a, b, c = map(int, input().split())
    adj[a-1].append((b-1,c))
    adj[b-1].append((a-1,c))
 
price[0]=0
disc[0]=0
pq = [(0,(0, 0))] 

while pq:
    (val,(node, cost))= heappop(pq)

    if val==1:
        if (disc[node]< cost):
            continue
    if val ==0:
        if (price[node]< cost):
            continue

    for (n, w) in adj[node]:
        if val==0:
            if price[n] > w+cost:
                price[n]= w+ cost
                heappush(pq, (0,(n, w+ cost)))
            if disc[n]> (w//2)+cost:
                disc[n]= (w//2)+ cost
                heappush(pq, (1,(n,(w//2)+ cost)))
        if val == 1:
            if disc[n]> w+cost:
                disc[n]= w+cost
                heappush(pq, (1,(n, w+cost)))

    
    _heapify_max(pq)

print(disc[-1])
            

