n = int(input())
d = int(input())
a = int(input())

dist = d - a
# dist = (d- a + n)%n
if d - a < 0:
    dist += n

print(dist)