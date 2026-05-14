class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;

        if(n <= 1) {
            return n;
        }

        int count=0;
        
        for(int j=0;j<n;j++){
            if(nums[i]!=nums[j]){
                nums[i+1]=nums[j];
                count++;
                i++;
            }
        }
        return i+1;
    }
};