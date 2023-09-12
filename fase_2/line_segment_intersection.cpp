#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;

struct Point{int x; int y;};


int check(Point& p, Point& s, Point& t){
    ii n = {p.x-s.x,p.y-s.y};
    ii m = {p.x-t.x,p.y-t.y};
    int ans = (n.first*m.second)-(n.second*m.first);
    
    return ans;
    
}

bool touch(Point& p, Point& s, Point& t){
    return (p.x<=max(t.x, s.x))&&(p.x>=min(t.x,s.x))&&(p.y<=max(t.y, s.y))&&(p.y>=min(t.y,s.y));
}

void solve(){
    Point a, b, c ,d;
    cin >> a.x >> a.y; 
    cin >> b.x >> b.y; 
    cin >> c.x >> c.y; 
    cin >> d.x >> d.y; 

    int t1 =check(c,a, b);
    int t2 =check(d,a, b);
    int t3 =check(a,c, d);
    int t4 =check(b, c, d);

    bool a1 = ((t1>=0 and t2<=0)||(t1<=0 and t2>=0))&&(t1!=0 or t2!=0);
    bool a2 = ((t3>=0 and t4<=0)||(t3<=0 and t4>=0))&&(t3!=0 or t4!=0);

    if(a1&&a2) cout << "YES"<< endl;
    else if (t1==0 && touch(c,a,b))cout << "YES"<< endl;
    else if (t2==0 && touch(d,a,b))cout << "YES"<< endl;
    else if (t3==0 && touch(a,c,d))cout << "YES"<< endl;
    else if (t4==0 && touch(b,c,d))cout << "YES"<< endl;
    else cout << "NO"<< endl;
}

int32_t main(){
    int t; cin>> t;
    while(t--) solve();


}