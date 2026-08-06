class Solution {
public:
    void merge(vector<int>&nums, int low, int mid, int high){
        vector<int>ans(high-low +1);
        int i = low;
        int j = mid+1;
        int k = 0;
        while(i <= mid && j <= high){
            if(nums[i] < nums[j]){
                ans[k] = nums[i];
                k++;
                i++;
            }
            else{
                ans[k] = nums[j];
                k++;
                j++;
            }
        }
        if(i > mid){
            for(int p = j; p<= high; p++){
                ans[k] = nums[p];
                k++;
            }
        }
        else{
            for(int p = i; p<= mid; p++){
                ans[k]=nums[p];
                k++;
            }
        }
        for(int a = low, k = 0; a<= high; a++, k++){
            nums[a] = ans[k];
        }
    }
    void mergesort(vector<int>&nums, int low, int high){
        if(low < high){
            int mid = low + (high-low)/2;
            mergesort(nums, low, mid);
            mergesort(nums, mid+1, high);
            merge(nums, low, mid, high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.empty()){
            return nums;
        }
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};