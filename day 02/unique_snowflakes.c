#include <stdio.h>
#define MAX_SNOWFLAKES 100000
#define MAX_SNOWFLAKE_LENGTH 10000000

void identify_identical(int values[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (values[i] == values[j]) {
                printf("Twin Integers Found");
                return;
            }
        }
    }

    printf("No Two Integers are alike");
}

int identical_right(int snow1[], int snow2[], int start) {
    int offset, snow2_index;

    for (offset = 0; offset < 6; offset++) {
        /*
        // alternative code
        snow2_index = start + offset;

        if (snow2_index >= 6) {
            snow2_index = snow2_index - 6;
        }
        if (snow1[offset] != snow2[snow2_index]) {
            return 0;
        }
         */
        snow2_index = start + offset;
        if (snow1[offset] != snow2[(start + offset) % 6]) {
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


int main() {
    int snow1[] = {1, 2, 3, 4, 5, 6};
    int snow2[] = {4,5,6,1,2,3};


    int identical = are_identical(snow1, snow2);

    printf("Is identical: %d", identical);
    return 0;
}