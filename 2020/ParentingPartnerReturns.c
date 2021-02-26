/*
This is enough to "qualify" because I got all the others before
Checks every possible combination 
It only passes the first test (and the sample)
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct atividade {
    int comeca, acaba;
} *Atividade;

int max(int num1, int num2) { return (num1 > num2 ) ? num1 : num2; }
int min(int num1, int num2) { return (num1 > num2 ) ? num2 : num1; }

int biparticao(Atividade *horario, int N, int particao[]) {
    int r = 1;
    for (int i = 0; r && i < N; i++) {
        for (int j = 0; r && j < N; j++) {
            if (i != j && particao[i] == particao[j]) {
                r = !(max(horario[i]->comeca, horario[j]->comeca) < min(horario[i]->acaba, horario[j]->acaba));
            }
        }
    }
    return r;
}

int solve(Atividade *horario, int N, int caseNum) {
    int particao[N], k;
    for (int i = 0; i < pow(2,N); i++) {
        k = i;
        for (int j = 0; j < N; j++) {
            particao[j] = k & 1;
            k = k >> 1;
        }
        if (biparticao(horario, N, particao)) {
            printf("Case #%d: ", caseNum);
            for (int k = 0; k < N; k++) {
                printf("%s", (particao[k]) ? "C" : "J" );
            }
            printf("\n");
            return 0;
        }
    }
    printf("Case #%d: IMPOSSIBLE\n", caseNum);
    return 1;
}

int main() {
    int T, N, a, b;
    scanf("%d", &T);
    for (int k = 0; k < T; k++) {
        scanf("%d", &N);
        Atividade horario[N], temp;
        for (int l = 0; l < N; l++) {
            scanf("%d %d", &a, &b);
            temp = malloc(sizeof(struct atividade));
            temp->comeca = a;
            temp->acaba = b;
            horario[l] = temp;
        }
        solve(horario, N, k+1);
    }
}
