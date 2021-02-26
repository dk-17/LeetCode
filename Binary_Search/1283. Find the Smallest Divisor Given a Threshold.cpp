// The range of divisor is from 1 to max element of array element!
// the reason to choose the upper boundary as a max element in the nums because all the divisors greater than equal to the max element will give a result equal to the size of nums!

// consider divisor greater than the element present in the array
// example [1,2,5,9]
// suppose the divisor is 20
// then
// 1/20+2/20+5/20+9/20
// 1+1+1+1=4 that is the size of the nums!
// The minimum value of the threshold can be the size of the nums!

// To increase the result, Decrease divisor
// To decrese the result, Increse divisor

// if(result<=threshold)
// then for sure, this can be a possible result so store it in ans variable
// and decrease range of divisor towards the left i.e(right=mid-1)
// else
// since the result value is greater than the threshold it needs to decrease the divisor range towards the right i.e(left=mid+1)!

class Solution {
public:
    int Calculate(vector<int>& nums,int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]%divisor==0) ? nums[i]/divisor:(nums[i]/divisor)+1;
        }
        return sum;
    }    
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=0;
        for(int i=0;i<nums.size();i++)
            right=max(right,nums[i]);
        int ans=0;
        int result=0;
        while(left<=right){
            int mid=left+(right-left)/2;
         
            result=Calculate(nums,mid);
            
            if(result<=threshold){
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return ans;
        
    }
};
