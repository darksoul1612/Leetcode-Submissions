class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size(); 
        vector<vector<int>> ans;   
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++)
        {
            if(i!=0 and nums[i]==nums[i-1]) continue;
            int j=i+1, k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    while(j<n-1 and nums[j]==nums[j+1]) j++;
                    
                    while(k>0 and nums[k]==nums[k-1]) k--;
                    
                }
                if(sum>0)
                    k--;
                else j++;
            }
        }
        return ans;
    }
};