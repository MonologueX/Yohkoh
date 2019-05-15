class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        int sum = A, carry = 0;
        while(B != 0)
        {
            sum = A^B;
            carry = (A&B) << 1;
            A = sum;
            B = carry;
        }
        return sum;
    }
};
