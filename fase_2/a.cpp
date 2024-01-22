#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define vii vector<vector<int>>
#define vi vector<int>
#define pii pair<int, int>
#define iii array<int, 3>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b, a%b);
}
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}




void fluminense(){
    int n; cin >> n;
    vector<int> v(n+1);
    vector<int> mp(n+1), l(n+1), r(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
       
    }
    mp[1]=2; mp[n]= n-1;
    for(int i=2; i<n; i++){
        if(abs(v[i]-v[i-1])<abs(v[i]-v[i+1]))mp[i]= i-1;
        else mp[i]= i+1;
    }
    for(int i=2; i<=n; i++){
        if(mp[i-1]<i)r[i] = (v[i]-v[i-1])+r[i-1];
        else r[i] = 1+r[i-1];
    }
    for(int i=n-1; i>0; i--){
        if(mp[i+1]>i)l[i] = (v[i+1]-v[i])+l[i+1];
        else l[i]= 1+l[i+1];
    }
    int m; cin >> m; 
    for(int i=1; i<=n; i++)cout << mp[i]<<  ' ';
    cout << endl;
    for(int i=1; i<=n; i++){
        cout << l[i]<< " "<< r[i]<< endl;
    }
    while(m--){
        int x, y; cin >> x >> y;
        if(x<y){
            cout << r[y]- r[x]<< endl;
        }else{
            cout << l[y] - l[x]<< endl;
        }
        

    }

}   

int32_t main(){
    sws;    
    int T=1;
    cin >> T;
    while(T--)fluminense(); 
    
}