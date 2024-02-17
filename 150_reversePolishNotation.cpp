#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> stk;
        int var1;
        int var2;

        for(int i=0; i<tokens.size(); i++)
        {
            string s = tokens[i];
            if(s == "+" || s == "-" || s == "*" || s == "/")
            // if(isalnum(char(s))
            {
                var2 = stk.top();
                stk.pop();
                var1 = stk.top();
                stk.pop(); 

                if(s == "+")
                    stk.push(var1+var2);
                else if(s == "-")
                    stk.push(var1-var2);
                else if(s == "*")
                    stk.push(var1*var2);
                else if(s == "/")
                    stk.push(var1/var2);
            }
            else
            {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};

int main()
{
    vector<string> tokens;
    tokens.push_back("2");
    tokens.push_back("4");
    tokens.push_back("+");
    tokens.push_back("3");
    tokens.push_back("/");

    Solution solulu;
    cout << "Result: " << solulu.evalRPN(tokens) << endl;
    cout << endl << "La fin!" << endl;
}