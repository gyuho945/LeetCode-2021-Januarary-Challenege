// Solution #1 Brute Force [Time Limit Exceeded]
// Time Complexity: O(m) where m is number of permutations
// Space Complexity: O(n) depth of stack tree

class Solution {
    int count = 0;
    
public:
    int countArrangement(int n) {
        vector<int> nums;
        
        for(int i = 1; i <= n; i++)
            nums.push_back(n);

        permute(nums, 0);
        return count;
        
        
    }
    
    void permute(vector<int> &nums, int l){
            if(l == nums.size()){
                int i;
                for(i = 1; i <= nums.size(); i++)
                    if(nums[i-1]%i != 0 && i % nums[i-1] != 0)
                        break;
    
                if(i == nums.size()+1)
                    count++;
                
                
            }
            
            for(int i = l; i < nums.size(); i++){
                swap(nums, i, l);
                permute(nums, l + 1);
                swap(nums, i, l);
            }
    }
    
    void swap(vector<int> &nums, int x, int y){
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
};

// Solution #2 Optimized Brute Force
// Time Complexity: O(m) where m is number of permutations
// Space Complexity: O(n) depth of stack tree

class Solution {
    int count = 0;
    
public:
    int countArrangement(int n) {
        vector<int> nums;
        
        for(int i = 1; i <= n; i++){
            nums.push_back(i);
        }
        
        permute(nums, 0);
        
        return count;
        
        
    }
    
    void permute(vector<int> &nums, int l){
        if(l == nums.size())
            count++;
        
        for(int i = l; i < nums.size(); i++){
            swap(nums, i, l);
            if(nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0)
                permute(nums, l + 1);
            swap(nums, i, l);
        }
            
    }
    
    void swap(vector<int> &nums, int x, int y){
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
};