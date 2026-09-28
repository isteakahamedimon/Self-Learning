#include<iostream>
#include<vector>

class Solution {

public:
    std::vector<std::vector<int>> ans;
    std::vector<int> ara;

//    k = len
//    finding out all the combinations of [1...m]
    void backtracking(int n, size_t k, int m) {
        if(ara.size() == k) {
            ans.push_back(ara);
            for(const auto& x : ara)
                std::cout << x << " ";
            std::cout << std::endl;

            return;
        }

        for(int i=n; i<=m; i++) {
            ara.push_back(i);
            backtracking(i+1, k, m);
            ara.pop_back();
        }
    }

    std::vector<std::vector<int>> combine(int m, int k) {
        backtracking(1, k, m);
        return ans;
    }
};

int main()
{
    Solution s;
    s.combine(4, 3);

    return 0;
}
