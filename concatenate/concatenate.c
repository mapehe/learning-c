// Concatenation exercise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concatenate(char *str1, char *str2)
{
        size_t len1 = strlen(str1);
        size_t len2 = strlen(str2);
        char *str = malloc(len1 + len2);

        for (int i = 0; i < (len1 + len2); i++)
        {
                if (i < len1)
                {
                        str[i] = str1[i];
                }
                else
                {
                        str[i] = str2[i - len1];
                }
        }

        return str;
}

int main(int argc, char *argv[])
{
        if (argc >= 3)
        {
                char *str = concatenate(argv[1], argv[2]);
                printf("%s\n", str);
                free(str);
        }
        return 0;
}
