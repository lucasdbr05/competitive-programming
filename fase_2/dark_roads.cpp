#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair <int, int> ii;
typedef tuple <int, int, int> tiii;
vector<int> id, sz;

int find(int x){
    return id[x]= (id[x]==x ? x: find(id[x]));
}

void uni(int p, int q){
    p = find(p); q=find(q);
    if(p==q) return;
    if (sz[p]>sz[q]) swap(p,q);
    id[p]=q;
    sz[q]+= sz[p];
}

int main(){
    int t=1;
    while (t){
        vector<tiii> g;
        int n, m; cin >> n >> m;
        if(n==0 and m==0) break;
        id = vector<int>(n);
        sz = vector<int>(n, 1);
        iota(id.begin(), id.end(), 0);
        int total=0;
        while (m--){
            int a, b, w; cin >> a >> b >> w;
            total+= w;
            g.emplace_back(w,a,b);
        }

        sort(g.begin(), g.end());
        int ans =0, aux=0;
        for (auto[w,a,b]:g){
            if (find(a)!= find(b)){
                uni(a,b);
                aux+= w;
            }
        }
        ans = total-aux;
        cout << ans << endl;
    }
    exit(0);
}