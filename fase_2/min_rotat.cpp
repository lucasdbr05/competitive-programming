#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 1e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

string booth(string s){
    int n = s.size();
    int  k =0;
    s+= s;
    vector<int> rt(2*n+1, -1);
    for(int i=1; i<2*n; i++){
        char curr = s[i];
        int j = rt[i-k-1];

        while(j!=-1 and curr!= s[j+k+1]){
            if(curr< s[j+k+1]){
                k= i-j-1;
            }
            j = rt[i];
        }

        if(curr!=s[j+k+1]){
            if(curr<s[j+k+1]){
                k=i;
            }
            rt[i-k]=-1;
        }else{
            rt[i-k]= j+1;
        }


    }


    string ret;
    for(int i=k; i<k+n; i++){
        ret.push_back(s[i]);
    }

    return ret;
}

void fluminense(){
    string s; cin >> s;

    cout << booth(s)<< endl; 
}

int32_t main(){
    sws;

    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}