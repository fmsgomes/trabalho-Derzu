#pragma once
#include "Endereco.h"
#include "Data.h"
#include <string>
using namespace std;

class Proprietario{
private:
    string nome;
    string telefone;
    Endereco endereco;
    Data data_nascimento;
    Data tempo_habilitacao;
public:
    Proprietario(string n, string t){
        nome = n;
        telefone = t;
    }
    void setEndereco(string r, int n, string b, string c, string e, string cep, string complemento){
        endereco = Endereco(r, n, b, c, e, cep, complemento);
    }
    void setDataNascimento(int dia, int mes, int ano) {
        data_nascimento = Data(dia, mes, ano);
    }

    void setTempoHabilitacao(int dia, int mes, int ano) {
        tempo_habilitacao = Data(dia, mes, ano);
    }

    string getNome() const{return nome;}
    string getTelefone() const{return telefone;}
    Endereco getEndereco()const{return endereco;}
    Data getDataNascimento()const{return data_nascimento;}
    Data getTempoHabilitacao()const{return tempo_habilitacao;}

    void lerDadosProprietario(){
        cout << "Insira os dados seguintes para cadastrar o Proprietário: ";
        cout << "\nNome do proprietário: ";
        getline(cin, nome);
        cout << "\nTelefone do proprietário: ";
        getline(cin, telefone);
        cout << "\nEndereço do proprietário: \n";
        endereco.lerEndereco();
        cout << "\nData de Nascimento do proprietário: \n";
        data_nascimento.lerData();
        cout << "\nData de emissão da habilitação do proprietário: ";
        tempo_habilitacao.lerData();

    }

    void ImprimirProprietario()const{
        cout << "\n\nNome: " << getNome() <<endl;
        cout << "Telefone: " << getTelefone() <<endl;
        cout << "Endereco: ";
        getEndereco().imprimirEndereco();
        cout << "\nData de Nascimento: ";
        getDataNascimento().imprimirData();
        cout << "Tempo de Habilitação: ";
        getTempoHabilitacao().imprimirData();
    }
};