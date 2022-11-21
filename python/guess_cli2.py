import numpy as np

# This function initialises the 'runum', 'tries', 'low', 'high', 'mode' and 'win' variables
# It takes no parameter and returns nothing.

def init():
    global ranum
    global tries
    global low
    global high
    global mode
    global win
    win = 0
    low = 10
    high = 60

# This function prints the details of the three game modes and asks the user to input 1 for 1st game mode, 2 for 2nd game mode and 3 for
# 3rd game mode.    It takes no parameter and returns the value of tries variable

def chooseGameMode():
    global mode
    global tries
    global low
    global high

    mode = int(input("\nChoose game mode:\n1 :  Range: 1 - 10  Tries : 2\n2 :  Range: 0 - 20  Tries : 3\n3 :  Range: 0 - 50  Tries : 5\nMode: "))
    if mode == 1:
        tries = 2
        low = 1
        high = 11
        return 2
    elif mode == 2:
        tries = 3
        low = 1
        high = 21
        return 3
    elif mode == 3:
        tries = 5
        low = 1
        high = 51
        return 5
    else:
        print("Wrong input")
        chooseGameMode()

# This function picks a random number between the range [low, high] and assigns it to the variable 'ranum'


def choose():
    global ranum
    ranum = np.random.randint(low, high)
    print(f"A number between {low} and {high-1} was chosen")

# This function verifies whether the supplied string 'raw' is numeric or not and then it checks whether the numeric value of raw is in between
# low and high.     It takes three parameter : raw and returns True or False

def isVerified(raw):
    try:
        value = int(raw)
        if value in range(low, high):
            return True
        else:
            return False
    except:
        return False

# This function checks whether the raw_input (the numeric value) supplied by user is equal to the random number (ranum)
# or less or greater than ranum and also checks whether the number of tries left or not prints the message accordingly
# ("Correct!", "UP" and "DOWN").    It takes three parameter : raw_input, randum, tries and returns nothing.

def decide(raw_input, randum, triess):
    stat = ""
    win = 0
    if int(raw_input) == randum:
        stat = "CORRECT!"
        win = 1
    elif int(raw_input) < randum:
        stat = "UP"
    else:
        stat = "DOWN"

    if (triess > 1) and (win == 0):
        print(f"{stat}  Tries: {triess-1}")

    if win == 1:
        print("You won the game!", stat);


# This function is the entry point for the program. It contains init(), chooseGameMode(), choose() in order and then it takes input from
# user and runs isVerified() and decide() in a loop till the tries variable become 0. Then it exits out of the loop
# and asks the user whether to replay or not. Finally it prints "Have a good day :)"

def play():
    init()
    tries = chooseGameMode()

    choose()

    print(f"Tries : {tries}")
    while (tries != 0) and (win == 0):
        raw_input = input("Enter the number: ")

        if isVerified(raw_input):

            decide(raw_input, ranum, tries)
            tries -= 1
        else:
            print("Wrong input, try again")

    print(f"The number was {ranum}")

    inp = input("Do you want to play again? (Y/N) : ")

    if (inp == "Y") or (inp == "y"):
        play()
    else:
        print("Have a good day :)")


play()