#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
int n;


struct Point {
	int x, y; 
	bool operator < (Point o){ 
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
	void operator+=(const Point& o) { x += o.x, y += o.y; } 
	void operator-=(const Point& o) { x -= o.x, y -= o.y; } 
	
};

vector<Point> pts;

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}


int limite(Point a, Point b){
    int x= abs(a.x-b.x);
    int y= abs(a.y-b.y);

    return gcd(x,y)-1;
}


int area(){
    int t =(int)pts.size();
    int ret = 0.0;
    for (int i=0; i<t; i++){
        Point a = pts[i], b=pts[(i+1)%t];
        ret += ((a.x*b.y)-(a.y*b.x));
    }

    return abs(ret);
}

int32_t main(){
    cin >> n;
    for (int i=0; i<n; i++){
        Point pt; cin >> pt.x >> pt.y;
        pts.push_back(pt);
    }

    int A = area()/2;
    int lim = n;
    for (int i=0; i<n; i++){
        Point a = pts[(i)], b=pts[(i+1)%n];
        lim += limite(a, b);
    }

    int in = A+1-(lim/2);
    cout << in << " "<<lim; 
}