class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        queue<char> q;
        
        int n=s.size(), mx=0;
        for(int i=0; i<n; i++){
            q.push(s[i]);
            mp[s[i]]++;
            
            while(mp[s[i]]>1){
                mp[q.front()]--;
                q.pop();
            }
            
            
            int sz=q.size();
            mx=max(mx, sz);
        }
        
        return mx;
    }
};