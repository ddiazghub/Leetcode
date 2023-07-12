#include <algorithm>
#include <vector>
#include <limits>
#include <iostream>

/**
 * Find the average salary in a list of salaries excluding the min and max salaries.
 */
double average(std::vector<int>& salaries) {
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    int total = 0;

    for (int salary: salaries) {
        total += salary;
        min = std::min(salary, min);
        max = std::max(salary, max);
    }

    return (total - (min + max)) / (salaries.size() - 2.0);
}

int main() {
    std::vector<int> salaries{48000, 59000, 99000, 13000, 78000, 45000, 31000, 17000, 39000, 37000, 93000, 77000, 33000, 28000, 4000, 54000, 67000, 6000, 1000, 11000};
    std::cout << average(salaries) << '\n';
}