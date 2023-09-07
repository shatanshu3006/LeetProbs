//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int n1=str1.length();
        int n2=str2.length();
        if(n2>n1){
            return "";
        }
        int i=0,j=0,k=0;
        int start=0,res=INT_MAX;
        while(j<n1 && k<n2){
            if(str1[j]==str2[k]){
                k++;
            }
            if(k==n2){
                i=j;
                k=n2-1;
                while(i>=0 && k>=0){
                    if(str1[i]==str2[k]){
                        k--;
                    }
                    i--;
                }
                i++;
                if(j-i+1 < res){
                    res=j-i+1;
                    start=i;
                }
                k=0;
                j=i+1;
            }
            j++;
        }
        if(res==INT_MAX){
            return "";
        }
        else{
            return str1.substr(start,res);
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends