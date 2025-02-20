
class BingoBoardContainer():
    def __init__(self):
        self.bingo_boards: list[BingoBoard] = []
        self.completed_boards: list[int] = []
        self.all_complete: bool = False

    def allComplete(self) -> bool:
        return self.all_complete
    
    def checkAllComplete(self):
        for board in self.completed_boards:
            if board == 0:
                return

        self.all_complete = True
        return

    def markComplete(self, board_index: int):
        self.completed_boards[board_index] = 1

        self.checkAllComplete()

class BingoBoard():
    def __init__(self):
        self._board: list[list[int]] = [[-1 for _ in range(5)] for _ in range(5)]
        self._marked_board: list[list[int]] = [[0 for _ in range(5)] for _ in range(5)]

    def markElement(self, number_to_mark: int):
        element = self.__findElement(number_to_mark)

        if (element[0] != -1) and (element[1] != -1):
            self._marked_board[element[0]][element[1]] = 1 
    
    def setRow(self, row: list[int], row_index: int):
        self._board[row_index] = row

    def checkWinner(self, diagonal: bool = False) -> bool:
        if diagonal:
            return False
        else:
            for row in self._marked_board:
                if self.__checkRow(row):
                    return True

            for col in zip(*self._marked_board):
                if self.__checkCol(list(col)):
                    return True

            return False
    
    def calculateUnmarkedSum(self) -> int:
        unmarked_sum: int = 0
        for row_index in range(0, len(self._board)):
            for col_index in range(0, len(self._board[0])):
                if self._marked_board[row_index][col_index] == 0:
                    unmarked_sum += self._board[row_index][col_index]

        return unmarked_sum 

    def __findElement(self, number_to_find: int) -> (int, int):
        for row_index in range(0, len(self._board)):
            for col_index in range(0, len(self._board[0])):
                if self._board[row_index][col_index] == number_to_find:
                    return (row_index, col_index)

        return (-1, -1)

    def __checkRow(self, row: list[bool]) -> bool:
        for row_mark in row:
            if row_mark == 0:
                return False

        return True

    def __checkCol(self, col: list[bool]) -> bool:
        for col_mark in col:
            if col_mark == 0:
                return False

        return True
                
def solutionOne():

    end_of_file: bool = False
    bingo_input_numbers: list[int] = []
    bingo_input_line_read: bool = False

    all_bingo_boards: BingoBoardContainer = BingoBoardContainer()
    row_index: int = 0

    with open("input.txt", "r", encoding="utf8") as f:
        while not end_of_file:
            line = f.readline()

            if not line:
                end_of_file = True
                continue

            if line in ('', '\n'):
                all_bingo_boards.bingo_boards.append(BingoBoard())
                row_index = 0
                continue
            
            if bingo_input_line_read == False:
                bingo_input_line_read = True
                split_by_comma: list[str] = line.split(',')
                bingo_input_numbers = list(map(lambda x : int(x), split_by_comma))
            else:
                split_by_space: list[str] = line.split() 
                bingo_input_row = list(map(lambda x : int(x), split_by_space))
                all_bingo_boards.bingo_boards[-1].setRow(bingo_input_row, row_index)
                row_index += 1

    def helper(bingo_input_list: list[int], all_bingo_boards: BingoBoardContainer) -> int:
        for new_number in bingo_input_list:
            for bingo_board in all_bingo_boards.bingo_boards:
                bingo_board.markElement(new_number)
                
                if bingo_board.checkWinner():
                    return bingo_board.calculateUnmarkedSum() * new_number

        return -1
    
    result = helper(bingo_input_numbers, all_bingo_boards)

    print(f"Solution one: {result}")

def solutionTwo():

    end_of_file: bool = False
    bingo_input_numbers: list[int] = []
    bingo_input_line_read: bool = False

    all_bingo_boards: BingoBoardContainer = BingoBoardContainer()
    row_index: int = 0

    with open("input.txt", "r", encoding="utf8") as f:
        while not end_of_file:
            line = f.readline()

            if not line:
                end_of_file = True
                continue

            if line in ('', '\n'):
                all_bingo_boards.bingo_boards.append(BingoBoard())
                all_bingo_boards.completed_boards.append(0)
                row_index = 0
                continue

            if bingo_input_line_read == False:
                bingo_input_line_read = True
                split_by_comma: list[str] = line.split(',')
                bingo_input_numbers = list(map(lambda x : int(x), split_by_comma))
            else:
                split_by_space: list[str] = line.split()
                bingo_input_row = list(map(lambda x : int(x), split_by_space))
                all_bingo_boards.bingo_boards[-1].setRow(bingo_input_row, row_index)
                row_index += 1

    def helper(bingo_input_list: list[int], all_bingo_boards: BingoBoardContainer) -> int:
        for new_number in bingo_input_list:
            for bingo_board_index in range(0, len(all_bingo_boards.bingo_boards)):
                if all_bingo_boards.completed_boards[bingo_board_index]:
                    continue

                all_bingo_boards.bingo_boards[bingo_board_index].markElement(new_number)

                if all_bingo_boards.bingo_boards[bingo_board_index].checkWinner():
                    all_bingo_boards.markComplete(bingo_board_index)

                if all_bingo_boards.allComplete():
                    return all_bingo_boards.bingo_boards[bingo_board_index].calculateUnmarkedSum() * new_number


    result = helper(bingo_input_numbers, all_bingo_boards)

    print(f"Solution two: {result}")

def main():
    solutionOne()
    solutionTwo()

if __name__ == "__main__":
    main()
