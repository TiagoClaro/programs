import os

clear = lambda: os.system('cls')
clear()

num_grades = int(input('Input the number of grades: '))
grades = []
sorted_grades = []
lowerGrade = 1000

print('')

for i in range(0, num_grades, 1):
    aux = float(input('Input your grade: '))
    grades.append(aux)

print('\nYour grades are:')

for i in range(0, num_grades, 1):
    print(grades[i])

ave = 0

for i in range(0, num_grades, 1):
    ave = ave + grades[i]

ave = ave / num_grades

print('\nThe average is: ', ave)

for j in range(0, num_grades, 1):
    for i in range(0, num_grades - j, 1):
        if(grades[i]<lowerGrade):
            lowerGrade = grades[i]
    sorted_grades.append(lowerGrade)
    grades.remove(lowerGrade)
    lowerGrade = 100

print('\nYour grades sorted are:')
for i in range(0, num_grades, 1):
    print(sorted_grades[i])