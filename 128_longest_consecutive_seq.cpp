#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int>& nums)
{
    set<int> mySet;
    int count = 0;
    int value = 0;
    int max_count = 0;

    if(nums.empty())
        return 0;

    for(auto i : nums)
        mySet.insert(i);

    for(auto s : mySet)
    {
        value = s;
        if(mySet.find(value-1) != mySet.end()) //find returns a iterator
            continue;
        count = 1;

        while(mySet.find(++value) != mySet.end())
            count++;
        max_count = max(max_count,count);
    }
    return max_count;
}

int main(void)
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    // vec.push_back(2);
    vec.push_back(4);
    vec.push_back(8);
    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(3);
    vec.push_back(6);


    cout << "Answer:  " << longestConsecutive(vec);

    cout << endl << "La fin!" << endl;
    return 0;
}
/*
//Time complexity: O(n) - visit each node max twice in worst case
//Space complexity: O(n) - we created a set - 
max will be same as the list for uniqu elemets
*/