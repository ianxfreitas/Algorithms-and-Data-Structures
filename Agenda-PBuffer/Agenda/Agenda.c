#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_MAX 50
#define EMAIL_MAX 50
#define TAM_PESSOA (NOME_MAX + sizeof(int) + EMAIL_MAX)

// Estrutura do buffer: qtd | opcao | tempNome | tempIdade | tempEmail | pessoas...
#define AREA_FIXA (sizeof(int)*2 + NOME_MAX + sizeof(int) + EMAIL_MAX)

void AddPessoa(void **ppBuffer);
void RemoverPessoa(void **ppBuffer);
void ListarPessoas(void *pBuffer);
void BuscarPessoa(void *pBuffer);

int main() {

    void *pBuffer = malloc(AREA_FIXA);
    if (!pBuffer) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    int *qtd = (int *)pBuffer;
    *qtd = 0;

    int *opcao = (int *)((char*)pBuffer + sizeof(int));

    while (1) {

        do {
            printf("\n#------------------------#\n");
            printf("#     Agenda pBuffer     #\n");
            printf("#------------------------#\n");
            printf("# 1 - Adicionar Pessoa   #\n");
            printf("# 2 - Remover Pessoa     #\n");
            printf("# 3 - Buscar Pessoa      #\n");
            printf("# 4 - Listar Todas       #\n");
            printf("# 5 - Sair               #\n");
            printf("#------------------------#\n");
            printf("Escolha uma opcao: ");

            if (scanf("%d", opcao) != 1) {
                while (getchar() != '\n');
                *opcao = 0;
                continue;
            }

            while (getchar() != '\n');

        } while (*opcao < 1 || *opcao > 5);

        switch (*opcao) {
            case 1:
                AddPessoa(&pBuffer);
                // Atualizar ponteiros após realloc
                qtd = (int *)pBuffer;
                opcao = (int *)((char*)pBuffer + sizeof(int));
                break;

            case 2:
                RemoverPessoa(&pBuffer);
                // Atualizar ponteiros após realloc
                qtd = (int *)pBuffer;
                opcao = (int *)((char*)pBuffer + sizeof(int));
                break;

            case 3:
                BuscarPessoa(pBuffer);
                break;

            case 4:
                ListarPessoas(pBuffer);
                break;

            case 5:
                printf("\nSaindo...\n");
                free(pBuffer);
                return 0;

            default:
                printf("Opcao inválida.\n");
        }
    }

    return 0;
}

