#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
typedef long long int lli;
using namespace std;

int main(){
    int x; cin >> x;
    vector<lli> v(x);
    
    for (int i=0; i< x ;i++){ cin>>v[i];}
    
    lli m_sum = -inf;
    lli aux = -inf;
    for (auto n: v){
        if (aux<0){
            aux = n;
        } else {
            aux += n;
        }
        
        m_sum = max(m_sum, aux);
    }
    
    cout << m_sum << endl;
    return 0;
}
