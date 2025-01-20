#include <iostream>
#include <string>
#include <limits>

template <typename T, typename Validator>
void input(T &out_value, Validator validate, std::string message) {
  while (!(std::cin >> out_value) || !validate(out_value)) {
    if (std::cin.eof()) {
      throw std::runtime_error("Le flux a été fermé !\n");
    } else if (std::cin.fail()) {
      std::cout << "Entrée invalide. Recommence : ";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      std::cout << message;
    }
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}