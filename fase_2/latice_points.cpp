#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const double  PI = 3.141592653589793;
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
    if(b==0) return a;
    return gcd(b%a, a);
}

int limite(Point a, Point b){
    int x = abs(a.x-b.x);
    int y = abs(a.y-b.y);
    return gcd(x,y)-1;
}

int area(){
    int a = 0;
    for (int i=0; i<n; i++){
        a += (pts[i].x*pts[(i+1)%n].y)-(pts[i].y*pts[(i+1)%n].x);
    }

    return (int)a/2;
}


int32_t main(){
    cin >> n;
    for (int i=0; i<n; i++){
        Point a; cin >> a.x >> a.y;
        pts.push_back(a);
    }

    int A = area();
    int lim = 0;

    for (int i=0; i<n; i++){
        lim+= limite(pts[i], pts[(i+1)%n]);
    }

    int in = A-lim/2+1;
    cout << in << " "<< lim<< endl;
}