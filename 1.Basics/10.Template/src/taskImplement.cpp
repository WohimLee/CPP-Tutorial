#include "taskImplement.hpp"

template<typename T>
void TaskImplement<T>::execute() {
    std::cout << "Executing task..." << std::endl;
}

template<typename T>
bool TaskImplement<T>::validate(const T& data) {
    if (!data.empty()) {
        std::cout << "Data is valid" << std::endl;
        return true;
    } else {
        std::cout << "Data is not valid" << std::endl;
        return false;
    }
}

// Explicit instantiation of template
// otherwise it will not be instantiated until used in another file
template class TaskImplement<std::string>;