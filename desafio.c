/*
Autor: Carlos Roberto Alves de Almeida Júnior
Linguagem utilizada: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SizeStr 100 //Tamanho fixo de quantidade senhas e tamanho das senhas

bool IsFim(char string[][100], int i)
{
    return (strlen(string[i]) >= 3 && (string[i][0] == 'f' || string[i][0] == 'F') && (string[i][1] == 'i' || string[i][1] == 'I') && (string[i][2] == 'm' || string[i][2] == 'M'));
}

int main()
{
    char password[SizeStr][SizeStr];
    int i = 0, contMaiusc = 0, contMinus = 0;
    int size = 0, charEspecial = 0, haveNumber = 0;

    //Senha digitada até a palavra FIM/fim for digitada, podendo testar várias senhas.
    do
    {
        fgets(password[i], 101, stdin);
        //printf("%s\n", password[i]);
        i++;
    } while (IsFim(password, i-1) == false);
    

    printf("\nSenhas fortes: \n");
    for (int f = 0; f < i; f++)
    {
        size = strlen(password[f]);
        if(size >= 7)
        {
            for (int x = 0; x < size; x++)
            {
                if (password[f][x] >= 'A' &&  password[f][x]<= 'Z')
                {
                    contMaiusc += 1;
                }else if (password[f][x] >= 'a' && password[f][x] <= 'z')
                {
                    contMinus += 1;
                }else if (password[f][x] >= 32 && password [f][x]<= 47) //aceita só alguns tipos de caracteres da Tabela ASCII
                {
                    charEspecial += 1;
                }else if (password[f][x] >= '0' && password[f][x] <= '9')
                {
                    haveNumber += 1;
                }
                
            }

            //printf("ContMaiusc - %d -- ContMinusc - %d -- charEspecial - %d -- haveNumber - %d\n", contMaiusc, contMinus, charEspecial, haveNumber); 
            
            if (contMaiusc >= 1 && contMinus >= 1 && charEspecial >= 1 && haveNumber >= 1)
            {
                printf("%s", password[f]);
            }
            contMaiusc = 0; contMinus = 0; charEspecial = 0; haveNumber = 0;
        }
    }
    

    return 0;
}