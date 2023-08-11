#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int MAX= 1e6;
int n, l, ans=0;
vector<int> ones;
int nums[MAX];
// int lsa_size[100010][100010];
int sub_arr[MAX];

void dp(){
    for (int i=n; i>0;i--){
        for (int j=i+1; j<=n; j++){
            if (abs(nums[i]-nums[j])==1){
                sub_arr[i]= max(sub_arr[i],1+sub_arr[j]);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    memset(nums, 0,sizeof(nums));
   
    for (int i=1; i<=n; i++){
        cin >> nums[i];
        if (nums[i]==1) {
            ones.push_back(i);
        }
    }
    dp();

    // for(int i=1; i<=n;i++) {cout << sub_arr[i] << " " ;}
    // cout << endl;
    if(!ones.empty()){
        for (int i=0; i<ones.size(); i++){
            for(int j= i+1; j<ones.size(); j++){
                // cout<< ones[i]<< " "<< ones[j]<< " "<< sub_arr[ones[i]-1]-sub_arr[ones[j]-1]<< endl;
                ans=max(ans, sub_arr[ones[i]]-sub_arr[ones[j]]);
            }
        }
            ans++;
        }
    cout<< ans << endl;

}









