#pragma once
#include <iostream>
#include <string>
#include "Plano.hpp"
#include "Planobasico.hpp"
#include "Planointermediario.hpp"
#include "Planocompleto.hpp"
#include "DadosVeiculo.hpp"
#include "Proprietario.hpp"
#define NUM_MAX_PLANOS 100
using namespace std;
class Gerenciarplanos {
    private:
    Plano* plano[NUM_MAX_PLANOS];
    int indice;
    
    public:

    Gerenciarplanos(){
        for(int i = 0; i < NUM_MAX_PLANOS; i++){
            plano[i] = nullptr;
        }
    }
    ~Gerenciarplanos(){
        deletarPlanos();
    }

    void deletarPlanos(){
        for(int i = 0; i < NUM_MAX_PLANOS; i++){
            if(plano[i] != nullptr){
            delete plano[i];
            plano[i] = nullptr;
            }
        }
    }

    void inserirPlanos(int ind){
        for(int i = 0; i < NUM_MAX_PLANOS; i++){
            if(plano[ind] != nullptr || ind < 0 || ind >= NUM_MAX_PLANOS){
                cout << "O índice posto já ocupa um lugar, tente novamente.\n";
                return;
            }
            DadosVeiculo veiculo("", "", "", "", 0);
            veiculo.lerDadosVeiculo();

            Proprietario proprietario("", "");
            proprietario.lerDadosProprietario();


            int tipo;

            cout << "Digite o tipo de plano que será cadastrado:\n";
            cout << "(1)Plano Básico.\n(2)Plano Intermediário.\n(3)Plano Completo.\nInsira uma das opções: ";
            cin >> tipo;

            switch(tipo){
                case 1:
                cout << "O Plano Básico oferece suporte aos seguintes acontecimentos:\n";
                cout << "Coisão.\nRoubo;\nFurto;\nIncêndio;\nDanos por eventos naturais;\nDanos materiais e pessoais a terceiros.\n";
                plano[ind] = new Planobasico(veiculo, proprietario);
                cout << "O novo plano foi cadastrado!\n";
                break;

                case 2:
                cout << "O Plano Intermediário oferece suporte aos seguintes acontecimentos:\n";
                cout << "Coisão.\nRoubo;\nFurto;\nIncêndio;\nDanos por eventos naturais;\nDanos materiais e pessoais a terceiros;\n";
                cout << "Quebra de vidros, faróis e retrovisores;\nDanos por alagamento.\n";
                plano[ind] = new Planointermediario(veiculo, proprietario);
                cout << "O novo plano foi cadastrado!\n";
                break;

                case 3:
                cout << "O Plano Completo oferece suporte aos seguintes acontecimentos:\n";
                cout << "Coisão.\nRoubo;\nFurto;\nIncêndio;\nDanos por eventos naturais;\nDanos materiais e pessoais a terceiros;\n";
                cout << "Quebra de vidros, faróis e retrovisores;\nDanos por alagamento;\n";
                cout << "Assistência de reboque;\nSocorro mecânico;\nChaveiro;\nPane seca\nTroca de pneu.\n";
                plano[ind] = new Planocompleto(veiculo, proprietario);
                cout << "O novo plano foi cadastrado!\n";
                break;
                default:
                cout << "Opção inválida.\n";
                break;
                }

            }

        }
};