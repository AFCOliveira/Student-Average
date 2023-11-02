#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *notas;
    int n_alunos = 10;
    int aprovados = 0;
    float media = 0.0;

    notas = (int *)malloc(n_alunos * sizeof(int));

    if (notas == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i < n_alunos; i++)
    {
        do
        {
            printf("Digite a nota do aluno %d (0 a 100): ", i + 1);
            scanf("%d", &notas[i]);
        } while (notas[i] < 0 || notas[i] > 100);
    }

    for (int i = 0; i < n_alunos; i++)
    {
        printf("Aluno %d: ", i + 1);
        if (notas[i] >= 0 && notas[i] <= 20)
        {
            printf("Reprovado\n");
        }
        else if (notas[i] >= 21 && notas[i] <= 59)
        {
            printf("Em prova especial\n");
        }
        else
        {
            printf("Aprovado\n");
            aprovados++;
        }
        media += notas[i];
    }

    media /= n_alunos;

    printf("Quantidade de alunos aprovados: %d\n", aprovados);
    printf("Media de notas da turma: %.2f\n", media);

    free(notas);

    return 0;
}