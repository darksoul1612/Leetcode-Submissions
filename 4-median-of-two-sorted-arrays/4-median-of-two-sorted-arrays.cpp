class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if( b.size() < a.size() )
            return findMedianSortedArrays(b,a);
        
        int s=0, e=a.size();
        while(s<=e){
            int i1= s+(e-s)/2;
            int i2= (a.size() + b.size() +1)/2 -i1;
            int min1=(i1==a.size())? INT_MAX : a[i1];
            int max1=(i1==0)? INT_MIN : a[i1-1];
            int min2=(i2==b.size())? INT_MAX : b[i2];
            int max2=(i2==0)? INT_MIN : b[i2-1];

            if(max1<=min2 && max2<=min1){
                if((a.size()+b.size())%2 == 0)
                    return (double)(max(max1, max2)+min(min1, min2))/2.00 ;
                else return (double) max(max1, max2);
            }
            else if(max2 > min1){
                s=i1+1;
                
            }else{
                e=i1-1;
            }
               
        }
        return 0.0;
    }
};