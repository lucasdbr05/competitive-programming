#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
vector<string> s;


bool cmp(string a, string b){
    if(a.size()!=b.size()) return a.size()<b.size();
    for (int i=0; i<a.size(); i++){
        if(a[i]!=b[i]) return a[i]<b[i];
    }
    return true;
}

bool comp(string a, string b){
    if(a.size()!=b.size()) return false;
    for (int i=0; i<a.size(); i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}

void solve(){

    int n; cin >> n;
    string str; cin >> str;

    for(int i=0; i<26; i++){
        bool fnd = false;
        string a;
        a.push_back('a'+i);
        for (int j=0; j<n; j++){
            if(str[j]==a[0]){
                fnd=true; break; 
            }
        }
        if(!fnd){
            cout << a << endl;
            return;
        }
    }
    for(int i=0; i<26; i++){
        string a;
        a.push_back('a'+i);
        for (int j = 0; j<26; j++){
        bool fnd = false;
            string b=a;
            b.push_back('a'+j);
            s.push_back(b);

            for (int k=0; k<n-1; k++){
                if(str[k]==b[0]and str[k+1]==b[1]){
                    fnd=true; break;
                }
            }
            if(!fnd){
                cout << b << endl;
                return;
            }
        }
        
    }
    for(int i=0; i<26; i++){
        string a;
        a.push_back('a'+i);
        for (int j = 0; j<26; j++){
            string b=a;
            b.push_back('a'+j);
            for (int k = 0; k<26; k++){
            bool fnd= false;
                string c=b;
                c.push_back('a'+k);
                 for (int l=0; l<n-2; l++){
                    if(str[l]==c[0]and str[l+1]==c[1] and str[l+2]==c[2]){
                        fnd=true; break;
                    }
                    }
                    if(!fnd){
                        cout << c << endl;
                        return;
                    }
                
            }
        }
    }
    string ans;
    

    // cout << " --- "<< endl;
    // for(auto x: aux) cout << x << endl;
    // cout << " --- "<< endl;


    // cout << ans << endl;
}

int32_t main(){
    sws;
    int t; cin >> t;

    while(t--) solve();
}
