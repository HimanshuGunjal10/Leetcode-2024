#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<char>>& grid, int i, int j, int m, int n)
{
    if( i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0' )
        return;
    //mark all adjacent as 0
    grid[i][j] = '0';
    dfs(grid, i-1, j, m, n);
    dfs(grid, i+1, j, m, n);
    dfs(grid, i, j-1, m, n);
    dfs(grid, i, j+1, m, n);
}

int numIslands(vector<vector<char>>& grid)
{
    //loop each element once
    int m = grid.size();
    int n = grid[0].size();
    int result = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] == '1')
            {
                dfs(grid, i, j, m, n);
                result++;
            }
        }
    }
    return result;
}

int main()
{
    char arr1[] = {'1','1','1','1','0'};
    char arr2[] = {'1','1','0','1','0'};
    char arr3[] = {'1','1','0','0','0'};
    char arr4[] = {'0','0','0','0','0'};

    vector<char> v1, v2, v3, v4;
    for(int i=0; i<5; i++)
    {
        v1.push_back(arr1[i]);
        v2.push_back(arr2[i]);
        v3.push_back(arr3[i]);
        v4.push_back(arr4[i]);
    }

    vector<vector<char>> grid;
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);
    grid.push_back(v4);

    cout << "numIslands: " << numIslands(grid);
    
    cout << endl << "La fin!\n" << endl;
}