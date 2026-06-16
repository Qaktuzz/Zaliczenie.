from abc import ABC, abstractmethod


class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Rectangle(Shape):
        def __init__(self, width, height):
            self.width = width
            self.height = height

        def area(self):
            return self.width * self.height

class Circle(Shape):
        def __init__(self, radius):
            self.radius = radius

        def area(self):
            return 3.14 * self.radius ** 2

class Triangle(Shape):
    def __init__(self, bottom, height):
            self.bottom = bottom
            self.height = height

    def area(self):
        return (self.bottom * self.height) / 2

class trapens(Shape):
    def __init__(self, bottom, top, height):
        self.bottom = bottom
        self.top = top
        self.height = height

    def area(self):
        return (self.bottom + self.top) * self.height / 2

if __name__ == "__main__":

    shapes = [Rectangle(4, 5), Circle(3), Triangle(7, 9), trapens(5, 6, 8)]

    for shape in shapes:
        print(shape.area())




