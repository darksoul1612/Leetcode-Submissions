class Solution {
public:
    void preSmaller(vector<int> &arr, vector<int> &ps){
        int n=arr.size();
        stack<int> s;
        for(int i=0; i<n ; i++){
            while(!s.empty() and arr[s.top()]>=arr[i]) s.pop();
            
            if(s.empty()) ps[i]=-1;
            else ps[i]=s.top();
            
            s.push(i);
        }
        
    }
    
    void nextSmaller(vector<int> &arr, vector<int> &ns){
        int n=arr.size();
        stack<int> s;
        for(int i=n-1; i>=0 ; i--){
            while(!s.empty() and arr[s.top()]>=arr[i]) s.pop();
            
            if(s.empty()) ns[i]=arr.size();
            else ns[i]=s.top();
            
            s.push(i);
        }
        
    }
    
    int largestRectangleArea(vector<int>& arr) {
        int res=0, n=arr.size();
        vector<int> ps(n,0), ns(n,0);
        preSmaller(arr, ps);
        nextSmaller(arr, ns);
        
        for(int i=0; i<n; i++){
            int curr=arr[i];
            
            curr+= ( ns[i]-ps[i] - 2)*arr[i];
            // curr += (i-ps[i]-1)*arr[i];
            // curr += (ns[i]-i-1)*arr[i];
            
            res=max(curr, res);
        }
        
        return res;
    }
};