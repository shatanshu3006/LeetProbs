class RandomizedCollection {
public:
unordered_map<int,priority_queue<int>>mp;
vector<int>v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ret=false;
        if(mp.count(val)==0){
            ret=true;
        }
        v.push_back(val);
        mp[val].push(v.size()-1);
        return ret;
    }
    
    bool remove(int val) {
        if(mp.count(val)==1){
            int i=mp[val].top();
            int s=v[i]=v[v.size()-1];

            mp[s].pop();
            mp[s].push(i);

            mp[val].pop();
            v.pop_back();

            if(mp[val].size()==0)mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int r=rand()%v.size();
        return v[r];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */