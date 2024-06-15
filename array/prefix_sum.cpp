// Find number of subarrays that fit an exact criteria
//


int fn(vector<int>& arr, int k)
{
    unordered_map<int, int> counts;
    counts[0] = 1;
    int ans = 0, curr = 0;

    for (int num: arr)
    {
        // do logic to change curr
        if (counts.count(curr - k))
            ans += counts[curr - k];
        counts[curr]++;
    }

    return ans;
}