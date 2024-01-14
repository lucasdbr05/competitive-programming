#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back 
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

string manachar(string s){
    int n=s.size();
    vector<int> lps(n+1, 0);
    int c = 0, r=0, aux;
    for(int i=0; i<n; i++){
        aux = 2*c-i;
        if(r>i){
            lps[i]= min(r-i, lps[aux]);
        }else{
            lps[i]=0;
        }

        while ((i + 1 + lps[i]<n and i - 1 - lps[i]>=0)and (s[i + 1 + lps[i]] == s[i - 1 - lps[i]])){
            lps[i] += 1;
        }

        if(i+lps[i]>r){
            c=i;
            r =i+lps[i]; 
        }


    }
    int rg = -1, idx = -1;
    for(int i=0; i<n; i++){
        if(rg< lps[i]){
            idx = i;
            rg = lps[i];
        }   
    }
    string ret;
    for(int i = idx - rg; i<idx+rg; i++){
        if(s[i]!='#')ret.pb(s[i]);
    }

    return ret;

}


void fluminense(){
    string s, ns = "#"; cin >> s;
    for(int i=0; i<s.size(); i++){
        ns.pb(s[i]);
        ns.pb('#');
    }
    cout << manachar(ns)<< endl;
    
}

int32_t main(){
    sws;

    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}