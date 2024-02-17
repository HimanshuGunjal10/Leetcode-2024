#include <iostream>
#include <vector>
using namespace std;


vector<int> twoSumClosest(vector<int> nums, int target)
{
    int size = nums.size();
    if(size < 2)
        return {-1,-1};
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = size-1;
    int closestDiff = INT_MAX;
    int sum = INT_MIN;
    int bestLeft = -1;
    int bestRight = -1;

    while(left<right)
    {
        sum = nums[left] + nums[right];
        if(sum > target)
            right--;
        else
        {
            if(abs(target - sum) < closestDiff)
            {
                closestDiff = abs(target - sum);
                bestLeft = left;
                bestRight = right;
            }
            left++;
        }
    }
    return {nums[bestLeft],nums[bestRight]};
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
    // int arr[] = {1,2,3,4,5};
    // int arr[] = {-1,2,1,-4};
    int arr[] = {1, 60, -10, 70, -80, 85};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++)
        nums.push_back(arr[i]);
    
    printVec(nums);
    vector<int> res;
    res = twoSumClosest(nums,0);
    printVec(res);

    cout << endl << "La Fin! \n";
    return 0;
}