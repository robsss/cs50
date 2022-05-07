# TODO
from cs50 import get_int


# Main
def main():
    # Get input
    while 1:
        height = get_int("Height: ")
        if (height >= 1) and (height <= 8):
            break
    # Draw
    for i in range(height):
        draw_space(height - (i + 1))
        draw_hash(i + 1)
        print()


# Draw spaces
def draw_space(number):
    for i in range(number):
        print(" ", end='')

# Draw hashes


def draw_hash(number):
    for i in range(number):
        print("#", end='')


if __name__ == "__main__":
    main()

