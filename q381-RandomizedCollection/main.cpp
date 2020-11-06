#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
    unordered_map<int, unordered_set<int> > mapIndex;   // val -> set(index)
    unordered_map<int, int> mapValue;   // index -> val
    int total;

public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        total = 0;
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        unordered_set<int> &s = mapIndex[val];
        bool bExist = s.empty();
        s.insert(total);
        mapValue[total++] = val;
        return bExist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        unordered_set<int> &s = mapIndex[val];
        if (s.empty()) {
            return false;
        }

        int delIndex = *s.begin();
        s.erase(delIndex);
        total--;
        int v = mapValue[total];
        mapValue[delIndex] = v;
        mapValue.erase(total);
        mapIndex[v].erase(total);
        mapIndex[v].insert(delIndex);
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand() % total;
        return mapValue[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
