##Continious

import numpy as np
import matplotlib.pyplot as plt

# Define the signum function
def SGN(t):
    return np.where(t>=0,1,-1)

# Generate time values
t = np.linspace(-1, 1, 1000)

# Generate signum signal
s = SGN(t)

# Plot the signal
plt.plot(t, s)
plt.title('Continuous Signum Signal')
plt.xlabel('Time (t)')
plt.ylabel('s(t)')
plt.grid()
plt.show()


##Discrete

import numpy as np
import matplotlib.pyplot as plt

# Define the signum function
def sgn(n):
    return np.where(n>=0,1,-1)

# Generate discrete time values
n = np.arange(-10, 11, 1)

# Generate signum signal
s = sgn(n)

# Plot the signal
plt.stem(n, s)
plt.title('Discrete Signum Signal')
plt.xlabel('n')
plt.ylabel('s[n]')
plt.grid()
plt.show()