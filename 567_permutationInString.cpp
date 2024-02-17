#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char,int> main_mp;
        
        
        int len_s1 = s1.length();
        for(int i=0; i<s1.length(); i++)
            main_mp[s1[i]]++;
        unordered_map<char,int>mp = main_mp;
        
        int l=0, r=0;
        while(r<s2.length())
        {
            
            //if(mp.count(s2[r]) <= 0) //!count will tell if found or not
            if(mp[s2[r]] <= 0)
            {
                mp = main_mp;
                l = ++r;
                len_s1 = s1.length();
                continue;
            }
            else
            {
                len_s1--;
                mp[s2[r]]--; //! can't do this way: mp.count(s[r])-- : 
                r++;
                if(len_s1 == 0)
                    return true;
            }
        }
        return false;
    }
};

int main(void)
{
    string s1 = "adc";
    string s2 = "dcda";

    Solution sol;
    cout << "answer: " << sol.checkInclusion(s1,s2);
    
    cout << endl << "La fin!" << endl;
    return 0;
}
/*

*/