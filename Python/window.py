from tkinter import *

root = Tk()

name = Entry(root, width=40)
name.grid(row=0, column=0)

def click():
    string = "Hello " + name.get() + ", how are you?"
    label = Label(root, text=string)
    label.grid(row=2, column=0)

myButton = Button(root, text="Enter your name!", padx=50, command=click)
myButton.grid(row=1, column=0)

root.mainloop()