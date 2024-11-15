import numpy as np
import matplotlib.pyplot as plt


# Generate time values
t = np.linspace(0, 1, 1000)

# Generate exponential growth signal
 # Exponential growth rate (a > 1)
u = np.exp(2 * t)

# Plot the signal
plt.plot(t, u)
plt.title('Continuous Exponential Growth Signal')
plt.xlabel('Time (t)')
plt.ylabel('e^(at)')
plt.grid()
plt.show()
