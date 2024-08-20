class NumberContainers {
public:
    unordered_map<int,set<int>>numToConts;
    unordered_map<int,int>contToNum;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(contToNum.find(index)==contToNum.end()){
            numToConts[number].insert(index);
            contToNum[index]=number;
        }
        else{
            numToConts[contToNum[index]].erase(index);
            numToConts[number].insert(index);
            contToNum[index]=number;
        }
    }
    
    int find(int number) {
        if(numToConts.find(number)!=numToConts.end() && numToConts[number].size()!=0){
            return *(numToConts[number].begin());
            
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */