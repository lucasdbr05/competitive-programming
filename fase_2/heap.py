import heapq
import random

data = [random.randint(0,100) for _ in range(20)] 
print(data)

heapq.heapify(data)
print(data)

print(heapq.heappop(data))
heapq.heapify(data)
print(data)

heapq.heappush(data, random.randint(0,100))
heapq.heappush(data, random.randint(0,100))
heapq.heappush(data, random.randint(0,100))
heapq.heappush(data, random.randint(0,100))
print(data)
heapq._heapify_max(data)
print(heapq._heappop_max(data))
data = [-i for i in data]
heapq.heapify(data)
print(data)