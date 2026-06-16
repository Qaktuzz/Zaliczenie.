class Circle:
    pi = 3.14159

    def __init__(self, radius):
        self.radius = radius


    def area(self):
        return self.pi * (self.radius ** 2)

    @classmethod
    def set_pi(cls, value):
        cls.pi = value


if __name__ == '__main__':
    circle = Circle(2)
    print('Circle 1 Area is:', circle.area())

    Circle.set_pi(80)
    print('Circle 1 Area is:', circle.area())
    circle2 = Circle(7)
    print('Circle 2 Area is:', circle2.area())
