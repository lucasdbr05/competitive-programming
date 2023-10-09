#include <bits/stdc++.h>
using namespace std;
#define sws ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'
#define int long long int
const int MAX=2e5+10;
int n;
int v[MAX], BIT[MAX];

// void add(int x, int val){
//     x++;
    
// }

void update(int x, int val){
    while(x<=n){
        BIT[x]+= val;
        x+= (x&-x);
    }
    v[x]=val;
}

int32_t main(){
    int m;cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> v[i];
        update(i, v[i]);
    }

    while(m--){
    }

    

}