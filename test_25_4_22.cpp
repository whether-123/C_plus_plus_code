class Solution {
public:
    string PrintMinNumber(vector<int>& numbers) 
    {
      //sort函数，自定义的比较函数，在条件为真的情况下，不交换
      //传递性，当xy<yx(y在x后面),yz<zy(z在y后面)时，可以证明出xz<zx(z在x后面)
      sort(numbers.begin(),numbers.end(),[](int x,int y){

        string s1=to_string(x);
        s1.append(to_string(y));

        string s2=to_string(y);
        s2.append(to_string(x));
        
        //如果 xy<yx  此时y应该在x的后面，返回真
        return s1<s2;
      });

      string ret;
      
      for(auto n:numbers)
      {
        ret.append(to_string(n));
      }

      return ret;
    }
};