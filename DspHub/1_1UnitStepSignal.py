##Continious

import numpy as np
import matplotlib.pyplot as plt

# Define the unit step function
def unit_step(t):
   return np.where(t>=0,1,-1)
# Generate time values
t = np.linspace(-11, 10, 10000)

# Generate unit step signal
u = unit_step(t)

# Plot the signal
plt.plot(t, u)
plt.title('Continuous Unit Step Signal')
plt.xlabel('Time (t)')
plt.ylabel('u(t)')
plt.grid()
plt.show()


##discrete

import numpy as np
import matplotlib.pyplot as plt

# Define the unit step function
def unit_step(n):
    return np.where(n >= 0, 1, 0)

# Generate discrete time values
n = np.arange(-10, 11, 1)

# Generate unit step signal
u = unit_step(n)

# Plot the signal
plt.stem(n, u)
plt.title('Discrete Unit Step Signal')
plt.xlabel('n')
plt.ylabel('u[n]')
plt.grid()
plt.show()


