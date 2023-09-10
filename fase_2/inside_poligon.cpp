#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;
int n,m;
const int MAX = 1e9+7;
struct Point{int x; int y;};
vector<Point> edges;


int check(Point& p, Point& s, Point& t){
    ii n = {p.x-s.x,p.y-s.y};
    ii m = {p.x-t.x,p.y-t.y};
    int ans = (n.first*m.second)-(n.second*m.first);
    
    return ans; 
}

int signal(int i){
    if (i>0) return 1;
    else if(i<0) return -1;
    else return 0;
}

bool intersect(Point a, Point b, Point c, Point d){
    int t1 =check(c,a, b);
    int t2 =check(d,a, b);
    int t3 =check(a,c, d);
    int t4 =check(b,c, d);
    // bool a1 = signal(t1)!=signal(t2);
    bool a1 = ((t1>=0 and t2<=0)||(t1<=0 and t2>=0));
    // bool a2 = signal(t3)!=signal(t4);
    bool a2 = ((t3>=0 and t4<=0)||(t3<=0 and t4>=0));

    // cout << t1 <<" "<< t2<< " " << t3<< " " << t4<< " "<<a1<< " "<<a2<< endl;
    return a1&&a2;
}


bool touch(Point& p, Point& s, Point& t){
    return (p.x<=max(t.x, s.x))&&(p.x>=min(t.x,s.x))&&(p.y<=max(t.y, s.y))&&(p.y>=min(t.y,s.y));
}

void solve(){
    Point s, INF; int count; bool lim;
    cin >> s.x >> s.y; 
    INF.x = MAX;INF.y=MAX+2;
    count = 0;
    for (int i=0; i<n; i++){
        Point r = edges[i]; Point t= edges[i+1];
        lim = false;

        if (check(s, r, t)==0 and touch(s, r, t)){
            lim = true;
            break;
        }if (intersect(r, t,s, INF)==true){
            count++;
        }
    
    }
    // cout << count<< endl;
    if (lim) cout << "BOUNDARY"<< endl;
    else if(count%2==1)cout << "INSIDE"<< endl;
    else if(count%2==0)cout << "OUTSIDE"<< endl;
}

int32_t main(){
    cin >> n >> m;
    for (int i=0; i<n; i++){
        Point p; cin >> p.x >> p.y;
        edges.push_back(p);
    }
    edges.push_back(edges[0]);
    while(m--) solve();


}