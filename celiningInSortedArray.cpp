#include <iostream>
using namespace std;

/* 
    https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/?ref=lbp
*/
/* Function to get index of
ceiling of x in arr[low..high]*/
int ceilSearch(int arr[], int low, int high, int target)
{
    /* binary search method */
    if(target <= arr[low])
        return low;
    if(target > arr[high])
        return -1;
    int mid = (low+high)/2; // or: low + (high-low)/2;
    if(target == arr[mid])
        return mid;
    else if(target < arr[mid])
        return ceilSearch(arr,low, mid-1, target);
    else
        return ceilSearch(arr,mid+1, high, target);

}

// Driver Code
int main()
{
	int arr[] = { 1, 2, 3, 4, 8, 10, 10, 12, 19 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 2;
	int index = ceilSearch(arr, 0, n - 1, x);
	if (index == -1)
		cout << "Ceiling of " << x
			<< " doesn't exist in array ";
	else
		cout << "ceiling of " << x << " is " << arr[index] << endl;

	return 0;
}


