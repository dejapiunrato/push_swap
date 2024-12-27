#include "push_swap.h"
#include <string.h>
#include <stdio.h>

void recursive_substitutions(char *str) {
    const char *substitutions[][2] = {
        {"rr\npa\nrr\npb\n", "sa\n"},
        {"rrr\npa\nrr\npb\n", "sa\n"},
        {"pb\npb\nrb\npa\n", "sa\npb\nrb\n"},
        {"pa\npa\nra\npb\n", "sb\npa\nra\n"},
        {"ra\nrb\n", "rr\n"},
        {"rra\nrrb\n", "rrr\n"},
        {"sa\nsb\n", "ss\n"},
        {"sb\nsb\n", ""},
        {"ss\nss\n", ""},
        {"rb\nra\n", "rr\n"},
        {"rrb\nrra\n", "rrr\n"},
        {"pa\npb\npa\n", "pa\n"},
        {"pb\npa\npb\n", "pb\n"}
    };
    int num_substitutions = sizeof(substitutions) / sizeof(substitutions[0]);
    int i;
    char *pos;

    while (1) {
        int found = 0;
        i = 0;
        while (i < num_substitutions) {
            pos = strstr(str, substitutions[i][0]);
            if (pos) {
                printf("Substituting: %s -> %s\n", substitutions[i][0], substitutions[i][1]);
                size_t len_after = strlen(pos + strlen(substitutions[i][0]));
                memmove(pos + strlen(substitutions[i][1]), pos + strlen(substitutions[i][0]), len_after + 1);
                memcpy(pos, substitutions[i][1], strlen(substitutions[i][1]));
                found = 1;
                break;
            }
            i++;
        }
        if (!found) {
            break;
        }
    }
}

void recursive_deletions(char *str) {
    const char *substrings[] = {
        "pa\npb\n", "pb\npa\n", "ra\nrra\n", "rb\n\rrb\n",
        "sa\nsa\n", "rra\npa\nra\npb\n", "rrb\npb\nrb\npa\n",
        "sb\nsb\n", "ss\nss\n"
    };
    int num_substrings = sizeof(substrings) / sizeof(substrings[0]);
    int i;
    char *pos;

    while (1) {
        int found = 0;
        i = 0;
        while (i < num_substrings) {
            pos = strstr(str, substrings[i]);
            if (pos) {
                printf("Deleting: %s\n", substrings[i]);
                memmove(pos, pos + strlen(substrings[i]), strlen(pos + strlen(substrings[i])) + 1);
                found = 1;
                break;
            }
            i++;
        }
        if (!found) {
            break;
        }
    }
}

char *optimization(char *str) {
    char *prev_str = NULL;
    size_t len = strlen(str) + 1;

    while (1) {
        prev_str = (char *)malloc(len);
        strcpy(prev_str, str);

        recursive_substitutions(str);
        recursive_deletions(str);

        if (strcmp(prev_str, str) == 0) {
            free(prev_str);
            break;
        }

        free(prev_str);
    }

    return str;
}
