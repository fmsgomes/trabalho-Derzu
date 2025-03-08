#pragma once
#include "Endereco.hpp"
#include "Data.hpp"
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

    Proprietario(string n, string t) : nome(n), telefone(t){}

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

    void ImprimirProprietario()const{
        cout << "Nome: " << getNome() <<endl;
        cout << "Telefone: " << getTelefone() <<endl;
        cout << "Endereco: " << getEndereco().imprimirEndereco() <<endl;
        cout << "Data de Nascimento: " << getDataNascimento().imprimirData()<<endl;
        cout << "Tempo de Habilitação: " << getTempoHabilitacao().imprimirData() <<endl;
    }
};