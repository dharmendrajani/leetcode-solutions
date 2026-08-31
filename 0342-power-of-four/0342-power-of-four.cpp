class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        long long int ans=1;
        while(ans<n){
            ans*=4;
        }

        return ans == n;
    }
};