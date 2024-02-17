int maxProduct(vector<int>& nums)
{
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int maxProductAnswer = nums[0];

    for(int i=1; i< nums.size(); i++)
    {
        /* if nums[i] is a -ve number then swap min and max values */
        if(nums[i] < 0)
        {
            swap(minProduct, maxProduct);
        }
        minProduct = min(minProduct, nums[i]);
        maxProduct = max(maxProduct, nums[i]);

        maxProductAnswer = max(maxProductAnswer, maxProduct);
    }
    return maxProductAnswer;
}