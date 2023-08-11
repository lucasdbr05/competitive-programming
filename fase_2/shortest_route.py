import heapq
n, m = map(int, input().split())

nbs = [[] for _ in range(n)]
lengths  = [float('inf')]*n
for i in range(m):
    a,b, c = map(int, input().split())
    nbs[a-1].append((b-1,c))



lengths[0]=0

pq = [(0, 0)]

while pq:
    dist, node = heapq.heappop(pq)
    if dist!= lengths[node]:
        continue
    for i, cost in nbs[node]:
        if dist+ cost < lengths[i]:
            lengths[i]= cost+ dist
            heapq.heappush(pq, (dist+cost, i))

print(*lengths)






################# Answer too slow ###########

# costs = {i: [float('inf'), False] for i in range(1, n+1)}
# fork = {i:[] for i in range(1, n+1)}
# parents = {i: None for i in range(2, n+1)}
# costs[1][0]=0




# def find_node(costs):
#     lower_cost = float('inf')
#     node_lower_cost = None
#     for node in costs:
#         cost = costs[node]
#         if cost[0] < lower_cost and not cost[1]:
#             lower_cost = cost[0]
#             node_lower_cost = node
#     return node_lower_cost


# node =  find_node(costs)
# while node is not None:
#     cost = costs[node]
#     neighbors = fork[node]
#     for n in neighbors:
#         aux_cost = cost[0] + n[1]
#         if costs[n[0]][0]> aux_cost:
#             costs[n[0]][0]= aux_cost
#             parents[n[0]]= node
#     cost[1]= True
#     node =  find_node(costs)

# for i in costs.values():
#     print(i[0], end=" ")

