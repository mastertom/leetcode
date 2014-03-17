class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int lessnum = ceil((m+n)/2.0);
        int i_A = 0;
        int i_B = 0;
        int e_A,e_B;
        int scanoverA = 0;
        int scanoverB = 0;
        int count = 0;
        int inwhich = -1;//1 means A and 2 means B
        int inposition = -1;
        if (m==0)
            scanoverA=1;
        else if (n==0)
            scanoverB=1;
        else
        {
            e_A = A[i_A];
            e_B = B[i_B];
        }
        while(count<lessnum)
        {
            count++;
            if(scanoverA)
            {
                inwhich = 2;
                i_B++;
                continue;
            }
    
            if(scanoverB)
            {
                inwhich = 1;
                i_A++;
                continue;
            }
    
            if(e_A <= e_B)
            {
                e_A = A[++i_A];
                inwhich = 1;
            } else
            {
                e_B = B[++i_B];
                inwhich = 2;
            }
    
            if(i_A==m)
                scanoverA = 1;
            if(i_B==n)
                scanoverB = 1;
        }
    
        if (((m+n)%2)!=0)
        {
            if (inwhich ==1)
                return A[i_A-1];
            else
                return B[i_B-1];
        } else
        {
            //find the next and average
            int cur;
            int next;
            if (inwhich ==1)
                cur = A[i_A-1];
            else
                cur = B[i_B-1];
            if (scanoverA)
                next = B[i_B];
            else if (scanoverB)
                next = A[i_A];
            else 
            {
                if (A[i_A] <= B[i_B])
                    next = A[i_A];
                else
                    next = B[i_B];
            }
            return ((cur+next)/2.0);
        }


        
    }
};
