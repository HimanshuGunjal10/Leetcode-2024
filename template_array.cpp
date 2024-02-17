#include <iostream>
#include <vector>
using namespace std;



void printVec(vector<int> vec)
{
    for(int i=0; i< vec.size(); i++)
        cout << vec.at(i) << " ";
    cout << endl;
}

int main()
{
    vector<int> nums;
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++)
        nums.push_back(arr[i]);
    
    printVec(nums);

    cout << endl << "La Fin! \n";
    return 0;
}