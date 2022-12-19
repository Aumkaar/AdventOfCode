moveCode = {
    "X" : 0,
    "Y" : 3,
    "Z" : 6
}

file = open("puz1.txt", "r")

total_score = 0

for line in file:
    score1 = ((ord(line[0]) - ord('A') + 1) + (ord(line[2]) - ord('Y'))) % 3
    if score1 == 0:
        score1 = 3

    score2 = moveCode[line[2]]
    total_score += score1 + score2

print(total_score)