// Alunos: Pedro Henrique, Taryck, Thiago Pacheco, Vin�cius Pereira.

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>

#define RAND_MAX 2O

using namespace std;

int main()
{
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.

    int random1,random2,random3; //Utilizado para criar obstaculos aleatoriamente
    srand(time(NULL));
    random1=rand()%10;
    random2=rand()%10;
    random3=rand()%10;

    int bird_x = 5, bird_y = 10;
    int obstaculo_x = 30, obstaculo_x2 = 60, obstaculo_x3 = 90, obstaculo_y, obstaculo_y2, obstaculo_y3;
    int tecla;
    int pontuacao = 0;

    ///DESENHO DO CEN�RIO
    while (true) { //este la�o faz o jogo executar infinitamente
        system("cls"); // Utilizado para limpar rastros do p�ssaro e dos obst�culos no cmd.
        cout<<"--------------------------------------------------------------------------------------------"; // Desenho das bordas do cen�rio.
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"; // Espa�ameto onde ser� rodado o game
        cout<<"--------------------------------------------------------------------------------------------";
        cout<< "\n- Pontuacao: " << pontuacao << endl; // Pontua��o exibida na parte inferior esquerda do game

    /// POSICIONAMENTO DO P�SSARO
    coord.X = bird_x;    coord.Y = bird_y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout<<char(190); //Caractere utilizado para simboliz�-lo


    ///POSICIONA O OBST�CULO
    obstaculo_y=1; // Valor inicial dado ao obst�culo 1.
    while(obstaculo_y<20){ // Enquanto o valor de Y estiver dentro dos padr�es estabelecidos, o la�o ser� repetido.
        coord.X = obstaculo_x;    coord.Y = obstaculo_y; //
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if(obstaculo_y<random1|| obstaculo_y>random1+4){ // Valores dados para a ocupa��o do obst�culo no eixo Y
            cout<<char(219); // Caractere escolhido para representar as colunas
            } else { // Caso n�o se encaixe nos padr�es estabelecidos, haver� uma abertura nos obst�culos.
                cout<<" "; // Caractere de espa�amento
            }
    obstaculo_y++; // Acionar um obst�culo infinitamente enquanto o la�o de repeti��o estiver executando
    }

    obstaculo_y2=1; // Valor inicial dado ao obst�culo 2.
    while(obstaculo_y2<20){ // Enquanto o valor de y2 estiver dentro dos padr�es estabelecidos, o la�o ser� repetido.
        coord.X = obstaculo_x2;    coord.Y = obstaculo_y2;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if(obstaculo_y2<random2 || obstaculo_y2>random2+4){ // Valores dados para a ocupa��o do obst�culo y2 no eixo Y
            cout<<char(219);
            } else {
                cout<<" ";
            }
    obstaculo_y2++;
    }

    obstaculo_y3=1; // Valor inicial dado ao obst�culo 2.
    while(obstaculo_y3<20){  // Enquanto o valor de y3 estiver dentro dos padr�es estabelecidos, o la�o ser� repetido.
        coord.X = obstaculo_x3;    coord.Y = obstaculo_y3;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if(obstaculo_y3<random3 || obstaculo_y3>random3+4){ // Valores dados para a ocupa��o do obst�culo y3 no eixo Y
            cout<<char(219);
            } else {
                cout<<" ";
            }
            obstaculo_y3++;
        }

    ///VERIFICA COLIS�O
    if (bird_x  == obstaculo_x && (bird_y >= random1 && bird_y <= random1+4)){ // Caso o p�ssaro passe pelo espa�amento entre o obst�culo 1, o desvio descrito abaixo ser� executado.
        pontuacao += 1; // Adiciona 1 na pontua��o
        } else if (bird_x  == obstaculo_x){ // Caso haja uma colis�o do p�ssaro no obst�culo 1, realizar o desvio:
            system("cls");
            cout<< "Game Over!" << endl; // Mensagem
            cout<< "Sua pontuacao foi : "<< pontuacao << endl;
            system("pause"); // Pausa a execu��o da aplica��o.
            return 0;
        }

    if (bird_x  == obstaculo_x2 && (bird_y >= random2 && bird_y <= random2+4)){ // Caso o p�ssaro passe pelo espa�amento entre o obst�culo 2, o desvio descrito abaixo ser� executado.
        pontuacao += 1;
        } else if (bird_x  == obstaculo_x2){ // Caso haja uma colis�o do p�ssaro no obst�culo 2, realizar o desvio:
            system("cls");
            cout<< "Game Over!" << endl;
            cout<< "Sua pontuacao foi : "<< pontuacao<< endl;
            system("pause");;
            return 0;
        }

    if (bird_x  == obstaculo_x3 && (bird_y >= random3 && bird_y <= random3+4)){ // Caso o p�ssaro passe pelo espa�amento entre o obst�culo 3, o desvio descrito abaixo ser� executado.
        pontuacao += 1;
        } else if (bird_x  == obstaculo_x3){ // Caso haja uma colis�o do p�ssaro no obst�culo 3, realizar o desvio:
            system("cls");
            cout<< "Game Over!" << endl;
            cout<< "Sua pontuacao foi : "<< pontuacao<< endl;
            system("pause");
            return 0;
            }

    if (bird_y == 20 ){ // Caso o p�ssaro toque na borda inferior do jogo, o desvio ser� realizado
        system("cls");
        cout<< "Game Over!" << endl;
        cout<< "Sua pontuacao foi : "<< pontuacao<< endl;
        system("pause");
        return 0;
        }

    if (bird_y == 0){ // Caso o p�ssaro toque na borda superior do jogo, o desvio ser� realizado
        system("cls");
        cout<< "Game Over!" << endl;
        cout<< "Sua pontuacao foi : "<< pontuacao<< endl;
        system("pause");
        return 0;
        }

    ///VERIFICA COMANDO DO JOGADOR
    if (kbhit()) { ///verifica se uma tecla foi pressionada
        tecla=getch(); //verifica comando do jogador
        }
    if ( tecla=='w' ){ // Caso a tecla w seja acionada, o p�ssaro vai para cima.
        bird_y--;
        tecla='0';
        } else { // Caso a tecla n�o seja acionada, ele cai uma posi��o.
            bird_y++;
        }

    ///OBST�CULO AVAN�A UMA POSI��O PARA ESQUERDA
    if (obstaculo_x <= 0) { // Quando o obst�culo surgir pela direita, realizar o desvio:
        obstaculo_x = 90; // O obst�culo surge no ponto mais distante
         random1=rand()%10;
        }
    if (obstaculo_x2 <=0){
        obstaculo_x2 =90;
         random2=rand()%10;
        }
    if (obstaculo_x3 <=0){
        obstaculo_x3 =90;
        random3=rand()%10;
        }
    obstaculo_x--; // O obst�culo vai se recuando para a esquerda a cada desvio realizado
    obstaculo_x2--;
    obstaculo_x3--;

    ///TEMPO DE ESPERA
    if ( pontuacao >= 0 && pontuacao < 5) { // Como n�o conseguimos aumentar a velocidade atrav�s do la�o de repeti��o, fizemos por meio de desvios condicionais.
        Sleep(180);
        } else if ( pontuacao >= 5 && pontuacao < 10 ) {
            Sleep(130);
        } else if ( pontuacao >= 10 && pontuacao < 15 ) {
            Sleep(110);
        } else if ( pontuacao >= 15 && pontuacao < 20 ) {
            Sleep(90);
        } else if ( pontuacao >= 25 ) {
            Sleep(50);
        }
    }
    return 0;
}
