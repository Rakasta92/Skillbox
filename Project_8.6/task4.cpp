#include <iostream>
#include <limits>
#include <cmath>

int main() {
  float fileSize, internetSpeed;
  
  std::cout << "Задание 4. Убийца Steam\n";
  std::cout << "=======================\n"; 
  std::cout << "Укажите размер файла для скачивания (в МБ): "; std::cin >> fileSize; 
  if (std::cin.fail() || std::cin.peek() != '\n' || fileSize <= 0) {
    std::cerr << "Ошибка ввода данных\n";
    return 1;
  }
  std::cout << "Какова скорость вашего соединения? в (МБ\\с) "; std::cin >> internetSpeed;
  if (std::cin.fail() || std::cin.peek() != '\n' || internetSpeed < 0) {
    if (internetSpeed <= 0) {
      std::cout << "Отсутствует интернет соединение!\n";
    } else {
      std::cerr << "Ошибка ввода данных\n";
    }
    return 1;
  }
  std::cout << std::endl;

  int time = 1;
  for (; time <= std::ceil(fileSize / internetSpeed); time++) {
    float currentSize = internetSpeed * time;
    if (currentSize >= fileSize) {
      std::cout << "Прошло " << time << " сек. Скачано " << fileSize << " из " << fileSize << " МБ (100%)\n";  
    } else {
      std::cout << "Прошло " << time << " сек. Скачано " << currentSize << " из " << fileSize 
                                     << " МБ (" << std::floor(currentSize / fileSize * 100) << "%)\n";
    }
  }
    std::cout << std::endl;
    std::cout << "Скачивание завершено!\n";
    std::cout << "Всего затрачено " << time - 1 << " сек.\n";
  
  return 0;
}