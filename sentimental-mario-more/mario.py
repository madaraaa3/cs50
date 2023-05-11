# TODO
def main():
    while True:
        try:
            height = int(input("Enter a positive number between 1 and 8 :"))
            if isinstance(height, int) and height <= 8 and height > 0:
                break
        except ValueError:
            continue
    build_pyramid(height)


def build_pyramid(height):
    width = height
    for c in range(width):
        print(' ' * (width - 1), end="")
        print("#" * (c + 1), "#" * (c + 1), sep='  ')
        width -= 1


main()