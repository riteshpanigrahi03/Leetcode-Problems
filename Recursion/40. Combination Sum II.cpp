class Solution
{
public:
    void combinations(int index, vector<int> &candidates, int target, vector<vector<int>> &result, vector<int> &d)
    {

        if (target == 0)
        {
            result.push_back(d);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            d.push_back(candidates[i]);
            combinations(i + 1, candidates, target - candidates[i], result, d);
            d.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> d;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        combinations(0, candidates, target, result, d);
        return result;
    }
};