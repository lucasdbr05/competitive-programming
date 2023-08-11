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


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis(n, 1);
        int ans = 0;

        for(int i=n;i>=0;i--){
            for(int j=i+1; j<n; j++){
                if (nums[i]<nums[j]){
                    lis[i] = max(lis[i], lis[j]+1);
                }
            }
        }
        
        for(auto q: lis) ans = max(q, ans);
        return ans;
    }
};


int main(){
    return 0;
}