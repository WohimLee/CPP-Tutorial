#include <vector>
#include <iostream>
#include <numeric>  // std::accumulate
#include <iterator> // std::istream_iterator

int main()
{
    std::vector<double> values;
    std::cout << "Enter values separated by one or more spaces.Enter Ctrl+Z to end:\n ";
    values.insert(std::begin(values),
                  std::istream_iterator<double>(std::cin),
                  std::istream_iterator<double> ());
    std::cout << "The average is "
              <<(std::accumulate(std::begin(values),
                                 std::end(values),
                                 0.0)/values.size())
              << std::endl;

    return 0;
}
