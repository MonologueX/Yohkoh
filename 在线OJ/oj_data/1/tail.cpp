
void Test1()
{
    Solution s;
    bool ret = s.IsPalindrome(121);
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
