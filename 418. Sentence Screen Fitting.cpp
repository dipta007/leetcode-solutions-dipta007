class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int r = 0, c = 0;
        int ww = 0, cnt = 0;
        while(r < rows) {
            if(c < cols && sentence[ww].size() <= cols-c) {
                c += sentence[ww].size();
                c++;
                ww++;
            }
            else {
                r++;
                c = 0;
            }
            
            if(ww == sentence.size()) {
                cnt++;
                if(c >= cols) {
                    cout << cnt << " " << r << endl;
                    int now = cnt;
                    int baki = rows - r - 1;
                    cnt += (baki/(r+1) * now);
                    
                    cout << baki%(r+1) << endl;
                    r = rows-(baki%(r+1));
                    c = 0;
                }
                ww = 0;
            }
        }
        return cnt;
    }
};