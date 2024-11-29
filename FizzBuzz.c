/*
    Jogo FizzBuzz
    O jogo lista números que estão no intervalo [RANGE_START, RANGE_END].
    Deve-se escolher dois números para testar a divisibilidade.
    Neste exemplo, quando o número for divisível por 3, será impresso Fizz, e quando for divisível por 5, será impresso Buzz.
    Se ele for dividível por 3 e 5, será impresso FizzBuzz.

    Autora: Andressa Von Ahnt
*/

#include <stdio.h>
#include <stdlib.h>

#define RANGE_START 1
#define RANGE_END 100

#define FIZZ 3
#define BUZZ 5

int main(){
    for (int i = RANGE_START; i <= RANGE_END; i++){
        if((i % FIZZ == 0) && (i % BUZZ == 0)){
            printf("FizzBuzz\n");
        }else{
            if(i % FIZZ == 0){
                printf("Fizz\n");
            }else{
                if(i % BUZZ == 0){
                    printf("Buzz\n");
                }else{
                    printf("%d\n", i);
                }
            }
        }
    }
}