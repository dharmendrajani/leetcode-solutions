class Solution {
public:
    string removeKdigits(string num, int k) {
       int cnt=0;
       string ans= "";
       stack<char> st;

       for(int i=0;i<num.size();i++){
        while (!st.empty() && k > 0 && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
       }
       while (k > 0) {
            st.pop();
            k--;
        }

       while(!st.empty()){
        ans += st.top();
        st.pop();
       }
       reverse(ans.begin(),ans.end());

       while (ans.size() > 1 && ans[0] == '0') {
            ans.erase(ans.begin());
        }

       if (ans == "")  return "0";

       return ans; 
    }
};