class Solution {
public:
    
    int Caculate(vector<int> & bloomDay,int day,int k){
        int NumberOfBouquet = 0;
        
        int count=0, i=0;
        while(i<bloomDay.size()){
           
            while(i<bloomDay.size() && bloomDay[i]<=day){
                count++;
                i++;
            }
            
            NumberOfBouquet+= count/k;
            count=0;
            i++;
        }
        return NumberOfBouquet;
        
    }
    
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left= 1;
        int right=0;
        for(int i=0;i<bloomDay.size();i++){
            right= max(right,bloomDay[i]);
        }
        
        int ans=-1;
        if(m*k >bloomDay.size()) return -1;
        
        while(left<=right){
            int day =left + (right - left)/2;
        
            int NumberOfBouquet = Caculate(bloomDay,day,k);
           
            if(NumberOfBouquet >= m){
                ans=day;
                right=day-1;
                
            }
            else if(NumberOfBouquet < m)
                left=day+1;
        }
        return ans;
        
    }
};
