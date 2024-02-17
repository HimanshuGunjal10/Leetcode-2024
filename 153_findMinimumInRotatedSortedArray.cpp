#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums)
{
    int l = 0, r = nums.size()-1;
    int mid;
    int res=INT_MAX;

    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(nums[l] < nums[r])
            res = min(res, nums[l]);
        res = min(res,nums[mid]);
        if(nums[mid] >= nums[l]) // means mid belongs to left sorted portion
            l = mid+1;
        else
            r = mid-1;
    }
    return res;
}

/*
BS. if n[l] < n[r] l can be the res. else check if mid falls in te sorted or unsorted half
*/

int findMin_1(vector<int>& nums)
{
    /* Binary Search */

    int l = 0;
    int r = nums.size()-1; //!missed -1
    int m = 0;
    int res = nums[0];
    while(l<=r)
    {
        if(nums[l] < nums[r]) //!need this base case
        {
            res = min(res,nums[l]);
            break;
        }
        m = (l+r)/2;
        res = min(res, nums[m]);
        if(nums[m] >= nums[l])
            l = m+1;      
        else
            r = m-1;       
    }
    return res;
}

int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(2);
    // print_vec(vec);
    
    cout << "Minimum value in the rotated sorted array is: " << findMin(vec);

    cout << endl << "La Fin!" << endl;
    return 0;
}