#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, vector<int>& nums, vector<int>& subset, vector<vector<int> >& res)
{
    /*build each subset first
    append to result
    */
   res.push_back(subset);
   for(int i=start; i<nums.size(); i++)
   {
        //push - dfs - pop
        subset.push_back(nums[i]);
        dfs(i+1,nums,subset,res);
        subset.pop_back();
   }
}

vector<vector<int> > subsets(vector<int>& nums)
{
    vector<vector<int> > res;
    vector<int> subset;

    dfs(0,nums,subset,res);
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
    int arr[] = {1,2,3};

    vector<int> nums;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        nums.push_back(arr[i]);

    vector<vector<int> > res;
    res = subsets(nums);
    printVecOfVec(res);

    cout << endl << "La fin!\n" << endl;
}