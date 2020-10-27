"""
cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.
For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
"""

def cons(a, b):
    def pair(f):
        return f(a,b)
    return pair

def cars(f):
    def get_first(a, b):
        return a

    return f(get_first)

def cdr(f):
    def get_last(a, b):
        return b

    return f(get_last)

def main():
    car = cars(cons(3, 4))
    cdrs = cdr(cons(3, 4))
    print(car)
    print(cdrs)


main()