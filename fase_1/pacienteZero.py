n, c = map(int, input().split())

grafo = {}
set_keys = set()
set_values = set()
for _ in range(c):
    x = list(map(int, input().split()))
    grafo[x[0]] = x[2:x[1]+2]
    set_keys.add(x[0])
    set_values |= set(x[2:])
# print(grafo)
# print(set_keys)
# print(set_values)  

set_ans = set_keys - set_values

for i in set_ans:
    print(i)