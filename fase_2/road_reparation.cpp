#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef tuple<int, int, int> iii;
const int MAX = 1e5+10;
bool vis[MAX];
int val=0;
int n,m, a, b,c;
vector<iii> v;
int  id[MAX], sz[MAX]; 

int find(int x){
    return id[x]=(id[x]==x?x:find(id[x]));
}

void join(int a, int b){
    a = find(a); b=find(b);
    if (a==b) return;
    if(sz[a]>sz[b]) swap(a,b);
    sz[b]+= sz[a];
    id[a]=b;
}


int32_t main(){
    sws;

    cin >> n >> m;
    memset(sz, 1, sizeof sz);
    for (int i=0;i<m; i++){
        cin >> a >> b >> c;
        v.push_back({c,a,b});
    }

    sort(v.begin(), v.end());

    for (int i=1; i<=n; i++){
        id[i]=i; sz[i]=1;
    }

    int ans =0;

    for(auto [w,a,b]: v){
        if(find(a)==find(b)) continue;

        else{
            join(a,b);
            vis[a]=true; vis[b]=true;
            ans += w;
        } 
    }

    for(int i=1; i<=n; i++){
        if(id[i]==i) {
            val++;
        }
    }

    

    if (val==1)cout << ans << endl;
    else cout << "IMPOSSIBLE"<< endl;

}