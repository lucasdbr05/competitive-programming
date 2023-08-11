#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
#define endl '\n'

const int MAX = 1e5+10;
vector<vector<int>> g(MAX);

int dist[MAX];

void dfs(int x){
    for (auto no:g[x]){
        if (dist[no]==-1){
            dist[no]= dist[x]+1;
            dfs(no);
        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin>>n;

    for (int i=0; i<(n-1); i++){
        int a, b;cin >> a >> b; 
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(dist, -1, sizeof dist);
    
    
    dist[0]=0;
    dfs(0);

    int pos= -1, auxdist = -1;

    for (int i=0; i<n; i++){
        if (dist[i]> auxdist){
            auxdist = dist[i];
            pos= i;
        }
    }

    memset(dist, -1, sizeof dist);
    dist[pos]=0;
    dfs(pos);

    int diametro=-1;
    for (int f=0; f< n; f++){
        diametro = max(diametro, dist[f]);
    }

    

    cout << diametro << endl;
}