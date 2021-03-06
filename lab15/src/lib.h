/**
 * @file lib.h
 * @brief Файл з прототипами функцій
 *
 * @author Belchynska K.
 * @date 02-march-2021
 * @version 1.0
 */
#pragma one
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#define INSTRUMENT_COUNT 6



//struct TestElement{
//    int id;
 //   char data[30];
//};






//long fileSize(FILE * file);
/**
 * Структура інструментів, включає до себе тип інструменту, фірму та рік виготовленя
 */

enum Material {BT = 1, PERNAMBUCO = 2, FIBERGLASS = 3};
//static char material[3][20] = {"Brazilian Tree", "Pernambuco", "Fiberglass"};

struct Bow {
    int weight;
    enum Material material;
};

struct Instrument {
    char type[15];
    char firm[15];
    int year;
    float size;
    struct Bow bow;

};


struct Instrument* printInstrument(struct Instrument** instrument);
/**
 *  Функція читає вхідні дані з файлу
 * @param i приймає вказівник на вказівники структури інструментів
 * @return вказівник на структуру елементів
 */
struct Instrument* readFromFile(struct Instrument **i, enum Material* material);
/**
 * Функція сортує інструменти за роком виготовлення
 * @param instruments
 * @return вказівник на структури інструментів
 */


struct Instrument* sortByYear(struct Instrument** instruments);

/**
 *
 * @param instrument
 * @return вказівник на структури інструментів
 */
struct Instrument* printTheOldestInstrument(struct Instrument** instrument, enum Material* material);

/**
 * Функція записує у файл  відсортовані елементи
 * @param instrument
 * @return вказівник на структури інструментів
 */
struct Instrument *writeInFile(struct Instrument **instrument, enum Material* material);

/**
 * Функція записує у бінарний файл  відсортовані елементи
 * @param instrument
* @return
 */
void writeToBinaryFile(struct Instrument** instrument, enum Material* material);

void readFromBinary(struct Instrument** instrument, enum Material* material);

struct Container{
    struct Instrument** array;
    int size;
};

