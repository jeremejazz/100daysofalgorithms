#include <stdio.h>
#define MAX_LINES 100

void shortestLine(int numLines, int lines[]) {
    int shortestLine = 0;
    int linePosition = 0;

    for (int j = 0; j < numLines; j++) {
        if (j == 0) {
            shortestLine = lines[j];
            linePosition = j;
        }

        if (j > 0 &&
            lines[j] <
                shortestLine) {  // <-- could have started from j=1 then initialize
                                 // shortestLine(index) to 0 for comparison
            shortestLine = lines[j];
            linePosition = j;
        }
    }

    printf("%d\n", shortestLine);
    lines[linePosition]++;
}

/* book solution*/



int shortest_line_index(int lines[], int n) {
    int j;
    int shortest = 0;

    for (j = 1; j < n; j++) {
        if (lines[j] < lines[shortest])
            shortest = j;
    }
    return shortest;
}

void solve(int lines[], int n, int m) {
    int i, shortest;
    for (i = 0; i < m; i++) {
        shortest = shortest_line_index(lines, n);
        printf("%d\n", lines[shortest]);
        lines[shortest]++;
    }
}

/* end book solution */

int main() {
    // int numLines = 3;
    // int lines[] = {3, 2, 5};

    // int newPeople = 4;

    // for (int i = 0; i < newPeople; i++) {
    //     shortestLine(numLines, lines);
    // }

    int lines[MAX_LINES];
    int numLines, newPeople, i;  // n = no of lines, m = new people, l = lines

    scanf("%d%d", &numLines, &newPeople);

    for ( i = 0; i < numLines; i++) {
        scanf("%d", &lines[i]);
    }

    for (int i = 0; i < newPeople; i++) {
        shortestLine(numLines, lines);
    }

    return 0;

    // int lines[MAX_LINES];
    // int n, m, i;  // n = no of lines, m = new people, l = lines

    // scanf("%d%d", &n, &m);

    // for ( i = 0; i < n; i++) {
    //     scanf("%d", &lines[i]);
    // }

    // solve(lines, n, m);

    // return 0;
}