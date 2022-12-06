class RandomizedSet {
public:
    unordered_map<int,int> mp;
    RandomizedSet() {
       mp.clear(); 
    }
    
    bool insert(int val) {
        if(mp.count(val) == 0){
            mp[val]=1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.count(val) == 1){
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int index=(rand())%(mp.size());
        auto it=mp.begin();
        while(index--){
            it++;
        }
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
