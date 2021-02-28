class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        // Example
        // nums=[2,2,1,1,1]
        //assume 2 to be the majority element so in first 2 iterations count=2 and element=2
        //for 3rd iteration num=1 which is not eqal to element so count--
        //same for 4th iteration count-- , now count=0 and element=2
        //for 5th iteration num=1 and count=0 so element will be 1
        //return element i.e return 1
        
        int count = 0;
        int element = 0;
        for (int num : nums)
        {
            if (count == 0)
                element = num;

            if (num == element)
                count++;
            else
                count--;
        }
        return element;
    }
};