#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 200005;
const int INF= 0x3f3f3f3f;

int n, m, a,b, comps, ans=0;
vector<int> idx;
int sz[MAX];

int find(int x){
    idx[x] = (idx[x]==x? x: find(idx[x]));
    return idx[x];
}


void uni(int p, int q){
    p = find(p); q = find(q);
    if (p==q)return;
    comps--;
    if (sz[p]>sz[q]) swap(p,q);
    idx[p]=q;
    sz[q]+= sz[p];
    //cout <<sz[q]<< endl;
    ans = max(ans, sz[q]);
    return;
}


int32_t main(){
    sws
    cin >> n >> m;
    
    for (int i=1; i<=n; i++) sz[i]=1;
    for (int i=0; i<=n; i++) idx.push_back(i);
    
    

    comps=n;
    ans=0;
    while (m--){
        cin>>a>> b;
        uni(a,b);
        cout << comps<< " "<< ans<< endl;
    }

}           