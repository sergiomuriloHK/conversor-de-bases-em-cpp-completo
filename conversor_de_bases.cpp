#include <iostream>
#include <list>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

// Essa função converte um número decimal para binário
string decimalParaBinario(int dec){
    string bin;
    string aux;
    if (dec == 0){
        bin += "0";
        return bin;
    }
    // Aqui é feito a conversão
    while (dec != 0){
        // A variável bin vai receber 0 se o resto da divisão do número decimal por dois for zero...
        // Caso contrário a variável receberá um
        aux += (dec % 2 == 0 ? "0" : "1");
        dec /= 2;
    }
    // O número binário na variável está invertido para isso tem que escrever na tela o número...
    // começando do seu último algarismo ao primeiro
    for (int i = aux.length(); i >= 0; i--){
        bin += aux[i];
    }
    return bin;
}

// Essa função converte um número binário para decimal
int binarioParaDecimal(string num){
    int dec = 0;
    for (int i = 0; i < num.length(); i++){
        int int_num = num[i] - 48;
        // Analisa se o número digitado contém apenas zeros e uns
        if ((int_num != 0) && (int_num != 1)){
            // Caso contenha algum número diferente de 0 ou 1 a função retornará -1 para tratar a exceção no loop principal
            return -1;
        }
        else{
            // Multiplica um algarismo do do número binário pela base 2 elevada a respectiva posição desse número
            dec += int_num*pow(2,(num.length()-i-1));
        }
    }
    return dec;
}

// Menu pricipal
int menu(){
     int escolha;
     cout << "--------------------\n";
     cout << " CONVERSOR DE BASES\n";
     cout << "--------------------\n";
     cout << "Escolha uma das opcoes:\n";
     cout << " [ 1 ] Converter de DECIMAL para BINARIO\n";
     cout << " [ 2 ] Converter de BINARIO para DECIMAL\n";
     cout << " [ 0 ] Sair do programa\n\n";
     cout << "Digite a opcao: ";
     // Aqui o programa vai receber a escolha do usuário e retornará o valor escolhido
     cin >> escolha;
     cout << endl;
     return escolha; 
}

int main(){
    bool run = true;
    // Loop principal
    while (run){
        int valor = 0;
        int decimal = 0;
        switch(menu()){
            // Decimal para binário
            case 1:
                cout << "Agora digite um numero DECIMAL para a conversao: ";
                cin >> valor;
                valor = std::abs(valor);
                valor = valor;
                cout << "O numero " << valor << " em BINARIO fica: " << decimalParaBinario(valor);
                break;
            // Binário para decimal
            case 2:
                cout << "Agora digite um numero BINARIO para a conversao: ";
                cin >> valor;
                valor = std::abs(valor);
                decimal = binarioParaDecimal(to_string(valor));
                if (decimal == -1){
                    cout << "O valor informado nao e binario.";
                }
                else{
                    cout << "O numero " << valor << " em DECIMAL fica: " << decimal;
                }
                break;
            // Sair do programa
            case 0: 
                run = false;
                break;
            // Tratamento de exceção
            default: 
                cout << "Por favor, digite uma opcao valida!";
            }
            cout << endl << endl;
        }
    // Mensagem de finalização e fim do programa
    cout << "Ate mais!";
    return 0;
}