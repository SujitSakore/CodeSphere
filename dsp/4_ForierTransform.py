import numpy as np
import matplotlib.pyplot as plt

# Sample parameters
sampling_rate = 1000  # Sampling rate in Hz
T = 1.0 / sampling_rate  # Time period
L = 1000  # Length of signal (number of samples)
t = np.linspace(-L * T / 2, L * T / 2, L) # Time vector 

# Example signal: sum of two sinusoids
freq1 = 50  # Frequency of the first sine wave
freq2 = 120  # Frequency of the second sine wave
signal = np.exp(-2.0*abs(t))

# Define frequency range for the Fourier Transform
frequencies = np.linspace(-500, 500, 500)  # Frequencies from 0 to 500 Hz

# Compute Fourier Transform using numerical integration
def numerical_fourier_transform(signal, t, frequencies):
    N = len(signal)
    dt = t[1] - t[0]  # Time step
    fourier_result = np.zeros(len(frequencies), dtype=complex)

    for i, f in enumerate(frequencies):
        integrand = signal * np.exp(-2j * np.pi * f * t)  # Signal * exponential term
        fourier_result[i] = np.trapz(integrand, dx=dt)  # Numerical integration (trapezoidal rule)
    
    return fourier_result

# Compute the Fourier Transform
fourier_transform = numerical_fourier_transform(signal, t, frequencies)
fourier_amplitude = np.abs(fourier_transform)
fourier_phase = np.angle(fourier_transform)

# Plot the signal
plt.figure(figsize=(12, 6))
plt.subplot(2, 1, 1)
plt.plot(t, signal) 
plt.title('Time Domain Signal')
plt.xlabel('Time (s)')
plt.ylabel('Amplitude')


# Plot the Fourier Transform
plt.subplot(2, 1, 2)
plt.plot(frequencies, fourier_amplitude)
plt.title('Frequency Domain (Numerical Fourier Transform)')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Amplitude')

plt.tight_layout()
plt.show()

# Phase plot
plt.subplot(3, 1, 3)
plt.plot(frequencies, fourier_phase)
plt.title('Phase Spectrum')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Phase (radians)')

plt.tight_layout()
plt.show()







