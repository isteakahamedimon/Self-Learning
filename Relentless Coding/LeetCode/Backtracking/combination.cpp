#include<iostream>
#include<vector>

class Solution {
public:

    std::vector<std::vector<int>> ans;
    std::vector<int> ara;
    int base = 0;

    void backtracking(int n, size_t k, std::vector<bool>& chosen) {
        if(ara.size() == k) {
            ans.push_back(ara);
            base = 0;
            for(const auto& x : ara)
                std::cout << x << " ";
            std::cout << std::endl;

            return;
        }

        for(int i=1; i<=n; i++) {
            if(i == base) base = 0;
//            std::cout << "i: " << i << "    temp: " << base << std::endl;
            if(chosen[i] || i<base)
                continue;

//            std::cout << "Came upto this line: " << "i: " << i << " temp: " << base << std::endl;

            ara.push_back(i);
            base = i;
            chosen[i] = true;
            backtracking(n, k, chosen);
            ara.pop_back();
            chosen[i] = false;
        }
    }

    std::vector<std::vector<int>> combine(int n, int k) {

        std::vector<bool> chosen(n+1, false);
        
        backtracking(n, k, chosen);
        return ans;
    }
};

int main()
{
//    std::cout << "Alhamdulillah" << std::endl;

    Solution s;
    s.combine(4, 3);

    return 0;
}
