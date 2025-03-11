#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//funcao 01
double ex01(double x,double y)
{double resto,total=0,num;
 for (int num=x+1; num<y; num++)
 {
  if (num %2==0)
    total+=pow(num,3); 
     else
     total+=0;

 }return total;
}

//funcao 02
long double fac(unsigned int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fac(n - 1);
}

void igualdade(int x)
{
    int i = 2, cont = 0;
    double ex = exp(x);
    double sum = 1 + x;
    double diferenca = 0.00001;
    while (1)
    {
        if (ex - sum < diferenca)
            break;

        sum += pow(x, i) / fac(i);
        i++;
        // printf("cont %d   sum %lf   i %d     pow %lf     fac %Lf    ex-sum%lf\n\n", cont, sum, i, pow(x, i), fac(i), (ex - sum));
    }
    printf("Numero de vezes necessaria para precisão de 4 casas decimais: %d\nMinha soma: %lf\nexp da math.h: %lf\n", (i - 2), sum, ex);
} 


//funcao03
void calcularCpf(int cpf[11]) {
    int i, resultado=0, resto=0;

    //1 digito verificador
    for (i=0; i<9; i++) {
        resultado += cpf[i] * (10 - i);//peso
    }
    resto = resultado % 11;
    cpf[9] = (resto < 2) ? 0 : 11 - resto;

    //2 digito verificador
    resultado = 0; // rsetar resultado para o segundo calc
    for (i = 0; i < 10; i++) {
        resultado += cpf[i] * (11 - i);
    }
    resto = resultado % 11;
    cpf[10] = (resto < 2) ? 0 : 11 - resto;
}

//funcao 04
void calcularDigitosVerificadores(char cnpj[14]) {
    int i, soma = 0, digito1, digito2;
    int pesos1[12] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2}; //cada peso de um digito do primeiro verificador
    int pesos2[13] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};//cada peso de um digito do segundo verificador

    //calculo do primeiro dígito verificador
    for (i = 0; i < 12; i++) {
        soma += (cnpj[i] - '0') * pesos1[i];
    }
    digito1 = (soma % 11 < 2) ? 0 : 11 - (soma % 11);
    
    //calculo do segundo digito verificador
    soma = 0; //resetar a soma(faz de um digito para dps fazer do outro)
    for (i = 0; i < 12; i++) {
        soma += (cnpj[i] - '0') * pesos2[i];
    }
    soma += digito1 * 2; //adicionar o primeiro digito calculado
    digito2 = (soma % 11 < 2) ? 0 : 11 - (soma % 11);//verificando se e divisivel por 11

    //exibir os digitos verificadores
    printf("Digitos verificadores: %d%d\n", digito1, digito2);
}


//escolha do exercicios
int main(){
    int num1;
    printf ("Escolha entre o exercicio 1,2,3 ou 4:\n");
    scanf ("%d", &num1);

  switch (num1)
  {
    
    //exercicio01
    case 1: 
    {
    double cubo,a,b;

        printf ("Digite o valor de A: ");
        scanf ("%lf", &a);
        printf ("Digite o valor de B: ");
        scanf ("%lf", &b);
        if(a==0 && b==0){
         break;
        }
        cubo=ex01(a,b);
        printf("Soma dos cubos do par de numeros escrito: %0.lf e %0.lf  = %0.lf \n",a,b,ex01(a,b));
    } 
    return 0;
    break;

      //exercicio02
    case 2: 
    {
    int num;
        printf("Qual numero deseja utilzar na equacao:? ");
        scanf("%d", &num);
        igualdade(num);
   }
    break;

    //exercicio03

    case 3: {
        int cpf[11]; //o cpf tera 11 dígitos

    printf("\nDigite seu CPF sem o numero verificador: ");

    for (int i=0; i<9; i++) {
        scanf("%1d", &cpf[i]);
    }

    calcularCpf(cpf);//chamar a funcao para calcular os dígitos verificadores

    //mostrar o CPF completo
    printf("O numero verificador do CPF e: ");
    for (int i = 0; i < 11; i++) {
        printf("%d", cpf[i]);
    }
    printf("\n");
    }break;

    case 4:{
            char cnpj[14];

    printf("Digite os 12 primeiros digitos do cnpj: ");
    scanf("%13s", cnpj);

    calcularDigitosVerificadores(cnpj);

    return 0;

    }
    }
} 
