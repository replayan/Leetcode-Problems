class Solution {
    int read(const string &s, int& i) {
        if (!isdigit(s[i])) {
            return 1;
        }
        int r = 0;
        for (; i < s.length() && isdigit(s[i]); r = r * 10 + (s[i++] - '0'))
        ;
        return r;
    }
    
    map<string, int> dfs(const string &s, int &i) {
        map<string, int> r;
        for (; i < s.length();) {
           switch(s[i]) {
               case ')':
               ++i;
               return r;
               case '(': {
                ++i;
                const auto& have = dfs(s, i);
                const int x = read(s, i);
                for (const auto & p : have) {
                    r[p.first] += p.second * x;
                }
                }
                break;
             default:
                string temp = s.substr(i, 1);
                for (++i; i < s.length() && islower(s[i]); temp.push_back(s[i++]))
                ;
                r[temp] += read(s, i);
                break;   
           }
        }
        return r;
    }
public:
    string countOfAtoms(string formula) {
        string r;
        int i = 0;
        for (const auto& p : dfs(formula, i)) {
            r.append(p.first);
            if (p.second > 1) {
                r.append(to_string(p.second));
            }
        }
        return r;
        
    }
};