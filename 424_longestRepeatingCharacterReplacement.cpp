#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> vec(26);
        int left = 0, right = 0;
        int res = 0;
        int maxApprearedCharCount = 0;
        while(right < s.length())
        {
            /*
            increment count in the vector
            update what the maxCharCount is
            */
           vec[s[right] - 'A']++;
           maxApprearedCharCount = max(maxApprearedCharCount, vec[s[right]-'A']);
           if((right-left+1 - maxApprearedCharCount) > k)
           {
                vec[s[left] - 'A']--;
                left++;
           }
           res = max(res, right-left+1);
           right++;
        }
        return res;
    }
/*
vec[s[right] - 'A']++; and maintain maxApprearedCharCount. check diff b.w r-l+1 - maxApearedCharCountr-l and k -> if greate. TC: O(n) SC: O(26) = O(1)
*/
    int characterReplacement_1(string s, int k)
    {
        unordered_map<char,int> mp; //!char and not string
        int result = 0;
        int l = 0;
        int max_char = 0;

        for(int r=0; r<s.length(); r++)
        {
            mp[s[r]]++;  //!mp.count and not mp[s[r]].count()
            max_char = max(max_char, mp[s[r]]);
            while( (r-l+1) - max_char > k)
            {
                mp[s[l]]--;
                l++;
            }
            result = max(result, (r-l+1));
        }
        return result;
    }
};

int main()
{
    string s = "AABABBA";
    int k = 2;

    Solution sol;
    cout << "Longest substring: " << sol.characterReplacement(s,k);

    cout << endl << "La Fin!" << endl;
    return 0;
}