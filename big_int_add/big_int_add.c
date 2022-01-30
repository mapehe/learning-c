// Simple big int sum
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "reverse.h"

typedef struct integer_node
{
        int val;
        struct integer_node *next;
} node_t;

size_t NODE_SIZE = sizeof(node_t);
const int CHARS_PER_NODE = 1;

node_t *node_from_string(char *str)
{
        size_t len1 = strlen(str);

        if (len1 == 0)
                return NULL;

        node_t *nod = malloc(NODE_SIZE);
        char tmp[2];
        tmp[0] = str[0];
        tmp[1] = '\0';
        nod->val = atoi(tmp);
        nod->next = node_from_string(str + 1);

        return nod;
}

void clear_node(node_t *node)
{
        if (node->next != NULL)
                clear_node(node->next);
        free(node);
}

node_t *node_sum(node_t *node1, node_t *node2, int add)
{

        node_t *nod = malloc(NODE_SIZE);
        int sum = node1->val + node2->val;

        nod->val = sum % (10 * CHARS_PER_NODE) + add;
        nod->next = NULL;

        node_t *next1 = malloc(NODE_SIZE);
        next1->val = 0;
        next1->next = NULL;

        node_t *next2 = malloc(NODE_SIZE);
        next2->val = 0;
        next2->next = NULL;

        int next_add = sum / (10 * CHARS_PER_NODE);

        if (node1->next != NULL)
                memcpy(next1, node1->next, NODE_SIZE);

        if (node2->next != NULL)
                memcpy(next2, node2->next, NODE_SIZE);

        if (next_add > 0 || node1->next != NULL || node2->next != NULL)
        {
                nod->next = node_sum(next1, next2, next_add);
        }

        free(next1);
        free(next2);

        return nod;
}

void print_node(node_t *node)
{
        if (node->next != NULL)
                print_node(node->next);
        printf("%d", node->val);
}

int main(int argc, char *argv[])
{
        if (argc >= 3)
        {
                char *str1 = argv[1];
                char *str2 = argv[2];

                str1 = reverse(str1);
                str2 = reverse(str2);

                node_t *head1 = node_from_string(str1);
                node_t *head2 = node_from_string(str2);

                node_t *sum = node_sum(head1, head2, 0);
                print_node(sum);
                printf("\n");

                clear_node(head1);
                clear_node(head2);
                clear_node(sum);
        }
        return 0;
}
