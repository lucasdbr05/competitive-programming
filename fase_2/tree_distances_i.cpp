#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int n, a, b;
const int MAX=2e5+10;
vector<int> tree[MAX];



int32_t main(){
    cin >> n;
    for(int i=1;i<n; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    
}