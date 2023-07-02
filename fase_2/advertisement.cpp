#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int x;
    vector<lli> v;
    cin >> x;
    for (int i=0; i<x; i++) {
        lli n;
        cin>> n;
        v.push_back(n);
    }
    v.push_back(0);
    stack<lli> st;
    int i =0;
    lli area = 0;
    while (i<=x){
        if (st.empty() || v[st.top()]< v[i]){
            st.push(i);
            i++;
        } else{
            lli top = st.top();
            st.pop();
            lli w;
            w = !st.empty()? i-st.top()-1: i;
            area = max(area, v[top]*w);
        }
    }
    cout << area << endl;
}


/*
int main(){
    int n;
    cin >>n;

    vector<int> v(n,0), res(n,0), esq(n,0), dir(n,0);
    for (int i= 0; i<n; i++){
        cin>>v[i];
    }

    stack<pair<int, int>> st;
    for (int i=0; i<n; i++){
        while (st.size() && (st.top()).first>=v[i]) {
            st.pop();
        }
        if (st.size() > 0){
            esq[i]= (st.top()).second;
        }
        st.push({v[i], i+1});
    }

    int ans= 0;
    for (int i=0; i<n; i++){
        int l = esq[i]+1;
        int r = dir[i]-1;

        int val = (r-l+1)*v[i];
        ans = max(ans, val);
    }
    cout<<ans<<endl;
}

*/
/*
x = int(input())
 
arr = list(map(int, input().split()))
 
stack = []
 
area =0
i = 0
 
arr.append(0)
 
while i <= x:
    #print(stack, i, area,sep= "       ")
    if not stack or arr[stack[-1]]<arr[i]:
        stack.append(i)
        i+=1
    else:
        top= stack.pop()
        w = i-stack[-1]-1 if stack else i
        area = max(area, arr[top]*w)
print(area)

*/