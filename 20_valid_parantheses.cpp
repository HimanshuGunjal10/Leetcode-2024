#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

bool isValid(string s)
{
    unordered_map<char,char> mp;
    mp['}'] = '{';
    mp[']'] = '[';
    mp[')'] = '(';

    stack<char> stk;

    for(int i=0; i<s.length(); i++)
    {
        if(!stk.empty() && stk.top() == mp[s[i]])
            stk.pop();
        else
            stk.push(s[i]);
    }
    if(stk.empty())
        return true;
    else
        return false;
}

/*
create map of char,char key=']' value = '['. iterate over string. if stk not empty and s[i] == stack.top -> pop else push s[i]. TC: O(n) SC: O(n)
*/

bool isValid_1(string s)
{
    unordered_map<char,char> mp;
    // mp.insert(
    //     {'}','{'},
    //     {')','('},
    //     {']','['}
    //     );

    mp[']'] = '[';
    mp['}'] = '{';
    mp[')'] = '(';

    stack<char> stk;

    for(int i=0; i<s.length(); i++)
    {
        if(stk.size() > 0 && mp[s[i]] == stk.top())
            stk.pop();
        else
            stk.push(s[i]);
    }
    if(stk.empty())
        return true;
    else
        return false;

}

int main(void)
{
    string s = "{(([]))}"; //output - 1
    // string s = "{(([])}"; //output - 0
    cout << isValid(s);
    cout << endl << "La fin!" << endl;
    return 0;
}
/*
//Time complexity: 
//Space complexity: 
*/