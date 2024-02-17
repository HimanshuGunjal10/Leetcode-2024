#include <stdio.h>
#include <stdlib.h>


int* twoSum_1(int* nums, int numsSize, int target, int* returnSize){

    int* sum = (int*)malloc(sizeof(int) * 2);
    if(sum == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = 2;

    for(int i=0; i<numsSize; i++)
    {
        for(int j=i+1; j<numsSize; j++)
        {
            if(nums[i]+nums[j] == target)
            {
                sum[0] = i; sum[1] = j;
                *returnSize = 2;
                return sum;
            }
        }
    }
    //not found case;
    *returnSize = 0;
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    
}

int main()
{

    int nums[4] = {2,11,7,5};
    int numsSize = 4;
    int target = 9;
    int returnSize[2];
    
    int* ans;
    ans = twoSum(nums, numsSize, target, returnSize);

    printf("ans: [%d,%d]",ans[0],ans[1]);

    printf("\n La Fin \n");
    return 0;
}