//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
int binarysearch(vector<vector<int> > &arr, int i){
    int low=0;int high=arr[0].size()-1;
    int fi1=arr[0].size(); //this denotes the first index of one that we finally find as 0 can also be the answer
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[i][mid]==1){
            fi1=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    int count=arr[0].size()-fi1;
    return count;
    
}
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    //each row of the matrix is sorted!!!!!!!!!
	    int omax=0; //overall maximum number if 1s
	    int r=-1; //for the identification of which row contains that
	    for(int i=0;i<n;i++){
	        int coir=binarysearch(arr,i);   //this gives the count of 1 in ith row
	        if(coir>omax){
	            omax=coir;
	            r=i;
	        }
	        
	    }
	    return r;
	    
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends