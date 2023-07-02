n,c,m = map(int, input().split())
car = set(map(int, input().split()))
comp = set(map(int, input().split()))

f = car - comp

print(len(f))


