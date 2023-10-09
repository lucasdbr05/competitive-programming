#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

const int MAX=1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
int factorial[MAX], chr[30];

int fexp(int b, int e){
    if (e==0) return 1;

    int ans = fexp(b, e/2);
    if(e%2) return (((ans*ans)%MOD)*b)%MOD;
    else return (ans*ans)%MOD;
}

int binomial(int n, int k) {
    return (factorial[n]*(fexp(factorial[k], MOD-2) * fexp(factorial[n - k], MOD-2) % MOD)) % MOD;
}



int32_t main(){
    factorial[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        factorial[i] = (factorial[i - 1] * i )% MOD;
    }
    memset(chr, 0, sizeof chr);
    string s; cin >> s;
    int n= s.size();
    for (int i=0; i<n; i++){
        chr[s[i]-'a']++;
    }

    int ans=1;
    // for (int i=0; i<26; i++) cout << chr[i]<< " ";
    for (int i=0; i<26; i++){
        if (chr[i]==0) continue;
        ans = (ans *binomial(n, chr[i]))%MOD;
        n-= chr[i];
    }
    
    cout << ans << endl;
    

   

}
