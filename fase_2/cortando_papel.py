# n = int(input())
# arr =list(map(int, input().split()))
# p = {}

# h = []

# h.append(0)
# for x in arr:
#     if x!=h[-1]:
#         h.append(x)
# h.append(0)

# size= len(h)

# for i in range(1, size-1):
#     if h[i-1]<h[i] and h[i]>h[i+1]:
#         if h[i] in p.keys():
#             p[h[i]]-= 1
#         else:
#             p[h[i]]= -1
#     if h[i-1]>h[i] and h[i]<h[i+1]:
#         if h[i] in p.keys():
#             p[h[i]]+= 1
#         else:
#             p[h[i]]= 1

# ans = 2
# pedacos = 2

# print(p)

# for i in p.values():
#     pedacos+= i
#     ans = max(pedacos, ans)

# print(ans)

def solve(n, heights):
    x = [0]
    for h in heights:
        if x[-1] != h:
            x.append(h)
    x.append(0)

    n = len(x)

    y = {}
    PICO = -1
    VALE = 1

    for i in range(1, n-1):
        if x[i - 1] < x[i] and x[i] > x[i + 1]:
            y[x[i]] = y.get(x[i], 0) + PICO
        if x[i - 1] > x[i] and x[i] < x[i + 1]:
            y[x[i]] = y.get(x[i], 0) + VALE

    ans = 2
    pieces = 2

    for aux_y in y.items():
        delta = aux_y[1]

        pieces += delta
        ans = max(ans, pieces)
    return ans



N = int(input())
h = list(map(int, input().split()))

ans = solve(N, h)

print(ans)


