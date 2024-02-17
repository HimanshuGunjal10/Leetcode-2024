#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    if(s.length() < 2)
        return true;
    int left = 0, right = s.length()-1;
    while(left < right)
    {
        while(left < right && !isalnum(s[left]))
            left++;
        while(left < right && !isalnum(s[right]))
            right--;
        if(tolower(s[left]) != tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

bool isPalindrome_1(string s)
{
    if(s.length() == 0 || s.length() == 1)
        return true;
    
    int l = 0;
    int r = s.length()-1;

    while(l<r)
    {
        while( l<r && (!isalnum(s[l])) )
            l++;
        while( l<r && (!isalnum(s[r])) )
            r--;
        if(tolower(s[l]) != tolower(s[r]))
            return false;
        l++;
        r--;
    }
    return true;
}

int main(void)
{
    string s = "A man, a plan, a canal: Panama";
    string s1 = "malayalaM";
    cout << "Answer:  " << isPalindrome(s);
    cout << endl << "La fin!" << endl;
    return 0;
}
/*
!! Imp: Ask if alphabets are capitalized, do spaces and colons matter. two pointer. isalnum(c) tolower(c)
*/