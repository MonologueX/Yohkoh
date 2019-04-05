
#include <algorithm>

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        int result = 0;
        sort(gifts.begin(); gifts.end());
        int num = gifts[n/2];
        for (size_t i = 0; i < n; i++)
        {
            if (gifts[i] == num)
                result++;
        }
        if (result > n / 2)
            result = gifts[n/2];
        return result;
};
