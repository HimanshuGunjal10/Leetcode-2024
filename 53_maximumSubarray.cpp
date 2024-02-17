#include<iostream>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int maxRes = nums[0];
    int sum = 0;
    for(int i=0; i<nums.size(); i++)
    {
        if(sum + nums[i] < nums[i])
        {
            sum = nums[i]; //reset
            maxRes = nums[i];
        }
        else
        {
            sum += nums[i];
            maxRes = max(maxRes, sum);
        }    
    }
    return maxRes;
}

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums;
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++)
    {
        nums.push_back(arr[i]);
    }

    cout << "maxSubArray: " << maxSubArray(nums) << endl;

    return 0;
}