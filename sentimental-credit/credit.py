# TODO
# declaring the main function
def main():
    while True:
        try:
            card_number = input("Enter you're credit card number")
            if card_number.isnumeric() and not card_number.isspace():
                break
        except:
            continue
    check(card_number)


def check(card_number):
    if checksum(card_number) and 13 <= len(card_number) <= 16:
        if card_number[0] == "3" and card_number[1] == "4" or card_number[1] == "7":
            print("AMEX")
        elif card_number[0] == "5" and int(card_number[1]) in range(1, 6):
            print("MASTERCARD")
        elif card_number[0] == "4":
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def checksum(card_number):
    icn = []
    for elm in card_number:
        f = int(elm)
        icn.append(f)
    sliced = icn[-2::-2]
    tmp = []
    ind = 0
    for i in sliced:
        x = int(sliced[ind]) * 2
        ind += 1
        if x >= 10 and x < 100:
            for s in str(x):
                y = int(s)
                tmp.append(y)
        else:
            tmp.append(x)
    total = sum(tmp, sum(icn[-1::-2]))
    it = str(total)
    if str(total)[-1] == "0":
        return True
    else:
        return False


main()
