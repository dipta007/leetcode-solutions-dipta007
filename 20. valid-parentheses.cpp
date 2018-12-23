class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        
        int flg = 1;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else
            {
                if(st.size()==0)
                {
                    flg = 0;
                    break;
                }
                char ch = st.top();
                st.pop();
                cout << ch << endl;
                if(ch=='(' && s[i]==')') ;
                else if(ch=='{' && s[i]=='}') ;
                else if(ch=='[' && s[i]==']') ;
                else flg = 0;
            }
            cout << flg << endl;
        }
        
        if(st.size()) flg = 0;
        
        return flg;
    }
};