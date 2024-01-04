// class Solution {
// public:
//     Solution(int m, int n) {
        
//     }
    
//     vector<int> flip() {
        
//     }
    
//     void reset() {
        
//     }
// };

// /**
//  * Your Solution object will be instantiated and called as such:
//  * Solution* obj = new Solution(m, n);
//  * vector<int> param_1 = obj->flip();
//  * obj->reset();
//  */


#include <vector>
#include <unordered_map>
#include <random>

class Solution {
    unordered_map<int, int> map;
    int zeros;
    random_device rd;
    mt19937 rand_gen;
    int n, m;

public:
    Solution(int m, int n) : rand_gen(rd()), n(n), m(m) {
        zeros = m * n;
    }
    
    vector<int> flip() {
        uniform_int_distribution<int> dist(0, zeros - 1);
        int r = dist(rand_gen);
        int actual = map.find(r) != map.end() ? map[r] : r;
        vector<int> ret = {actual / n, actual % n};

        map[r] = map.find(zeros - 1) != map.end() ? map[zeros - 1] : zeros - 1;
        zeros--;

        return ret;
    }
    
    void reset() {
        map.clear();
        zeros = m * n;
    }
};

/* Usage:
Solution* obj = new Solution(m, n);
std::vector<int> param_1 = obj->flip();
obj->reset();
*/
