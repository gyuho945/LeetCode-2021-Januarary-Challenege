// Solution 
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.length();
        
        if(!n)
            return 0;
        
        if(n == 1)
            return 1;
        
        return findLongestSubstr(s, n);
    }
    
    int findLongestSubstr(string s, int n){
        
        int longest = 0;
        int count;
        
        for(int i = 0; i < n; i++){
            
            count = 0;
            vector<bool> store(256, false);
        
            if(longest > n-i)
                break;
            
            for(int j = i; j < n; j++){
                
                if(store[s[j] - 0])
                    break;
                
                store[s[j] - 0] = true;
                count++;
            }
            
            longest = count > longest ? count : longest;
        }
        
        return longest;
    }
};