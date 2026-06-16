class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age


    def greet(self):
            return f"Hello; my name is {self.name}, and I'm {self.age} years old"


if __name__ == '__main__':
    person1 = Person("John", 28)
    print(person1. greet())
    person2 = Person("Adam", 18)
    print(person2.greet())
    person3 = Person("Joachim", 22)
    print(person3.greet())
