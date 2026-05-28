#include <iostream>
#include <limits>

int main() {
  float initAmplitude;
  float finalAmplitude;
  
  std::cout << "Задание 6. Маятник\n";
  std::cout << "==================\n"; 
  std::cout << "Введите начальную амплитуду колебаний маятника (в см.): "; std::cin >> initAmplitude; 
  if (std::cin.fail() || std::cin.peek() != '\n' || initAmplitude <= 0) {
    std::cerr << "Ошибка ввода данных\n";
    return 1;
  }
  std::cout << "Введите конечную амплитуду колебаний маятника, которая считается его остановкой (в см.): "; std::cin >> finalAmplitude; 
  if (std::cin.fail() || std::cin.peek() != '\n' || finalAmplitude <= 0) {
    std::cerr << "Ошибка ввода данных\n";
    return 1;
  }
  if (finalAmplitude >= initAmplitude) {
    std::cerr << "Конечная амплитуда должна быть меньше начальной\n";
    return 1;
  }
  std::cout << std::endl;
  
  int count = 0;
  float currentAmplitude = initAmplitude;
  while (currentAmplitude > finalAmplitude && count < 10000) {
    currentAmplitude *= 0.916f;
    count++;
  }
  if (count == 10000) {
      std::cerr << "Превышен лимит итераций. Возможно, конечная амплитуда слишком мала\n";
      return 1;
  }
  
  std::cout << "Маятник считается остановившимся через " << count << " колебаний\n";
    
  return 0;
}