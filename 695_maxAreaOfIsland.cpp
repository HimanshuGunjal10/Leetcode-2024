#include <iostream>
#include <vector>
using namespace std;

#if 0
/* This is problem 200 - find max number of islands */
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
#endif

int dfs_area(vector<vector<int>>& grid, int i, int j, int m, int n)
{
    if( i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 )
        return 0;
    grid[i][j] = 0;
    int area = 1;
    area += dfs_area(grid, i-1, j, m, n);
    area += dfs_area(grid, i+1, j, m, n);
    area += dfs_area(grid, i, j-1, m, n);
    area += dfs_area(grid, i, j+1, m, n);

    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int max_area = 0;
    int area = 0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            area = 0;
            if(grid[i][j] == 1)
            {
                area += dfs_area(grid, i, j, m, n);
            }
            max_area = max(area,max_area);
        }
    }
    return max_area;
}

int main()
{

    /* int grid */
    int arr1[] = {1,1,1,1,0};
    int arr2[] = {1,1,0,1,0};
    int arr3[] = {1,1,0,0,0};
    int arr4[] = {0,0,0,0,0};

    vector<int> v1, v2, v3, v4;
    for(int i=0; i<5; i++)
    {
        v1.push_back(arr1[i]);
        v2.push_back(arr2[i]);
        v3.push_back(arr3[i]);
        v4.push_back(arr4[i]);
    }

    vector<vector<int>> grid;
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);
    grid.push_back(v4);

    // cout << "numIslands: " << numIslands(grid);
    cout << endl;
    cout << "max area: " << maxAreaOfIsland(grid);
    
    cout << endl << "La fin!\n" << endl;
}