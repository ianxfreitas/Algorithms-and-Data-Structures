#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(){

    int numsSize;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &numsSize);

    int *nums = (int*) malloc(sizeof(int) * numsSize);
    if (nums == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return 1;
    }
    
    int target;
    printf("Digite o numero que deseja :");
    scanf("%d", &target);

    int returnSize;

    int* resposta = twoSum(nums, numsSize, target, &returnSize);

    printf("Resposta: indices [%d, %d] = %d\n", resposta[0], resposta[1],target);
    
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *resposta = (int*) malloc(sizeof(int) * 2);
    if (resposta == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return NULL;
    }

    for (int i = 0; i < numsSize; i++)
    {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &nums[i]);
    }

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                resposta[0] = i;
                resposta[1] = j;
                *returnSize = 2;
                return resposta;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}