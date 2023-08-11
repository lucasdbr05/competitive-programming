#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ios_ ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int, int> ii;
typedef long long int ll;
const int INF= 0x3f3f3f3f;
const int MAX= 1e6+10;
int t,n, p; 
ll aux, out=0;
ll v[MAX];


int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> v(n+1);
        for (int i=1; i<=n;i++) cin >>v[i];
        p=1; aux = v[p]; out =0;
        while(p<=n){
            if (aux>=0){
                if (v[p]<0) {out += aux; aux=v[p]; }
                else if (v[p]>aux) aux=v[p];
            } else{
                if (v[p]>=0) {out += aux; aux=v[p];}
                else if (v[p]>aux) aux=v[p];
            }
            p++;
        }
        out += aux;
        cout << out << endl;

    }
}
