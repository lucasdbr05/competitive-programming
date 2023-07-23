#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair <lli, lli> ii;

#define _ ios::sync_with_stdio(false);cin.tie(0);



int bs(vector<int> &v, int num, int h){
    int l=0, r=h;
    int m;
    while (l<r){
        m=(l+r)/2;
        if (v[m]>num) r = m;
        else l = m+1;

    }
    return l;

}

int main(){_ 
    int n;
    cin >> n;
    int ans = 0;
    vector<int>v;
    for (int i =0; i< n; ++i){
        int x; 
        cin >> x; 
        int aux = bs(v,x, ans);
        if (aux==ans){
            v.push_back(x);
            ans ++;
        }else{
            v[aux]= x;
        }  
    }

    cout << ans << endl;
}