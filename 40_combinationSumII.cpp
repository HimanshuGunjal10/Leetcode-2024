#include <iostream>
#include <vector>
using namespace std;

void backtrack(int start, int target, int sum, bool limit_reached, vector<int>& candidates, vector<int>& subset, vector<vector<int> >& res)
{
    //basecase
    if(sum == target)
    {
        res.push_back(subset);
        limit_reached = true;
        return;
    }
    if(start > candidates.size() || limit_reached == true || sum > target)
    {
        limit_reached = true;
        return;
    }
    
    //choose next number but avoiding duplicate -> backtrack -> backtrack without the next number

    for(int i=start; i<candidates.size(); i++)
    {    
        subset.push_back(candidates[i]);
        sum += candidates[i];
        backtrack(i+1, target, sum, limit_reached, candidates, subset, res);
        subset.pop_back();
        sum -= candidates[i];   //! missed this
        while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
            i++;
    }
}
/* Note: combination is asked and not permutation*/
vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > res;
    vector<int> subset;
    backtrack(0, target, 0, false, candidates, subset,res);
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
    int arr[] = {1,2,3,3,5,6};
    int target = 6;

    vector<int> nums;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        nums.push_back(arr[i]);

    vector<vector<int> > res;
    res = combinationSum2(nums, target);
    printVecOfVec(res);

    cout << endl << "La fin!\n" << endl;
}