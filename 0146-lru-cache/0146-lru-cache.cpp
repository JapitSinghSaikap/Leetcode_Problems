class LRUCache {
public:
        //yeh 
       unordered_map<int, pair<int, list<int>::iterator>> cache;
        list<int> order;
        int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        //if key not found
        if (cache.find(key) == cache.end()) return -1;
        //uska itr remove krta pehle from the orders list
        order.erase(cache[key].second);
        //wapis dala usko order mein taki woh mru bnjaye
        order.push_back(key);
        //updating the iterator in the map to the new position --order.end(); is iterator to last element
        cache[key].second = --order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        //if key exists update krdo usko
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        } else if (cache.size() == capacity) {
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        // Store in map: {value, iterator to back}
        cache[key] = {value, --order.end()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */