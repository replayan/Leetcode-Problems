/*
class Solution {
public:
    string reversePrefix(string word, char ch) {
        const char* chr = strchr(word.c_str(), ch);
        if (chr) {
            reverse(word.begin(), word.begin() + (chr - word.c_str()) + 1);
        }
        return word;
    }
};
*/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j=word.find(ch);
        int i=0;
        while(i<j){
            swap(word[i],word[j]);
            ++i;
            --j;
        }
        return word;
    }
};