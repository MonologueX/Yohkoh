#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

void SetNonBlck(int fd)
{
    int fl = fcntl(fd, F_GETFL);
    fcntl(fd, F_SETFL, fl | O_NONBLOCK);
}

int main()
{
    // SetNonBlck(0);
    char buf[1024];
    while (1)
    {
        ssize_t s = read(0, buf, sizeof(buf)-1);
        if (s > 0)
        {
            buf[s] = 0;
            cout << buf << endl;
        }
        else 
        {
            cout << "default" << endl;
        }
        sleep(2);
    }
    return 0;
}
