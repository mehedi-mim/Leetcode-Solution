class Solution {
public:
    unsigned getSum(unsigned a, unsigned b) {
    if(b == 0) return a;
    unsigned int carry = (a & b) << 1;
    unsigned int sum = a ^ b;
    return getSum(sum, carry);
    }
};
