#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef int HANDLE;

int main(int argc, char** argv)
{
    std::string directory = argv[0];
    directory.erase(directory.find_last_of('/')+1);//remove binary
    directory+="testfile";

    HANDLE fd = open(directory.c_str(),O_CREAT|O_WRONLY);


    std::string greeting= "Hello, world!";
    write(fd,greeting.c_str(),greeting.length());

    close(fd);

    return 0;
}
