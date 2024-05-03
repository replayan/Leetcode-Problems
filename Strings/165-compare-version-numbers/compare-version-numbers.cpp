class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> levels1;
        vector<string> levels2;
        
        size_t pos = 0;
        while ((pos = version1.find('.')) != string::npos) {
            levels1.push_back(version1.substr(0, pos));
            version1.erase(0, pos + 1);
        }
        levels1.push_back(version1);
        
        pos = 0;
        while ((pos = version2.find('.')) != string::npos) {
            levels2.push_back(version2.substr(0, pos));
            version2.erase(0, pos + 1);
        }
        levels2.push_back(version2);
        
        int length = max(levels1.size(), levels2.size());
        for (int i = 0; i < length; i++) {
            int v1 = i < levels1.size() ? stoi(levels1[i]) : 0;
            int v2 = i < levels2.size() ? stoi(levels2[i]) : 0;
            int compare = v1 - v2;
            if (compare != 0) {
                return compare > 0 ? 1 : -1;
            }
        }
        
        return 0;
    }
};
