#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int

vector<int> Z(string s){
    int n = s.size();
    vector<int> z(n);
    int l = 0, r=0;

    for(int i=1; i<n; i++){
        z[i]= max((int)0, min(z[i-l], r-i+1));
        while(i+z[i]<n and s[z[i]]==s[i+z[i]]) {l=i; r=i+z[i]; z[i]++;}

    }

    return z;
}

int32_t main(){
    string s; cin >>s;
    vector<int> z = Z(s);
    // for (int i=0; i<z.size(); i++) cout << z[i]<< " ";
    // cout << endl; 
    for (int i=1; i<z.size(); i++){
        if(z[i]+i==z.size()) cout << i << " ";
    }
    cout << z.size() << endl;
}