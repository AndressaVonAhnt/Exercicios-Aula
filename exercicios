/*
    Este código implementa uma agenda em que se armazena o nome, idade e número de telefone de n pessoss (n não é pré estabelecido)
    É usado apenas um ponteiro (pBuffer) para fazer o armazenamento
    É possível adicionar, listar, buscar e excluir pessoas da agenda

    Autora: Andressa Von Ahnt
*/      

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FlushStdin() {
    while(getchar()!= '\n');
}

void PrintPerson(char *ptr){
    printf("Name: ");
        while(*ptr != '\0'){
            putchar(*ptr);
            ptr++;
        }
        ptr++;

        printf("\nAge: ");
        while(*ptr != '\0'){
            putchar(*ptr);
            ptr++;
        }
        ptr++;

        printf("\nPhone Number: ");
        while(*ptr != '\0'){
            putchar(*ptr);
            ptr++;
        }
        ptr++;
        printf("\n");
}

void AddPerson(void** pBuffer, int* size){
    char name[10], phone[10], age[3];
    int i;

    printf("\nName (max 9 characters): ");
    if((fgets(name, 10, stdin))== NULL){
        printf("Error reading name\n");
        exit(1);
    }
    
    if((i = strcspn(name, "\n")) >= 9)
        FlushStdin();
    else
        name[i] = '\0';

    printf("Age: ");
    if((fgets(age, 3, stdin))== NULL){
        printf("Error reading name\n");
        exit(1);
    }
    
    if((i = strcspn(age, "\n")) >= 2)
        FlushStdin();
    else
        age[i] = '\0';

    printf("Phone Number: ");
    if((fgets(phone, 10, stdin))== NULL){
        printf("Error reading phone number\n");
        exit(1);
    }
    
    if((i = strcspn(phone, "\n")) >= 9)
        FlushStdin();
    else
        phone[i] = '\0';

    size_t nameSize = strlen(name) + 1;
    size_t ageSize = strlen(age) + 1;
    size_t phoneSize = strlen(phone) + 1;

    int size_old = *size;
    int recordSize = nameSize + ageSize + phoneSize;
    *size += recordSize;

    if((*pBuffer = realloc(*pBuffer, *size)) == NULL){
        printf("Error allocating memory");
        exit(1);
    }

    memset((char*)*pBuffer + size_old, 0, *size - size_old);
    char *ptr = (char *)*pBuffer + size_old;

    memcpy(ptr, name, nameSize);
    ptr += nameSize;
    memcpy(ptr, age, ageSize);
    ptr += ageSize;
    memcpy(ptr, phone, phoneSize);
}

void ListPeople(void* pBuffer){
    int count = *(int *)pBuffer;
    printf("\nTotal: %d %s\n", count, count == 1 ? "person" : "people");

    char *ptr = (char *)pBuffer + sizeof(int);
    
    for (int i = 0; i < count; i++){
        printf("\nPerson %d\n", i + 1);
        PrintPerson(ptr);

        while (*ptr != '\0') ptr++; 
        ptr++; 
        while (*ptr != '\0') ptr++; 
        ptr++;
        while (*ptr != '\0') ptr++; 
        ptr++;
    }
}

char* SearchPerson(void *pBuffer, int a){
    char name[10];
    int i;

    printf("\nName: ");
    if((fgets(name, 10, stdin))== NULL){
        printf("Error reading name\n");
        exit(1);
    }
    
    if((i = strcspn(name, "\n")) >= 9)
        FlushStdin();
    else
        name[i] = '\0';

    char *ptr = (char *)pBuffer + sizeof(int);
    int count = *(int *)pBuffer;
    
    for (i = 0; i < count; i++) {
        if (strcmp(ptr, name) == 0) {
            if(a){
                printf("\nPerson found:\n");
                PrintPerson(ptr);
            }
            return ptr;
        }

        while (*ptr != '\0') ptr++; 
        ptr++; 
        while (*ptr != '\0') ptr++; 
        ptr++; 
        while (*ptr != '\0') ptr++; 
        ptr++; 
    }

    printf("\nName not found.\n");
    return NULL;
}

void DeletPerson(void **pBuffer, int *size){
    char* ptr = SearchPerson(*pBuffer, 0);

    if(ptr != NULL){
        char *current = ptr;
        size_t ptrSize = 0;

        while (*current != '\0') {
            current++; 
            ptrSize++;
        }
        current++;
        ptrSize++;

        while (*current != '\0') {
            current++; 
            ptrSize++;
        }
        current++; 
        ptrSize++;

        while (*current != '\0') {
            current++; 
            ptrSize++;
        }
        current++; 
        ptrSize++;

        size_t remainingSize = *size - (current - (char *)*pBuffer);

        memmove(ptr, current, remainingSize);
    
        void* temp = realloc(*pBuffer, *size - ptrSize);
        if (temp == NULL) {
            printf("Error reallocating memory.\n");
            exit(1);
        }
        *pBuffer = temp;

        (*(int *)(*pBuffer))--;
        *size -= ptrSize;
        printf("\nName deleted.\n");
    }
}

int main(){
    void* pBuffer;
    int option = 0;
    int size = sizeof(int);

    if((pBuffer = calloc(1, sizeof(int))) == NULL){
        printf("Error allocating memory");
        exit(1);
    }  

    while(1){
        printf("\nInsert an option:\n1.Add person\n2.List people\n3.Search person\n4.Delet Person\n5.Close\nEnter: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            FlushStdin();
        }
        FlushStdin();

        switch (option){
            case 1:
                AddPerson(&pBuffer, &size);
                (*(int*)pBuffer)++;
                break;
            
            case 2:
                ListPeople(pBuffer);
                break;

            case 3:
                SearchPerson(pBuffer, 1);
                break;

            case 4:
                DeletPerson(&pBuffer, &size);
                break;

            case 5:
                free(pBuffer);
                printf("\nProgram closed.\n");
                return 0;
                break;

            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    free(pBuffer);
    return 0;
}
