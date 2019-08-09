class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int size = sequence.size();
        if (size == 0)
            return false;
        int i = 0;
        
        while (size--)
        {
            i = 0;
            while (sequence[i++] < sequence[size]);
            while (sequence[i++] > sequence[size]);
            if (i < size)
                return false;
        }
        
        return true;
    }
};
