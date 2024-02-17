#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target)
{
    /* Binary Search */

    int l = 0;
    int r = nums.size()-1;
    int mid = 0;

    while(l<=r)
    {
        mid = (l+r)/2;
        if(target == nums[mid])
            return mid;
        
        //left is the sorted array
        if(nums[l] <= nums[mid])
        {
            if((target > nums[mid]) || (target < nums[l]))
                l = mid + 1;
            else
                r = mid - 1;
        }
        else
        //right is the sorted array
        {
            if((target < nums[mid]) || (target > nums[r]))
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec;
    vec.push_back(11);
    vec.push_back(13);
    vec.push_back(15);
    vec.push_back(17);
    vec.push_back(20);
    // print_vec(vec);
    
    int target = 17;
    cout << "Index of target: " << search(vec,target);

    cout << endl << "La Fin!" << endl;
    return 0;
}