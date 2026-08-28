#include<iostream>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int len = nums.size();
    std::vector<int>product(len), product1(len), product2(len);
    
    for(size_t i=0; i<product.size(); i++) {
        product[i] = 1;
        std::cout << product[i] << "    ";
    }
    std::cout << std::endl;
    
    product1[0] = 1;
    for(int i=1; i<len; i++) {
        product1[i] = product1[i-1] * nums[i-1];
    }

    for(int i=0; i<len; i++) {
        std::cout << product1[i] << "    ";
    }   std::cout << std::endl;
    
    product2[len-1] = 1;
    for(int i=len-2; i>=0; i--) {
        product2[i] = product2[i+1] * nums[i+1];
    }

    for(int i=0; i<len; i++) {
        std::cout << product2[i] << "    ";
    }   std::cout << std::endl;

    // Final Answer
    for(int i=0; i<len; i++) {
        product[i] = product1[i] * product2[i];
        std::cout << product[i] << "    ";
    }   std::cout << std::endl;
 
    return product;
}

int main()
{
    std::vector<int>nums = {1,2,3,4};
    productExceptSelf(nums);

    return 0;
}
