#include <iostream>
#include <vector>
using namespace std;

int maxProduct(vector<int>& nums)
{
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int maxProductAnswer = nums[0];

    for(int i=1; i< nums.size(); i++)
    {
        /* if nums[i] is a -ve number then swap min and max values */
        if(nums[i] < 0)
        {
            swap(minProduct, maxProduct);
        }
        minProduct = min(nums[i], minProduct * nums[i]); //and not min(minPr, minPr* nums[i])
        maxProduct = max(nums[i], maxProduct * nums[i]);

        maxProductAnswer = max(maxProductAnswer, maxProduct);
    }
    return maxProductAnswer;
}

int maxProduct_INCORRECT_1(vector<int>& nums)
{
    /* Note: edge case - if all elements are 0 */
    int maxProd = nums[0];
    int prod = 1;
    for(int i=0; i<nums.size(); i++)
    {
        /*
        1. nums[i] is a large number
        until we hit a 0, we can expand

        */
        if(nums[i] > prod)
        {
            //prod = nums[i];
            maxProd = max(maxProd, nums[i]);
        }
        prod = prod * nums[i];
        if(prod > maxProd)
        {
            maxProd = prod;
        }   
        if(nums[i] == 0)
        {
            //Note: reset after setting maxProd = 0 for addressing this input {-2,0,-1}
            prod = 1;
        }
    }
    return maxProd;
}

int main()
{
    int arr[] = {2,-5,-2,-4,3};
    vector<int> nums;
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++)
    {
        nums.push_back(arr[i]);
    }

    cout << "maxProduct: " << maxProduct(nums) << endl;

    return 0;
}