#include <iostream>
#include "./libraries/classes.hpp"
#include "./libraries/functions.hpp"

int main(void) {

  int option;
  Gerenciador gerenciador;

  std::cout << ".    _     *       \\|/   .       .      -*-              +" << std::endl;
  std::cout << "  .' \\\\`.     +    -*-     *   .         '       .   *" << std::endl;
  std::cout << ". |__''_|  .       /|\\ +         .    +       .           |" << std::endl;
  std::cout << "  |     | .                                        .     -*-" << std::endl;
  std::cout << "  |     |           `  .    '             . *   .    +    |" << std::endl;
  std::cout << "_.'-----'-.__    *                  ." << std::endl;
  std::cout << "/          AEB\\__.__.--._______________\n\n" << std::endl;
  std::cout << "\033[1;34mBem vindo ao gerenciador de viagens espaciais!\033[0m\n" << std::endl;

  while (true)  {

    interface();
    /*Selecione a funcao que deseja realizar:
    [1]: Cadastrar voo
    [2]: Cadastrar astronauta
    [3]: Adicionar astronauta em um voo
    [4]: Remover astronauta de um voo
    [5]: Lançar um voo
    [6]: Explodir voo
    [7]: Finalizar um voo
    [8]: Listar todos os voos
    [9]: Listar fatalidades
    [0]: Sair*/

    option = -1;
    /*Eu defini o option como -1 aqui só para caso haja um erro e o 
      std::cin não funcione, o código não comece a alocar novos voos
      ou astronautas em loop por acidente e sim dê erro de opção inválida*/
    std::cin >> option;
    
    switch (option)  {
      
      // Cadastrar voo
      case 1:
        {
          Voo *voo = new Voo();
          gerenciador.cadastrarVoo(voo);
        }
        break;

      // Cadastrar astronauta
      case 2:
        {
          int escolha;
          std::cout << "\nDeseja definir os parametros do astronauta ou gerar um astronauta aleatorio?\n" << std::endl;
          std::cout << "[1] Passar parametros" << std::endl;
          std::cout << "[2] Gerar astronauta aleatorio" << std::endl;
          std::cin >> escolha;

          if (escolha == 1)  {
            std::string CPF, nome;
            int idade;
            std::cout << "Digite o CPF do astronauta: ";
            std::cin >> CPF;
            formatCPF(CPF);
            std::cout << "Digite o nome do astronauta: ";
            std::getline(std::cin >> std::ws, nome);
            std::cout << "Digite a idade do astronauta: ";
            std::cin >> idade;

            Astronauta *astronauta = new Astronauta(CPF, nome, idade);
            gerenciador.cadastrarAstronauta(astronauta);
          }
          else if (escolha == 2)  {
            Astronauta *astronauta = new Astronauta();
            gerenciador.cadastrarAstronauta(astronauta);
          }
          else  {
            std::cout << "\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
          }
        }
        break;

      // Castrar astronauta em um voo
      case 3:
        {
          if (gerenciador.getQtdViagens() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha voos cadastrados.\033[m" << std::endl;
          }
          else if (gerenciador.getQtdViajantes() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha astronautas cadastrados.\033[m" << std::endl;
          }
          else {
            std::string cpf;
            int codigo;
            std::cout << "Digite o CPF do astronauta que deseja adicionar: ";
            std::cin >> cpf;
            formatCPF(cpf);
            std::cout << "Digite o codigo do voo que deseja atribuir: ";
            std::cin >> codigo;
            gerenciador.adicionarTripulante(cpf, codigo);
          }
        }
        break;

      // Remover astronauta de um voo
      case 4:
        {
          if (gerenciador.getQtdViagens() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha voos cadastrados.\033[m" << std::endl;
          }
          else if (gerenciador.getQtdViajantes() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha astronautas cadastrados.\033[m" << std::endl;
          }
          else {
            std::string cpf;
            int codigo;
            std::cout << "Digite o CPF do astronauta que deseja remover: ";
            std::cin >> cpf;
            formatCPF(cpf);
            std::cout << "Digite o codigo do voo do qual deseja remover: ";
            std::cin >> codigo;
            gerenciador.removerTripulante(cpf, codigo);
          }
        }
        break;

      // Lançar um voo
      case 5:
        {
          if (gerenciador.getQtdViagens() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha voos cadastrados.\033[m" << std::endl;
          }
          else if (gerenciador.getQtdViajantes() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha astronautas cadastrados.\033[m" << std::endl;
          }
          else {
            int codigo;
            std::cout << "Digite o codigo do voo que deseja lancar: ";
            std::cin >> codigo;
            gerenciador.lancarVoo(codigo);
          }
        }
        break;

      // Explodir voo
      case 6:
        {
          if (gerenciador.getQtdViagens() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha voos cadastrados.\033[m" << std::endl;
          }
          else if (gerenciador.getQtdViajantes() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha astronautas cadastrados.\033[m" << std::endl;
          }
          else {
            int codigo;
            char confirmacao;
            
            std::cout << "Digite o codigo do voo que deseja explodir: " <<  std::endl;
            std::cin >> codigo;
            std::cout << "\n\033[33;1mATENCAO: Esse voo e toda a sua tripulacao vao\n         ficar indisponiveis para sempre.\n\033[m" << std::endl;
            
            std::cout << "Tem certeza que deseja continuar? (S/N)" << std::endl;
            std::cin >> confirmacao;
  
            if (confirmacao == 'S' || confirmacao == 's')  {
              gerenciador.explodirVoo(codigo);
            }
            else if (confirmacao == 'N' || confirmacao == 'n')  {
              std::cout << "\nVoltando ao menu principal...\n" << std::endl;
            }
            else {
              std::cout << "\n\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
            }
          }
        }
        break;

      // Finalizar voo com sucesso
      case 7:
        {
          if (gerenciador.getQtdViagens() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha voos cadastrados.\033[m" << std::endl;
          }
          else if (gerenciador.getQtdViajantes() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha astronautas cadastrados.\033[m" << std::endl;
          }
          else {
            int codigo;
            std::cout << "Digite o codigo do voo que deseja finalizar: ";
            std::cin >> codigo;
            gerenciador.finalizarVoo(codigo); 
          }
        }
        break;

      case 8:
        {
          if (gerenciador.getQtdViagens() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha voos cadastrados.\033[m" << std::endl;
          }
          else {
            gerenciador.listViagens();
            int escolha;
            std::cout << "\nDeseja consultar a tripulacao de algum voo?\n" << std::endl;
            std::cout << "[1] Consultar tripulacao" << std::endl;
            std::cout << "[2] Voltar ao menu principal" << std::endl;
            std::cin >> escolha;
            if (escolha == 1)  {
              int codigo;
              std::cout << "Digite o codigo de voo: ";
              std::cin >> codigo;
              gerenciador.consultarTripulacao(codigo);
            }
            else if (escolha != 1 && escolha != 2)  { 
              std::cout << "\n\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
            }
          }
        }
        break;

      // Listar fatalidades
      case 9:
        {
          if (gerenciador.getQtdViajantes() == 0)  {
            std::cout << "\n\033[31;1mERRO: Nao ha astronautas cadastrados.\033[m" << std::endl;
          }
          else {
            int check = gerenciador.listFatalidades();
            if (check) {break;}
            int escolha;
            std::cout << "\nDeseja consultar o historico de voos de algum astronauta?\n" << std::endl;
            std::cout << "[1] Visualizar historico de voos" << std::endl;
            std::cout << "[2] Voltar ao menu principal" << std::endl;
            std::cin >> escolha;
            if (escolha == 1)  {
              std::string CPF;
              std::cout << "Digite o CPF do astronauta: ";
              std::cin >> CPF;
              formatCPF(CPF);
              gerenciador.histVoos(CPF);
            }
            else if (escolha != 1 && escolha != 2)  { 
              std::cout << "\n\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
            }
          }
        }
        break;
      
      // Sair
      case 0:
        {
          char confirmacao;
          
          std::cout << "Tem certeza que deseja sair? (S/N)" << std::endl;
          std::cin >> confirmacao;
          
          if (confirmacao == 'S' || confirmacao == 's')  {
            std::cout << "\n\033[32;1mObrigado por usar o gerenciador de viagens espaciais!!\033[m\n" << std::endl;
            return 0;
          }
          else if (confirmacao == 'N' || confirmacao == 'n')  {
            std::cout << "\n\033[33;1mVoltando ao menu principal...\033[m" << std::endl;
          }
          else {
            std::cout << "\n\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
          }
        }
        break;

      // Opção inválida
      default:
        {
          std::cout << "\n\033[31;1mERRO: Opcao invalida.\033[m" << std::endl;
        }
        break;
    }
  }
  

  return 1;
}