class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> output(nums.size());

        //output[i] will contain product of all elements to left of nums[i]
        // for 1st element output[0]=1
        output[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {

            //output[i-1] already has product of all elements to left of i-1
            // so multiply output[i-1] with nums[i-1] to get output[i]
            output[i] = output[i - 1] * nums[i - 1];
        }

        //r will contain product of all elements to right of nums[i]
        // for last element r=1
        int r = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            //output[i] contains product of all elements to the left of i and r contains product of all elements to the right
            //so multiplying both will get us product except self
            output[i] = output[i] * r;

            //for the next iteration when i=i-1
            // multiply r with nums[i] which will be product of all elements to the right for element i-1
            r *= nums[i];
        }

        return output;
    }
};