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
  this->nome = "Filipe Campos";
  this->idade = 20 + rand() % 60;
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
void Astronauta::toggleDisponivel()  {
  if (this->disponivel == false && this->alive == true)  {
    this->disponivel = true;
  }
  else {
    this->disponivel = false;
  }
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
  this->passageiros.clear();
}

// Método para adicionar astronautas em um voo
void Voo::adicionarPassageiro(Astronauta *tripulante)  {
  this->passageiros.insert({tripulante->getCPF(), tripulante});
}

// Método para explodir um voo
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

// Get disponivel
bool Voo::getDisponivel()  {
  return this->disponivel;
}

//-------------------------------------------------------------------//
/*A partir daqui estão implementados os métodos da classe Gerenciador*/
//-------------------------------------------------------------------//

// Construtor padrão de Gerenciador
Gerenciador::Gerenciador()  {
  this->viagens = std::map <int, Voo*>();
  this->viajantes = std::map <std::string, Astronauta*>();
}

// Método para cadastrar um novo voo
void Gerenciador::cadastrarVoo(Voo *voo)  {
  
  this->viagens.insert({voo->getCodigo(), voo});
  
  std::cout << "\n\033[32;1mVoo cadastrado com sucesso!\033[m" << std::endl;
  std::cout << "\033[34;1mCódigo de voo:\033[m " << voo->getCodigo() << std::endl;
}

// Método para cadastrar um novo astronauta
int Gerenciador::cadastrarAstronauta(Astronauta *astronauta)  {
  
  if (this->viajantes.count(astronauta->getCPF()))  {
    std::cout << "\n\033[31;1mERRO: Astronauta ja cadastrado.\033[m" << std::endl;
    delete astronauta;
    
    return 1;
  }
  
  this->viajantes.insert({astronauta->getCPF(), astronauta});

  std::cout << "\n\033[32;1mAstronauta cadastrado com sucesso!\033[m" << std::endl;
  std::cout << "\033[34;1mCPF do astronauta:\033[m " << astronauta->getCPF() << std::endl;
  std::cout << "\033[34;1mNome do astronauta:\033[m " << astronauta->getNome() << std::endl;
  std::cout << "\033[34;1mIdade do astronauta:\033[m " << astronauta->getIdade() << std::endl;

  return 0;
}

// Destrutor de Gerenciador
Gerenciador::~Gerenciador()  {
  
  std::map<int, Voo*>::iterator it1;

  for (it1 = this->viagens.begin(); it1 != this->viagens.end(); it1++)  {
    delete it1->second;
  }
  
  this->viagens.clear();
  
  std::map<std::string, Astronauta*>::iterator it2;

  for (it2 = this->viajantes.begin(); it2 != this->viajantes.end(); it2++)  {
    delete it2->second;
  }

  this->viajantes.clear();
}

// Get quantidade de viagens cadastradas
int Gerenciador::getQtdViagens()  {
  return this->viagens.size();
}

// Get quantidade de astronautas cadastrados
int Gerenciador::getQtdViajantes()  {
  return this->viajantes.size();
}

// Adicionar astronauta em um voo
void Gerenciador::adicionarTripulante(std::string cpf, int codigo)  {
  
  std::map<int, Voo*>::iterator it1 = this->viagens.find(codigo);
  
  if (it1 != this->viagens.end() && it1->second->getDisponivel())  {
    
    std::map<std::string, Astronauta*>::iterator it2 = this->viajantes.find(cpf);
    
    if (it2 != this->viajantes.end() && it2->second->getDisponivel())  {
      it1->second->adicionarPassageiro(it2->second);
      it2->second->toggleDisponivel();
      it2->second->adicionarVoo(codigo);

      std::cout << "\n\033[32;1mAstronauta adicionado ao voo com sucesso!\033[m" << std::endl;
      std::cout << "\033[34;1mCPF do astronauta:\033[m " << it2->second->getCPF() << std::endl;
      std::cout << "\033[34;1mCódigo de voo:\033[m " << it1->second->getCodigo() << std::endl;
    }
    else if (it2 == this->viajantes.end())  {
      std::cout << "\n\033[31;1mERRO: Astronauta não encontrado.\033[m" << std::endl;
    }
    else {
      std::cout << "\n\033[31;1mERRO: Astronauta indisponível.\033[m" << std::endl;
    }
  }
  else if (it1 == this->viagens.end())  {
    std::cout << "\n\033[31;1mERRO: Voo não encontrado.\033[m" << std::endl;
  }
  else  {
    std::cout << "\n\033[31;1mERRO: Voo indisponível.\033[m" << std::endl;
  }
}