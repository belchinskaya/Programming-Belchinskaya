/**
 * @mainpage
 * # Індивідуальне завдання
 * Змінити модульні тести таким чином, щоб:
 *
 * • при запуску кожного тесту виводити ім’я тесту, а по завершенні тесту виводити час, що було витрачено на виконання даного тесту;
 *
 * • по завершенні всіх тестів було виведено час їх виконання.
 * @date 14-april-2021
 * @version 1.0
 */

#include "list.h"

/**
 * @file main.c
 * @brief Головний файл з викликом функцій,
 * виділенням пам'яті для динамічних масивів та заданням вхідного тексту.
 *
 *
 * @author Belchynska K.
 * @date 17-march-2021
 * @version 1.0
 */

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - виклик функції для вставки одного масиву в інший
 * - виклик функції для видалення ділянки масиву
 * - виділення пам'яті для структури інструментів
 * - зчитування інформації з файлу
 * - виклик функції для сортування інструментів за роком випуску
 * - виклик функції для виведеня на екран найстаршої скрипки фірми Yamaha
 * - виклик функції для запису результату у файл
 * - виклик функції для запису результату у бінарний файл
 * - виклик функції для видалення елементу з файлу
 * - виклик функції для копіювання елементу структури у файл
 * - звільнення пам'яті для структури інструментів
 *
 * @return 0 при успішному завершенні програми
 */

#include <sys/time.h>
long  currentTimeMillis() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time.tv_sec * 1000 + time.tv_usec / 1000;
}
int main() {
#ifdef DEBUG
    long  start = currentTimeMillis();
#endif
    struct Container container = {NULL, 0, NULL};
    container.head = malloc(sizeof(struct ElementCapsule));
    container.head->previous = NULL;

    container.tail = malloc(sizeof(struct ElementCapsule));
    container.tail->next = NULL;
    container.head->next = container.tail;
    container.tail->previous = container.head;
    container.size = 0;
    insert("abracadabra", "TEXT2", 4 );
    delete_array("abracadabra", 4, 8);

//FILE * file = fopen("/home/kate/Programming-Belchynska/lab15/InstrumentsOut.txt", "r");
    struct Instrument ** instruments = malloc(INSTRUMENT_COUNT * sizeof(struct Instrument* ));
    for (int i = 0; i < 200; i++) {
        *(instruments + i) = malloc(sizeof(struct Instrument));
    }
    getInstrumentList(&container);
    enum Material* material = malloc(sizeof(enum Material));

    readFromFile(instruments);
    sortByYear(instruments);
    deleteStructElement(instruments, material);
    //printInstrument(instruments);
    printTheOldestInstrument(instruments);

    writeInFile(instruments);
    writeToBinaryFile(instruments);
    readFromBinary( instruments);
    copyStructElement(instruments, material);
    //
    //sortByYearList(&container);
    //struct Instrument item;
    //showList(&container);

    dialog(&container, instruments);
    //showArray(&container);
    cleanUp(&container);
#ifdef DEBUG
    long end = currentTimeMillis();
    printf("Total time: %d milliseconds\n", end - start);
#endif

    free(material);
    free(instruments);
    return 0;
}
