class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest=0, dif=INT_MAX;
        
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1]) continue;   // reference 3sum (if any sum is repeating due to i then we neglecting it before while loop)
            
            int j=i+1, k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                
                if(sum==target)
                    return target;
                
                if(sum>target){
                    if(abs(target-sum) < dif){
                        dif=abs(target-sum);
                        closest=sum;
                    }
                    k--;
                }
                else {
                    if(abs(target-sum) < dif){
                        dif=abs(target-sum);
                        closest=sum;
                    }
                   j++; 
                }
            }
        }
        return closest;
    }
};