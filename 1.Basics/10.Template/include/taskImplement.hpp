#ifndef TASKIMPLEMENT_HPP
#define TASKIMPLEMENT_HPP

#include "taskInterface.hpp"
#include <iostream>

template<typename T>
class TaskImplement : public TaskInterface<T> {
public:
    void execute() override;
    bool validate(const T& data) override;
};


#endif // TASKIMPLEMENT_HPP