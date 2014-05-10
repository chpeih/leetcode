class Solution {
public
    int singleNumber(int A[], int n) {
        int one = 0, two = 0, three = 0;
        for(int i = 0;in;i++){
            two = one&A[i];
            one ^= A[i];
            three = ~(one & two);
            one = one &three;
            two = two &three;
            
        }
        return one;
    }
};
