class LRUCache {
public:
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> cache;
    int cap;

    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
    if(mp.find(key)== mp.end())
        {
         return -1;
        }
    auto it = mp[key];
    int value = it->second;

    cache.erase(it);
    cache.push_front({key,value});
    
    mp[key]= cache.begin();
    return value;
    }
    
    void put(int key, int value) {
        if (mp.find(key)!= mp.end())
        {
            cache.erase(mp[key]);
        }
        cache.push_front({key,value});
        mp[key] = cache.begin();

        if(cache.size()>cap)
        {
            int lruKey = cache.back().first;
           
            cache.pop_back();
            mp.erase(lruKey);
        }
    }
};

/*
search entire list for key

if found
    move it to the most recently used position

if insterting and capacity is full
    remove the least recently used element
*/

/*
for optimization i would use 
a hash map and a doubly linked list

front = most recently used
back = least recently used
*/