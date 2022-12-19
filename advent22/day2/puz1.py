player1Code = {
    "A" : "rock",
    "B" : "paper",
    "C" : "scissors"
}

player2Code = {
    "X" : "rock",
    "Y" : "paper",
    "Z" : "scissors"
}

shapeScore = {
    "rock" : 1,
    "paper" : 2,
    "scissors" : 3
}

def gameOutcome(ch1, ch2):
    if ch1 == 'rock' and ch2 == 'scissors':
        return 0
    elif ch1 == 'scissors' and ch2 == 'rock':
        return 1
    elif ch1 == 'paper' and ch2 == 'rock':
        return 0
    elif ch1 == 'rock' and ch2 == 'paper':
        return 1
    elif ch1 == 'scissors' and ch2 == 'paper':
        return 0
    elif ch1 == 'paper' and ch2 == 'scissors':
        return 1    

file = open("puz1.txt", "r")

total_score = 0

for line in file:
    oppMove = player1Code[line[0]]
    playerMove = player2Code[line[2]]
    gameScore = 0
    if(oppMove == playerMove):
        gameScore = 3
    else:
        gameScore = 6*gameOutcome(oppMove, playerMove)
    total_score += gameScore + shapeScore[playerMove]

print(total_score)
