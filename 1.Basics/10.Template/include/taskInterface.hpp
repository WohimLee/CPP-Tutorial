
#ifndef TASKINTERFACE_HPP
#define TASKINTERFACE_HPP

template<typename T>
class TaskInterface {
public:
    virtual void execute() = 0;
    virtual bool validate(const T& data) = 0;
};
#endif // TASKINTERFACE_HPP