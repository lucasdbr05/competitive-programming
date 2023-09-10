#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
const double  PI = 3.141592653589793;
int n,m, o;
const int MAX = 1e9+7;
struct Point {
	int x, y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	Point operator+(const Point& o) { return Point(x+o.x, y+o.y); } 
	Point operator-(const Point& o) { return Point(x-o.x, y-o.y); } 
	bool operator < (Point o){ 
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
	void operator+=(const Point& o) { x += o.x, y += o.y; } 
	void operator-=(const Point& o) { x -= o.x, y -= o.y; } 
	long long dot(const Point& o) { return 1ll*x*o.x + 1ll*y*o.y; } 
	long long cross(const Point& o) { return 1ll*x*o.y - 1ll*y*o.x; } 
};

vector<Point> polygon;
stack<Point> hull;
Point cen;

double angle(Point p){
    double ret = atan2(p.y, p.x);
    while(ret < 0)
        ret += 2*PI;
    return ret;
}

bool radialComp( Point &a,Point& b){
	Point v, u; 
        v.x = a.x - cen.x;
		u.x = b.x - cen.x;
        v.y = a.y - cen.y,
		u.y = b.y - cen.y;
	return angle(v) < angle(u);
}

bool cmp(Point a, Point b){
    if (a.y<b.y) return true;
    else if(a.y==b.y){
        if (a.x<b.x) return true;
    }
    return false;
}


int check(Point& p, Point& s, Point& t){
    ii n = {p.x-s.x,p.y-s.y};
    ii m = {p.x-t.x,p.y-t.y};
    int ans = (n.first*m.second)-(n.second*m.first);
    
    return ans; 
}

int signal(Point& p, Point& s, Point& t){
    int i= check(p,s,t);
    if (i>0) return 1;
    else if(i<0) return -1;
    else return 0;
}

double dist(Point a, Point b){
    return sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}



bool touch(Point& p, Point& s, Point& t){
    return (p.x<=max(t.x, s.x))&&(p.x>=min(t.x,s.x))&&(p.y<=max(t.y, s.y))&&(p.y>=min(t.y,s.y));
}

void convex_hull(){
    int aux= 0;
    for (int i=1; i<n; i++){
        if(polygon[i].y< polygon[aux].y){
            aux=i;
        }
    }
 
    int s=0, t=1, i =2;

    hull.push(polygon[0]);
    do{
        t=(s+1)%n;
        if((signal(polygon[t], hull.top(), polygon[(t+1)%n])!=1)){
            hull.push(polygon[t]);
        }else{
            hull.pop();
        }
        s++;
    } while(s!=0);
}
int32_t main(){
    cin >> n;
    
    for (int i=0; i<n; i++){
        Point p; cin >> p.x >> p.y;
        polygon.push_back(p);
    }

    int aux= 0;
    for (int i=1; i<n; i++){
        if(polygon[i].y< polygon[aux].y){
            aux=i;
        }
    }

    cen = polygon[aux];

    sort(polygon.begin(), polygon.end());
    convex_hull();


    cout << hull.size()<< endl;
    while (!hull.empty()){
        auto p =hull.top(); hull.pop();
        cout << p.x << " "<< p.y << endl;
    }
    

}