#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(0);
const int MAX =1e7+10;
int k, n, a, b, l, r;
bool ans;
int crivo[MAX];

int32_t  main(){
    crivo[1]= 1;
    for (int i=2; i<=MAX; i++){
        if (!crivo[i]){
            for (int j=i; j<=MAX; j+=i){
                crivo[j]= i;
            }
        }
    }

    cin >> k;
    while(k--){
        cin >> a >> b;
        ans = false;
        int aux = a;
        while (aux <=b){
            l = crivo[aux];
            r= (aux-crivo[aux]);
            if(a<=(l+r) and (l+r)<=b and gcd(l,r)!=1){
                ans =true;
                break;
            }
            aux ++;
        }
        if (ans) cout << l << " "<< r << endl;
        else cout << -1 << endl;


    }
}