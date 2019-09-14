/***********************************
 * 文件名称: N皇后
 * 文件描述: https://www.lintcode.com/problem/n-queens-ii/description
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        count = 0;
        DFS(n, 0, 0, 0, 0);
        return count;
    }
public:
    void DFS(int n, int row, int col, int pie, int na)
    {
        if (row >= n)
        {
            count += 1;
            return;
        }
        int bits = (~(col | pie | na)) & ((1 << n) - 1);
        while (bits)
        {
            int p = bits & -bits;
            DFS(n, row+1, col | p, (pie | p) << 1, (na | p) >> 1);
            bits &= (bits-1);
        }
    }
private:
    int count = 0;
};
