#include <iostream>
#include <iomanip>
#include "../libraries/classes.hpp"

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
  std::cout << "\033[34;1mCodigo de voo:\033[m " << voo->getCodigo() << std::endl;
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
    
    if (it2 != this->viajantes.end() && it2->second->getAlive())  {

      if (it1->second->checkPassageiros(cpf))  {
        std::cout << "\n\033[33;1mATENCAO: Esse astronauta ja esta vinculado a esse voo\033[m" << std::endl;
      }
      else {
        it1->second->adicionarPassageiro(it2->second);
        std::cout << "\n\033[32;1mAstronauta adicionado ao voo com sucesso!\033[m" << std::endl;
      }
        std::cout << "\033[34;1mCPF do astronauta:\033[m " << it2->second->getCPF() << std::endl;
        std::cout << "\033[34;1mCodigo de voo:\033[m " << it1->second->getCodigo() << std::endl;
    }
    else {
      std::cout << "\n\033[31;1mERRO: Astronauta nao encontrado.\033[m" << std::endl;
    }
  }
  else if (it1 == this->viagens.end())  {
    std::cout << "\n\033[31;1mERRO: Voo nao encontrado.\033[m" << std::endl;
  }
  else  {
    std::cout << "\n\033[31;1mERRO: Voo indisponivel.\033[m" << std::endl;
  }
}

// Remover astronauta de um voo
void Gerenciador::removerTripulante(std::string cpf, int codigo)  {

  std::map<int, Voo*>::iterator it1 = this->viagens.find(codigo);

  if (it1 != this->viagens.end() && it1->second->getDisponivel())  {
    
    if (it1->second->checkPassageiros(cpf))  {
      
      std::map<std::string, Astronauta*>::iterator it2 = this->viajantes.find(cpf);
      
      it1->second->removerPassageiro(it2->second->getCPF());

      std::cout << "\n\033[32;1mAstronauta removido do voo com sucesso!\033[m" << std::endl;
      std::cout << "\033[34;1mCPF do astronauta:\033[m " << it2->second->getCPF() << std::endl;
      std::cout << "\033[34;1mCodigo de voo:\033[m " << it1->second->getCodigo() << std::endl;
    }
    else {
      std::cout << "\n\033[31;1mERRO: Astronauta nao encontrado.\033[m" << std::endl;
    }
  }
  else if (it1 == this->viagens.end())  {
    std::cout << "\n\033[31;1mERRO: Voo nao encontrado.\033[m" << std::endl;
  }
  else  {
    std::cout << "\n\033[31;1mERRO: Voo indisponivel.\033[m" << std::endl;
  }
}

// Lançar voo
int Gerenciador::lancarVoo(int codigo)  {
  
  std::map<int, Voo*>::iterator it = this->viagens.find(codigo);

  if (it == this->viagens.end())  {
    std::cout << "\n\033[31;1mERRO: Voo nao encontrado.\033[m" << std::endl;

    return 1;
  }
  
  if (it->second->getQtdPassageiros() >= 1 && it->second->getDisponivel() && it->second->getFinalizado() == false)  {
    if (it->second->decolar())  {
      std::cout << "\n\033[31;1mERRO: Voos com astronautas indisponiveis nao podem decolar.\033[m" << std::endl;
      return 2;
    }
    
    it->second->decolar();
    std::cout << "\n\033[32;1mVoo decolando!\033[m" << std::endl;
    std::cout << "\033[34;1mCodigo de voo:\033[m " << it->second->getCodigo() << std::endl;
    std::cout << "\033[34;1mTamanho da tripulacao: \033[m" << it->second->getQtdPassageiros() << std::endl;
  }
  else if (it->second->getQtdPassageiros() < 1)  {
    std::cout << "\n\033[31;1mERRO: Voo sem passageiros.\033[m" << std::endl;
  }
  else  {
    std::cout << "\n\033[31;1mERRO: Voo indisponivel.\033[m" << std::endl;
  }
  
  return 0;
}

// Explodir voo
int Gerenciador::explodirVoo(int codigo)  {
  
  std::map<int, Voo*>::iterator it = this->viagens.find(codigo);

  if (it == this->viagens.end())  {
    std::cout << "\n\033[31;1mERRO: Voo nao encontrado.\033[m" << std::endl;

    return 1;
  }

  if (it->second->getDisponivel() == false)  {
    it->second->explodir();
    
    std::cout << "\n\033[32;1mVoo explodido\033[m" << std::endl;
    std::cout << "\033[34;1mCodigo de voo:\033[m " << it->second->getCodigo() << std::endl;
    std::cout << "\033[34;1mNumero de baixas: \033[m" << it->second->getQtdPassageiros() << std::endl;
  }
  else  {
    std::cout << "\n\033[31;1mERRO: Esse voo ainda nao foi lancado.\033[m" << std::endl;
  }

  return 0;
}

