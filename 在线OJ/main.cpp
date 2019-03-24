#include "util.hpp"

int main()
{
    std::string test;
    FileUtil::Read("./oj_data/1/desc.txt", &test);
    std::cout << "desc:" << test << std::endl;
    return 0;
}
