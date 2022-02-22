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
        calculation.clear();
        result.push_back(calculation);
    }
    return result;
}

int main() {
    std::vector<CalculationRow> calculations = calculate(1000, 1400, 10);
    Saver firstSaver;
    for (const auto &calculation: calculations) {
        firstSaver.add(calculation);
    }
    firstSaver.save("ultra_data.csv");
    return 0;
}
