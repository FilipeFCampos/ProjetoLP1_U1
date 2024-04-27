#include <iostream>
#include <cstdlib>
#include "classes.hpp"
#include "functions.hpp"


//------------------------------------------------------------------//
/*A partir daqui estão implementados os métodos da classe Astronauta*/
//------------------------------------------------------------------//

// Construtor padrão de Astronauta
Astronauta::Astronauta() {
  this->CPF = gerarCPF();
  //this->nome = gerarNome();
  this->idade = 20 + rand() % 80;
  this->alive = true;
  this->disponivel = true;
  this->listaVoos = std::vector<int>();
}

// Construtor parametrizado de Astronauta
Astronauta::Astronauta(std::string CPF, std::string nome, int idade) {
  this->CPF = CPF;
  this->nome = nome;
  this->idade = idade;
  this->alive = true;
  this->disponivel = true;
  this->listaVoos = std::vector<int>();
}

// Destrutor de Astronauta
Astronauta::~Astronauta() { 
  this->listaVoos.clear(); 
}

// Get CPF
std::string Astronauta::getCPF() { 
  return this->CPF; 
}

void Astronauta::morrer()  {
  this->alive = false;
}

void Astronauta::adicionarVoo(int codigo)  {
  this->listaVoos.push_back(codigo);
}

//-----------------------------------------------------------//
/*A partir daqui estão implementados os métodos da classe Voo*/
//-----------------------------------------------------------//

// Declaração variável static qtdVoos
int Voo::qtdVoos = 0;

// Construtor padrão de Voo
Voo::Voo()  {
  this->passageiros = std::map<std::string, Astronauta*>();
  this->codigo = qtdVoos + 1;
  this->disponivel = true;
  qtdVoos++;
}

// Construtor parametrizado de Voo
Voo::Voo(int codigo)  {
  this->passageiros = std::map<std::string, Astronauta*>();
  this->codigo = codigo;
  this->disponivel = true;
  qtdVoos++;
}

// Destrutor de Voo
Voo::~Voo()  {
  std::map<std::string, Astronauta*>::iterator it;

  for (it = this->passageiros.begin(); it != this->passageiros.end(); it++)  {
    delete it->second;
  }

  this->passageiros.clear();
}

// Método adicionarPassageiros
void Voo::adicionarPassageiro(Astronauta *tripulante)  {
  this->passageiros.insert({tripulante->getCPF(), tripulante});
}

// Método explodir
void Voo::explodir()  {
  this->disponivel = false;

  std::map<std::string, Astronauta*>::iterator it;

  for (it = this->passageiros.begin(); it != this->passageiros.end(); it++)  {
    it->second->morrer();
  }
}

// Get codigo
int Voo::getCodigo()  {
  return this->codigo;
}

//-------------------------------------------------------------------//
/*A partir daqui estão implementados os métodos da classe Gerenciador*/
//-------------------------------------------------------------------//

// Construtor padrão de Gerenciador
Gerenciador::Gerenciador()  {
  this->viagens = std::map <int, Voo*>();
}

// Método cadastrarVoo
void Gerenciador::cadastrarVoo()  {

  Voo *voo = new Voo();
  
  this->viagens.insert({voo->getCodigo(), voo});
  
  std::cout << "\033[32;1mVoo cadastrado com sucesso!\033[m" << std::endl;
  std::cout << "\033[34;1mCódigo de voo:\033[m " << voo->getCodigo() << std::endl;
}

// Destrutor de Gerenciador
Gerenciador::~Gerenciador()  {
  std::map<int, Voo*>::iterator it;

  for (it = this->viagens.begin(); it != this->viagens.end(); it++)  {
    delete it->second;
  }

  this->viagens.clear();
}