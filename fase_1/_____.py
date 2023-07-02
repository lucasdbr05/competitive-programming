n, m = map(int, input().split())

grafo = [[] for _ in range(n)]

dist = [float("inf")]*(n+1)

for _ in range(m):
    u, v, p = map(int, input().split())
    grafo[u-1].append((v,p))
    grafo[v-1].append((u,p))
    
fonte = int(input())

costs = {i:float("inf") for i in range(1,n+1)}
costs[fonte] = 0
dist[fonte] = 0
#parents = dict()
for x in grafo[fonte-1]:
    costs[x[0]] = x[1]
    dist[x[0]] = x[1]
    #parents[x[0]] = x[1]

processados = []
def find_lower_cost(costs):
    l_node = None
    l_cost = float("inf")
    for node in costs:
        cost = costs[node]
        if cost< l_cost and node not in processados:
            l_node = node
            l_cost = cost
    return l_node 



node = find_lower_cost(costs)


while node is not None:
    weight = costs[node]
    neighbors = grafo[node-1]

    for neighbor in neighbors:
        new_cost = weight + neighbor[1]
        if new_cost < costs[neighbor[0]]:
            costs[neighbor[0]] = new_cost
            #parents[neighbor[0]] = node
            dist[neighbor[0]] = new_cost
    processados.append(node)
    node = find_lower_cost(costs)


#print(costs)

# costs = {i:v for i, v in costs.items() if 0<v}

# greater = max(costs.values())
# lower = min(costs.values())
# print(costs)
# print(greater - lower)

greater = None
lower = None      
for i in dist:
    if i == float("inf"):
        continue
    greater = i if greater==None or ((i!=0 )  and i > greater) else greater 
    lower = i if  lower==None or ((i!=0) and i < lower) else lower
# print(dist)
print(greater - lower)
