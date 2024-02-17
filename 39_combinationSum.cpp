#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, int target, vector<int>& candidates, vector<int>& subset, vector<vector<int> >& res)
{
    //basecase
    if(start >= candidates.size())
        return;
    
    int sumSubset = 0;
    for(int i=0; i<subset.size(); i++)
    {
        sumSubset += subset[i];
    }
    if(sumSubset == target)
    {
        res.push_back(subset);
        return;
    }
    if(sumSubset > target)
    {
        return;
    }

    //push -> backtrack -> pop
    for(int i=start; i<candidates.size(); i++)
    {
        subset.push_back(candidates[i]);
        backtrack(i,target, candidates, subset, res);
        subset.pop_back();
    }
}
/* Note: combination is asked and not permutation*/
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int> > res;
    vector<int> subset;
    backtrack(0,target,candidates, subset,res);
    return res;
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
    int arr[] = {2,3,6,7};
    int target = 7;

    vector<int> nums;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        nums.push_back(arr[i]);

    vector<vector<int> > res;
    res = combinationSum(nums, target);
    printVecOfVec(res);

    cout << endl << "La fin!\n" << endl;
}