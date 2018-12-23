unordered_map < string, int > mp;
unordered_map < int, string > rev;
int dist1[100004];
int dist2[100004];

class Solution {
public:
    int bfs1(string src, string dest)
    {
        memset(dist1, -1, sizeof dist1);
        dist1[ mp[src] ] = 0;
        queue < string > q;
        q.push(src);
        
        while(!q.empty())
        {
            string u = q.front(); q.pop();
            if(u == dest) return dist1[ mp[u] ];

            // cout << u << endl;
            int ui = mp[u];
            
            int len = u.size();
            for(int i=0; i<len; i++)
            {
                string v = u;
                for(int j=0; j<=25; j++)
                {
                    char ch = (char)(j + 'a');
                    
                    if(ch == v[i]) continue;
                    
                    v[i] = ch;
                    
                    // cout << v << " in "  << mp[v] << endl;
                    
                    if(mp[v] == 0) continue;
                    
                    int vi = mp[v];
                    
                    // cout << dist[vi] << endl;
                    
                    if(dist1[vi] == -1)
                    {
                        dist1[vi] = dist1[ui] + 1;
                        q.push(v);
                    }
                    else if(dist1[vi] > dist1[ui] + 1)
                    {
                        dist1[vi] = dist1[ui] + 1;
                        q.push(v);
                    }
                    
                    // cout << dist[ui] << " -> " << dist[vi] << endl;
                }
            }
        }
        return -1;
    }
    
    int bfs2(string src, string dest)
    {
        memset(dist2, -1, sizeof dist2);
        dist2[ mp[src] ] = 0;
        queue < string > q;
        q.push(src);
        
        while(!q.empty())
        {
            string u = q.front(); q.pop();
            if(u == dest) return dist2[ mp[u] ];

            // cout << u << endl;
            int ui = mp[u];
            
            int len = u.size();
            for(int i=0; i<len; i++)
            {
                string v = u;
                for(int j=0; j<=25; j++)
                {
                    char ch = (char)(j + 'a');
                    
                    if(ch == v[i]) continue;
                    
                    v[i] = ch;
                    
                    // cout << v << " in "  << mp[v] << endl;
                    
                    if(mp[v] == 0) continue;
                    
                    int vi = mp[v];
                    
                    // cout << dist[vi] << endl;
                    
                    if(dist2[vi] == -1)
                    {
                        dist2[vi] = dist2[ui] + 1;
                        q.push(v);
                    }
                    else if(dist2[vi] > dist2[ui] + 1)
                    {
                        dist2[vi] = dist2[ui] + 1;
                        q.push(v);
                    }
                    
                    // cout << dist[ui] << " -> " << dist[vi] << endl;
                }
            }
        }
        return -1;
    }
    
    string dest;
    int len;
    vector < vector < string > > res;
    int totD;
    void call(int lvl, vector < int > v)
    {
        // cout << lvl << " " << rev[ v.back() ] << endl;
        if(lvl == 0)
        {
            if(v.back() == mp[dest])
            {
                // cout << lvl << " " << rev[ v.back() ] << " " << mp[dest] << " " << v.size() << " " << endl;
                vector < string > tmp;
                for(int i=0; i<v.size(); i++)
                {
                    tmp.push_back(rev[v[i]]);
                }
                res.push_back(tmp);
            }
            return;
        }
        
        for(int i=0; i<len; i++)
        {
            string now = rev[ v.back() ];
            for(int j=0; j<=25; j++)
            {
                char ch = (char)(j + 'a');
                    
                if(ch == now[i]) continue;
                
                now[i] = ch;
                
                if(mp[now] == 0) continue;
                
                int vi = mp[now];
                
                int d1 = dist1[v.back()];
                int d2 = dist2[vi];
                if(d1 + d2 + 1 == totD)
                {
                    v.push_back(vi);
                    call(lvl - 1, v);
                    v.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        res.clear();
        mp.clear();
        rev.clear();
        
        int in = 1;
        for(int i=0; i<wordList.size(); i++)
        {
            mp[ wordList[i] ] = in;
            rev[ in ] = wordList[ i ];
            
            in++;
        }
        
        
        if(mp[ endWord ] == 0) return res;
        
        int kk = bfs1(beginWord, endWord);
        if(kk == -1) return res;
        
        bfs2(endWord, beginWord);
        
        len = beginWord.size();
        dest = endWord;
        vector < int > v;
        
        if(mp[beginWord] == 0)
        {
            rev[0] = beginWord;
            mp[beginWord] = 0;
        }
        
        v.push_back(mp[beginWord]);
        
        cout << kk << endl;
        totD = kk;
        call(kk, v);
        return res;
    }
};