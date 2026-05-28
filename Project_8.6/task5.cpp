#include <iostream>
#include <limits>
#include <cmath>

int main() {
  int distance;
  
  std::cout << "Задание 5. Кенийский бегун\n";
  std::cout << "==========================\n"; 
  std::cout << "Ввод:\n";
  std::cout << "Привет, Сэм! Сколько километров ты сегодня пробежал? "; std::cin >> distance; 
  if (std::cin.fail() || std::cin.peek() != '\n' || distance <= 0) {
    if (distance <= 0) {
      std::cout << "У тебя сегодня выходной, Сэм?\n";
    } else {
      std::cerr << "Ошибка ввода данных\n";
    }
    return 1;
  }
  std::cout << std::endl;

  int totalTime = 0;
  for (int time, i = 1; i <= distance; ++i) {
    std::cout << "Какой у тебя был темп на километре " << i << "? "; std::cin >> time;
    if (std::cin.fail() || std::cin.peek() != '\n' || time <= 0) {
      std::cerr << "Ошибка ввода данных\n";
      return 1;
    }
    totalTime += time;   
    std::cout << std::endl;
  }

  float averageTime = (float)totalTime / (float)distance;
  int minutes = std::floor(averageTime / 60.f);
  int seconds = (int)(std::round(averageTime)) % 60;
  
  std::cout << "Вывод:\n";
  std::cout << std::endl;
  std::cout << "Твой средний темп за тренировку: " << minutes << " " 
                                                   << (minutes == 1 ? "минута" : (minutes > 1 && minutes < 5 ? "минуты" : "минут")) << " "
                                                   << seconds << " " << (seconds == 1 ? "секунда" : (seconds > 1 && seconds < 5 ? "секунды" : "секунд"));
  
  return 0;
}