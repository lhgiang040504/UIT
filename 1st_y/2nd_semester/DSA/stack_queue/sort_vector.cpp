int maxProduct__(vector<int>& nums) {
    int max1 = 0, max2 = 0;
    for (int num : nums) {
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }
    }
    return (max1 - 1) * (max2 - 1);
}
    int maxProduct(vector<int>& nums) {
        //sort decreasing
        sort(nums.begin(), nums.end(), greater<int>());
        //sort(nums.rbegin(), nums.rend());
        return (nums[0]-1)*(nums[1]-1);
}