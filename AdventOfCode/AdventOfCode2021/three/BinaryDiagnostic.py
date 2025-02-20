

def solutionOne():

    end_of_file: bool = False
    bit_parity_list: list[int] = []
    gamma: int = 0
    epsilon: int = 0

    with open("input.txt", "r", encoding="utf8") as f:
        while not end_of_file:
            line = f.readline()

            if not line:
                end_of_file = True
                continue

            if len(bit_parity_list) == 0:
                bit_parity_list = [0] * (len(line) - 1)
            
            for bit_index in range(0, len(line) -1):
                if line[bit_index] == "1":
                    bit_parity_list[bit_index] += 1
                else:
                    bit_parity_list[bit_index] -= 1
        
        # Constructing binary string to convert to int
        gamma_string: str = ""
        for bit in bit_parity_list:
            if bit < 0:
                gamma_string += "0"
            else:
                gamma_string += "1"

        gamma = int(gamma_string, 2) 
        epsilon = gamma ^ (2**len(gamma_string) - 1)

    print(f"Solution 1 is: {gamma * epsilon}") 


def solutionTwo():

    end_of_file: bool = False
    list_of_binary_numbers: list[str] = []

    def helper(binary_numbers_list: list[str], bit_position: int, tiebreaker_one: bool) -> int:
        if len(binary_numbers_list) == 1:
            return int(binary_numbers_list[0], 2)
        
        parity: int = 0
        for binary_number in binary_numbers_list:
            if binary_number[bit_position] == '1':
                parity += 1
            else:
                parity -= 1
        
        filtered_list: list[str] = []

        if tiebreaker_one:
            if parity >= 0:
                filtered_list = list(filter(lambda x : x if x[bit_position] == '1' else None, binary_numbers_list))
            else:
                filtered_list = list(filter(lambda x : x if x[bit_position] == '0' else None, binary_numbers_list))
        else:
            if parity >= 0:
                filtered_list = list(filter(lambda x : x if x[bit_position] == '0' else None, binary_numbers_list))
            else:
                filtered_list = list(filter(lambda x : x if x[bit_position] == '1' else None, binary_numbers_list))

        
        return helper(filtered_list, bit_position + 1, tiebreaker_one)

    with open("input.txt", "r", encoding="utf8") as f:
        while not end_of_file:
            line = f.readline()
            
            if not line:
                end_of_file = True
                continue

            list_of_binary_numbers.append(line.strip())

    oxygen: int = helper(list_of_binary_numbers, 0, True)
    co2: int = helper(list_of_binary_numbers, 0, False)

    print(f"Solution 2 is: {oxygen * co2}")

def main():
    solutionOne()
    solutionTwo()

if __name__ == "__main__":
    main()
