#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs = 0;
        unordered_map<int, int> d;
        unordered_map<int, int>::iterator iter;
        for(auto n:nums){
            if((iter = d.find(n)) == d.end()){
                d[n] = 1;
            }
            else{
                pairs += iter->second;
                d[n] += 1;
            }
        }
        return pairs;
    }
};