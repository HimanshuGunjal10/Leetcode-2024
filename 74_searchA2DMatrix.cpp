#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        //1. Binary search on finding the row and 2. BS on the selected row

        int left = 0, right = matrix.size();
        int mid = 0;
        int row = 0;

        while(left <= right)
        {
            mid = left + (right-left)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix.size()-1])
            {
                row = mid;
                break;
            }
            if(target < matrix[mid][0])
                right = mid-1;
            else if(target > matrix[mid][0])
                left = mid+1;
        }
        
        left = 0;
        right = matrix[0].size()-1;

        while(left <= right)
        {
            mid = left + (right-left)/2;
            if(target == matrix[row][mid])
                return true;
            if(target < matrix[row][mid])
                right = mid-1;
            else if(target > matrix[row][mid])
                left = mid+1;
        }
        return false;
    }

/*
//1. Binary search for finding the row and 2. BS on the selected row. O(log(M*N)) O(1)

*/

    bool searchMatrix_1(vector<vector<int>>& matrix, int target)
    {
        // bottom is wrong
        //int m = matrix.size();matrix[0].size();
        int m = matrix.size();matrix[0].size();
        int n = matrix[0].size();

        int top = 0, bot = m-1, row;

        while(top<=bot)
        {
            row = top + (bot-top)/2;
            if(target < matrix[row][0])
                bot = row-1;
            else if(target > matrix[row][n-1]) //! search the last element and not 0th
                top = row+1;
            else
                break;
        }
        if(!(top <= bot))
            return false;
        
        int l=0, r= n-1, mid;

        while(l<=r)
        {
            mid = l + (r-l)/2;
            if(target < matrix[row][mid])
                r = mid-1;
            else if (target > matrix[row][mid])
                l = mid+1;
            else
                return true;
        }
        return false;
    }
};

int main(void)
{
    vector<int> vec1, vec2, vec3;
    for(int i=0; i<15; i++)
    {
        if(i==7)
            continue;
        vec1.push_back(i);
        vec2.push_back(i+22);
        vec3.push_back(i+45);
    }
    vector<vector<int>> vec;
    vec.push_back(vec1);
    vec.push_back(vec2);
    vec.push_back(vec3);

    Solution s;
    // cout << "Search index: " << s.searchMatrix(vec, 7);
    cout << "Search index: " << s.searchMatrix(vec, 8);
    cout << "Search index: " << s.searchMatrix(vec, 24);
    
    cout << endl << "La fin!" << endl;
    return 0;
}
/*

*/