void AddPessoa(void **ppBuffer) {

    int *qtd = (int *)(*ppBuffer);

    // Área temporária no buffer para guardar os dados antes de salvar
    char *tempNome  = (char*)(*ppBuffer) + sizeof(int)*2;
    int  *tempIdade = (int *)(tempNome + NOME_MAX);
    char *tempEmail = (char *)(tempIdade + 1);

    printf("\nNome: ");
    fgets(tempNome, NOME_MAX, stdin);
    tempNome[strcspn(tempNome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", tempIdade);
    getchar();

    printf("Email: ");
    fgets(tempEmail, EMAIL_MAX, stdin);
    tempEmail[strcspn(tempEmail, "\n")] = '\0';

    // Aumentar o buffer para caber mais uma pessoa
    *ppBuffer = realloc(*ppBuffer, AREA_FIXA + TAM_PESSOA * ((*qtd) + 1));
    if (!(*ppBuffer)) {
        printf("Erro ao realocar memória.\n");
        exit(1);
    }

    // Atualizar ponteiros após realloc (endereço pode ter mudado)
    qtd = (int *)(*ppBuffer);
    tempNome  = (char*)(*ppBuffer) + sizeof(int)*2;
    tempIdade = (int *)(tempNome + NOME_MAX);
    tempEmail = (char *)(tempIdade + 1);

    // Posição onde a nova pessoa será salva
    char *novaPessoa = (char*)(*ppBuffer) + AREA_FIXA + TAM_PESSOA * (*qtd);
    
    memcpy(novaPessoa, tempNome, NOME_MAX);
    memcpy(novaPessoa + NOME_MAX, tempIdade, sizeof(int));
    memcpy(novaPessoa + NOME_MAX + sizeof(int), tempEmail, EMAIL_MAX);

    (*qtd)++;

    printf("\nPessoa adicionada com sucesso!\n");
}

void RemoverPessoa(void **ppBuffer) {
    
    int *qtd = (int*)(*ppBuffer);

    if (*qtd == 0) {
        printf("\nNenhuma pessoa cadastrada.\n");
        return;
    }

    char *tempEmail = (char*)(*ppBuffer) + sizeof(int)*2 + NOME_MAX + sizeof(int);

    printf("\nDigite o email da pessoa a remover: ");
    fgets(tempEmail, EMAIL_MAX, stdin);
    tempEmail[strcspn(tempEmail, "\n")] = '\0';

    char *pessoa = (char*)(*ppBuffer) + AREA_FIXA;

    int *i = (int*)malloc(sizeof(int));
    for (*i = 0; *i < *qtd; (*i)++) {
        
        char *emailPessoa = (char*)(pessoa + NOME_MAX + sizeof(int));

        if (strcmp(emailPessoa, tempEmail) == 0) {
            printf("\nPessoa encontrada e removida.\n");

            // Mover todas as pessoas seguintes uma posição para trás
            char *proxima = pessoa + TAM_PESSOA;
            memmove(pessoa, proxima, (*qtd - *i - 1) * TAM_PESSOA);

            (*qtd)--;

            // Diminuir o tamanho do buffer
            *ppBuffer = realloc(*ppBuffer, AREA_FIXA + (*qtd) * TAM_PESSOA);
            if (!(*ppBuffer) && *qtd > 0) {
                printf("Erro ao realocar memória.\n");
                free(i);
                return;
            }

            free(i);
            return;
        }

        pessoa += TAM_PESSOA;
    }

    printf("\nPessoa nao encontrada.\n");
    free(i);
}

void ListarPessoas(void *pBuffer) {

    int *qtd = (int*)pBuffer;
    
    if (*qtd == 0) {
        printf("\nNenhuma pessoa cadastrada.\n");
        return;
    }

    printf("\n--- LISTA DE PESSOAS ---\n");

    char *pessoa = (char*)pBuffer + AREA_FIXA;

    int *i = (int*)malloc(sizeof(int));
    for (*i = 0; *i < *qtd; (*i)++) {

        char *nome  = pessoa;
        int  *idade = (int*)(pessoa + NOME_MAX);
        char *email = (char*)(pessoa + NOME_MAX + sizeof(int));

        printf("\nPessoa %d:\n", (*i) + 1);
        printf("Nome : %s\n", nome);
        printf("Idade: %d\n", *idade);
        printf("Email: %s\n", email);

        pessoa += TAM_PESSOA;
    }
    
    free(i);
}

void BuscarPessoa(void *pBuffer) {

    int *qtd = (int*)pBuffer;

    if (*qtd == 0) {
        printf("\nNenhuma pessoa cadastrada.\n");
        return;
    }

    char *tempEmail = (char*)pBuffer + sizeof(int)*2 + NOME_MAX + sizeof(int);

    printf("\nDigite o email para buscar: ");
    fgets(tempEmail, EMAIL_MAX, stdin);
    tempEmail[strcspn(tempEmail, "\n")] = '\0';

    char *pessoa = (char*)pBuffer + AREA_FIXA;

    int *i = (int*)malloc(sizeof(int));
    for (*i = 0; *i < *qtd; (*i)++) {

        char *nome = pessoa;
        int *idade = (int*)(pessoa + NOME_MAX);
        char *emailPessoa = (char*)(pessoa + NOME_MAX + sizeof(int));

        if (strcmp(emailPessoa, tempEmail) == 0) {

            printf("\n--- PESSOA ENCONTRADA ---\n");
            printf("\nNome : %s\n", nome);
            printf("Idade: %d\n", *idade);
            printf("Email: %s\n", emailPessoa);
            
            free(i);
            return;
        }

        pessoa += TAM_PESSOA;
    }

    printf("\nPessoa nao encontrada.\n");
    free(i);
}