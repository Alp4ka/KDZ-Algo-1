/*
 * ПиАА 2022, Горковец Роман Романович, БПИ204
 * CLion 2021.2.3
 * Чек-лист:
 * + Все труебуемые виды сортировок;
 * + Сохранение результатов расчетов в .csv формат;
 * + Графики, их анализ;
 * + Ассерт на условие отсортированности массива. В случае false - бросатеся исключение;
 * + Программы были запущены несколько раз для чистоты эксперимента;
 * + Значения итоговых файлов были усреднены для более точной картины происходящего;
 * + Сохранение входных массивов в формате .csv;
 * + Сохрвнение отсортированных входных массивов в формате .csv;
 * + Подсчет времени сортировки в наносекундах;
 * + Документация к коду;
 */


#include "generator_wrappers.h"
#include "saver.h"
#include <vector>

/*
 * Start analytics.
 */
std::vector<CalculationRow> calculate(int start_from, int end_with, int diff) {
    std::vector<CalculationRow> result;
    for (int number_of_elements = start_from; number_of_elements <= end_with;
         number_of_elements += diff) {
        CalculationRow calculation(number_of_elements);
        calculation.start();
        result.push_back(calculation);
    }
    return result;
}

int main() {
    std::vector<CalculationRow> calculations = calculate(100, 4100, 100);
    Saver firstSaver;
    for (CalculationRow calculation: calculations) {
        firstSaver.add(calculation);
    }
    firstSaver.save("../results_nanos/4100.csv");
    firstSaver.saveArrays("../results_nanos/input4100.csv", "../results_nanos/output4100.csv");
    for (CalculationRow calculation: calculations) {
        calculation.clear();
    }
    return 0;
}
