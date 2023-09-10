#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;


struct Point{int x; int y;};


void check(Point p, Point s, Point t){
    ii n = {p.x-s.x,p.y-s.y};
    ii m = {p.x-t.x,p.y-t.y};
    int ans = (n.first*m.second)-(n.second*m.first);
    if (ans ==0) cout << "TOUCH"<< endl;
    else if(ans >0)cout << "RIGHT"<< endl;
    else if(ans <0)cout << "LEFT"<< endl;
    
}

void solve(){
    Point a, b, c ,d;
    cin >> a.x >> a.y; 
    cin >> b.x >> b.y; 
    cin >> c.x >> c.y; 
     


    check(c, b, a) ;
    
}

int32_t main(){
    int t; cin>> t;
    while(t--) solve();


}