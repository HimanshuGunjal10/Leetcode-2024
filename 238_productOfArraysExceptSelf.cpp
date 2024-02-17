#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int prefix = 1;
    int postfix = 1;
    vector<int> res;
    res = nums;

    for(int i=0; i<nums.size(); i++)
    {
        if(i==0)
            res[i] = prefix;
        else
        {
            prefix = prefix * nums[i-1];
            res[i] = prefix;
        }
    }
    for(int i=nums.size()-1; i>=0; i--)
    {
        if(i==nums.size()-1)
            postfix = 1;
        else
        {
            postfix = postfix * nums[i+1];
            res[i] = res[i] * postfix;
        }
    }
    return res;
}

void printVec(vector<int> vec)
{
    for(int i=0; i< vec.size(); i++)
        cout << vec.at(i) << " ";
    cout << endl;
}

int main()
{
    vector<int> nums;
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++)
        nums.push_back(arr[i]);
    
    printVec(nums);
    vector<int> res = productExceptSelf(nums);
    printVec(res);

    cout << endl << "La Fin! \n";
    return 0;
}