import tkinter as tk
import time

root= tk.Tk()

canvas1 = tk.Canvas(root, width = 300, height = 300)
canvas1.pack()

def hello ():  
    print("start - start your MC 1.15.2 server")
    print("stop - stop your MC 1.15.2 server")
    print("restart - restart your MC 1.15.2 server")
    
button1 = tk.Button(text='Executions:',command=hello, bg='brown',fg='white')
canvas1.create_window(150, 150, window=button1)

root.mainloop()
