#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    if(strs.size() == 0)
        return {{}};
    if(strs.size() == 1)
        return {{strs[0]}};
    
    //1. sort each string and use that as key to create a map
    unordered_map<string,vector<string> > mp;
    string temp;
    for(int i=0; i<strs.size(); i++)
    {
        temp = strs[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(strs[i]);
    }

    //2. create a result vector from map's values
    vector<vector<string> > result;
    int i=0;
    for(unordered_map<string,vector<string> >::iterator it = mp.begin(); it != mp.end(); it++)
    {
        result.push_back(it->second);
    }
    return result;
}

vector<vector<string>> groupAnagrams_1(vector<string>& strs)
{
    unordered_map <string,vector<string> > mp;
    for(auto s : strs)
    {
        string word = s;
        sort(word.begin(), word.end());
        mp[word].push_back(s);
    }
    //create retrun vector
    vector<vector<string >  > ans;
    for(auto x: mp)
    {
        ans.push_back(x.second);
    }
    return ans;
}

int main(void)
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("bat");
    strs.push_back("tea");
    strs.push_back("tab");
    strs.push_back("tae");

    vector<vector<string>> ans;
    ans = groupAnagrams(strs);

    cout << endl << "La fin!" << endl;
    return 0;
}

/*
sort each string and use that as a key. value will be all the corresponding strings
push it->second of the map to a resultant vector
TC: sorting m number of strings will take m.nlog(n)
SC: O(n)
*/