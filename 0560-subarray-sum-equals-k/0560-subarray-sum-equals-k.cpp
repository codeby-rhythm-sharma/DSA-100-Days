#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1; // Base case for sub-arrays starting at index 0
        
        int current_sum = 0;
        int count = 0;
        
        for (int num : nums) {
            current_sum += num;
            
            // Check if there is a prefix sum that yields sum k
            if (prefix_counts.count(current_sum - k)) {
                count += prefix_counts[current_sum - k];
            }
            
            prefix_counts[current_sum]++;
        }
        
        return count;
    }
};