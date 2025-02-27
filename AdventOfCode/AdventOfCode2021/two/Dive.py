
def solutionOne():
    
    horizontal_position: int = 0
    depth: int = 0

    end_of_line: bool = False

    with open("input.txt", "r", encoding="utf8") as f:
        while not end_of_line:

            line = f.readline()

            if not line:
                end_of_line = True
                continue

            instruction_list: list[str] = line.split(" ")
            instruction: str = instruction_list[0]
            amount: int = int(instruction_list[1])

            if instruction == "forward":
                horizontal_position += amount
            
            elif instruction == "down":
                depth += amount

            elif instruction == "up":
                depth -= amount
    
    print(f"Solution 1: {horizontal_position * depth}")
    

def solutionTwo():

    horizontal_position: int = 0
    depth: int = 0
    aim: int = 0

    end_of_line: bool = False

    with open("input.txt", "r", encoding="utf8") as f:
        
        while not end_of_line:
            
            line = f.readline()
            if not line:
                end_of_line = True
                continue

            instruction_list: list[str] = line.split(" ")
            instruction: str = instruction_list[0]
            amount: int = int(instruction_list[1])

            if instruction == "forward":
                horizontal_position += amount
                depth += aim * amount
            
            elif instruction == "down":
                aim += amount

            elif instruction == "up":
                aim -= amount
    
    print(f"Solution 2: {horizontal_position * depth}")


def main():
    solutionOne()
    solutionTwo()

if __name__ == "__main__":
    main()
