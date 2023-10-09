#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
int n, k;
vector<int> primes;


int32_t main(){
    cin>> n >> k;
    for (int i=0; i<k;i++){
        int a; cin >> a;
        primes.push_back(a);
    }
    int ans = 0;
    for (int i=1; i<(1<<k); i++){
        int mask = i;
        int divs = 0;
        int aux = n;
        for (int j=0; j<k; j++){
            if(mask&(1<<j)){
                aux/=primes[j];
                divs++;
            }
        }
        // cout << aux<<" "<< divs << endl;
        ans += (divs%2)?aux: -aux;
    }

    cout << ans << endl;
}