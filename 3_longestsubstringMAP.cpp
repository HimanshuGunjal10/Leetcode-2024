#include <iostream>
#include <map>
#include <unordered_map>
#include<unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> mySet;
    int left = 0, right = 0;
    int maxLength = 0;
    int length = 0;

    if(s.length() < 2)
        return s.length();

    while( right < s.length())
    {
        if(mySet.find(s[right]) == mySet.end())
        {
            mySet.insert(s[right]);
            length++;
            right++;  
        }
        else
        {
            maxLength = max(length, maxLength);
            mySet.erase(s[left]);
            left++;
            length--;
        }
    }
    maxLength = max(maxLength, length);
    return maxLength;
}

int lengthOfLongestSubstring_1(string s)
{
    unordered_map<char,int> charmap;
    int max_length = 0;
    int left = 0;
    int n = s.length();

    for(int right = 0; right < n; right++)
    {
        if( charmap.count(s[right]) == 0 || charmap[s[right]] < left)   //! no ease here, different logic for map and sets
        {
            max_length = max(max_length, right - left + 1);
            charmap[s[right]] = right;
        }
        else
        {
            left = charmap[s[right]]+1;
            charmap[s[right]] = right;
        }
    }
    return max_length;
}

int main()
{   
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    
    cout << endl << " La Fin " << endl;
    return 0;
}