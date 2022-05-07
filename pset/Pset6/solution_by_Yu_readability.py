# TODO
# program that first asks the user to type in some text,
# and then outputs the grade level for the text, according
# to the Coleman-Liau formula, exactly as you did in Problem
# Set 2, except that your program this time should be written
# in Python.
# Coleman-Liau index is computed as 0.0588 * L - 0.296 * S - 15.8


from cs50 import get_string

text = get_string("Text: ").lower()

num_letters = 0
num_words = 1
num_sentences = 0

for chara in text:
    if chara == ' ':
        num_words += 1
    if (chara >= 'a') and (chara <= 'z'):
        num_letters += 1
    if chara == '.' or chara == '!' or chara == '?':
        num_sentences += 1

L = 100 * num_letters / num_words
S = num_sentences / num_words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
