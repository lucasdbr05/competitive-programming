#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll INF= 0x3f3f3f3f;
int v, n, m, x, y;
ll out =INF;
ll price[1005];
ll pages[1005];
ii books[1005];
ll memo[100005];
bool vis[1005];
bool val=false;

int main(){
    _ios_  
    cin >> n >> x;
    for (int i=1;i<=n; i++) cin >>price[i];
    for (int i=1;i<=n; i++) cin >>pages[i];
    for (int i=1;i<=n; i++) books[i]={pages[i], price[i]};
    

    for (int i=1; i<=n; i++){
        ii curr = books[i];
        for(int j=x; j>=curr.second; j--){
            memo[j]= max(memo[j], memo[j-curr.second]+curr.first);
            
        }         
    }

    ll ans = memo[x];

    cout << ans<< endl;
}