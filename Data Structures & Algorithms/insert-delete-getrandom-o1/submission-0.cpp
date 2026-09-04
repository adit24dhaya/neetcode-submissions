class RandomizedSet {
private:
    unordered_map<int,int> mp;
    vector<int> nums; 
public:
    RandomizedSet() {
    
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
        {
            return false;
        }
        int indx = nums.size();
        nums.push_back(val);
        mp[val] = indx;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
        {
            return false;
        }
        // get the index from map and last element from nums
        // we swap the last element with the given value and pop from the end
        int indx = mp[val];
        int last = nums.back();
        nums[indx] = last;
        mp[last] = indx;
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int indx = rand() % nums.size();
        return nums[indx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */