#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        //since sorted - we use binary search
        int result = -1;
        int left = 0, right = nums.size()-1;
        int mid = (left + (right-left)/2);

        while(left <= right)
        {
            mid = (left + (right-left)/2);
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                left = mid+1;
            else if(nums[mid] > target)
                right = mid-1;
        }
        return -1;
    }

    /*
    Binary Search O(log(n)). mid = left + (right-left)/2; //imp to not have integer overflow O(logn) O(1)
    */


    int search_1(vector<int>& nums, int target)
    {
        int size = nums.size();
        if(size == 0)
            return -1;
        if(size == 1)
            return (nums[0] == target)? 0 : -1;

        int left = 0, right = size-1, mid = size/2;
        /* Binary search */

        while(left <= right)
        {
            /* this can cause integer overflow  */
            //mid = (right+left)/2;
            mid = left + (right-left)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;
    }
};

int main(void)
{
    vector<int> vec;
    for(int i=0; i<15; i++)
    {
        if(i==7)
            continue;
        vec.push_back(i);
    }

    Solution s;
    cout << "Search index: " << s.search(vec, 8);
    
    cout << endl << "La fin!" << endl;
    return 0;
}
/*

*/