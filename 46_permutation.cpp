#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void backtrackPerm(vector<int>& nums, vector<int>& subset, vector<bool>& visited, \
                    vector<vector<int> >& result)
{
    //basecase
    if(subset.size() == nums.size())
    {
        result.push_back(subset);
        return;
    }

    for(int i=0; i<nums.size(); i++)
    {
        //push, mark visited -> backtrack -> pop
        if(visited[i] == false)
        {
            subset.push_back(nums[i]);
            visited[i] = true;
            backtrackPerm(nums, subset, visited, result);
            subset.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int> > permute(vector<int>& nums)
{
    vector<vector<int> > result;
    vector<int> subset;
    vector<bool> visited;
    for(int i=0; i<nums.size(); i++)
        visited.push_back(false);
    
    backtrackPerm(nums,subset,visited,result);
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
    int arr[] = {1,2,3};
    int target = 7;

    vector<int> nums;
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
        nums.push_back(arr[i]);

    vector<vector<int> > res;
    res = permute(nums);
    printVecOfVec(res);

    cout << endl << "La fin!\n" << endl;
}