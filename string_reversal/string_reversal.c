// String reversal exercise
#include <stdio.h>
#include <string.h>

char *reverse(char str[])
{
    size_t len = strlen(str);
    int max_str_index = len - 1;
    int max_loop_index = len / 2;
    char tmp;

    if (max_loop_index < 1)
        return str;

    for (int i = 0; i < max_loop_index; i++)
    {
        tmp = str[i];
        str[i] = str[max_str_index - i];
        str[max_str_index - i] = tmp;
    }

    return str;
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        char *reversed = reverse(argv[1]);
        printf("%s\n", reversed);
    }
    return 0;
}
