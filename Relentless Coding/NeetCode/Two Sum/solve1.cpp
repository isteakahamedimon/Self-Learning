#include<iostream>
#include<unordered_set>

std::vector<int> twoSum(std::vector<int>& nums, int target) 
{
    std::unordered_map<int, int> mp;
    std::vector<int> ans;

    for(unsigned long i=0; i<nums.size(); i++) {
        auto it = mp.find(nums[i]);
        if(it != mp.end()) {
            ans.push_back(i);
            ans.push_back(it->second);
            // return ans;
            break;
        }
        mp[target - nums[i]] = i;
    }

    return ans;
}

int main()
{
    std::vector<int> nums = {7, 6, 5, 4};
    std::vector<int> ans = twoSum(nums, 10);

    for(int x : ans)
        std::cout << x << std::endl;

    return 0;
}
