// A possible answer (i.e k) can be from 1 to 10^9 as in constraint maximum value of piles[i] is 10^9.
// Now brute force approach will be from 1 to 10^9 trying every possibility as the number of banana-per-hour eating speed of k and answer will be the first k value that satisfies the condition!

// the time complexity for the brute force approach will be 10^4 * 10^9

// Optimal Solution!
// Binary search the answer
// If the mid-value (i.e k) number of banana eaten per hour(or speed).
// With that k value, calculate the total time taken to eat all the bananas.

// Here the relation between NumberOfhours and k(speed) is
// To increase NumberOfHours, decrease speed.
// To decrease NumberOfHours, increase speed.

// if(NumberOfHours>H)
// that is within the given limit(H) speed is less to eat all the banana , so need to decrease NumberOfHours, and to do so, need to increase speed.
// Therefore range for k will be reduced towards the right (i.e left=k+1).

// else if(NumberOfHours<=H)
// then this speed can be the possible answer so store that speed and what if while reducing speed further might possible all the banana can be eaten within H hours too!
// Therefore reducing the range of speed towards the left (i.e right=k-1).
// Time complexity 10^4 *(log 10^9).
class Solution {
public:
    int Calculate(vector<int>& nums,int k){
        int NumberOfHours=0;
        for(int i=0;i<nums.size();i++){
            NumberOfHours+=(nums[i]%k==0) ? nums[i]/k : (nums[i]/k)+1;
        }
        return NumberOfHours;
    }
    
    
    
    
    int minEatingSpeed(vector<int>& nums, int H) {
        int left=1;
        int right=1000000000;
        int ans=0;
        while(left<=right){
           int k=left+(right-left)/2;    
            
           int NumberOfHours = Calculate(nums,k);
            
            if(NumberOfHours>H){
                left=k+1;
            }
            else if(NumberOfHours<=H){
                ans=k;
                right=k-1;
            }
        }
        return ans;
        
    }
};
