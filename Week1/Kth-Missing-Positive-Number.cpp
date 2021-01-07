// Solution #1 
// Time Complexity: O(n) size of array
// Space Complexity: O(1) not using any extra memory

class Solution {
public:
    // First 
    
    int findKthPositive(vector<int>& arr, int k) {
        
        if(arr[0] > 1){
            int missing = arr[0]-1;
            if(k - missing <= 0)
                return k;
            k -= missing;
        }
        
        for(int i = 0; i + 1 < arr.size(); i++){
            
            if(arr[i+1] - arr[i] > 1){
                int missed = arr[i+1]-arr[i]-1;
                
                if(k - missed <= 0)
                    return arr[i]+k;
                k -= missed;
            }
        }
        
        return arr[arr.size()-1] + k;
        
    }
};