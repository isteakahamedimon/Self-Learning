#include<iostream>

class Solution {
public:
    std::string ara;
    std::vector<std::string> ans;
    void gp(int n, int l, int r) {
        if(ara.size() == 2*n) {
            ans.push_back(ara);
            std::cout << ara << std::endl;
            return;
        }
        if(l < n) {
            ara.push_back('(');
            l++;
            gp(n, l, r);
            ara.pop_back();
            l--;
        }
        if(l > r && r < n) {
            ara.push_back(')');
            r++;
            gp(n, l, r);
            ara.pop_back();
            r--;
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        int l = 0, r = 0;
        gp(n, l, r);
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> ans;
    ans = s.generateParenthesis(3);

    return 0;
}
