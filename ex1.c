/*
    Autora: Andressa Von Ahnt 
    Este programa armazena todos os nomes na mesma string.
    O tamanho da string cresce e diminui conforme nomes forem colocados ou removidos.
    Há um menu onde é possível:
    - Adicionar nome
    - Remover nome
    - Listar
    - Sair
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_name(char* buffer){
    printf("\nEnter a name (max 50 characters): ");
    if (fgets(buffer, 51, stdin) == NULL){
        printf("Error reading string\n");
        exit(1);
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

void add_name(char** string){
    char buffer[51];
    read_name(buffer);

    size_t size = (strlen(*string) + strlen(buffer) + 2)* sizeof(char);
    *string = (char *)realloc(*string, size);

    if(*string == NULL){
        printf("Error allocating memory");
        exit(1);
    }
    
    if ((*string)[0] == '\0'){
        strcpy(*string, buffer);
    }
    else{
        strcat(*string, ",");
        strcat(*string, buffer);
    }
    printf("Name added successfully.\n");
}

void delet_name(char** string){
    char buffer[51], *ptr, *end;

    read_name(buffer);
    ptr = strstr(*string, buffer);
    end = ptr + strlen(buffer);

    if(ptr == NULL || 
        (ptr != *string && *(ptr - 1) != ',') || 
        (*end != '\0' && *end != ',')){
        printf("Name not found.\n");
        return;
    }
    
    if (*end == ',') {
        memmove(ptr, end + 1, strlen(end + 1) + 1); 
    } 
    else if (*end == '\0') {
        if (ptr != *string) {
            *(ptr - 1) = '\0'; 
        } else {
            *ptr = '\0'; 
        }
    }
      
    *string = (char *)realloc(*string, strlen(*string)+1);
    if(*string == NULL){
        printf("Error allocating memory");
        exit(1);
    }
    printf("Name deleted successfully.\n"); 
}

int main(){
    char *string;
    int option, size;

    if((string = malloc(sizeof(char))) == NULL){
        printf("Error allocating memory");
        exit(1);
    }

    string[0] = '\0';

    while(1){
        printf("\nInsert an option:\n1.Add name\n2.Delet name\n3.List names\n4.Close\nEnter: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        while (getchar() != '\n');

        switch (option){
            case 1:
                add_name(&string);
                break;
            
            case 2:
                delet_name(&string);
                break;

            case 3:
                size = strlen(string);
                printf("\nList:\n");
                for (int i = 0; i < size; i++){
                    if(string[i] == ','){
                        printf("\n");
                    }else{
                        printf("%c", string[i]);
                    }
                }        
                printf("\n");
                break;

            case 4:
                free(string);
                printf("Program closed.\n");
                return 0;
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    free(string);
    return 0;
}