class student:
    def __init__(self, firstName, secondName, a, b, c):
        self.fName = firstName
        self.sName = secondName
        self.firstG = a
        self.secondG = b
        self.thirthG = c
    def ave(self):
        self.average = (self.firstG + self.secondG + self.thirthG)/3
        return self.average

    

student1 = student('Paulo', 'Borges', 5, 14, 15)
student2 = student('Mariana', 'Silva', 16, 18, 17)

print(student1.fName + ' ' + student1.sName)
print(student1.firstG, student1.secondG, student1.thirthG)
print('Average is: ', round(student1.ave(), 1))
print('')
print(student2.fName + ' ' + student2.sName)
print(student2.firstG, student2.secondG, student2.thirthG)
print('Average is: ', round(student2.ave(), 1))
