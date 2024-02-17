#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram_1(string s, string t)
{
    if(s.length() != t.length())
        return false;

    unordered_map<char,int> mp;
    for(int i=0; i<s.length(); i++)
    {
        mp[s[i]]++;
    }
    for(int i=0; i<t.length(); i++)
    {
        if(mp[t[i]] < 1)
            return false;
        mp[t[i]]--;
    }
    return true;
}


bool isAnagram(string s, string t)
{
    unordered_map<char,int> map;
    if(s.length() != t.length())
    {
        cout << "length not same" << endl;
        return false;
    }
    for(int i=0; i<s.length(); i++)
    {
        map[s[i]]++;
    }
    for(int i=0; i<t.length(); i++)
    {
        if(map[t[i]] < 1)
            return false;
        else
            map[t[i]]--;
    }
    return true;
}

int main(void)
{
    string s = "acacc";
    string t = "ccaca";
    cout << "Lengths: " << s.length() << t.length() << endl;
    cout << endl << "Answer: " << isAnagram_1(s,t);
    cout << endl << "La fin!" << endl;
    return 0;
}

/*
Need count so use hashmap
add all of s to hashmap
loop through t and find - if no - return false else if yes decrement each count in t
check length as first step
*/