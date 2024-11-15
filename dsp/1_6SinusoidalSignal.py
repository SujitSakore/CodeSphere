##Continious

import numpy as np
import matplotlib.pyplot as plt

# Generate time values
t = np.linspace(0, 1, 1000)

# Generate sine signal
frequency = 2# Frequency in Hz
sine_wave = np.sin(2 * 3.14 *t*6)

# Plot the signal
plt.plot(t, sine_wave)
plt.title('Continuous Sine Signal')
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')
plt.grid()
plt.show()


##discrete

import numpy as np
import matplotlib.pyplot as plt

# Generate discrete time values
n = np.arange(0, 100, 1)

# Generate sine signal
frequency = 0.2 # Frequency in Hz
sine_wave = np.sin(2 * np.pi * frequency * n)

# Plot the signal
plt.stem(n, sine_wave)
plt.title('Discrete Sine Signal')
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.grid()
plt.show()

