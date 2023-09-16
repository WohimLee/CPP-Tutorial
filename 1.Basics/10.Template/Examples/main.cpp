#include "taskImplement.hpp"

int main() {
    TaskImplement<std::string> task;
    task.execute(); // Output: Executing task...
    task.validate("some data"); // Output: Data is valid
    task.validate(""); // Output: Data is not valid


    return 0;
}
