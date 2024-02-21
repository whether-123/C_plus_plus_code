class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      map<string,int> cinMap;
      for(auto str: words) 
      {
          cinMap[str]++;   //利用map 统计出次数
      }

      multimap<int,string,greater<int>> countSort;  //反过来按次数排序 通过仿函数实现降序
      for(auto kv:cinMap)  
      {
         countSort.insert(make_pair(kv.second,kv.first));
      }
      
      vector<string> v;
      for(auto str:countSort)   //排好序后 依次存入vector
      {
          if(k==0)
          break;
          v.push_back(str.second);
          --k;
      }
      
      return v;

    }
};