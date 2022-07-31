class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums2.size();
            
        map<int,int> m;
        
        stack<int> s;
        s.push(n-1);
        m[nums2[n-1]]=-1;
        
        for(int i=n-2; i>=0; i--){
            
            while(s.size() and nums2[i] > nums2[s.top()] ){
                s.pop();
            }
            
            
            if(s.size()==0){
                m[nums2[i]]=-1;
            }else{
                m[nums2[i]]=nums2[s.top()];
            }
            
            s.push(i);
            
}
        for(int i=0;i<nums1.size();i++){
            nums1[i]=m[nums1[i]];
        }
        
        return nums1;
    }
};