#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair <int, int> ii;
typedef long long int ll;
const int MAX= 1e5+5;
const int INF= 0x3f3f3f3f;
int n, m;
int arr[MAX];
ii seg[4*MAX];

ii combina(ii a, ii b){
    if (a.first< b.first) return a;
    if (b.first< a.first) return b;
    return {a.first, a.second+b.second};
}

ii build(int p, int l, int r){
    if (l==r) return seg[p]={arr[l], 1};
    int m= (l+r)/2;
    return seg[p]=combina(build(2*p, l, m), build(2*p+1, m+1, r));

}

ii query(int a, int b, int p, int l, int r){
    if (b<l or r<a) return {INF,1};
    if (a<=l and r<=b) return seg[p];
    int m = (l+r)/2;
    return combina(query(a,b,2*p, l, m), query(a,b, 2*p+1,m+1, r));
}

ii update(int a, int b, int p, int l, int r){
    if (a<l or r<a) return seg[p];
    if (l==r) return seg[p]={b,1};
    int m = (l+r)/2;
    return seg[p]= combina(update(a,b,2*p, l, m), update(a,b, 2*p+1,m+1, r));
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    build(1,0,n-1);

    while (m--){
        int i,u,v; cin >> i >> u >> v;
        if (i==1){
            update(u,v,1,0,n-1);
        } else{
            ii num = query(u,v-1,1,0,n-1);
            cout << num.first<< " "<< num.second<< endl;
        }
    }
    exit(0);
}