// Solution #1 HashMap Two Pass
// Time Complexity: O(n) where n is length of the input string
// Space Complexity: O(1) falls in 128 ASCII Characters

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        int len = s.length();
        
        if(len <= 1)
            return true;
                
        bool isOdd = len%2 == 1 ? true : false;
        
        map<char, int> charStorage;
        
        for(char &c : s){
            charStorage[c]++;
        }
        
        int oddCount = 0;
        
        for(pair<char, int> p : charStorage){
            if(p.second%2)
                oddCount++;
            if(oddCount > 1)
                return false;
        }
        
        if(isOdd){
            return oddCount == 1;
        }
        else{
            return oddCount == 0;
        }
    }
};

// Solution #1 HashMap One Pass
// Time Complexity: O(n) where n is length of the input string
// Space Complexity: O(1) falls in 128 ASCII Characters

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        int len = s.length();
        
        if(len <= 1)
            return true;
                
        bool isOdd = len%2 == 1 ? true : false;
        
        map<char, int> charStorage;
        
        int count = 0;
        
        for(char &c : s){
            charStorage[c]++;
            if(charStorage[c]%2 == 0)
                count--;
            else
                count++;
            
        }

        return count <= 1;
    }
};

// Solution #1 Set One Pass
// Time Complexity: O(n) where n is length of the input string
// Space Complexity: O(1) falls in 128 ASCII Characters

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        int len = s.length();
        
        if(len <= 1)
            return true;
                
        set<char> charStorage;
        
        for(char &c : s){
            if(charStorage.count(c) == 0)
                charStorage.insert(c);
            else
                charStorage.erase(c);
        }
        
        return charStorage.size() <= 1;
    }
};