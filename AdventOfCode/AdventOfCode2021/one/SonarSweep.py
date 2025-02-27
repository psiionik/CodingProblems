import sys

def solutionOne():

    increase_count: int = 0

    with open("input.txt", "r", encoding="utf8") as f:
        end_of_file: bool = False
        previousValue: int = sys.maxsize

        while not end_of_file:
            line = f.readline()

            if not line:
                end_of_file = True
                continue
            
            if previousValue < int(line):
                increase_count += 1

            previousValue = int(line)

    print(f"Total number of increases is: {increase_count}")

def solutionTwo():
    
    increase_count: int = 0

    with open("input.txt", "r", encoding="utf8") as f:
        end_of_file: bool = False
        value_a: int = -1 
        value_b: int = -1 
        value_c: int = -1
        previous_sum: int = sys.maxsize

        while not end_of_file:
            line = f.readline()

            if not line:
                end_of_file = True
                continue

            if value_a == -1 or value_b == -1 or value_c == -1:
                value_c = value_b
                value_b = value_a
                value_a = int(line)
            else:
                previous_sum = value_a + value_b + value_c
                value_c = value_b
                value_b = value_a
                value_a = int(line)

                if previous_sum < value_a + value_b + value_c:
                    increase_count += 1


    print(f"Total number of increases is: {increase_count}")


def main():
    solutionOne()
    solutionTwo()

if __name__ == "__main__":
    main()
