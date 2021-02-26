class Solution {
public:
    
    int num_of_days(vector<int>& W,int capacity){
        int NumOfDays=1;
        int sum=0;
       
        for(int i=0;i<W.size();i++){
            sum+=W[i];
            if(sum>capacity){
                sum=W[i];
                NumOfDays++;
            }
        }
      
        return NumOfDays;
    }
    
    
    int shipWithinDays(vector<int>& weights, int D) {
        int low=0,high=0;
        int ans=0;
        for(int i=0;i<weights.size();i++){
            low=max(low,weights[i]);
            high+=weights[i];
        }
      
        
        while(low<=high){
                int capacity=low+(high-low)/2;
                if(num_of_days(weights,capacity)>D)
                    low=capacity+1;
                else{
                    ans=capacity;
                    high=capacity-1;
                }
            }
           
        
    
         return ans;
    }
    
};
