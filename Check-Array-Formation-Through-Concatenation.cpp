// Solution #1 Brute Force
// Time Complexity: O(n*m) where n is length of arr, m is number of element of pieces array
// Space Complexity: O() falls in 128 ASCII Characters

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        int index = 0;
        
        while(index < arr.size()){
            
            int temp = index;
            bool found = false;
            
            for(int i = 0; i < pieces.size(); i++){
                temp = index;
                
                for(int j = 0; j < pieces[i].size(); j++){
                    
                    if(j == pieces[i].size()-1 && arr[temp] == pieces[i][j]){
                        found = true;
                        temp++;
                        break;
                    }
                        
                    if(arr[temp] == pieces[i][j])
                        temp++;
                    else
                        break;
                }
                
                if(found){
                    index = temp;
                    break;
                }                
            }
  
            if(!found)
                return false;
        }
        
        return true;
    }
};