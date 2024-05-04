class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //traversing using two pointers from left and right after sorting
        int boatCount = 0;
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        
        while(left <= right){
            int sum = people[left] + people[right];
            if(sum <= limit){
                boatCount++;
                left++;
                right--;
            }
            else{
                boatCount++;
                right--;
            }
        }
        return boatCount;
    }
};