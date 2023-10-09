#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
const int MAX = 2e5+10;
const int INF = 0x3f3f3f3f;
vector<int> tree[MAX];

int par[MAX], dist1[MAX], dist2[MAX];

void dfs1(int i, int p){
    for(auto v:tree[i]){
        if(v!=p){
            dfs1(v,i);
            dist1[i]= max(dist1[i], 1+ dist1[v]);
        }
    }

}
void dfs2(int i, int p){
    int m1=-1, m2=-1;
    for(auto v:tree[i]){
        if(v!=p){
            if(m1<=dist1[v]){
                m2=m1;
                m1 = dist1[v];
            } else if(m2<=dist1[v]){
                m2 = dist1[v];
            }
        }
    }

    for (auto v: tree[i]){
        if(v!=p){
            int aux = m1;
            if(m1==dist1[v]) aux = m2;
            dist2[v]= 1+ max(dist2[i], 1+aux);
            dfs2(v, i);
        }
    }

}

int32_t main(){
    int n;cin >> n;
    for (int i=1; i<n; i++){
        int a,b; cin >> a >>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs1(1, -1);
    dfs2(1, -1);



    for(int i=1; i<= n; i++){
        cout << max(dist1[i], dist2[i])<<" ";
    }

    cout << endl;





}