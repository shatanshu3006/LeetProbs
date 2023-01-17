#include <iostream>
using namespace std;
int f(int a,int b,int c,int n ){
    if(n==1){
        return a;
    }
    if(n==2){
        return b;
    }
    if(n==3){
        return c;
    }
    return f(a,b,c,n-1)+f(a,b,c,n-2)+f(a,b,c,n-3);
}
int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int a,b,c,n;cin>>a>>b>>c>>n;
	    cout<<f(a,b,c,n)<<endl;
	}
	return 0;
}