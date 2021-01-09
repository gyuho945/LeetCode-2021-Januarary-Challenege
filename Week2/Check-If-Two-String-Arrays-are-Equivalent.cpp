//Solution
//TC: O(n+m) size of word1 + size of word2
//SC: O(1) not using any extra memory

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string str1 = "";
        string str2 = "";
        
        for(string a : word1)
            str1 += a;
        
        for(string a : word2)
            str2 += a;
        
        return str1 == str2;
    }
};