#include<iostream>

void nextPermutation(std::vector<int>& nums) {
    int i = nums.size() - 1;
    int val = nums[i], largest = nums[i];

    std::vector<int> v;
    
    // std::cout << "Inside: " << std::endl;

    while(val >= largest) {
        v.push_back(val);
        i--;
        std::cout << "i: " << i << "   ";
        if(i<0) break;
        val = nums[i];
        largest = std::max(largest, val);
    }
    std::cout << std::endl;

    std::sort(v.begin(), v.end());
    // for(int x : v)
    //     std::cout << x << " ";
    // std::cout << std::endl;

    if(i<0) {
        nums = v;
    }
    else {
    
        int start = i;
        int pivot = nums[i];
        int targetIndx = 0;
        while(v[targetIndx] <= pivot) {
            targetIndx++;
        }

        // std::cout << "pivot: " << pivot << std::endl;
        // std::cout << "targetIndx: " << targetIndx << std::endl;

        int temp = nums[start];
        nums[start++] = v[targetIndx];
        v[targetIndx] = temp;

        for(int i=0; i<v.size(); i++) {
            nums[start++] = v[i];
        }

    }

    for(int x : nums)
        std::cout << x << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> nums = {5, 4, 3, 2, 1};
    nextPermutation(nums);

    return 0;
}
