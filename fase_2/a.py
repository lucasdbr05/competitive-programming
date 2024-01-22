import bisect
def find_closest_cities(n, cities):
    left_closest = [0] * n
    right_closest = [0] * n

    # Compute closest city on the left for each city
    for i in range(1, n):
        left_closest[i] = i - bisect.bisect_left(cities, cities[i] - cities[i-1])

    # Compute closest city on the right for each city
    for i in range(n - 2, -1, -1):
        right_closest[i] = bisect.bisect_left(cities, cities[i + 1] - cities[i])

    return left_closest, right_closest

def min_coins_to_travel(n, cities, m, queries):
    left_closest, right_closest = find_closest_cities(n, cities)
    result = []

    for query in queries:
        x, y = query
        x, y = x - 1, y - 1  # Adjust indices to 0-based

        # Calculate the minimum coins to travel from city x to city y
        if x < y:
            result.append(str(min(x - y, x + left_closest[x], y - x + right_closest[y])))
        else:
            result.append(str(min(y - x, y + left_closest[y], x - y + right_closest[x])))

    return result
t = int(input())
for _ in range(t):
    n = int(input())
    cities = list(map(int, input().split()))
    m = int(input())
    queries = [tuple(map(int, input().split())) for _ in range(m)]

    # Solve and print the result for each test case
    result = min_coins_to_travel(n, cities, m, queries)
    print("\n".join(result))