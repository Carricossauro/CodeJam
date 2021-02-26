// This is CodeJam 2020 Vestigium
#include <stdio.h>
#include <stdlib.h>

int isLatinSquare(int **mat, int N, int *rows, int *columns) {
    int vis[N], sum = 0;
    for(int i = 0; i < N; i++) sum += mat[i][i];
    
    // Check Rows
    for(int i = 0; i < N; i++) {
        for(int k = 0; k < N; k++) vis[k] = 0;
        for(int j = 0; j < N; j++) {
            if (vis[mat[i][j]-1]) {
                (*rows)++;
                break;
            } else vis[mat[i][j]-1] = 1;
        }
    }
    // Check columns
    for(int i = 0; i < N; i++) {
        for(int k = 0; k < N; k++) vis[k] = 0;
        for(int j = 0; j < N; j++) {
            if (vis[mat[j][i]-1]) {
                (*columns)++;
                break;
            } else vis[mat[j][i]-1] = 1;
        }
    }
    return sum;
}

int main() {
    int rows = 0, columns = 0;
    int T, N;
    scanf("%d", &T);
    for(int k = 0; k < T; k++) {
        rows = columns = 0;
        scanf("%d", &N);
        int *mat[N];
        for(int i = 0; i < N; i++) mat[i] = malloc(sizeof(int) * N);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                scanf("%d", &(mat[i][j]));
            }
        }
        int sum = isLatinSquare(mat, N, &rows, &columns);
        printf("Case #%d: %d %d %d\n", k+1, sum, rows, columns);
    }
    return 0;
}
