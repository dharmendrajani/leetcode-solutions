class Solution {
public:
    bool backspaceCompare(string s, string t) {
       stack<char> st;
 
       for(int i=0;i<s.length();i++){
        if(s[i] == '#'){
            if(!st.empty()){
                st.pop();
            }
        }else{
            st.push(s[i]);
        }
       } 
        
        string s1 ="";
       while(!st.empty()){
        s1+= st.top();
        st.pop();
       }

       for(int i=0;i<t.length();i++){
        if(t[i] == '#'){
            if(!st.empty()){
                st.pop();
            }
        }else{
            st.push(t[i]);
        }
       } 

       string t1 = "";

        while(!st.empty()) {
            t1 += st.top();
            st.pop();
        }


       return s1==t1;
    }
};