# ЛАБОРАТОРНА РОБОТА № 24. ООП. ПОТОКИ.
1. ВИМОГИ
#### 1.1. Розробник
* Бельчинська Катерина Юріївна;
* студентка групи КІТ-320;
* 28 травня 2021.
#### 1.2. Загальне завдання
Поширити попередню лабораторну роботу таким чином:
• Використання функцій printf/scanf замінити на використання cin/count;

• Усі конкатенації рядків замінити на використання stringstream;

• Замінити метод виводу інформації про об’єкт на метод, що повертає рядок-інформацію про об’єкт, який далі можна виводити на екран;

• Замінити метод вводу інформації про об’єкт на метод, що приймає рядок з інформацією про об’єкт, обробляє його та створює об’єкт на базі цієї інформації;

• Поширити клас-список, шляхом реалізації методів роботи з файлами за допомогою файлових потоків (fstream) (якщо використовувалися функції fprintf/fscanf – замінити їх на класи ifstream/ofstream), при цьому сигнатури методів повинні виглядати таким чином:

◦ Читання (List – клас-список об’єктів, при цьому слід пам’ятати, що при повторному читанні файлу, попередні дані списку повинні бути очищені):

◦ Запис;

• Продемонструвати відсутність витоків пам’яті;

• Продемонструвати роботу розроблених методів за допомогою модульних тестів;

• Не використовувати конструкцію “using namespace std;”, замість цього робити “using” кожного необхідного класу.

2. ОПИС ПРОГРАМИ
#### 2.1. Функціональне призначення

![рисунок 1](assets/read_from_file.png)

Рисунок 1. Читання списку з файлу.

![рисунок 1](assets/element_from_string.png)

Рисунок 2. Створення елементу зі строки.

![рисунок 1](assets/remove.png)

Рисунок 3. Видалення елементу зі списку.

#### 2.2. Опис логічної структури

![рисунок 1](assets/readFromFile.png)

Рисунок 4. Блок-схема алгоритму методу читання списку з файлу

![рисунок 1](assets/writeInFile.png)

Рисунок 5. Блок-схема алгоритму методу для запису списку у файл


#### 2.3. Структура проекту

```
.
├── doc
│   ├── assets
│   │   ├── doxygen.png
│   │   ├── element_from_string.png
│   │   ├── readFromFile.png
│   │   ├── read_from_file.png
│   │   ├── remove.png
│   │   └── writeInFile.png
│   └── lab24.md
├── Doxyfile
├── Makefile
├── README.md
├── src
│   ├── data.cpp
│   ├── data.h
│   ├── list.cpp
│   ├── list.h
│   └── main.cpp
└── test
    └── test.cpp


```
#### 2.4. Особливості програми
- використання cin/cout замість printf/scanf:
```
std::cout << "Type: " << this->type << std::endl;
```
- заміна char на std::string:
```
std::string firm;
```
#### 2.5. Генерування Doxygen-документації

![рисунок 1](assets/doxygen.png)

Рисунок 6. Генерація Doxygen документації

3. ВАРІАНТИ ВИКОРИСТАННЯ

Програму доцільно використовувати для обробки інформації про список інструментів з файлу.

ВИСНОВКИ

В ході виконання даної роботи були освоєні інструменти роботи з вводом виводом у C++ та особливості використання stringstream.
