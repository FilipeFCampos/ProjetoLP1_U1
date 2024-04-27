#include <cstdlib>
#include "classes.hpp"
#include "functions.hpp"

//Constructor padrão do Astronauta
Astronauta::Astronauta() {
  this->CPF = gerarCPF();
  //this->nome = gerarNome();
  this->idade = 20 + rand() % 80;
  this->alive = true;
  this->disponivel = true;
}

//Constructor parametrizado do Astronauta
Astronauta::Astronauta(std::string CPF, std::string nome, int idade) {
  this->CPF = CPF;
  this->nome = nome;
  this->idade = idade;
  this->alive = true;
  this->disponivel = true;
}

//Destructor do Astronauta
Astronauta::~Astronauta() { 
  this->listaVoos.clear(); 
}

//Get CPF
std::string Astronauta::getCPF() { 
  return this->CPF; 
}

void Astronauta::adicionarVoo(int codigo)  {
  this->listaVoos.push_back(codigo);
}

Voo::Voo()  {
  this->codigo = qtdVoos;
  this->disponivel = true;
  qtdVoos++;
}