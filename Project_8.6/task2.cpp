#include <iostream>
#include <limits>

int main() {
  float health, resistance;

  std::cout << "Задание 2. Immolate Improved!\n";
  std::cout << "================================\n"; 
  std::cout << "Введите количество здоровья орка (от 0 до 1): "; std::cin >> health;
  if (std::cin.fail() || std::cin.peek() != '\n' || health <= 0 || health > 1) {
    if (health <= 0) {
      std::cerr << "Орк уже мертв\n";
    } else {
      std::cerr << "Ошибка ввода данных\n";
    }
    return 1;
  }
  std::cout << "Введите сопротивляемость магии орка (от 0 до 1): "; std::cin >> resistance;
  if (std::cin.fail() || std::cin.peek() != '\n' || resistance < 0 || resistance >= 1) {
    if (resistance == 1) {
      std::cerr << "Вы встретили бессмертного орка, бегите!\n";
    } else {
      std::cerr << "Ошибка ввода данных\n";
    }
    return 1;
  }
  std::cout << std::endl;
  
  while (health > 0) {
    float damage;
    std::cout << "Введите мощность огненного шара (от 0 до 1): "; std::cin >> damage;
      if (std::cin.fail() || std::cin.peek() != '\n' || damage < 0 || damage > 1) {
        std::cerr << "Ошибка ввода данных\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
    float actualDamage = damage * (1 - resistance);
    health -= actualDamage;
    if (health < 0) health = 0;
    std::cout << "Урон: " << damage;
    std::cout << ", сопротивляемость: " << resistance;
    std::cout << ", по орку будет нанесено: " << actualDamage << " урона";
    std::cout << ", оставшееся здоровье орка: " << health << "\n";
  } 
  
  std::cout << "\nОрк пал жертвой огненных шаров.\n";
  return 0;
}