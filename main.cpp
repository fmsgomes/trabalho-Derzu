#include <iostream>
#include <string>
#include "Plano.h"
#include "Planobasico.h"
#include "Planointermediario.h"
#include "Planocompleto.h"
#include "DadosVeiculo.h"
#include "Proprietario.h"
#include "Gerenciarplanos.h"
using namespace std;

int main() {
    Gerenciarplanos sistema;
    sistema.carregarDadosDoArquivo();
    int opcao;
    int indice;

    while(opcao != 6){
        cout << "\nMenu de Operações:\n";
        cout << "1 - Adicionar Plano\n";
        cout << "2 - Listar Todos\n";
        cout << "3 - Exibir Um\n";
        cout << "4 - Alterar Plano\n";
        cout << "5 - Remover Plano\n";
        cout << "6 - Sair do programa\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore(); // Para limpar o buffer de entrada após ler o número

        switch (opcao) {
            case 1:
                cout << "\nDigite o número de cadastro: ";
            cin >> indice;
            sistema.inserirPlanos(indice);
            break;
            case 2:
                sistema.exibirTodos();
            break;

            case 3:
                sistema.exibirumPlano();
            break;
            case 4:
                sistema.alterarPlanos();
            break;
            case 5:
                sistema.deletarPlanos();
            break;
            case 6:
                cout << "\nSalvando dados antes de sair...\n";
                sistema.salvarDadosEmArquivo();
                cout << "\nSaindo do sistema...\n";
            return 0;
            default:
                cout << "\nOpção inválida! Tente novamente.\n";
            break;
        }
    }

    return 0;
}