// Finalizar voo com sucesso
int Gerenciador::finalizarVoo(int codigo)  {
  
  std::map<int, Voo*>::iterator it = this->viagens.find(codigo);

  if (it == this->viagens.end())  {
    std::cout << "\n\033[31;1mERRO: Voo nao encontrado.\033[m" << std::endl;

    return 1;
  }

  if (it->second->getDisponivel() == false && it->second->getExplodido() == false)  {
    it->second->setDisponivel(true);
    it->second->setFinalizado(true);

    std::cout << "\n\033[32;1mVoo aterrissando!\033[m" << std::endl;
    std::cout << "\033[34;1mCodigo de voo:\033[m " << it->second->getCodigo() << std::endl;
    std::cout << "\033[34;1mTamanho da tripulacao: \033[m" << it->second->getQtdPassageiros() << std::endl;
  }
  else if (it->second->getDisponivel() == true && it->second->getExplodido() == false)  {
    std::cout << "\n\033[31;1mERRO: Esse voo nao foi lancado.\033[m" << std::endl;
  }
  else  {
    std::cout << "\n\033[31;1mERRO: Voo indisponivel.\033[m"  << std::endl;
  }

  return 0;
}

// Listar todos os voos
void Gerenciador::listViagens()  {
  std::map<int, Voo*>::iterator it;
  
  std::cout << "\n\033[34;1mVoo:  Tripulacao:  Status:\033[m" << std::endl;

  for (it = this->viagens.begin(); it != this->viagens.end(); it++)  {
    
    std::cout << std::left << std::setw(6) << it->second->getCodigo();
    std::cout << std::setw(13) << it->second->getQtdPassageiros();

    if (it->second->getExplodido() == true)  {
      std::cout << "\033[31;1mExplodido\033[m" << std::endl;
    }
    else if (it->second->getDisponivel() == false)  {
      std::cout << "\033[32;1mVoando\033[m" << std::endl;
    }
    else if (it->second->getFinalizado() == true)  {
      std::cout << "\033[32;1mFinalizado\033[m" << std::endl;
    }
    else  {
      std::cout << "\033[33;1mStandby\033[m" << std::endl;
    }
  }
}

// Listar todos as fatalidades
int Gerenciador::listFatalidades()  {
  std::map<std::string, Astronauta*>::iterator it;
  int qtdBaixas = 0;

  std::cout << "\n\033[34;1mNome:           CPF:            Idade:\033[m" << std::endl;
  
  for (it = this->viajantes.begin(); it != this->viajantes.end(); it++)  {

    if (it->second->getAlive() == false)  {
      std::cout << std::left << std::setw(16) << it->second->getNome();
      std::cout << std::setw(16) << it->second->getCPF();
      std::cout << std::setw(8) << it->second->getIdade();
      std::cout << "\033[31;1mR.I.P\033[m"<< std::endl;
      
      qtdBaixas++;
    }
  }
  if (qtdBaixas == 0)  {
    std::cout << "\n\033[33;1mNao houveram fatalidades\033[m" << std::endl;

    return 1;
  }
  else {
    std::cout << "\n\033[34;1mTotal de baixas: \033[m" << qtdBaixas << std::endl;
  }

  return 0;
}

// Listar histórico de voos
int Gerenciador::histVoos(std::string cpf)  {
  std::map<std::string, Astronauta*>::iterator it = this->viajantes.find(cpf);

  if (it == this->viajantes.end() || it->second->getAlive() == true)  {
    std::cout << "\n\033[31;1mERRO: Astronauta nao encontrado.\033[m" << std::endl;

    return 1;
  }

  it->second->exibirListaVoos();
  
  return 0;
}

// Consultar tripulação de determinado voo
int Gerenciador::consultarTripulacao(int codigo)  {
  std::map<int, Voo*>::iterator it = this->viagens.find(codigo);

  if (it == this->viagens.end())  {
    std::cout << "\n\033[31;1mERRO: Voo nao encontrado.\033[m" << std::endl;

    return 1;
  }

  it->second->exibirTripulacao();

  return 0;
}