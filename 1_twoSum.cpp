#include <iostream>
#include <vector>
#include <unordered_map>
#include<unordered_set>
using namespace std;

/* Note: Asked to return indices */

vector<int> twoSum(vector<int>& nums, int target)
{
    // vector<int> result;
    unordered_map<int,int> mp;
    if(nums.size() < 2)
        return {-1,-1};
    for(int i=0; i<nums.size(); i++)
    {
        if(mp.find(target - nums[i]) != mp.end())
            return {i, mp[target-nums[i]]};
        mp.insert({nums[i],i});
    }
    return{-1,-1};
}
vector<int> twoSum_returnNumbersNotIndices(vector<int>& nums, int target)
{
    // vector<int> result;
    unordered_set<int> s;
    if(nums.size() < 2)
        return {-1,-1};
    for(int i=0; i<nums.size(); i++)
    {
        if(s.find(target - nums[i]) != s.end())
            return {nums[i], target-nums[i]};
        s.insert(nums[i]);
    }
    return{-1,-1};
}

vector<int> twoSum_1(vector<int>& nums, int target)
{
    unordered_map<int,int> mp;
    vector<int> res;
    for(int i=0; i<nums.size(); i++)
    {
        if(mp[target - nums[i]] == 1)
        {
            res.push_back(nums[i]);
            res.push_back(target-nums[i]);
            return res;
        }
        mp[nums[i]]++;
    }
    return {-1,-1};
}

int main()
{
    vector<int> v;
    for(int i=0; i<10; i++)
        v.push_back(i);
    vector<int> res;
    res = twoSum(v, 8);

    for(int i=0; i<res.size(); i++)
        cout << res[i] << " ";

    cout << endl << "La fin! \n";
    return 0;
}

/*
Need map as indices is asked and not numbers
I know nums[i] - so will search for target-nums[i]. return true if yes - if no - add nums[i] to map . | O(n) O(n)
kwy-number, value-index
*/