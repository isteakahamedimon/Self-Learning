#include<iostream>

class Solution {
public:
    std::vector<std::vector<int>> ans;
    std::vector<int> ara;
    int len;
    int sum = 0;
    int lastPopped = -1;

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        len = candidates.size();
        std::sort(candidates.begin(), candidates.end());

        backtracking(candidates, target, 0);

        return ans;
    }
private:
    void backtracking(std::vector<int>& candidates, int target, int indx) {
        if(sum == target) {
            ans.push_back(ara);

//            std::cout << "A way: ";
            for(auto& x : ara)
                std::cout << x << " ";
            std::cout << std::endl;

            return;
        }
        if(sum > target)
            return;

        for(int i=indx; i<len; i++) {
//            std::cout << "ara.size() : " << ara.size() << "\n";
            if(candidates[i] == lastPopped)
                continue;

            sum += candidates[i];
            ara.push_back(candidates[i]);
            backtracking(candidates, target, i+1);

//            if(sum > target) break;

            sum -= candidates[i];
            lastPopped = ara[ara.size() - 1];
            ara.pop_back();

//            std::cout << "After each pop_back: \n";
//            for(auto& x : ara)
//                std::cout << x << " ";
//            std::cout << "\n";
        }
    }
};

int main()
{
    Solution s;
    
    std::vector<int> candidates = {10,1,2,7,6,1,5};

    int target = 8;
    std::vector<std::vector<int>> ans;
    ans = s.combinationSum2(candidates, target);

    return 0;
}
