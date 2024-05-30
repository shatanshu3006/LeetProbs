class Solution {
public:
void recursive(int& head,int& step,bool& left,int& n){
    if(n==1)return;

    if(n%2==1){
        head+=step;
    }
    else{
        if(left==true){
            head+=step;
        }
    }
    step*=2;
    n/=2;
    left=!left;
    recursive(head,step,left,n);
}
    int lastRemaining(int n) {
        int step=1; //increments
        int head=1; //head of the set of n elements
        bool left=true;  //for telling right or left traversal
        recursive(head,step,left,n);
        return head;
    }
};