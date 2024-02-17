#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    //1. create a map that records count of each element in nums
    unordered_map<int,int> mp;
    vector<int> result;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    //2. create a bucket to store the elements wrt their frequency
    vector<vector<int> > bucket(nums.size()+1); //! initialize the vector this way and +1 is needed as vector's min vale will be 1 and not 0
    for(unordered_map<int,int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        bucket[it->second].push_back(it->first);
    }

    //3. max size of the bucket will be the size of nums as the key here is the freq of occurance
    for(int i=bucket.size()-1; i>=0; i--)
    {
        for(int j=0; j<bucket[i].size(); j++)
        {
            // while to take care of not pushing everything in the most freq bucket but only till the k elements (note: order not important is give)
            if(k>0)
            {
                result.push_back(bucket[i][j]);
                k--;
            }
        }
    }
    return result;
}

vector<int> topKFrequent_1(vector<int>& nums, int k)
{
    unordered_map<int,int> mp;
    /* Fill the map */
    for(auto i : nums)
        mp[i]++;
    
    /* Select which values to push_back*/
    vector<pair<int,int> > vec;
    for(auto i : mp)
    {
        vec.push_back(make_pair(i.second, i.first)); //make pair to sort by second
    }
    sort(vec.begin(), vec.end());

    stack<int> stk;
    for(auto i : vec)
        stk.push(i.second);
    
    int i = k;
    vector<int> ans;
    while(i>0)
    {
        ans.push_back(stk.top()); //use top if you want value
        stk.pop();  //pop() doesn't return anything
        i--;
    }
    return ans;
}


int main(void)
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(12);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(4);

    int k = 3;
    vector<int>result = topKFrequent(nums, k);

    for(int x : result)
    {
        cout << x << " ";
    }
    cout << endl;


    cout << endl << "La fin!" << endl;
    return 0;
}

/*
1. use map to store count of each element
2. create a bucket v(v) and store [value][key]
3.loop in descending and push to result vector 
O(n + O(different elem)) O(2n)
*/