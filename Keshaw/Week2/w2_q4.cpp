class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> dq;
        vector<int> out;
        out.reserve(n - k + 1);

        for (int i=0; i<k; i++){
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        out.push_back(nums[dq.front()]);

        for (int i=k; i<n; i++){
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            out.push_back(nums[dq.front()]);
        }
        return out;
    }
};
