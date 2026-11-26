class Solution {
public:
    bool solve(int n, int k, bool aliceTurn){
        if(n<k){
            return !aliceTurn;
        }
        return solve(n-k,k-1,!aliceTurn);

    }

    bool canAliceWin(int n) {

       return solve(n,10,true);
    }
};