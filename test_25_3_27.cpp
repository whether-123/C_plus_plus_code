class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       //先将区间 按照左端点进行升序 排序
       sort(intervals.begin(),intervals.end(),[&](vector<int>& v1,vector<int>& v2)->bool{
        return v1[0]<v2[0];
        });
        
        vector<vector<int>> ret;
        
        if(intervals.size()==0)  
           return ret;
        
        ret.push_back(intervals[0]);
        //由于已经按照左区间递增的方式排序
        //将intervals 中的 左区间和 ret中的右区间进行比较  
        for(int i=1;i<intervals.size();i++)
        {
           if(intervals[i][0]<=ret.back()[1])
           {
              if(intervals[i][1]>ret.back()[1])
                {
                    ret.back()[1]=intervals[i][1];
                }
           }
           else
           {
             ret.push_back(intervals[i]);
           }
        }
        return ret;
    }
};