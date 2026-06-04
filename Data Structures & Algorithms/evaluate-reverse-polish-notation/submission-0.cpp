class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for (string c : tokens){
            if (c == "+" || c == "-" || c == "*" || c == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                int tmp;
                st.pop();
                if (c == "+"){
                    tmp = a + b;
                }
                else if(c == "-"){
                    tmp = b - a;
                }
                else if(c == "*"){
                    tmp = a * b;
                }
                else{
                    tmp = b / a;
                }
                st.push(tmp);
            }
            else{
                int a = stoi(c);
                st.push(a);
            }
        }
        return st.top();
    }
};
