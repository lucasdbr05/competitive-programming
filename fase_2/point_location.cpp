#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const ll INF= 0x3f3f3f3f;
int t;
ll a, b, c, d, e, f, ans;

int main(){
    cin >> t;
    _ios_
    while(t--){
        cin >> a>> b>> c>> d>> e>> f;
        ans = (a*d + c*f + e*b)-( a*f+ e*d + c*b);

        if (ans==0){
            cout << "TOUCH"<< endl;
        }else if (ans>0){
            cout << "LEFT"<< endl;
        }else if(ans<0){
            cout << "RIGHT" << endl;
        }
    }

}