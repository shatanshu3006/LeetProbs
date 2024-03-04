class Solution {
public:
//We can approach this problem using a greedy strategy. We sort the tokens first, then we maintain two pointers: one at the start of the sorted array and one at the end. We start with the maximum possible score and gradually adjust it based on the available power and the tokens. If we have enough power to buy a token at the current start pointer position, we do so and increase the score. Otherwise, if our score is positive, we trade our least valuable token for power. We continue this process until we exhaust all possibilities.
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1;
        int score=0;
        int res=0;
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                res=max(res,score);
                power-=tokens[i];
                i++;
            }
            else if(score>0){
                power+=tokens[j];
                score--;
                j--;
            }
            else{
                i++;
            }
        }
        return res;
    }
};