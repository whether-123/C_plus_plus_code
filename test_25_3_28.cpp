class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
         unordered_map<int,int>  kv;
         for(int i=0;i<arr2.size();i++)
         {
            kv[arr2[i]]=i;
         }
         
         //自定义排序方式
         sort(arr1.begin(),arr1.end(),[&](int x,int y)->bool{
            //只有一个在arr2中，在的元素小
            if(kv.count(x))
            {
                //x y 都存在arr2中 比较其在arr2中的下标
                return kv.count(y)?kv[x]<kv[y]:true;
            }
            else
            {
                //x y 都不存在arr2中 比较其值
                return kv.count(y)?false:x<y;
            }
         });

         return arr1;
    }
};