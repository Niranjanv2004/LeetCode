class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {

        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        vector<int> diff(nums.size() + 1, 0);
        priority_queue<int> pq;
        int operations = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            operations += diff[i];
            while (j < queries.size() && queries[j][0] == i) {
                pq.push(queries[j][1]);
                j++;
            }
            while (operations < nums[i] && !pq.empty() && pq.top() >= i) {
                operations++;
                diff[pq.top() + 1]--;
                pq.pop();
            }
            if (operations < nums[i])
                return -1;
        }
        return pq.size();
    }
};