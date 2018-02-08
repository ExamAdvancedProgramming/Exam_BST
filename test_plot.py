import numpy as np
import matplotlib.pyplot as plt

with open("Integer_comparison.txt") as ino:
	lines = ino.readlines()

x = lines[10:]
y = lines[5:10]

fig = plt.figure()

ax1 = fig.add_subplot(111)

ax1.set_title("Integers plot")    
ax1.set_xlabel('Number of nodes')
ax1.set_ylabel('Computational times')

ax1.plot(x,y, c='r', label='Integers times')

leg = ax1.legend()

plt.savefig("Integer_plot.png")
plt.show()

with open("String_comparison.txt") as sto:
	lines = sto.readlines()

x = lines[10:]
y = lines[5:10]

fig = plt.figure()

ax2 = fig.add_subplot(111)

ax2.set_title("Strings plot")    
ax2.set_xlabel('Number of nodes')
ax2.set_ylabel('Computational times')

ax2.plot(x,y, c='b', label='Strings times')

leg = ax2.legend()

plt.savefig("String_plot.png")
plt.show()

















