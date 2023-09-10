#include <bits/stdc++.h>
using namespace std;
 
 
 
bool gray(int num, int i){
    return (num&1<<i)>0;
}
 
int main() {
	int n;cin >> n;
	
	for(int i=0;i<(1<<n);i++){
	    cout<<gray(i,n-1);
	    
	    for(int p=n-2;p>=0;p--){
	        cout<<(gray(i,p)^gray(i,p+1));
	    }
	    cout << endl;
	}
	return 0;
}