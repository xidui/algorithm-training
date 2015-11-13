// 168ms
class LRUCache{
public:
    list<pair<int, int> > li;
    unordered_map<int, list<pair<int, int> >::iterator> cache;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        unordered_map<int, list<pair<int, int> >::iterator>::iterator it = cache.find(key);
        if (it == cache.end()) return -1;
        li.push_front(make_pair(key, it->second->second));
        li.erase(it->second);
        it->second = li.begin();
        return cache[key]->second;
    }

    void set(int key, int value) {
        unordered_map<int, list<pair<int, int> >::iterator>::iterator it = cache.find(key);
        if (it == cache.end()){
            li.push_front(make_pair(key, value));
            cache[key] = li.begin();

            if (li.size() > capacity){
                cache.erase(li.back().first);
                li.pop_back();
            }
        }else{
            li.push_front(make_pair(key, value));
            li.erase(it->second);
            it->second = li.begin();
        }
    }
};