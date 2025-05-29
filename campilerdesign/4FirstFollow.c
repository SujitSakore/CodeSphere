// run using cmd
// gcc first_follow.c -o firstfollow
// ./firstfollow

// ✅ Sample Input:
// Enter number of productions: 4
// E=TR
// R=+TR
// R=#
// T=i

// ✅ Sample Output:
// FIRST sets:
// FIRST(E) = { i }
// FIRST(R) = { +# }
// FIRST(R) = { +# }
// FIRST(T) = { i }

// FOLLOW sets:
// FOLLOW(E) = { $ }
// FOLLOW(R) = { $ }
// FOLLOW(R) = { $ }
// FOLLOW(T) = { +$ }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char productions[MAX][MAX];
char first[MAX][MAX];
char follow[MAX][MAX];
int n;

int isTerminal(char symbol) {
    return !isupper(symbol);
}

int isInSet(char set[], char val) {
    for (int i = 0; set[i]; i++)
        if (set[i] == val)
            return 1;
    return 0;
}
void addToSet(char set[], char val) {
    if (!isInSet(set, val)) {
        int len = strlen(set);
        set[len] = val;
        set[len + 1] = '\0';
    }
}

void computeFirst(char symbol, char result[]) {
    if (isTerminal(symbol)) {
        addToSet(result, symbol);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (productions[i][0] == symbol) {
            int j = 2;
            while (productions[i][j]) {
                char next = productions[i][j];
                char temp[MAX] = "";

                computeFirst(next, temp);

                for (int k = 0; temp[k]; k++) {
                    if (temp[k] != '#')  // '#' is used for epsilon
                        addToSet(result, temp[k]);
                }

                if (!isInSet(temp, '#'))
                    break;

                j++;
                if (!productions[i][j])
                    addToSet(result, '#');
            }
        }
    }
}
void computeFollow(char symbol, char result[]) {
    if (productions[0][0] == symbol)
        addToSet(result, '$');

    for (int i = 0; i < n; i++) {
        for (int j = 2; productions[i][j]; j++) {
            if (productions[i][j] == symbol) {
                int k = j + 1;

                while (productions[i][k]) {
                    char temp[MAX] = "";
                    computeFirst(productions[i][k], temp);

                    for (int m = 0; temp[m]; m++) {
                        if (temp[m] != '#')
                            addToSet(result, temp[m]);
                    }

                    if (isInSet(temp, '#'))
                        k++;
                    else
                        break;
                }

                if (!productions[i][k] || productions[i][k] == '\0') {
                    if (productions[i][0] != symbol) {
                        char temp[MAX] = "";
                        computeFollow(productions[i][0], temp);
                        for (int m = 0; temp[m]; m++)
                            addToSet(result, temp[m]);
                    }
                }
            }
        }
    }
}
int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (use '#' for epsilon, format: A=BC or A=#):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    for (int i = 0; i < n; i++) {
        char res[MAX] = "";
        computeFirst(productions[i][0], res);
        strcpy(first[i], res);
    }

    for (int i = 0; i < n; i++) {
        char res[MAX] = "";
        computeFollow(productions[i][0], res);
        strcpy(follow[i], res);
    }

    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++)
        printf("FIRST(%c) = { %s }\n", productions[i][0], first[i]);

    printf("\nFOLLOW sets:\n");
    for (int i = 0; i < n; i++)
        printf("FOLLOW(%c) = { %s }\n", productions[i][0], follow[i]);

    return 0;
}
