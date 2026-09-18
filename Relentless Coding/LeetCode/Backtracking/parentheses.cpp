#include<iostream>

class Solution {
public:
    void generate(std::vector<std::string>& ans, std::vector<std::string>& ansCopy, int n) {
        if(n == 1) {
            ans.push_back("()");
            return;
        }

        generate(ans, ansCopy, n-1);

        int len = ans.size();
        for(int i=0; i<len; i++) {
//             int last = ans[i].size() - 1;
            
            std::string strNew = ans[i];
            std::string ref = ans[i];
            int last = ref.size() - 1;
//             std::cout << "last: " << last << std::endl;

//             std::cout << "ref: " << ref << std::endl;

            strNew.push_back('(');
            strNew.push_back(')');
            ans.push_back(strNew);
//           std::cout << "First: " << strNew << std::endl;

            int rightParenthesisCount = 0;
            while(ref[last] != '(') {
//                 std::cout << "came upto this line" << std::endl;

//                 strNew.push_back('(');
//                 strNew.push_back(')');
                strNew = ref;
//                 std::cout << "strNew inside while loop: " << strNew << std::endl;
                rightParenthesisCount++;
                last--;

                for(int j=0; j<rightParenthesisCount; j++) {
                    strNew.pop_back();
                } 
//                 std::cout << "After pop, strNew: " << strNew << std::endl;

//                std::string strNew = ans[i];
                strNew.push_back('(');
                strNew.push_back(')');
//                 strNew.push_back("()");

                for(int j=0; j<rightParenthesisCount; j++) {
                    strNew.push_back(')');
                }

                ans.push_back(strNew);
//                 std::cout << strNew << std::endl;
            }
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> ans, ansCopy;
        generate(ans, ansCopy, n);

        std::reverse(ans.begin(), ans.end());
        for(int i=ans.size()-1; i>=0; i--) {
            if(ans[i].size() < 2*n) {
                ans.pop_back();
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    
    std::vector<std::string> ans;
//    int n; std::cin >> n;
    ans = s.generateParenthesis(3);
    for(auto str : ans)
        std::cout << str << std::endl; 

//     std::cout << "\nTesting: \n";
//     std::vector<std::string>ara = {"((()))","(()())","(())()","()(())","()()()"};
//     std::cout << ara.size() << std::endl;
// 
//     for(int i=0; i<ara.size(); i++) {
//         std::string newStr = ara[i];
//         newStr.push_back('a');
//         std::cout << newStr << std::endl;
//    }

    return 0;
}
