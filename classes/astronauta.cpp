#include <iostream>
#include "../libraries/classes.hpp"
#include "../libraries/functions.hpp"
#include "../libraries/name_generator.hpp"

//------------------------------------------------------------------//
/*A partir daqui estão implementados os métodos da classe Astronauta*/
//------------------------------------------------------------------//

// Construtor padrão de Astronauta
Astronauta::Astronauta() {
  this->CPF = gerarCPF();
  this->nome = gerarNome();
  this->idade = 20 + rand() % 50;
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

// Get nome
std::string Astronauta::getNome()  {
  return this->nome;
}

// Get idade
int Astronauta::getIdade() {
  return this->idade;
}

// Get alive
bool Astronauta::getAlive()  {
  return this->alive;
}

// Get disponivel
bool Astronauta::getDisponivel()  {
  return this->disponivel;
}

// Exibir histórico de voos
void Astronauta::exibirListaVoos()  {
  std::cout << "\n\033[34;1m" << this->getNome() 
  << " participou dos seguintes voos:\033[m" << std::endl;

  for (unsigned int i = 0; i < this->listaVoos.size(); i++)  {
    std::cout << "Voo " << this->listaVoos[i] << std::endl;
  }
}

// Função para matar o astronauta
void Astronauta::morrer()  {
  this->alive = false;
  this->disponivel = false;
}

// Função para adicionar um voo ao histórico de voos do astronauta
void Astronauta::adicionarVoo(int codigo)  {
  this->listaVoos.push_back(codigo);
}

// Mudar a disponibilidade do astronauta
void Astronauta::setDisponivel(bool set)  {
  this->disponivel = set;
}
