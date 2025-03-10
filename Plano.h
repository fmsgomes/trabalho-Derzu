#pragma once
#include <string>
#include "DadosVeiculo.h"
#include "Proprietario.h"
using namespace std;

class Plano{
protected:
    DadosVeiculo veiculo;
    Proprietario proprietario;

public:
    virtual DadosVeiculo getVeiculo() const = 0;

    Plano(DadosVeiculo d, Proprietario p) : veiculo(d), proprietario(p){}

    Proprietario getProprietario(){return proprietario;}

    void adicionarVeiculo(){
        veiculo.lerDadosVeiculo();
    }
    void adicionarProprietario(){
        proprietario.lerDadosProprietario();
    }
    void exibirveiculo()const{
        veiculo.ImprimirVeiculo();
    }
    void exibirproprietario()const{
        proprietario.ImprimirProprietario();
    }
    float getFipeVeiculo(){return veiculo.getFipe();}
    virtual float calculoPlano() = 0;
    virtual void imprimirPlano() = 0;
};