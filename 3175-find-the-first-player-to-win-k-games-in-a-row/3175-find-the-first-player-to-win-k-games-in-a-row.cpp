class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n=skills.size();
        if(k==1){
            if(skills[0]>skills[1]){
                return 0;
            }
            else{
                return 1;
            }
        }

        deque<pair<int,int>>dq;
        int maxi=INT_MIN,maxInd=-1,count=1;

//pushingn into the queue and marking the highest val with maxInd
        for(int i=0;i<n;i++){
            dq.push_back({skills[i],i});

            if(maxi<skills[i]){
                maxi=skills[i];
                maxInd=i;
            }
        }
        if(n<k){
            return maxInd;
        }
        maxi=INT_MIN,maxInd=-1;

        int temp=n;
        while(temp--){
            auto firstVal=dq.front();dq.pop_front();
            auto secondVal=dq.front();dq.pop_front();

            if(firstVal.first>secondVal.first){
                dq.push_front(firstVal);
                dq.push_back(secondVal);

                if(firstVal.first==maxi){
                    count++;
                    if(count==k){
                        return firstVal.second;
                    }

                }
                else{
                    count=1;
                }
                maxi=firstVal.first;
            }
            else{
                dq.push_front(secondVal);
                dq.push_back(firstVal);

                if(secondVal.first==maxi){
                    count++;
                    if(count==k){
                        return secondVal.second;
                    }
                }
                else{
                    count=1;
                }

                maxi=secondVal.first;
            }
        }

        return dq.front().second;


    }
};