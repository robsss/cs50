# TODO
from cs50 import get_int

# Numbers of digits
N = 16

# Get input
while 1:
    numbers = get_int("Number: ")
    if numbers > 50000:
        break

# Get digits
digits = []
for i in range(N):
    digits.append(int(numbers / 10 ** (N - i - 1)))
    numbers -= digits[i] * (10 ** (N - i - 1))

print(digits)

sum_up = 0
# Luhn algorithm
for i in range(N - 1, 0, -2):
    print(digits[i - 1]*2 % 10, end='')
    print(int(digits[i - 1]*2 /10), end='')
    print(digits[i])
    sum_up += digits[i - 1]*2 % 10
    sum_up += int(digits[i - 1]*2 /10)
    sum_up += digits[i]

print(sum_up)
if (sum_up % 10) == 0:
    if (digits[0] == 0 and digits[1] == 3) and (digits[2] == 4 or digits[2] == 7):
        print("AMEX")
    elif (digits[0] == 5) and (digits[1] >= 1 and digits[1] <= 5):
        print("MASTERCARD")
    elif (digits[0] == 4) or (digits[0] == 0 and digits[1] == 0 and digits[2] == 0 and digits[3] == 4):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")

