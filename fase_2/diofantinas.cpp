#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define tiii tuple<int,int, int>
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}

int euc_ext(int a, int b, int& x, int& y){
    if(b==0){
        x=1;b=0;
        return a;
    }
    int x1, y1;
    g = euclidian(b, a%b, x1, y1);
    x= y1;
    y = x1-(a/b)*y1;
    return g;    
}


int32_t main(){
    sws;
    int a, b; cin >> a >> b;
    int x, y, mdc;
    mdc = euclidian(a, b,x,y);  
}