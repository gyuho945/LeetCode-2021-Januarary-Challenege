// Solution #1 Brute Force
// Time Complexity: O(n*m) where n is length of arr, m is number of element of pieces array
// Space Complexity: O(1) no extra memory is used

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

// Solution #2 Brute Force Optimized
// Time Complexity: O(n*j) where n is length of arr, m is size of subarray in pieces which contains the first number
// Space Complexity: O(1) no extra memory is used

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        int index = 0;
        
        while(index < arr.size()){
            
            int first = -1;
            for(int i = 0; i < pieces.size(); i++){
                if(pieces[i][0] == arr[index])
                    first = i;
            }
            if(first == -1)
                return false;
            
            int temp = index;
            bool found = false;
            
            for(int j = 0; j < pieces[first].size(); j++){
                if(j == pieces[first].size()-1 && arr[temp] == pieces[first][j]){
                    found = true;
                }
                if(arr[temp++] != pieces[first][j]){
                    break;
                }        
            }
            
            if(!found)
                return false;
            
            index = temp;
        }
        
        return true;
    }
};

// Solution #3 Brute Force Optimized
// Time Complexity: O(n*logm) where n is length of arr, m is size of subarray in pieces which contains the first number
// Space Complexity: O(1) no extra memory is used

class Solution {
public:

    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        int arr_size = arr.size();
        sort(pieces.begin(), pieces.end());
        
        int index = 0;
        
        while(index < arr_size){
            
            int pos = binarySearch(pieces, arr[index]);
            if(pos == -1)
                return false;
            
            int temp = index;
            for(int i = 0; i < pieces[pos].size(); i++){
                if(pieces[pos][i] != arr[temp])
                    return false;
                temp++;
            }
            
            index = temp;
        }
        
        return true;
    }
    
    int binarySearch(vector<vector<int>> &pieces, int target){
        
        int left = 0;
        int right = pieces.size() - 1;
        
        while(left <= right){
            int pivot = left + (right - left)/2;
            
            if(pieces[pivot][0] == target){
                return pivot;
            }
            else if(pieces[pivot][0] > target){
                right = pivot - 1;
            }
            else{
                left = pivot + 1;
            }
        }
        
        return -1;
    }
};


// Solution #4 Map
// Time Complexity: O(n) where n is size of arr
// Space Complexity: O(m) where n is the size of pieces

class Solution {
public:

    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int arr_size = arr.size();
        map<int, int> m;
        int index = 0;
        
        for(int i = 0; i < pieces.size(); i++)
            m[pieces[i][0]] = i;
            
        while(index < arr_size){
            
            int pos = m[arr[index]];
            
            int temp = index;
            for(int i = 0; i < pieces[pos].size(); i++){
                if(pieces[pos][i] != arr[temp])
                    return false;
                temp++;
            }
            
            index = temp;
        }
        
        return true;
    }
    

};