from math import lcm
t = int(input())
MAX = 2 * 10**6
crivo = [0] * (MAX + 1)



for _ in range(t):
    k, a, b = map(int, input().split())
    
    int vx = n/x, vy = n/y;
	int lcm = (x*y)/(gcd(x, y));
	vx -= (n/lcm); vy -= (n/lcm);
	int py = ((vy)*(vy+1))/2;
	int px = ((vx)*(n+(n-vx+1)))/2;
	cout << px-py << endl;


	x = ((ax)*(k+(k-ax+1)))/2;
    y = ((ay)*(ay+1))/2;
    
    
    print(x - y)
