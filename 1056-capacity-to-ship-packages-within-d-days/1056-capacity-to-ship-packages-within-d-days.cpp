class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            int day = 1;
            int currentWeight = 0;

            for (int w : weights) {
                if (currentWeight + w > mid) {
                    day++;
                    currentWeight = 0;
                }
                currentWeight += w;
            }

            if (day > days) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};