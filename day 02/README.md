# Day 2

https://jeremenotes.notion.site/Day-2-16e74ba6330481f2a3e5d0d658a49afa?pvs=4

## What I Learned Today

Learned about problem solving strategies. Current lesson is under hash tables though the first part of  the chapter is not there yet since the author is currently focusing on the challenge and it seems that we are trying to solve it first without using any form of data structure. Probably tomorrow we would be able to dive into other approaches such as using a data structure to improve performance.

## Key Concepts

- When solving complex problems, try to start with the simpler form.  (ex 2.1 code snippet) instead immediately comparing 2 multidimensional arrays, try to compare 1 array and check if there are identical integers.

### Quick Links

---

[dmoj.ca](https://dmoj.ca)

## Code Snippets

```c
// 2.1
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

// 2.2
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

// 2.3
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

// 2.4
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

```

## Challenges Experienced

Challenge is based on Unique Snowflake Challenge from DMOJ Challenge “[CCO '07 P2 - Snowflakes](https://dmoj.ca/problem/cco07p2)” where the challenge is to test 2 snowflakes if identical. I’ve attempted to solve initially and one of the challenge faced is trying to test for rotation. The author provides a simple approach in solving the problem initially without the use of a data structure. This is probably needed to compare the performance when using a data structure.

## Resources Used

- Algorithmic Thinking
- https://dmoj.ca/problem/cco07p2/pdf