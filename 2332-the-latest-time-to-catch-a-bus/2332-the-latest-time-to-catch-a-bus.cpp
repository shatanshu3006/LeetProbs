class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int capacity) {
        int n=b.size(),m=p.size();
        int j=0,ans;
        set<int>st;
        sort(b.begin(),b.end());
        sort(p.begin(),p.end());

        for(int i=0;i<n;i++){
            int c=0;
            while(j<m && c<capacity && p[j]<=b[i]){
                if(st.find(p[j]-1)==st.end()){  //not found in set
                    ans=p[j]-1;

                }
                st.insert(p[j]);
                c++;
                j++;
            }
            //onelast possibility is if seat is still there and we dont have anyone arriving in the end of time of the current bus then we can be that person to come latest
            if(c<capacity && st.find(b[i])==st.end()){ //capacity is there and there is no one to come on the last moment 
                ans=b[i];
            }
        }
        return ans;
    }
};