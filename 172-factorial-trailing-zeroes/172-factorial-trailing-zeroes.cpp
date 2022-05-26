class Solution {
public:
    int trailingZeroes(int n) {
        int countTrailingZeros = 0;
        for(int i = 5; i <= n; i *= 5) {
            countTrailingZeros += n / i;
        }
        return countTrailingZeros;
    }
};