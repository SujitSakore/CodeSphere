##Continious

import numpy as np
import matplotlib.pyplot as plt

# Generate time values
t = np.linspace(0, 1, 2000)

# Generate cosine signal
frequency = 5  # Frequency in Hz
cosine_wave = np.cos(2 * np.pi * frequency * t)

# Plot the signal
plt.plot(t, cosine_wave)
plt.title('Continuous Cosine Signal')
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.grid()
plt.show()

'''
##Discrete

import numpy as np
import matplotlib.pyplot as plt

# Generate discrete time values
n = np.arange(0, 100, 1)

# Generate cosine signal
frequency = 0.1  # Frequency in Hz
cosine_wave = np.cos(2 * np.pi * frequency * n)

# Plot the signal
plt.stem(n, cosine_wave)
plt.title('Discrete Cosine Signal')
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.grid()
plt.show()
'''