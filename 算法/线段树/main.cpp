#include <iostream>
using namespace std;

void build_tree(int arr[], int tree[], int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
    }
    else 
    {
        int mid = (start + end) >> 1;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build_tree(arr, tree, left_node, start, mid);
        build_tree(arr, tree, right_node, mid+1, end);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update_tree(int arr[], int tree[], int node, int start, int end, int index, int value)
{
    if (start == end)
    {
        arr[index] = value;
        tree[node] = value;
    }
    else 
    {
        int mid = (start + end) >> 1;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (index >= start && index <= mid)
            update_tree(arr, tree, left_node, start, mid, index, value);
        else 
            update_tree(arr, tree, right_node, mid+1, end, index, value);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

int query_tree(int arr[], int tree[], int node, int start, int end, int Left, int Right)
{
    cout << "start = " << start << " end = " << end << endl;
    // 不在计算范围
    if (Right < start || Left > end)
        return 0;
    else if (start == end || (Left <= start && Right <= end))
        return tree[node];
    else 
    {
        int mid = (start + end) >> 1;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        int sum_left = query_tree(arr, tree, left_node, start, mid, Left, Right);
        int sum_right = query_tree(arr, tree, right_node, mid+1, end, Left, Right);
        return sum_left + sum_right;
    }
}

int main()
{
    constexpr int MAX_LEM = 1000;
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = 6;
    int tree[MAX_LEM] = {0};

    build_tree(arr, tree, 0, 0, size-1);
    for (int i = 0; i < 15; i++)
    {
        cout << i << ":" << tree[i] << " ";
    }
    cout << endl;

    update_tree(arr, tree, 0, 0, size-1, 4, 6);
    for (int i = 0; i < 15; i++)
    {
        cout << i << ":" << tree[i] << " ";
    }
    cout << endl;

    int s= query_tree(arr, tree, 0, 0, size-1, 2, 5);
    cout << "s = " << s << endl;
    return 0;
}
