# TODO
from cs50 import get_float

while 1:
    changes = get_float("Change owed: ")
    if changes > 0:
        break

changes = round(changes * 100)
# Quarters
quarters = int(changes / 25)
changes = changes - quarters*25

# Dimes
dimes = int(changes / 10)
changes = changes - dimes*10

# Nickles
nickles = int(changes / 5)
changes = changes - nickles*5

# Pennies
pennies = changes

# Print out the number of coins
print(quarters + dimes + nickles + pennies)

