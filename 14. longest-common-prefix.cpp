class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        
        string res = strs[0];
        
        for(int i=0; i<strs.size(); i++)
        {
            string tmp = strs[i];
            
            string now = "";
            for(int j=0; j<tmp.size() && j<res.size(); j++)
            {
                if(tmp[j] == res[j])
                {
                    now += tmp[j];
                }
                else break;
            }
            
            res = now;
        }
        return res;
    }
};