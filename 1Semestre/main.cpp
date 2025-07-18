// Integrantes: Pedro Kons, Taryck Santos, Thiago Yukio, Vinicius Pereira
#include <iostream>
using namespace std;
#include <locale.h>
int main()
{
//Pack de linguagem para incluir a l�ngua portuguesa
    setlocale (LC_ALL, "Portuguese");

//Utilizamos o long long int para podermos ampliar a capacidade de recep��o de algarismos de cada vari�vel
    long long int cdg, d12, d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, s11, s9, s7, s5, s3, s1, soma3, soma5, dvs4, mtp6, digito;

    cout << "Informe o c�digo de barras: ";
    cin >> cdg;

// Divis�o do n�mero do c�digo de barras e depois � feito o resto para selecionar o n�mero que queremos
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

// Multiplica��o dos vari�veis impares por 3
    s11 = d11 * 3;
    s9 = d9 * 3;
    s7 = d7 * 3;
    s5 = d5 * 3;
    s3 = d3 * 3;
    s1 = d1 * 3;

// Somat�rio dos resultados das vari�veis �mpares, ap�s a multiplica��o, com as vari�veis pares
    soma3 = s11 + s9 + s7 + s5 + s3 + s1 + d12 + d10 + d8 + d6 + d4 + d2;

// Divis�o do resultado obtido na soma anterior por 10
    dvs4 = soma3 / 10;

//Somat�rio da divis�o anterior com 1
    soma5 = dvs4 + 1;

//Multiplica��o do resultado anterior por 10
    mtp6 = soma5 * 10;

//Processo para obter o digito verificador, subtraindo o resultado da multiplica��o feita anteriormente pelo resultado obtido na somat�ria das vari�veis
    digito = mtp6 - soma3;

//Se o c�digo for maior que 13 algarismos, ele � inv�lido
    if (cdg > 9999999999999 ) {

        cout << "\nO c�digo � inv�lido" << endl;
    }

//Caso o resultado for um multiplo de 10 e o digito de verifica��o for 0 o c�digo de barras est� correto
    else if (digito % 10 == 0 and d0 == 0) {

        cout << "\nO c�digo est� correto" << endl << "\nDigito de confirma��o: 0" << endl;
    }

//Se o resultado for diferente do digito de verifica��o, o c�digo est� incorreto
    else if (d0 != digito) {

        cout << "\nO c�digo est� incorreto" << endl;

//Caso n�o se enquadre em nenhuma das alternativas anteriores, o c�digo est� correto
    } else {

        cout << "\nO c�digo est� correto" << endl << "\nDigito de confirma��o: "<< digito << endl;
    }

    return 0;
}
