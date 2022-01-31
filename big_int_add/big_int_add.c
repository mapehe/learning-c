// Simple big int sum
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *large_sum(char *str1, char *str2)
{
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int max_len = len1 > len2 ? len1 : len2;

        char *output = malloc(sizeof(char) * max_len);
        int sum = 0;

        for (int i = 0; i < max_len; i++)
        {
                int idx1 = len1 - i - 1;
                int idx2 = len2 - i - 1;

                int val1 = idx1 >= 0 ? str1[idx1] - '0' : 0;
                int val2 = idx2 >= 0 ? str2[idx2] - '0' : 0;

                sum = val1 + val2 + sum;
                int idxO = max_len - i - 1;
                output[idxO] = (sum % 10) + '0';
                sum = sum / 10;
        }

        if (sum > 0)
        {
                char *output_with_one = malloc(sizeof(*output) + sizeof(char));
                output_with_one[0] = '1';
                strncat(output_with_one, output, sizeof(*output));
                free(output);
                return output_with_one;
        }
        else
        {
                return output;
        }
}

int main(int argc, char *argv[])
{
        if (argc >= 3)
        {
                char *str1 = argv[1];
                char *str2 = argv[2];

                char *sum = large_sum(str1, str2);
                printf("%s\n", sum);
                free(sum);
        }
        return 0;
}
