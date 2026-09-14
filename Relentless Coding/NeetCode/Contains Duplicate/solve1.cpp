#include<iostream>
using namespace std;

bool hasDuplicate(vector<int>& nums) {
        bool ans = false;
        int highest = 0, lowest = 0;
        for(unsigned long i=0; i<nums.size(); i++) {
            if(nums[i] >= 0 && nums[i] > highest) {
                highest = nums[i];
            }
            if(nums[i] < 0 && nums[i] < lowest) {
                lowest = nums[i];
            }
        }

        // std::cout << highest << "   " << lowest << std::endl;

        std::vector<int>ara_p(highest+1);
        std::vector<int>ara_n(-lowest+1);

        for(unsigned long i=0; i<nums.size(); i++) {
            // std::cout << "ans: " << ans << std::endl;
            if(nums[i] >= 0) {
                ara_p[nums[i]]++;
                if(ara_p[nums[i]] > 1) {
                    ans = true;
                    // std::cout << "ans becomes true when i = " << i << std::endl;
                    break;
                }
            } else {
                ara_n[-nums[i]]++;
                if(ara_n[-nums[i]] > 1) {
                    ans = true;
                    // std::cout << "ans becomes true when i = " << i << std::endl;
                    break;
                }
            }
        }
        
        // Testing the arrays
        // std::cout << "ara_p: ";
        // for(int i=0; i<highest+1; i++)
        //     std::cout << ara_p[i] << "  ";
        // std::cout << std::endl;

        // std::cout << "ara_n: ";
        // for(int i=0; i<-lowest+1; i++)
        //     std::cout << ara_n[i] << "  ";
        // std::cout << std::endl;


        return ans;
    }

int main()
{
    std::vector<int>nums = {-3, -2, -1, 0, -3, 1, 2, 3, 0};
    bool ans = hasDuplicate(nums);
    std::cout << "Duplicate ache? : " << ans << std::endl;

    return 0;
}
