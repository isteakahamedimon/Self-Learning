#include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     std::vector<std::vector<int>> zeroSum(std::vector<int> nums) {
// 
// 
//     }
// };

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>>ans;
    std::sort(nums.begin(), nums.end());

    for(size_t i=0; i<nums.size(); i++) {
        int target = -nums[i];
        int j = i+1, k = nums.size()-1;
        
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        while(j<k) {
            if(target == nums[j]+nums[k]) {
                // if(nums[j] == nums[j+1] && nums[k] == nums[k-1])
                //     continue;
                ans.push_back({nums[i], nums[j], nums[k]});
                std::cout << j << "     " << k << std::endl;
                j++; k--;
                while(j<k && nums[j] == nums[k]) {
                    j++;
                }
            } else if(target < nums[j]+nums[k]) {
                k--;
            } else {
                j++;
            }
        }
    }

    return ans;
}

int main()
{
    std::vector<int> nums = {1,2,0,1,0,0,0,0};
    std::vector<std::vector<int>>ans;

    ans = threeSum(nums);
    
    return 0;
}
