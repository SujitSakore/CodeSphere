import numpy as np
import matplotlib.pyplot as plt

LL=int(input("Enter LL for graph"))
UL=int(input("Enter UL for graph"))
a= int(input("Enter a:"))
t = np.linspace(LL, UL, 1000) # time interval of the signal

y = np.exp(-a * t)

plt.plot(t, y)
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.title('Continuous e^-at Function')
plt.xticks(np.arange(LL, UL, 1))
plt.show()