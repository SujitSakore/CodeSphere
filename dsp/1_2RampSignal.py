##Continious

import numpy as np
import matplotlib.pyplot as plt

# Generate time values
n = np.linspace(-1, 1, 100)

# Generate ramp signal
ramp = np.where(n>=0,n,0)

# Plot the signal
plt.plot(n, ramp)
plt.title('Continuous Ramp Signal')
plt.xlabel('Time (t)')
plt.ylabel('r(t)')
plt.grid()
plt.show()


##Discrete

import numpy as np
import matplotlib.pyplot as plt

# Generate discrete time values
n = np.arange(-10, 11, 1)

# Generate ramp signal
ramp = np.maximum(0, n)

# Plot the signal
plt.stem(n, ramp)
plt.title('Discrete Ramp Signal')
plt.xlabel('n')
plt.ylabel('r[n]')
plt.grid()
plt.show()


