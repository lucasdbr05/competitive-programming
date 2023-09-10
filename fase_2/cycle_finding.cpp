#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(0);
typedef tuple<int, int ,int> iii; 
const int MAX= 2e5+10;
vector <iii> path;
int n,m, a, b, w;
int dist[MAX], rel[MAX];
vector<int> cycle;

void belmann_ford(){
    int x;

    for (int k=1; k<=n; k++){
        x=-1;
        for (auto [u,v,c]: path){
            if(dist[v]> dist[u]+c){
                dist[v]=dist[u]+c;
                rel[v]=u;
                x=v;
            }
        }
    }

    if(x==-1) cout << "NO"<< endl;
    else{
        for (int i=1; i<=n; i++) x=rel[x];

        int v=x;
        while (true){
            cycle.push_back(v);
            if (v==x and cycle.size()>1){
                
                break;
            } 
            v = rel[v];
        }

        cout << "YES"<< endl;
        reverse(cycle.begin(), cycle.end());
        for (int z:cycle){
            cout << z << " ";
        }
        cout << endl;
    }
}

int32_t main(){
    cin >> n>> m;

    memset(rel, -1, sizeof rel);
    for(int i=0;i<m; i++){
        cin >> a >> b >> w;
        path.push_back({a, b, w});
    }

    belmann_ford();
}