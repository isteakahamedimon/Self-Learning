#include<iostream>
#include<algorithm>

class Solution {
public:
    size_t len;
    std::vector<int> ara;
    std::vector<std::vector<int>> ans;
    int sum = 0;

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        len = candidates.size();
        std::sort(candidates.begin(), candidates.end());

        backtracking(candidates, 0, target);

        return ans;
    }

    void backtracking(std::vector<int>& candidates, int indx, int target) {
        if(sum == target) {

//            std::cout << "sum: " << sum << "    target: " << target << std::endl;
//            std::cout << "ara.size(): " << ara.size() << std::endl;

            for(int i=0; i<ara.size(); i++)
                std::cout << ara[i] << " ";
            std::cout << std::endl;

            ans.push_back(ara);
//            sum = 0;
            return;
        }
        if(sum > target) {
//            std::cout << "came here. sum: " << sum << std::endl;
//            for(auto x : ara)
//                std::cout << x << " ";
//            std::cout << std::endl;
            
            return;
        }

        for(int i=indx; i<len; i++) {
            sum += candidates[i];
            ara.push_back(candidates[i]);
            backtracking(candidates, i, target);

//            std::cout << "After return: ";
//            for(auto x : ara)
//                std::cout << x << " ";
//            std::cout << std::endl;

            sum -= candidates[i];
            ara.pop_back();
        }

    }
};

int main()
{
    Solution s;
    std::vector<int> candidates = {2, 3, 4, 5, 7};
    int target = 7;

    std::vector<std::vector<int>> ans;
    ans = s.combinationSum(candidates, target);

    return 0;
}
