#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
Use set to maintain count - one pass | O(n) O(n)
*/

bool containsDuplicate2(vector<int>& nums)
{
#if 0
    /*sets*/
    unordered_set<int> s;
    for(int i=0; i<nums.size(); i++)
    {
        if(s.find(nums[i]) != s.end())
            return true;
        s.insert(nums[i]);
    }
    return false;
#endif

    /*map*/
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]]++;
        if(mp[nums[i]] > 1)
            return true;
    }
    return false;
}

bool containsDuplicate_1(vector<int>& nums)
{
    if(nums.size() == 0)
    {
        // cout << "here" << endl;
        return false;
    }
    unordered_map<int,int> table;
    /*
    for(int i=0; i<nums.size(); i++)
    {
        if(table.count(nums[i]) > 0)
        {
            cout << nums[i] << " ";
            return true;
        }
        table[nums[i]]++;
    }
    return false;
    */

    for(int num : nums)
    {
        if(table[num] > 0)
            return true;
        table[num]++;
    }
    return false;

}

bool containsDuplicate(vector<int>& nums)
{
    if(nums.size() <= 1)
        return false;
    unordered_map<int,int> mp;

    for(int i=0; i<nums.size(); i++)
    {
        if(mp.count(nums[i]) > 0)
            return true;
        mp[nums[i]]++;
    }
    return false;
}

int main(void)
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(7);
    // vec.push_back(3);
    vec.push_back(6);


    cout << "Answer:  " << containsDuplicate2(vec);

    cout << endl << "La fin!" << endl;
    return 0;
}