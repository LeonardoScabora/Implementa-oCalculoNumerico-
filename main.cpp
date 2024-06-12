#include <iostream>
#include <locale.h>
#include <iomanip>

using namespace std;
struct Paradas{
float X;
float Y;
float Z;
};

void Leitura(float vetA[], float vetB[], float vetC[], float vetD[]){

    for(int i=0; i<3; i++){
        cout << "valores de A" << i+1 << ": ";
        cin >> vetA[i];}
    for(int i=0; i<3; i++){
        cout << "valores de B" << i+1 << ": ";
        cin >> vetB[i];}
    for(int i=0; i<3; i++){
        cout << "valores de C" << i+1 << ": ";
        cin >> vetC[i];}
    for(int i=0; i<3; i++){
        cout << "valores de D" << i+1 << ": ";
        cin >> vetD[i];
    }
}

void Convergencia(float vetA[], float vetB[], float vetC[], float vetD[], float &b1, float &b2, float &b3){
int p = 0;
int maior = 0;
///B1
b1 = (vetA[p+1] + vetA[p+2]) / (vetA[p]);
///B2
b2 = ((vetB[p] * b1) + vetB[p+2]) / vetB[p+1];
///B3
b3 = ((vetC[p] * b1) + (vetC[p+1] * b2)) / vetC[p+2];

cout << endl;
cout << "B1: " << b1 << "; B2: " << b2 << "; B3: " << b3 << endl;
        if(b1 > maior){
            maior = b1;
        }else if(b2 > maior){
            maior = b2;
        }else{
        maior = b3;
        }
        if(maior < 1){
            cout << "Convergente\n";
        }

}

void SolucaoInicial(float vetA[], float vetB[], float vetC[], float vetD[], float vetSoluZero[]){
int p=0;
    cout << "\nSolução Inicial\n";

vetSoluZero[p] = (vetD[p]) / (vetA[p]);
vetSoluZero[p+1] = vetD[p+1] / vetB[p+1];
vetSoluZero[p+2] = vetD[p+2] / vetC[p+2];

cout << endl;
cout << "Xº: " << vetSoluZero[p] << "; Yº: " << vetSoluZero[p+1] << "; Zº: " << vetSoluZero[p+2] << endl;

}

void CondicaoParada(float vetA[], float vetB[], float vetC[], float vetD[], float vetSoluZero[], float PriInte[], float SegInte[], float TerInte[]){
int p=0;
float maiorX =0;
float maiorY=0;
float maiorZ=0;
float ER = 0;
float maiorTodos= 0;
cout << setprecision(3);
    cout << "\nCondição de Parada\n";
///1º interação TA CERTO
PriInte[p] = (1/vetA[p]) * (vetD[p] - vetSoluZero[p+1] - vetSoluZero[p+2]);
PriInte[p+1] = (1/vetB[p+1]) * (vetD[p+1] - (vetB[p] * PriInte[p]) - vetSoluZero[p+2]);
PriInte[p+2] = (1/vetC[p+2]) * (vetD[p+2] - PriInte[p] - PriInte[p+1]);

///2º interação
SegInte[p] = (1/vetA[p]) * (vetD[p] - PriInte[p+1] - PriInte[p+2]);///SE DER B.O VER AQUI O SINAL DE +
SegInte[p+1] = (1/vetB[p+1]) * (vetD[p+1] - (vetB[p] * SegInte[p]) - PriInte[p+2]);
SegInte[p+2] = (1/vetC[p+2]) * (vetD[p+2] - SegInte[p] - SegInte[p+1]);


///3º interação
TerInte[p] =  (1/vetA[p]) * (vetD[p] - SegInte[p+1] - SegInte[p+2]);
TerInte[p+1] = (1/vetB[p+1]) * (vetD[p+1] - (vetB[p] * TerInte[p]) - SegInte[p+2]);
TerInte[p+2] = (1/vetC[p+2]) * (vetD[p+2] - TerInte[p] - TerInte[p+1]);


maiorX = TerInte[p] - SegInte[p];
maiorY = TerInte[p+1] - SegInte[p+1];
maiorZ = TerInte[p+2] - SegInte[p+2];
if(maiorX > maiorTodos){
    maiorTodos = maiorX;
}else if(maiorZ > maiorTodos){
    maiorTodos = maiorZ;
}else{
    maiorTodos = maiorY;
}
ER = (maiorTodos / TerInte[p]);

if(ER < 0.05){
    cout << setprecision(1);
    cout << "ER: " << ER << endl;
    cout << setprecision(3);
    cout << "X(1)\n";
    cout << "x: " << PriInte[p] << endl;
    cout << "y: " << PriInte[p+1] << endl;
    cout << "z: " << PriInte[p+2] << endl;
}else{
    cout << "Algo deu errado!!" << endl;
}

}

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil" );
    bool ativo = true;
    int num;
    int T=2;
    int z=3;
    float vetA[T];
    float vetB[T];
    float vetC[T];
    float vetD[T];
    float b1, b2, b3 = 0 ;
    float vetSoluZero[T];
    float PriInte[T];
    float SegInte[T];
    float TerInte[T];

        while(ativo == true){

        cout << "\nImplementa Brito\n";
        cout << "1-Inserir o valor\n";
        cout << "2-Convergencia\n";
        cout << "3-Solução Inicial\n";
        cout << "4-Condição de Parada\n";
        cout << "5-Sair\n";
        cout << "Qual operação deseja? R: ";
        cin >> num;

            switch(num){
                case 1:
                    Leitura(vetA, vetB, vetC, vetD);
                    break;
                case 2:
                    Convergencia(vetA, vetB, vetC, vetD, b1, b2, b3);
                    break;
                case 3:
                    SolucaoInicial(vetA, vetB, vetC, vetD, vetSoluZero);
                    break;
                case 4:
                    CondicaoParada(vetA, vetB, vetC, vetD, vetSoluZero, PriInte, SegInte, TerInte);
                    break;
                case 5:
                    ativo = false;
                    break;
                   }
        }
}
