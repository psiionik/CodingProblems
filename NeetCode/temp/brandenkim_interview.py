import copy
import random
import pprint
import uuid

class Payment():
    def __init__(self):
        pass

    def processPayment(self):
        return True
        # credit_card = parameters['credit_card']
        # user_seats = parameters['user_seats']

class FlightSeatPicker():
    def __init__(self, rows, columns):
        self.row_length = rows
        self.column_length = columns
        self.board = [[None] * columns for _ in range(rows)]

    def getAllSeats(self, parameters):
        user_id = parameters['user_id']
        anon_board = [[None] * self.column_length for _ in range(self.row_length)]
        user_seats = []
        
        for row in range(self.row_length):
            for col in range(self.column_length):
                if self.board[row][col] is not None:
                    anon_board[row][col] = -1
                    if self.board[row][col] == user_id:
                        user_seats.append((row, col))

        return {
            'board': anon_board,
            'user_seats': user_seats
        } 

    def postPickSeats(self, list_of_selected):
        payment = Payment()
        board_copy = copy.deepcopy(self.board)
        for attributes in list_of_selected:
            row = attributes['row']
            column = attributes['column']
            user_id = attributes['user_id']

            if row < 0 or row >= self.row_length or column < 0 or column >= self.column_length:
                assert False, f"Invalid row / column size! Got {row}, {column}."

            if board_copy[row][column] is not None:
                assert False, f"Tried to book {row} {column} when it was already booked!"
            
            board_copy[row][column] = user_id

        try:
            payment.processPayment()
            self.board = board_copy
            return True
        except:
            print("Payment Failed! Please Try Again!") 
            return False
    

def runTestCase1():
    rows = 4
    columns = 50
    ap = FlightSeatPicker(rows, columns)
    list_of_selected = [
        {
            "row": 0,
            "column": 0,
            "user_id": "abc"
        }
    ]

    res = ap.postPickSeats(list_of_selected)
    assert res == True

    expected = [[None] * columns for _ in range(rows)]
    expected[0][0] = "abc"

    assert ap.board[0][0] == expected[0][0], "Test Case 1 Failed!"

def runTestCase2():
    rows = 4
    columns = 50
    ap = FlightSeatPicker(rows, columns)
    list_of_selected = [
        {
            "row": 12,
            "column": 0,
            "user_id": "abc"
        }
    ]
    try:
        res = ap.postPickSeats(list_of_selected)
    except:
        print('Board update failed as expected!')
        expected = [[None] * columns for _ in range(rows)]

        assert ap.board[0][0] == expected[0][0], "Test Case 2 Failed!"

def runTestCase_BookTwice():
    rows = 4
    columns = 50
    ap = FlightSeatPicker(rows, columns)
    list_of_selected_1 = [
        {
            "row": 0,
            "column": 0,
            "user_id": "abc"
        }
    ]
    res = ap.postPickSeats(list_of_selected_1)

    list_of_selected_2 = [
        {
            "row": 0,
            "column": 0,
            "user_id": "def"
        }
    ]

    try:
        res = ap.postPickSeats(list_of_selected_2)
    except:
        print('Board update failed as expected!')

def runTestCase_Generative():
    rows = 4
    columns = 50
    ap = FlightSeatPicker(rows, columns)
    list_of_selected_1 = [
        {
            "row": 0,
            "column": 0,
            "user_id": "abc"
        }
    ]
    res = ap.postPickSeats(list_of_selected_1)

    list_of_selected_2 = [
        {
            "row": 0,
            "column": 0,
            "user_id": "def"
        }
    ]

    try:
        res = ap.postPickSeats(list_of_selected_2)
    except:
        print('Board update failed as expected!')

def runTestCase_GetSeatsUserSimple():
    user_id = "abc"
    row = 4
    column = 5
    list_of_selected = [
        {
            "row": 0,
            "column": 0,
            "user_id": "abc"
        },
        {
            "row": 2,
            "column": 3,
            "user_id": "abc"
        }
    ]
    sp = FlightSeatPicker(row, column)
    sp.postPickSeats(list_of_selected)

    res = sp.getAllSeats({'user_id': user_id})
    pprint.pprint(res)

def runTestCase_GetSeatsUserUnbooked():
    user_id = "def"
    row = 4
    column = 5
    list_of_selected = [
        {
            "row": 0,
            "column": 0,
            "user_id": "abc"
        },
        {
            "row": 2,
            "column": 3,
            "user_id": "abc"
        }
    ]
    sp = FlightSeatPicker(row, column)
    sp.postPickSeats(list_of_selected)

    res = sp.getAllSeats({'user_id': user_id})
    pprint.pprint(res)

def runTestCase_GetSeatsUserFilterOthers():
    user_id = "def"
    row = 4
    column = 5
    list_of_selected = [
        {
            "row": 0,
            "column": 0,
            "user_id": "abc"
        },
        {
            "row": 2,
            "column": 3,
            "user_id": "def"
        }
    ]
    sp = FlightSeatPicker(row, column)
    sp.postPickSeats(list_of_selected)

    res = sp.getAllSeats({'user_id': user_id})
    pprint.pprint(res)

def runTestCase_GetSeatsFuzzing():
    for _ in range(10000):
        row = random.randint(1, 1000)
        col = random.randint(1, 1000)
        user_id = "abc"
        list_of_selected = []

        for _ in range(row * col):
            list_of_selected.append(
                {
                    "row": random.randint(1, row),
                    "col": random.randint(1, col),
                    "user_id": str(uuid.uuid4())
                }
            )

def runAllTestCases():
    # runTestCase1()
    # runTestCase2()
    # runTestCase_BookTwice()
    runTestCase_GetSeatsUserSimple()
    runTestCase_GetSeatsUserUnbooked()
    runTestCase_GetSeatsUserFilterOthers()

def main():
    runAllTestCases()

if __name__ == "__main__":
    main()