import random


def randomIntSet(size, Filename):
    file = open(Filename, 'w')
    file.write(f"{size}\n")
    noDupList = random.sample(range(size*10), size)
    for n in noDupList:
        file.write(f"{n}\n")
    file.close()

def ascendingIntSet(size, Filename):
    file = open(Filename, 'w')
    file.write(f"{size}\n")
    for n in range(size):
        file.write(f"{n}\n")
    file.close()

def ascendingSixtyIntSet(size, Filename):
    file = open(Filename, 'w')
    begin = int(size*0.6)
    end = int(size - begin)
    file.write(f"{size}\n")
    for n in range(begin):
        file.write(f"{n}\n")
    lastForty = random.sample(range(end*10), end)
    lastForty.sort(reverse=True)
    for n in lastForty:
        file.write(f"{n+begin}\n")
    file.close()

def randomDupIntSet(amtDup, size, Filename):
    file = open(Filename, 'w')
    end = int(size*amtDup)
    begin = int(size-end)
    file.write(f"{size}\n")
    someDupList = random.sample(range(begin), begin)
    for n in someDupList:
        file.write(f"{n}\n")

    someDupList = random.sample(range(end), end)
    for n in someDupList:
        file.write(f"{n}\n")
    file.close()





size = 1000000
randomIntSet(size, "random_noDup.txt")
ascendingIntSet(size, "ascending_noDup.txt")
ascendingSixtyIntSet(size, "60ascending_noDup.txt")
randomDupIntSet(0.2, size, "random_20Dup.txt")
randomDupIntSet(0.4, size, "random_40Dup.txt")

