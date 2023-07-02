n, m = map(int, input().split())
    

def find_circular_line_stations(n, m, connections):
    # Create an adjacency list to represent the connections between stations
    adj_list = [[] for _ in range(n+1)]
    for p, q in connections:
        adj_list[p].append(q)
        adj_list[q].append(p)

    # Start a DFS from station 1 to find the longest path on the graph
    visited = [False] * (n+1)
    stack = [(1, 0)]
    max_distance = 0
    farthest_station = 1
    while stack:
        station, distance = stack.pop()
        if distance > max_distance:
            max_distance = distance
            farthest_station = station
        visited[station] = True
        for neighbor in adj_list[station]:
            if not visited[neighbor]:
                stack.append((neighbor, distance+1))
        print(stack)

    # Start another DFS from the farthest station found to find the diameter of the graph
    visited = [False] * (n+1)
    stack = [(farthest_station, 0)]
    diameter = 0
    while stack:
        ##print(stack)
        station, distance = stack.pop()
        if distance > diameter:
            diameter = distance
        visited[station] = True
        for neighbor in adj_list[station]:
            if not visited[neighbor]:
                stack.append((neighbor, distance+1))
        print(stack)
    # The number of stations in the circular line is the diameter + 1
    return diameter


connections = []
while m:
    p, q = map(int, input().split())
    connections.append((p,q))
    m-=1
num_circular_stations = find_circular_line_stations(n, m, connections)
print(num_circular_stations)