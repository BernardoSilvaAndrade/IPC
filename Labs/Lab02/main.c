/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()

{
    int num1;
    printf ("Escolha entre o exercício 1,2,3 ou 4:\n");
    scanf ("%d", &num1);


  switch (num1)
  {
    
    case 1: 
    
    {
        
        int n,x,resultado;
        printf ("Digite um numero: ");
        scanf ("%d", &x);
        printf("A tabuada desse número é:");

        for(n=0;n<=10;n++)
        { resultado=x*n;
            
            printf ("\n%d\n",resultado);

        }


    break;
    }

    case 2: 
    
    {
        
        int z,total=1;
        printf ("Digite um numero inteiro: ");
        scanf ("%d", &z);
        if(z<0){
        printf ("Digite um numero inteiro positivo: ");
        } else {

        do {
            total*=z;
            z--;
        } while (z>=1);
        printf ("O fatorial desse número é:%d\n",total);
        }
    break;
    }
    
    case 3: 
    
    {
        
        int numero,digito,inverso=0;
        printf ("Digite um numero inteiro: ");
        scanf ("%d", &numero);
        
        while (numero != 0){
            digito = numero % 10;
            inverso = inverso*10+digito;
            numero = numero / 10;
        }
        
        printf("O número invertido é: %d\n", inverso);
         return 0;
        
     break;   
    }
    
    case 4: 
    
    {
        
        int numero,i,primo=1;
        printf ("Digite um numero inteiro: ");
        scanf ("%d", &numero);
        
        if (numero <= 1){
            primo=0;
        } else {
            for(i=2; i <= numero /2; i++) {
                if (numero %i == 0) {
                    primo=0;
                    break;
                }
            }
        }
        
        if (primo) {
        printf("%d é um número primo.\n", numero);
    } else {
        printf("%d não é um número primo.\n", numero);
    }
         return 0;
        
     break;   
    }
    
    default:
            printf("Opção inválida.\n");
            break;
 }
return 0;
}
