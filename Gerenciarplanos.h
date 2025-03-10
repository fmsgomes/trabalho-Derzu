#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Plano.h"
#include "Planobasico.h"
#include "Planointermediario.h"
#include "Planocompleto.h"
#include "DadosVeiculo.h"
#include "Proprietario.h"
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
    void salvarDadosEmArquivo() {
        ofstream arquivo("dados_planos.txt");
        if (arquivo.is_open()) {
            for (int i = 0; i < NUM_MAX_PLANOS; i++) {
                if (plano[i] != nullptr) {

                    if (dynamic_cast<Planobasico*>(plano[i])) {
                        arquivo << "PlanoBásico\n";
                    } else if (dynamic_cast<Planointermediario*>(plano[i])) {
                        arquivo << "PlanoIntermediario\n";
                    } else if (dynamic_cast<Planocompleto*>(plano[i])) {
                        arquivo << "PlanoCompleto\n";
                    }

                    arquivo << plano[i]->getProprietario().getNome() << "\n";
                    arquivo << plano[i]->getProprietario().getDataNascimento().getdia() << "\n";
                    arquivo << plano[i]->getProprietario().getDataNascimento().getmes() << "\n";
                    arquivo << plano[i]->getProprietario().getDataNascimento().getano() << "\n";
                    arquivo << plano[i]->getProprietario().getTempoHabilitacao().getdia() << "\n";
                    arquivo << plano[i]->getProprietario().getTempoHabilitacao().getmes() << "\n";
                    arquivo << plano[i]->getProprietario().getTempoHabilitacao().getano() << "\n";
                    arquivo << plano[i]->getProprietario().getTelefone() << "\n";
                    arquivo << plano[i]->getProprietario().getEndereco().getRua() << "\n";
                    arquivo << plano[i]->getProprietario().getEndereco().getNum() << "\n";
                    arquivo << plano[i]->getProprietario().getEndereco().getBairro() << "\n";
                    arquivo << plano[i]->getProprietario().getEndereco().getCidade() << "\n";
                    arquivo << plano[i]->getProprietario().getEndereco().getEstado() << "\n";
                    arquivo << plano[i]->getProprietario().getEndereco().getCEP() << "\n";
                    arquivo << plano[i]->getProprietario().getEndereco().getComplemento() << "\n";

                    DadosVeiculo veiculo = plano[i]->getVeiculo();
                    arquivo << veiculo.getMarca() << "\n";
                    arquivo << veiculo.getModelo() << "\n";
                    arquivo << veiculo.getPlaca() << "\n";
                    arquivo << veiculo.getCategoria() << "\n";
                    arquivo << veiculo.getFipe() << "\n";

                    arquivo << "-------------\n";
                }
            }
            arquivo.close();
        } else {
            cout << "Erro ao abrir o arquivo para salvar os dados.\n";
        }
    }
    void carregarDadosDoArquivo() {
         ifstream arquivo("dados_planos.txt");
    string linha;
    int i = 0;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            if (i >= NUM_MAX_PLANOS) break;

            if (linha == "PlanoBásico") {
                string nome, telefone, rua, bairro, cidade, estado, cep, complemento;
                int num, diaNascimento, mesNascimento, anoNascimento;
                int diaHabilitacao, mesHabilitacao, anoHabilitacao;
                string marca, modelo, placa, categoria;
                float fipe;

                // Ler dados do proprietário e endereço
                getline(arquivo, nome);

                // Ler dados do proprietário (data de nascimento e habilitação)
                arquivo >> diaNascimento >> mesNascimento >> anoNascimento;
                arquivo >> diaHabilitacao >> mesHabilitacao >> anoHabilitacao;
                arquivo.ignore();

                getline(arquivo, telefone);
                getline(arquivo, rua);
                arquivo >> num;
                arquivo.ignore();
                getline(arquivo, bairro);
                getline(arquivo, cidade);
                getline(arquivo, estado);
                getline(arquivo, cep);
                getline(arquivo, complemento);


                // Ler dados do veículo
                getline(arquivo, marca);
                getline(arquivo, modelo);
                getline(arquivo, placa);
                getline(arquivo, categoria);
                arquivo >> fipe;
                arquivo.ignore();

                // Criar o proprietário e o veículo
                Proprietario proprietario(nome, telefone);
                proprietario.setEndereco(rua, num, bairro, cidade, estado, cep, complemento);
                proprietario.setDataNascimento(diaNascimento, mesNascimento, anoNascimento); // Definindo a data de nascimento
                proprietario.setTempoHabilitacao(diaHabilitacao, mesHabilitacao, anoHabilitacao); // Definindo a data de habilitação

                DadosVeiculo veiculo(marca, modelo, placa, categoria, fipe);  // Criando o objeto do veículo

                // Adicionar plano
                plano[i] = new Planobasico(veiculo, proprietario);
            }
            else if (linha == "PlanoIntermediario") {
                string nome, telefone, rua, bairro, cidade, estado, cep, complemento;
                int num, diaNascimento, mesNascimento, anoNascimento;
                int diaHabilitacao, mesHabilitacao, anoHabilitacao;
                string marca, modelo, placa, categoria;
                float fipe;

                // Ler dados do proprietário e endereço
                getline(arquivo, nome);

                // Ler dados do proprietário (data de nascimento e habilitação)
                arquivo >> diaNascimento >> mesNascimento >> anoNascimento;
                arquivo >> diaHabilitacao >> mesHabilitacao >> anoHabilitacao;
                arquivo.ignore();

                getline(arquivo, telefone);
                getline(arquivo, rua);
                arquivo >> num;
                arquivo.ignore();
                getline(arquivo, bairro);
                getline(arquivo, cidade);
                getline(arquivo, estado);
                getline(arquivo, cep);
                getline(arquivo, complemento);

                // Ler dados do veículo
                getline(arquivo, marca);
                getline(arquivo, modelo);
                getline(arquivo, placa);
                getline(arquivo, categoria);
                arquivo >> fipe;
                arquivo.ignore();

                // Criar o proprietário e o veículo
                Proprietario proprietario(nome, telefone);
                proprietario.setEndereco(rua, num, bairro, cidade, estado, cep, complemento);
                proprietario.setDataNascimento(diaNascimento, mesNascimento, anoNascimento); // Definindo a data de nascimento
                proprietario.setTempoHabilitacao(diaHabilitacao, mesHabilitacao, anoHabilitacao); // Definindo a data de habilitação

                DadosVeiculo veiculo(marca, modelo, placa, categoria, fipe);  // Criando o objeto do veículo

                // Adicionar plano
                plano[i] = new Planointermediario(veiculo, proprietario);
            }
            else if (linha == "PlanoCompleto") {
                string nome, telefone, rua, bairro, cidade, estado, cep, complemento;
                int num, diaNascimento, mesNascimento, anoNascimento;
                int diaHabilitacao, mesHabilitacao, anoHabilitacao;
                string marca, modelo, placa, categoria;
                float fipe;

                // Ler dados do proprietário e endereço
                getline(arquivo, nome);

                // Ler dados do proprietário (data de nascimento e habilitação)
                arquivo >> diaNascimento >> mesNascimento >> anoNascimento;
                arquivo >> diaHabilitacao >> mesHabilitacao >> anoHabilitacao;
                arquivo.ignore();


                getline(arquivo, telefone);
                getline(arquivo, rua);
                arquivo >> num;
                arquivo.ignore();
                getline(arquivo, bairro);
                getline(arquivo, cidade);
                getline(arquivo, estado);
                getline(arquivo, cep);
                getline(arquivo, complemento);

                // Ler dados do veículo
                getline(arquivo, marca);
                getline(arquivo, modelo);
                getline(arquivo, placa);
                getline(arquivo, categoria);
                arquivo >> fipe;
                arquivo.ignore();

                // Criar o proprietário e o veículo
                Proprietario proprietario(nome, telefone);
                proprietario.setEndereco(rua, num, bairro, cidade, estado, cep, complemento);
                proprietario.setDataNascimento(diaNascimento, mesNascimento, anoNascimento); // Definindo a data de nascimento
                proprietario.setTempoHabilitacao(diaHabilitacao, mesHabilitacao, anoHabilitacao); // Definindo a data de habilitação

                DadosVeiculo veiculo(marca, modelo, placa, categoria, fipe);  // Criando o objeto do veículo

                // Adicionar plano
                plano[i] = new Planocompleto(veiculo, proprietario);
            }

            i++;
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para carregar os dados.\n";
    }
}
};
