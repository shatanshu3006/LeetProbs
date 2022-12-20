//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            int n=A.length();
            int m=B.length();
            set<char> s1;
            set<char> s2;
            for(int i=0;i<n;i++){
                s1.insert(A[i]);
            }
            for(int i=0;i<m;i++){
                s2.insert(B[i]);
            }
            vector<char> v;
            for(auto c:s1){
                v.push_back(c);
            }
            for(auto c:s2){
                v.push_back(c);
            }
            map<char,int> mp;
            for(int i=0;i<v.size();i++){
                mp[v[i]]++;
            }
            string ans="";
            for(auto x:mp){
                if(x.second==1){
                    ans+=x.first;
                }
            }
            string ans1="-1";
            if(ans.length()>0){
                return ans;
            }
            else{
                return ans1;
            }
            
            
            
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends