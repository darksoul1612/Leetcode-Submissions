class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int, int> mp;

        s.push(nums2[nums2.size()-1]);
        mp[s.top()]=-1;
        
        for(int i=nums2.size()-2; i>=0; i--){            
            while(!s.empty() and nums2[i]>s.top() ) s.pop();
            
            if(s.empty())
                mp[nums2[i]]=-1;
            else 
                mp[nums2[i]]=s.top();
            
            s.push(nums2[i]);
            // cout<<s.top()<<" ";
            
        }
        
        for(int i=0 ; i<nums1.size(); i++)
            nums1[i]=mp[nums1[i]];
        
        return nums1;
    }
};