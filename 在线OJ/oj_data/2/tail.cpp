
void Test1()
{
    Solution s;
    vector<vector<int> > array = { {1, 2}, {3, 4}};
    bool ret = s.Find(4, array);
    if (ret)
    {
        std::cout << "Test1 OK!!!" << std::endl;
    }
    else 
    {
        std::cout << "Test1 failed!!!" << std::endl;
    }
}

int main()
{
    Test1();
    return 0;
}
