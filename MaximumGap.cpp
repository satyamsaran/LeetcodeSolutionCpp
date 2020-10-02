class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //calc some quantities
        int n=nums.size(),i,maxNum=INT_MIN,minNum=INT_MAX,bNum;
        
        if(n<=1) return 0;
        
        //find max and min 
        
        for(i=0;i<n;i++){
            maxNum=max(maxNum,nums[i]);
            minNum=min(minNum,nums[i]);
            
        }
        
        //bucket size
        int b=max((maxNum-minNum)/(n-1),1);
        
        //num of buckets
        int numBuck=(maxNum-minNum)/b+1;
        
        //lets create these buckets
        vector<pair<int,int>> buckets(numBuck,make_pair(INT_MAX,INT_MIN));
        
        //lets map numbers to buckets
        for(i=0;i<n;i++){
            //buckets num for this i
            bNum=(nums[i]-minNum)/b;
            
            buckets[bNum].first=min(buckets[bNum].first, nums[i]);
            buckets[bNum].second=max(buckets[bNum].second, nums[i]);
        }
        
        //calc the answer
        int res=INT_MIN,prev=buckets[0].second;
        for(i=1;i<numBuck;i++){
            //empty bucket
            if(buckets[i].first==INT_MAX && buckets[i].second==INT_MIN) continue;
            
            res=max(res,buckets[i].first-prev);
            prev=buckets[i].second;
        }
        
        return max(res,0);
    }
};
