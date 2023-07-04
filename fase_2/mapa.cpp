#include <bits/stdc++.h>
using namespace std;
using ii= pair <int, int>;

ii solve(int L, int C, vector<string> &M){
    int x=-1, y=-1;
    for (int i=0; i<L; i++)
        for (int j=0; j<C;j++)
            if (M[i][j]=='o'){
                x=i;y=j;
                break;
            }
    
    const vector<ii> dirs {ii(1,0),ii(-1,0),ii(0,1),ii(0,-1)};

    while(true){
        bool move = false;

        for (auto d:dirs){
            auto dx = d.first, dy = d.second;
            auto u = x+dx , v = y+dy;
            if (0<=u and u<L and 0<=v and v<C and M[u][v]=='H'){
                M[u][v]='.';
                move= true;
                x = u; y=v;
            }
        }
        if (not move) break; 
    }
    
    return ii(x+1,y+1);
}

int main(){
    ios::sync_with_stdio(false);
    int l,c;
    cin>> l>>c;
    vector<string> M(l);
    for (int i=0; i<l; ++i) cin>>M[i];
    auto ans = solve(l,c,M);
    cout << ans.first << " "<< ans.second<<"\n";
    return 0;

}