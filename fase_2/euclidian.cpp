#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 1e18+1;


struct Point {
	int x, y; 
	bool operator < (Point o){ 
        if(x == o.x) return y < o.y;
        return x < o.x;
    }
	void operator+=(const Point& o) { x += o.x, y += o.y; } 
	void operator-=(const Point& o) { x -= o.x, y -= o.y; } 
	
};


int32_t main(){
    sws;

    int n; cin >> n; int D = INF;
    vector<Point> pts; set<pair<int, int>> s;
    for(int i=0; i<n; i++){
        Point p; cin >> p.x >> p.y;
        pts.push_back(p);
    }

    sort(pts.begin(), pts.end());

    for(int i=0, j=0; i<n; i++){
        int d = ceil(sqrt(D));

        while(abs(pts[i].x - pts[j].x) >= d){
            s.erase({pts[i].y, pts[i].x});
            j++;
        }

        auto it1 = s.lower_bound({pts[i].y - d, pts[i].x});
        auto it2 = s.upper_bound({pts[i].y + d, pts[i].x});

        for(auto x= it1; x!=it2; x++){
            int dx = pts[i].x- x->second;
            int dy = pts[i].y- x->first;
            D = min(D, (dx*dx)+(dy*dy));

        }

        s.insert({pts[i].y, pts[i].x});
    }


    cout << D << endl;


    
    
}