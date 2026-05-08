# 🏦 Bank Manager v1.0

**Консольное приложение на C++ для управления банковскими счетами**

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-3.10+-green.svg)](https://cmake.org/)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

---

## 📋 О проекте

Bank Manager — это учебный проект, реализующий базовую банковскую систему с возможностью:
- Создания клиентов
- Открытия дебетовых и кредитных счетов
- Выполнения финансовых операций (пополнение, снятие, перевод)
- Просмотра информации о клиентах и счетах
- Сохранения и загрузки данных между сеансами работы

Проект написан на C++17 с использованием объектно-ориентированного подхода, полиморфизма, исключений и работы с файлами.

---

## 🚀 Возможности

### Клиенты
- Добавление клиента (имя, паспорт, возраст)
- Проверка возраста (мин. 14 лет)
- Уникальная идентификация по ID и паспорту

### Счета
- **Дебетовый счёт** — нельзя уйти в минус
- **Кредитный счёт** — овердрафт до установленного лимита (только с 18 лет)
- Автоматическая генерация уникальных номеров счетов

### Операции
- Пополнение (deposit)
- Снятие (withdraw)
- Перевод между счетами (transfer)
- Закрытие счёта

### Просмотр информации
- Список всех клиентов
- Счета выбранного клиента
- Детальная информация о клиенте
- Детальная информация о счёте

### Сохранение данных
- Текстовые файлы: `Clients.txt`, `Accounts.txt`, `Counters.txt`
- Автосохранение при выходе из программы
- Автозагрузка при запуске
- Отказоустойчивость — при повреждённых файлах программа запускается с чистыми данными

### Дебаг-меню (скрытое)
- Доступ по коду `3434` (ввести `-20` в главном меню)
- Принудительная загрузка/сохранение отдельных компонентов
- Корректировка счётчиков ID и номеров счетов
- Удаление всех данных с подтверждением

---

## 🛠️ Технологии

| Компонент | Технология |
|-----------|------------|
| Язык | C++17 |
| Сборка | CMake 3.10+ |
| Компилятор | GCC / MinGW |
| Работа с памятью | Умные указатели, ручная память |
| Обработка ошибок | Исключения (std::runtime_error, std::invalid_argument) |
| Файлы | Текстовый формат (std::ofstream / std::ifstream) |

---

## 📁 Структура проекта

BankManager/                        
├── include/                                                                                                  
│ ├── Bank.hpp                                                                              
│ ├── Client.hpp            
│ ├── Account.hpp            
│ ├── DebitAccount.hpp          
│ └── CreditAccount.hpp           
├── src/                   
│ ├── Bank.cpp                     
│ ├── Client.cpp                 
│ ├── Account.cpp               
│ ├── DebitAccount.cpp            
│ └── CreditAccount.cpp            
├── data/                     
│ ├── Clients.txt               
│ ├── Accounts.txt              
│ └── Counters.txt               
├── main.cpp                  
├── CMakeLists.txt                
└── README.md                 
---

## 🖥️ Интерфейс
!== BANK MANAGER v1.0 ==!-

All Actions - -            
[1] Add client               
[2] Open account             
[3] Deposit                 
[4] Withdraw                
[5] Transfer                  
[6] Show all clients               
[7] Show client accounts                
[8] Show account info                
[9] Show client info                   
[10] Close account 
[11] Delete client
[0] Exit                           
Select an action: _                 
---

## 🔧 Сборка и запуск

### Требования
- CMake 3.10+
- Компилятор с поддержкой C++17 (GCC, MinGW, MSVC)

### Инструкция

```bash
# Клонирование репозитория
git clone https://github.com/AstBrow/BankManager.git
cd BankManager

# Сборка через CMake
mkdir build && cd build
cmake ..
cmake --build .

# Запуск
./BankManager.exe   # Windows
./BankManager       # Linux / Mac

