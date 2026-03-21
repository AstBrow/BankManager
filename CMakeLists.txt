cmake_minimum_required(VERSION 3.10)
project(BankManager VERSION 1.0.0)

# Устанавливаем стандарт C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем папку include для поиска заголовочных файлов
include_directories(include)

# Находим все .cpp файлы в src/
file(GLOB SOURCES "src/*.cpp")

# Добавляем main.cpp (если он в корне)
list(APPEND SOURCES "main.cpp")

# Создаём исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCES})