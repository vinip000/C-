// Integrantes: Pedro Kons, Taryck Santos, Thiago Yukio, Vinicius Pereira
#include <iostream>
using namespace std;
#include <locale.h>
int main()
{
//Pack de linguagem para incluir a língua portuguesa
    setlocale (LC_ALL, "Portuguese");

//Utilizamos o long long int para podermos ampliar a capacidade de recepção de algarismos de cada variável
    long long int cdg, d12, d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, s11, s9, s7, s5, s3, s1, soma3, soma5, dvs4, mtp6, digito;

    cout << "Informe o código de barras: ";
    cin >> cdg;

// Divisão do número do código de barras e depois é feito o resto para selecionar o número que queremos
    d12 = cdg / 1000000000000;
    d11 = (cdg / 100000000000) % 10;
    d10 = ((cdg / 10000000000) % 100) % 10 ;
    d9 = ((((cdg / 1000000000) % 1000)% 100)% 10);
    d8 = (((((cdg / 100000000) % 10000) % 1000)% 100)% 10);
    d7 = ((((((cdg / 10000000) % 100000) % 10000) % 1000)% 100)% 10);
    d6 = (((((((cdg / 1000000) % 1000000) % 100000) % 10000) % 1000)% 100)% 10);
    d5 = ((((((((cdg / 100000) % 10000000) % 1000000) % 100000) % 10000) % 1000)% 100)% 10);
    d4 = (((((((((cdg / 10000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000)% 100)% 10);
    d3 = ((((((((((cdg / 1000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000)% 100)% 10);
    d2 = (((((((((((cdg / 100) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000)% 100)% 10);
    d1 = ((((((((((((cdg / 10) % 100000000000) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000)% 100)% 10);
    d0 = (((((((((((((cdg / 1) % 1000000000000) % 100000000000) % 10000000000) % 1000000000) % 100000000) % 10000000) % 1000000) % 100000) % 10000) % 1000)% 100)% 10);

// Multiplicação dos variáveis impares por 3
    s11 = d11 * 3;
    s9 = d9 * 3;
    s7 = d7 * 3;
    s5 = d5 * 3;
    s3 = d3 * 3;
    s1 = d1 * 3;

// Somatório dos resultados das variáveis ímpares, após a multiplicação, com as variáveis pares
    soma3 = s11 + s9 + s7 + s5 + s3 + s1 + d12 + d10 + d8 + d6 + d4 + d2;

// Divisão do resultado obtido na soma anterior por 10
    dvs4 = soma3 / 10;

//Somatório da divisão anterior com 1
    soma5 = dvs4 + 1;

//Multiplicação do resultado anterior por 10
    mtp6 = soma5 * 10;

//Processo para obter o digito verificador, subtraindo o resultado da multiplicação feita anteriormente pelo resultado obtido na somatória das variáveis
    digito = mtp6 - soma3;

//Se o código for maior que 13 algarismos, ele é inválido
    if (cdg > 9999999999999 ) {

        cout << "\nO código é inválido" << endl;
    }

//Caso o resultado for um multiplo de 10 e o digito de verificação for 0 o código de barras está correto
    else if (digito % 10 == 0 and d0 == 0) {

        cout << "\nO código está correto" << endl << "\nDigito de confirmação: 0" << endl;
    }

//Se o resultado for diferente do digito de verificação, o código está incorreto
    else if (d0 != digito) {

        cout << "\nO código está incorreto" << endl;

//Caso não se enquadre em nenhuma das alternativas anteriores, o código está correto
    } else {

        cout << "\nO código está correto" << endl << "\nDigito de confirmação: "<< digito << endl;
    }

    return 0;
}
