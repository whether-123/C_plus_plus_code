class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int len=nums.size();
        vector<int> psum(len,0);
         
        //统计nums的前缀和
        psum[0]=nums[0];
        for(int i=1;i<len;i++)
        {
          psum[i] =nums[i]+psum[i-1];
        }
        //中心下标在最左边
         if(psum[len-1]==psum[0])  return 0;

         for(int i=2;i<len;i++)
         { 
            //因为存在多个时 返回最左边的那个 
            //从左往右判断 找到即可返回
            if(psum[len-1]-2*psum[i-2]==nums[i-1])
                return i-1;
         }
         //中心下标在最右边
         if(psum[len-2]==0)        return len-1;

         return -1;
    }
};