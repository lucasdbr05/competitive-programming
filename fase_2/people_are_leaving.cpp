#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// #define int long long int
typedef pair <int, int> ii;

vector<int> id, sz;

int find(int x){
    return id[x]= (id[x]==x ? x: find(id[x]));
}

void uni(int p, int q){
    p = find(p); q=find(q);
    id[p]=q;
}

int main(){
    sws
    int n, m; cin >> n >> m;
    id = vector<int>(n+2);
    sz = vector<int>(n+2, 1);
    iota(id.begin(), id.end(), 0);
    while(m--){
        char c; cin >> c;
        int x; cin >> x;
        if (c=='-') uni(x, x+1);
        else {
            int aux = find(x);
            cout << (aux==n+1 ? -1: aux)<< endl;
        }
    }

    exit(0);
}