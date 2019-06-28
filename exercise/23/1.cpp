class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        // 1 2 3 2 2 4
        // 2 1 0 2 3 2
        int count = 1;
        int result = gifts[0];
        for (auto i = 0; i < n; i++)
        {
            if (count <= 0)
            {
                count = 1;
                result = gifts[i];
            }
            if (gifts[i] == result)
                count++;
            else 
                count--;
        }
        if (count < 3)
            return 0;
        return result;
    }
};
