


class Person:
    def __init__(self, age):
        self.age = age

    def PersonAddAge(self, p):
        self.age += p.age
        return self


if __name__ == "__main__":
    p = Person(10, "Tom")
    p.func()
    Person.func()