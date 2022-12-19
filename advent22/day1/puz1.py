elf_sum = 0
max = 0
file = open("trial.txt", "r")

three_largest = [float("-inf"), float("-inf"), float("-inf")]

for line in file:
    if(line == '\n'):
        if(elf_sum > three_largest[0]):
            three_largest[2] = three_largest[1]
            three_largest[1] = three_largest[0]
            three_largest[0] = elf_sum
        elif(elf_sum > three_largest[1]):
            three_largest[2] = three_largest[1]
            three_largest[1] = elf_sum
        elif(elf_sum > three_largest[2]):
            three_largest[2] = elf_sum
        elf_sum = 0
    else:
        elf_sum += int(line.strip())
if(elf_sum > three_largest[0]):
    three_largest[2] = three_largest[1]
    three_largest[1] = three_largest[0]
    three_largest[0] = elf_sum
elif(elf_sum > three_largest[1]):
    three_largest[2] = three_largest[1]
    three_largest[1] = elf_sum
elif(elf_sum > three_largest[2]):
    three_largest[2] = elf_sum

print(sum(three_largest))