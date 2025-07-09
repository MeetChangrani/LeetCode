#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};  
                }
            }
        }
        return {};  
    }
};

// int main() {
//     vector<int> nums = {1, 2, 3, 4};
//     int target = 6;

//     Solution s1;
//     vector<int> result = s1.twoSum(nums, target);

//     if (!result.empty()) {
//         cout << "Indices: " << result[0] << " and " << result[1] << endl;
//     } else {
//         cout << "No two numbers add up to target." << endl;
//     }

//     return 0;
// }
