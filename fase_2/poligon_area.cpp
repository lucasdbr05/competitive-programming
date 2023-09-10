#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll INF= 0x3f3f3f3f;
int x;
ll a, b, ans=0;
vector<ii> v;


int main(){
    cin>>x;
    for(int i=0;i<x; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back(v.front());

    for(int i=0; i<x; i++){
        ans += (v[i].first*v[i+1].second)-(v[i+1].first*v[i].second);
    }
    cout << abs(ans) << endl;
}