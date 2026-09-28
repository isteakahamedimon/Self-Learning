#include<iostream>

class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> ara;
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        ans.push_back(ara);

        int lastPopped = -100;

        int len = nums.size();
        for(int i=1; i<=len; i++) {
            backtracking(nums, i, 0, lastPopped);
        }

        return ans;
    }


private:
    void backtracking(std::vector<int>& nums, int len, int indx, int lastPopped) {

        if(ara.size() == len) {
            ans.push_back(ara);

            for(auto& x : ara)
                std::cout << x << " ";
            std::cout << "\n";

            return;
        }

        for(int i=indx; i<nums.size(); i++) {
            
            if(nums[i] == lastPopped)
                continue;

            ara.push_back(nums[i]);
            backtracking(nums, len, i+1, lastPopped);
            lastPopped = ara[ara.size()-1];
            ara.pop_back();
        }
    }
};


int main()
{
    Solution s;

    std::vector<std::vector<int>> ans;
    std::vector<int> nums = {1, 1, 2};

    ans = s.subsets2(nums);
    std::cout << "Size: " << ans.size() << "\n";

    return 0;
}
