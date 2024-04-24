class Solution {
    public: double myPow(double x, int n) {
        long long b = n;
        if(x==0) return 0;
        else if(b==0) return 1;
        else if(b<0){
            b = b*(-1);
            x = 1/x;
        }
        double a = 1;
        while(b>0){
            if(b%2==0){
                x = x*x;
                b = b/2;
            }
            else{
                b = b-1;
                a = a*x;
            }
        }
        return a;
    }
};