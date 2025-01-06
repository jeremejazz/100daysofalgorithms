#include <stdio.h>

#define SIZE 100000

typedef struct snowflake_node {
    int snowflake[6];
    struct snowflake_node *next;
} snowflake_node;

int are_identical(int[], int[]);

int code(int snowflake[]) {
    return (snowflake[0] + snowflake[1] + snowflake[2] + snowflake[3] + snowflake[4] +
            snowflake[5]) %
           SIZE;
}

void identify_identical(int values[][6], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (are_identical(values[i], values[j])) {
                printf("Twin snowflakes found.\n");
                return;
            }
        }
    }

    printf("No two snowflakes are alike.\n");
}

int identical_right(int snow1[], int snow2[], int start) {
    int offset, snow2_index;

    for (offset = 0; offset < 6; offset++) {
        snow2_index = start + offset;

        if (snow2_index >= 6) {
            snow2_index = snow2_index - 6;
        }
        if (snow1[offset] != snow2[snow2_index]) {
            return 0;
        }
    }
    return 1;
}

int identical_left(int snow1[], int snow2[], int start) {
    int offset, snow2_index;

    for (offset = 0; offset < 6; offset++) {
        snow2_index = start - offset;

        if (snow2_index <= -1) {
            snow2_index = snow2_index + 6;
        }
        if (snow1[offset] != snow2[snow2_index]) {
            return 0;
        }
    }
    return 1;
}

int are_identical(int snow1[], int snow2[]) {
    int start;
    for (start = 0; start < 6; start++) {
        if (identical_right(snow1, snow2, start)) {
            return 1;
        }

        if (identical_left(snow1, snow2, start)) {
            return 1;
        }
    }

    return 0;
}

int main(void) {
    static snowflake_node *snowflakes[SIZE] = {NULL};

    snowflake_node *snow;

    int n, i, j, snowflake_code;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        snow = malloc(sizeof(snowflake_node));

        if (snow == NULL) {
            fprintf(stderr, "malloc error\n");
            exit(1);
        }

        for (j = 0; j < 6; j++) {
            scanf("%d", &snow->snowflake[j]);
        }

        snowflake_code = code(snow->snowflake);
        snow->next = snowflakes[snowflake_code];

    }

    identify_identical(snowflakes, n);

    return 0;
}