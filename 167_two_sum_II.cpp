#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    int left = 0;
    int right = numbers.size()-1;

    while(left < right)
    {
        if(numbers[left] + numbers[right] == target)
            return {++left,++right};    //!imp this is asked
        if(numbers[left] + numbers[right] < target)
            left++;
        else
            right--;
    }
    return {-1,-1};
}

#if 0
vector<int> twoSum_passed_butexceeded_time(vector<int>& numbers, int target)
{
    vector<int> ans;
    int left = 0, right = 0, end = numbers.size();
    while(left < end)
    {
        right = left+1;
        while(right<numbers.size())
        {
            if(target - numbers[left] == numbers[right])
            {
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
            else if (target - numbers[left] < numbers[right])
            {
                end = right-1;
                break;
            }
            else
            {
                right++;
            }
        }
        left++;
    }
    return ans;
}
#endif
//123459
/* Two pointer method */
vector<int> twoSum_1(vector<int>& numbers, int target)
{
    vector<int> ans;
    int left = 0, right = numbers.size()-1; //missed -1
    int sum = 0;
    while(left < right)
    {
        sum = numbers[right] + numbers[left];
        if(sum > target)
            right--;
        else if(sum < target)
            left++;
        else if(sum == target)
        {
            ans.push_back(left+1);
            ans.push_back(right+1);
            break;
        }
    }
    return ans;
}

int main(void)
{
    vector<int> vec;

    vec.push_back(0);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(9);

    
    vector<int> ans = twoSum(vec, 8);
    cout << "Answer:  " << ans[0] << " " << ans[1];

    cout << endl << "La fin!" << endl;
    return 0;
}
/*
two pointers TC O(n/2) == O(n) | SC: O(1)
*/