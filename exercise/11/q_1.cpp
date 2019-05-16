class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        while (1)
        {
            if (a == b)
                break;
            if (a > b)
                a /= 2;
            else 
                b /= 2;
        }
        if (a != 0)
            return a;
        return 1;
    }
};
