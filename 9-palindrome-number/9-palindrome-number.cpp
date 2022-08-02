class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;

        int c=x, rv=0;
        while(c>0){
            if(rv> (INT_MAX/10)) return false;
            rv = rv*10 + (c%10);
            c/=10;
        }
        
        return rv==x;
    }
};