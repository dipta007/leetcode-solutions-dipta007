class Solution {
public:
    string check(string &st) {
        string tmp = "";
        int flg = 1;
        for(int i=0; i<st.size(); i++) {
            if(st[i] == '.' && flg != 2) continue;
            else if(st[i] == '+' && flg == 1) flg = 0;
            else if(st[i] == '@') flg = 2;
            
            if(flg) tmp += st[i];
        }
        
        return tmp;
    }
    int numUniqueEmails(vector<string>& emails) {
        map < string, int > mp;
        for(int i=0; i<emails.size(); i++) {
            mp[ check(emails[i]) ] ++;
        }
        
        return mp.size();
    }
};