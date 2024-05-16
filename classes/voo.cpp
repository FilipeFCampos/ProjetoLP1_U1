#include <iostream>
#include <iomanip>
#include "../libraries/classes.hpp"

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
  this->explodido = false;
  this->finalizado = false;
  qtdVoos++;
}

// Construtor parametrizado de Voo
Voo::Voo(int codigo)  {
  this->passageiros = std::map<std::string, Astronauta*>();
  this->codigo = codigo;
  this->disponivel = true;
  this->explodido = false;
  this->finalizado = false;
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

// Método para remover astronautas de um voo
void Voo::removerPassageiro(std::string cpf)  {
  this->passageiros.erase(cpf);
}

// Método para explodir um voo
void Voo::explodir()  {

  this->explodido = true;
  this->disponivel = false;
  
  std::map<std::string, Astronauta*>::iterator it;

  for (it = this->passageiros.begin(); it != this->passageiros.end(); it++)  {
    it->second->morrer();
  }
}

// Método para verificar se um passageiro faz parte do voo
int Voo::checkPassageiros(std::string CPF)  {
  return this->passageiros.count(CPF);
}

// Get codigo
int Voo::getCodigo()  {
  return this->codigo;
}

// Get disponivel
bool Voo::getDisponivel()  {
  return this->disponivel;
}

// Get finalizado
bool Voo::getFinalizado()  {
  return this->finalizado;
}

// Set disponibilidade do voo
void Voo::setDisponivel(bool set)  {
  if (this->explodido == false)  {
    this->disponivel = set;
    
    std::map<std::string, Astronauta*>::iterator it;

    for (it = this->passageiros.begin(); it != this->passageiros.end(); it++)  {
      it->second->setDisponivel(set);
    }
  }
  else  {
    this->disponivel = false;
  }
}

// Set finalizado
void Voo::setFinalizado(bool set)  {
  this->finalizado = set;
}

// Get explodido
bool Voo::getExplodido()  {
  return this->explodido;
}

// Lançar este voo
int Voo::decolar()  {

  std::map<std::string, Astronauta*>::iterator it;
  
  for (it = this->passageiros.begin(); it != this->passageiros.end(); it++)  {
    if (it->second->getDisponivel() == false)  {
      return 1;
    }
  }
  for (it = this->passageiros.begin(); it != this->passageiros.end(); it++)  {
    it->second->adicionarVoo(this->getCodigo());
  }
  this->setDisponivel(false);

  return 0;
}

// Get quantidade de passageiros
int Voo::getQtdPassageiros()  {
  return this->passageiros.size();
}

// Exibir tripulação
void Voo::exibirTripulacao()  {
  std::map<std::string, Astronauta*>::iterator it;

  std::cout << "\n\033[34;1mNome:           CPF:            Idade:\033[m" << std::endl;

  for (it = this->passageiros.begin(); it != this->passageiros.end(); it++)  {
    std::cout << std::left << std::setw(16) << it->second->getNome();
    std::cout << std::setw(16) << it->second->getCPF();
    std::cout << std::setw(8) << it->second->getIdade() << std::endl;
  }
}
