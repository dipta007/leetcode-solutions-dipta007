class Solution {
public:
    string add(string &a, string &b)
    {
        while(a.size() < b.size()) a = "0" + a;
        while(b.size() < a.size()) b = "0" + b;
        
        //cout << a << "*" << b << endl;
        
        int carry = 0;
        string tmp = "";
        for(int i=a.size()-1; i>=0; i--)
        {
            int k1 = a[i] - '0';
            int k2 = b[i] - '0';
            
            int sum = k1 + k2 + carry;
            int kk = sum % 10;
            
            char ch = kk + '0';
            tmp = ch + tmp;
            
            carry = sum / 10;
        }
        
        if(carry)
        {
            char ch = carry + '0';
            tmp = ch + tmp;
        }
        
        return tmp;
    }
    
    string normalize(string &st)
    {
        int cnt = 0;
        for(int i=0; i<st.size(); i++)
        {
            if(st[i]!='0') break;
            cnt++;
        }
        cout << st.size() << " " << cnt << endl;
        if(cnt==st.size()) return "0";
        return st.substr(cnt, st.size()-cnt);
    }
    
    string multiply(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        
        if(l1 < l2)
        {
            swap(s1, s2);
            swap(l1, l2);
        }
        
        string res = "";
        
        int cc = 0;
        for(int i=l2-1; i>=0; i--)
        {
            int k2 = s2[i] - '0';
            
            int carry = 0;

            string st = "";
            for(int j=0; j<cc; j++) st += "0";
            cc++;
            
            for(int j=l1-1; j>=0; j--)
            {
                int k1 = s1[j] - '0';
                
                int now = k1 * k2 + carry;
                
                int kk = now % 10;
                
                char ch = kk + '0';
                st = ch + st;
                
                carry = now / 10;
            }
            //cout <<res << " " << st << endl;
            if(carry)
            {
                char ch = carry + '0';
                st = ch + st;
            }
            
            res = add(res, st);
            
            
            // cout << res << endl;
        }
        res = normalize(res);
        if(res.size()==0) res = "0";
        return res;
    }
};