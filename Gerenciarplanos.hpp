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
        Plano* planoencontrado = buscarPlanos();
        if(planoencontrado != nullptr){
        planoencontrado->imprimirPlano();
        }
        if(planoencontrado != nullptr){
            for(int i = 0; i < NUM_MAX_PLANOS; i++){
                if(plano[i] == planoencontrado){
                    delete plano[i];
                    plano[i] = nullptr;
                    cout << "O plano foi deletado!\n";
                    return;
                }
            }
        }else{cout << "O plano não foi encontrado!\n";}
    }
    void exibirumPlano(){
        Plano* planoencontrado = buscarPlanos();
        if(planoencontrado != nullptr){
            planoencontrado->imprimirPlano();
    }else{cout << "O plano não foi encontrado!\n";}
}
    void exibirTodos(){
        for(int i = 0; i < NUM_MAX_PLANOS; i++){
            if(plano[i] != nullptr){
                plano[i]->imprimirPlano();
                cout <<endl;
            }
        }
    }
    void alterarPlanos(){
        Plano* planoencontrado = buscarPlanos();
        if(planoencontrado != nullptr){
        planoencontrado->imprimirPlano();
        }
        if(planoencontrado != nullptr){
            for(int i = 0; i < NUM_MAX_PLANOS; i++){
                if(plano[i] == planoencontrado){
                    plano[i]->adicionarProprietario();
                    plano[i]->adicionarVeiculo();        
                    cout << "O plano foi alterado!\n";
                }
            }   
        }else{cout << "O plano não foi encontrado!\n";}
    }
    

    Plano* buscarPlanos() {
    string acharnome;
    cout << "Digite o nome que deseja procurar: ";
    getline(cin, acharnome);

    // Verifica todos os planos cadastrados
    for (int i = 0; i < NUM_MAX_PLANOS; i++) {
        if (plano[i] != nullptr && plano[i]->getProprietario().getNome() == acharnome) {
            return plano[i];  // Retorna o ponteiro do plano encontrado
        }
    }

    // Se não encontrar nenhum plano com esse nome
    cout << "Plano não encontrado para o proprietário: " << acharnome << endl;
    return nullptr;
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
                return;

                case 2:
                cout << "O Plano Intermediário oferece suporte aos seguintes acontecimentos:\n";
                cout << "Coisão.\nRoubo;\nFurto;\nIncêndio;\nDanos por eventos naturais;\nDanos materiais e pessoais a terceiros;\n";
                cout << "Quebra de vidros, faróis e retrovisores;\nDanos por alagamento.\n";
                plano[ind] = new Planointermediario(veiculo, proprietario);
                cout << "O novo plano foi cadastrado!\n";
                return;

                case 3:
                cout << "O Plano Completo oferece suporte aos seguintes acontecimentos:\n";
                cout << "Coisão.\nRoubo;\nFurto;\nIncêndio;\nDanos por eventos naturais;\nDanos materiais e pessoais a terceiros;\n";
                cout << "Quebra de vidros, faróis e retrovisores;\nDanos por alagamento;\n";
                cout << "Assistência de reboque;\nSocorro mecânico;\nChaveiro;\nPane seca\nTroca de pneu.\n";
                plano[ind] = new Planocompleto(veiculo, proprietario);
                cout << "O novo plano foi cadastrado!\n";
                return;
                default:
                cout << "Opção inválida.\n";
                return;
                }

            }

        }
};