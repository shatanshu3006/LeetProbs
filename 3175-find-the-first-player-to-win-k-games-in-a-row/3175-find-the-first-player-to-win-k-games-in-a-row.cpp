class Solution {
public:
    int findWinningPlayer(vector<int>& s, int k) {
        int n=s.size();
        deque<int>dq;
        for(int i=1;i<n;i++){
            dq.push_back(i);
        }
        int z=k,ele=0,w=0;
        while(true){
            int num=dq.front();
            dq.pop_front();
            if(s[num]<s[ele]){
                w++;
                dq.push_back(num);
            }
            else{
                w=1;
                dq.push_back(ele);
                ele=num;
            }
            if(w==k || w>=n-1){
                return ele;
            }
        }
        return 1;
    }
};