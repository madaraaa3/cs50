def main():
    greeting()


def greeting():
    greet = input("Greeting: ")
    if "Hello" in greet:
        print( "$0")
    elif greet[0] in ["h", "H"]:
        print("$20")
    else:
        print("$100")


main()