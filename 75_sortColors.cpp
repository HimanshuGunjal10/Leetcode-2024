#include <iostream>
#include <vector>

using namespace std;


void sortColors(vector<int>& nums)
{
    int left = 0;
    int right = (nums.size())-1;
    int i = 0;

    while(i <= right)
    {
        if(nums[i] == 0)
        {
            swap(nums[i],nums[left]);
            left++;
        }

        else if(nums[i] == 2)
        {
            swap(nums[i],nums[right]);
            right--;
            i--;//! important step for edge case to not get this as a case: 010
                // L should always be pointing at 1
                // decrement so that next statement's increment cancels it out
                // i.e mainly i shouldn't be incremented while swapping for 2
                // it should always check if what we swapped is a zero or not
        }
        i++;
    }
}

void printVec(vector<int> vec)
{
    for(int i=0; i< vec.size(); i++)
        cout << vec.at(i) << " ";
    cout << endl;
}

int main(void)
{
    int arr[] = {2,0,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> vec;

    for(int i=0; i<size; i++)
        vec.push_back(arr[i]);

    printVec(vec);
    sortColors(vec);
    printVec(vec);

    cout << endl << "La fin!" << endl;
    return 0;
}
