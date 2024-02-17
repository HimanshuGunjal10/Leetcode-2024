#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int left, right, target;
    vector<vector<int> > result;
    vector<int> subset;
    for(int i=0; i<nums.size(); i++)
    {
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        left = i+1;
        right = nums.size()-1;

        target = -(nums[i]); //search for a combination that is now equal to target
        while(left < right)
        {
            if(nums[left] + nums[right] == target)
            {   
                subset.push_back(nums[i]);
                subset.push_back(nums[left]);
                subset.push_back(nums[right]);
                result.push_back(subset);
                subset.clear();
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1])
                    left++;
                while(left < right && nums[right] == nums[right+1])
                    right--;
                // result.push_back({nums[i],nums[left],nums[right]});
            }
            else if(nums[left] + nums[right] < target)
                left++;
            else
                right--;
        }
    }
    return result;
}
#if 0
vector<vector<int> > threeSum_1(vector<int>& nums)
{
    vector<vector<int> > ans;
    if(nums.size() < 3)
        return ans;

    sort(nums.begin(), nums.end());
    
    vector<int> temp;
    int i=0, j=0, k=0;
    int sum = 0;
    while(nums[i]<=0)
    {
        j = i+1;
        k = nums.size()-1;
        while(j<k)
        {
            sum = nums[i] + nums[j] + nums[k];
            if(sum == 0)
            {
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                ans.push_back(temp);
                temp.clear();
                while(nums[j]==nums[++j] && j<k);
                while(nums[k]==nums[--k] && j<k);
            }
            else if(sum < 0)
                j++;
            else if(sum > 0)
                k--;
        }
        i++;
        if(i>=nums.size())
            break;
        while(i<j && nums[i]<=0 && nums[i] == nums[i-1])
            i++;
    }
    return ans;
}
#endif

int main(void)
{
    vector<int> vec;

    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.push_back(-4);

    // vec.push_back(0);
    // vec.push_back(0);
    // vec.push_back(0);

    vector<vector<int> > ans = threeSum(vec);
    
    for(auto x : ans)
    {
        cout << x[0] << x[1] << x[2] << endl;
    }

    cout << endl << "La fin!" << endl;
    return 0;
}
/*
two pointers. find sum(l+r) to be equal to -i. TC: O(nlog(n)+ O(n^2)), SC: O(1) or O(n)->this is for some sorting algorithms
*/