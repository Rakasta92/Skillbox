#include <iostream>
#include <limits>
#include <cmath>

int main() {
  float length, width, height;
  const float MAX_VALUE = 1e9f;
  const float CUBE_SIZE = 5.0f;
  const int MIN_SET_SIDE = 2;
  const int MIN_CUBES_IN_SET = MIN_SET_SIDE * MIN_SET_SIDE * MIN_SET_SIDE;  // 8

  std::cout << "Задание 3. Игрушечная история\n";
  std::cout << "=============================\n"; 
  
  std::cout << "Введите длину поступившего в мастерскую бруска (в сантиметрах): "; std::cin >> length; 
  if (std::cin.fail() || std::cin.peek() != '\n' || length < 5 || length >= MAX_VALUE) {
    if (length < 5 && length > 0) {
      std::cout << "Длина бруска должна быть не менее 5 см.\n";
    } else {
      std::cerr << "Ошибка ввода данных\n";
    }
    return 1;
  }
  std::cout << "Введите ширину поступившего в мастерскую бруска (в сантиметрах): "; std::cin >> width;
  if (std::cin.fail() || std::cin.peek() != '\n' || width < 5 || width >= MAX_VALUE) {
    if (width < 5 && width > 0) {
      std::cout << "Ширина бруска должна быть не менее 5 см.\n";
    } else {
      std::cerr << "Ошибка ввода данных\n";
    }
    return 1;
  }
  std::cout << "Введите высоту поступившего в мастерскую бруска (в сантиметрах): "; std::cin >> height;
  if (std::cin.fail() || std::cin.peek() != '\n' || height < 5 || height >= MAX_VALUE) {
    if (height < 5 && height > 0) {
      std::cout << "Высота бруска должна быть не менее 5 см.\n";
    } else {
      std::cerr << "Ошибка ввода данных\n";
    }
    return 1;
  }
  std::cout << std::endl;
  
  std::cout << "Поступивший в мастерскую брусок: " << length << " x " << width << " x " << height << " см." << "\n";
  int cubesX = (int)(length / CUBE_SIZE);
  int cubesY = (int)(width / CUBE_SIZE);
  int cubesZ = (int)(height / CUBE_SIZE);
  int totalCubes = cubesX * cubesY * cubesZ;
  std::cout << "Кубиков из этого бруска можно изготовить: " << totalCubes << "\n";

  int maxSizeSet = MIN_SET_SIDE;
  if (totalCubes < MIN_CUBES_IN_SET) {
    std::cout << "Из такого количества кубиков: " << totalCubes << " нельзя собрать минимальный набор из " 
                                                  << MIN_CUBES_IN_SET << " кубиков." << "\n";
  } else {
    while (std::pow (maxSizeSet + 1, 3) <= totalCubes) {
      maxSizeSet++;
    }
    std::cout << "Из такого количества кубиков: " << totalCubes << " можно собрать набор из " 
                                                  << std::pow (maxSizeSet, 3) << " кубиков." << "\n"; 
  }

  return 0;
}