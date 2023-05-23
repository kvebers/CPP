#include <iostream>

void    toUpper(char *str)
{
    int cnt;

    cnt = 0;
    while (str[cnt] != '\0')
    {
        if (str[cnt] >= 'a' && str[cnt] <= 'z')
            str[cnt] = str[cnt] - 32;
        cnt++;
    }
}

int main(int argc, char **argv)
{
    int cnt;

    cnt = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (cnt < argc)
    {
        toUpper(argv[cnt]);
        std::cout << argv[cnt] << " ";
        cnt++;
    }
    std::cout << std::endl;
    return 0;
}
