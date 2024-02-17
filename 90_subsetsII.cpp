#include <iostream>
#include <vector>
using namespace std;

void backtrackingRec(int start, vector<int>& nums, vector<int>& subset, vector<vector<int> >& result)
{
    #if 0
    //basecase
    if(start == nums.size())
    {
        result.push_back(subset);
        return;
    }
    for(int i=start; i<nums.size(); i++)
    {
        //push to subset -> backtrack -> pop

        //1. all subsets that include nums[i]
        subset.push_back(nums[i]);
        backtrackingRec(i+1,nums,subset,result);
        subset.pop_back();

        
        //2. all subsets that do not include nums[i]
        while(i+1<nums.size() && nums[i] == nums[i+1])
            i++;
        backtrackingRec(i+1,nums,subset,result);
    }
    #endif
    result.push_back(subset);
    for(int i=start; i<nums.size(); i++)
    {
        if(i > start && nums[i] == nums[i-1])
            continue;
        subset.push_back(nums[i]);
        backtrackingRec(i+1,nums,subset,result);
        subset.pop_back();
    }
}
vector<vector<int> > subsetsWithDup(vector<int>& nums)
{
    // step 1 is to sort the input
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    vector<int> subset;
    backtrackingRec(0, nums,subset, result);
    return result;
}

void printVecOfVec(vector<vector<int> > vv)
{
    for(int i=0; i<vv.size(); i++)
    {
        cout << "{ ";
        for(int j=0; j<vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        } 
        cout << "} ";    
    }
    cout << endl;
}

int main()
{
    /* int grid */
    int arr[] = {1,2,2,3};

    vector<int> nums;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        nums.push_back(arr[i]);

    vector<vector<int> > res;
    res = subsetsWithDup(nums);
    printVecOfVec(res);

    cout << endl << "La fin!\n" << endl;
}