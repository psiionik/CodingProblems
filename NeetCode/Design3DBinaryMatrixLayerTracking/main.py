from solution import Matrix3D

def testCase1():
    n = 3
    matrix_3d = Matrix3D(n) 
    matrix_3d.setCell(0, 0, 0)
    print(matrix_3d.largestMatrix())
    matrix_3d.setCell(1, 1, 2)
    print(matrix_3d.largestMatrix())
    matrix_3d.setCell(0, 0, 1)
    print(matrix_3d.largestMatrix())

def main():
    testCase1()

if __name__ == "__main__":
    main()