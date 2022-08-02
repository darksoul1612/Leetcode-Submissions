class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        deque<int> dq;
        int i=0, curr=0, n=gas.size();
        
        while(i<2*n){               // maximum 2 traversals could happen.
            if(dq.size()==n){
                if(curr>=0) return dq.front();
                else return -1;
            }
            
            curr+= gas[i%n] - cost[i%n];
            dq.push_back(i%n);
            
            while(!dq.empty() and curr<0){
                curr-= (gas[dq.front()] - cost[dq.front()]);
                dq.pop_front();
            }
            
            i++;
        }
        
        return -1;
    }
};