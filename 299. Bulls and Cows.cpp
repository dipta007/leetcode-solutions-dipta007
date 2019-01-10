class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;
        for(int i=0; i<secret.size(); i++) {
            if(secret[i] == guess[i]) {
                bull++;
                secret[i] = guess[i] = '*';
            }
        }
        
        map<char, int> mp;
        for(int i=0; i<secret.size(); i++) {
            if(secret[i] != '*') {
                mp[guess[i]]++;
            }
        }
        
        for(int i=0; i<secret.size(); i++) {
            if(secret[i] != '*') {
                cow += min(mp[secret[i]], 1);
                if(mp[secret[i]]) mp[secret[i]]--;
            }
        }
        
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};