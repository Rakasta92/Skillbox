#include <iostream>
#include <cmath>

int main() {
  float m, F, t, distance;
  const float MAX_VALUE = 1e9f;

  std::cout << "Задание 1. Космический симулятор\n";
  std::cout << "================================\n";
  std::cout << "Введите массу космического корабля, в килограммах: "; std::cin >> m;
  if (std::cin.fail() || std::cin.peek() != '\n' || m <= 0 || m >= MAX_VALUE) {
    std::cerr << "Ошибка ввода данных\n";
    return 1;
  }
  std::cout << "Введите силу тяги, в ньютонах: "; std::cin >> F;
  if (std::cin.fail() || std::cin.peek() != '\n' || F <= 0 || F >= MAX_VALUE) {
    std::cerr << "Ошибка ввода данных\n";
    return 1;
  }
  std::cout << "Введите время полёта, в секундах: "; std::cin >> t;
  if (std::cin.fail() || std::cin.peek() != '\n' || t <= 0 || t >= MAX_VALUE) {
    std::cerr << "Ошибка ввода данных\n";
    return 1;
  }
    
  distance = (F * std::pow(t, 2)) / (2 * m);
  std::cout << "\nРасстояние, на которое корабль отдалится от первоначального положения: " << distance << " метров\n";

  return 0;
}