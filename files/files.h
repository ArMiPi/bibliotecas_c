#ifndef FILES_H
#define FILES_H

#include <stdbool.h>
#include <stdio.h>

/*
    - Esse módulo tem por objetivo implementar funções para
      facilitar a modificação e criação de arquivos

    - filename != NULL para todas as funções
*/

/*
    # Entrada:
        - filename: Path ou nome para um arquivo
    
    # Saídas:
        - true / false
    
    # Descrição:
        - Verifica se um arquivo já existe e
          retorna true se existir, false caso
          contrário
*/
bool fileExists(char *filename);

/*
    # Entradas:
        - filename: Path ou nome para um arquivo
        - content: Conteúdo a ser escrito no arquivo
        - flag: 0 / 1

    # Saídas:
        - 0: Operação não concluída
        - 1: Operação concluída
    
    # Descrição:
        - Escreve o conteúdo de content em filename

        - content != NULL

        - Se flag == 0, será utilizado o modo write para
          escrita no arquivo
        
        - Se flag == 1, será utilizado o modo append para
          escrita no arquivo
        
        - Caso ocorra algum erro durante a escrita, será retornado
          0, caso contrário, será retornado 1
*/
int filePutContent(char *filename, char *content, int flag);

/*
    # Entrada:
        - file: Ponteiro para arquivo aberto no modo r
    
    # Saída:
        - char*: String
    
    # Descrição:
        - Retorna uma string contendo o conteúdo de uma linha de file

        - file != NULL

        - Se a função encontrar o fim do arquivo, o arquivo
          será fechado
        
        - É necessário desalocar a memória utilizada pelo retorno
          dessa função
*/
char *fileGetLine(FILE *file);

#endif