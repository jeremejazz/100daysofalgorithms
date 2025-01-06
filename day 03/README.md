# Day 3

https://jeremenotes.notion.site/Day-2-16e74ba6330481f2a3e5d0d658a49afa?pvs=4
## What I Learned Today

I tried summitting this to the online judge DMOJ. While the code works, I have gotten a Time To Live error since the code would take more time for larger inputs. This is expected since the code uses 2 nested loops.

## Key Concepts

- The current code is a demonstration of O(n^2) since each number of snowflakes has a condition of (n-1).



### Quick Links

---

[dmoj.ca](https://dmoj.ca/problem/cco07p2)

[github.com](https://github.com/jeremejazz/100daysofalgorithms)

## Code Snippets

```c
#include <stdio.h>

#define SIZE 100000

int are_identical(int[], int[]);

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

int main() {
    static int snowflakes[SIZE][6];
    int n, i, j;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            scanf("%d", &snowflakes[i][j]);
        }
    }

    identify_identical(snowflakes, n);
 
    return 0;
}
```

## Challenges Experienced

n/a

## Resources Used

- [Algorithmic Thinking](https://www.amazon.com/Algorithmic-Thinking-2nd-Problem-Based-Introduction/dp/1718503229) by Daniel Zingaro
- https://dmoj.ca/problem/cco07p2/pdf