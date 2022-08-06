class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<n-3; i++)
        {
            if(i>0 and nums[i]==nums[i-1]) continue;
            // if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            for(int j=i+1; j<n-2; j++)
            {
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                // if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                int l=j+1, r=n-1;
                while(l<r)
                {
                    long long sum=1ll*nums[i]+nums[j]+nums[l]+nums[r];
                    if(sum==target*1LL){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        
                        while(l<r and nums[l]==nums[l+1]) l++;
                        while(r>l and nums[r]==nums[r-1]) r--;
                    }
                    if(sum>target)
                        r--;
                    else l++;
                }
            }
        }
        
        return ans;
    }
};