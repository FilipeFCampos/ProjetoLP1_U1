#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main(void)  {

  int digito;
  std::string CPF;

  std::srand(std::time(0));

  for (int i = 0; i <= 9; i++)  {
    CPF += std::to_string(rand() % 9);
  }
  
  return 0;
}