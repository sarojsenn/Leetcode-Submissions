
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int maxi = 0;
        long long total = 0;

        // Step 1: Calculate absolute differences
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
            total += diff[i];
        }

        // If all differences can become zero
        if (k >= total) {
            return 0;
        }

        // Step 2: Binary search for the target level
        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int target = low;
        long long used = 0;
        long long ans = 0;
        long long count = 0;

        // Step 3: Reduce every difference to target
        for (int d : diff) {
            int remaining = min(d, target);

            ans += 1LL * remaining * remaining;

            if (d > target) {
                used += d - target;
            }

            if (d >= target) {
                count++;
            }
        }

        // Step 4: Use leftover operations
        long long left = k - used;

        // Each operation changes target^2 to (target-1)^2
        ans -= left * (2LL * target - 1);

        return ans;
    }
};
