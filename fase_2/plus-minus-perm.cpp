#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
int t, k, a, b, x, y;
const int MAX = 2e6;
int crivo[MAX];

int32_t main(){
    crivo[1]= 1;
    for (int i=2; i<=MAX; i++){
        if (!crivo[i]){
            for (int j=i; j<=MAX; j+=i){
                crivo[j]++;
            }
        }
    }
    cin >> t;
    while(t--){
        cin>> k >> a >> b;
        int gst = (lcm(a,b)/a)-1;
        int lws = (lcm(a,b)/b)-1;

        x = (k+k-gst)/2;
        y = (1+lws)/2;

        cout << x - y<< endl;
    }
}