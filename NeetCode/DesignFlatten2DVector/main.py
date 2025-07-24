from solution import Vector2D

def testCase1():
    vec = [[1, 2], [3], [4]]
    f2dv = Vector2D(vec) 

    print(f2dv.next())
    print(f2dv.next())
    print(f2dv.next())
    print(f2dv.hasNext())
    print(f2dv.hasNext())
    print(f2dv.next())
    print(f2dv.hasNext())

def testCase2():
    vec = [[], [3]]
    f2dv = Vector2D(vec) 

    print(f2dv.hasNext())
    print(f2dv.next())
    print(f2dv.hasNext())

def main():
    testCase2()

if __name__ == "__main__":
    main()