class Solution {
public:
    long long sumByD(vector<int>& piles, int div){
        int n = piles.size();
        long long sum = 0;
        for(int i = 0; i< n; i++){
            sum += ((long long)piles[i] + div - 1) / div;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            if(sumByD(piles, mid) <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};