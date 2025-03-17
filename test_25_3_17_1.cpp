class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;

        //减1后 在与原整数& 会把该整数最右边的1变为0
        while(n)
        {
            ++count;
            n&=(n-1);
        }

        return count;
    }
};