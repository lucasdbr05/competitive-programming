#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> ii;
#define endl '\n'
typedef long long int lli;
const int MAX = 1e6+10;
int n, a, b, d, len;
lli aux,ans= MAX, sp;
int adj[2500][2500];

int vis[2500];
int dis[2500];




void traverse(vector<int>& v){
    aux = 0;
    for (int i=1; i<n;i++){
        aux += adj[v[i]][v[i-1]];
    }
    ans = min(ans, aux);
    
}




int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    len = n*(n-1)/2;
    for (int i=0; i<len; i++){
        cin >> a >> b >> d;
        adj[a][b] = d;
        adj[b][a] = d;
    }

    
    vector<int> v;
    for(int i = 1; i<=n; i++){v.push_back(i);}


    traverse(v);
    

    for(int i=0; i<n-1;i++){
        for (int j =i+1; j<n-1; j++){
            sp = v[i];
            v[i] = v[j];
            v[j]= sp;

            traverse(v);
        }
    }

    cout << ans << endl;


}