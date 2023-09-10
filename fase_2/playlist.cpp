#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair <int, int> ii;
typedef long long int ll;
const int MAX= 1e5+5;
const int INF= 0x3f3f3f3f;
int n;
vector<int> v;
map<int, int> mp;

int main(){
    int n; cin >> n;
    for (int i=0;i<n;i++){
        int x; cin >> x;
        v.push_back(x);
        mp[x]=-1;
    }
    int l=0;
    int ans=0;
    for (int r=0; r<n; r++){
        if (mp[v[r]]>=l){
            l= mp[v[r]]+1;
        }
        mp[v[r]]=r;
        ans=max(ans, r-l+1);
    }

    cout << ans << endl;




}