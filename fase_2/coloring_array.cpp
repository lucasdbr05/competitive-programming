#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define _ ios::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr)


int main(){
    int t; cin >> t;
    while (t--){
        int n, e=0, o=0; cin>> n;
        bool y=false;
        vector<int> v(n);
        for (int i=0; i<n; i++){
            cin>> v[i];
            if (v[i]%2) o++;
            else e++; 
        }

        if (!(e%2) && !(o%2)) y= true;
        if ((e%2) && (o%2)) { 
           y=false;
        }
        if ((e%2) && !(o%2)) y= true;
        if (!(e%2) && (o%2)) y= false;

        if (y){
            cout << "YES"<< endl;
        } else{
            cout << "NO"<< endl;
        }
    }
}