#include<iostream>

class Solution {
public:

    std::vector<std::vector<int>> ans;
    std::vector<int> ara;
    std::unordered_map<int, int> freq;
    std::unordered_map<int, int> track;
    
    void gp(std::vector<int>& nums) {
        if(ara.size() == nums.size()) {
            ans.push_back(ara);
            for(auto x : ara)
                std::cout << x << " ";
            std::cout << std::endl;

            return;
        }
        for(const auto& [key, count] : freq) {
            if(track[key] >= freq[key])
                continue;

            ara.push_back(key);
            track[key]++;
            gp(nums);
            ara.pop_back();
            track[key]--;
        }
    }

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        for(auto x : nums)
            freq[x]++;

        // 
        for(auto& [key, count] : freq) {
            track[key] = 0;
        }

        gp(nums);
        
        return ans;
    }
};

int main()
{
    Solution s;
    
    std::vector<int> nums = {3, 1, 2};
    
    std::vector<std::vector<int>> ans;
    ans = s.permuteUnique(nums);

    return 0;
}
