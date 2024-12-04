import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import firwin, freqz

# Filter specifications
fs = 10000.0  # Sampling frequency
fp = 1500     # Passband frequency
fs_cutoff = 3000  # Stopband frequency
numtaps = 101    # Number of taps in the filter

# Calculating the normalized cutoff frequency
cutoff = (fp + fs_cutoff) / 2
normalized_cutoff = cutoff / (fs / 2)

# Designing FIR filter using Hamming window to approximate Butterworth-like response
fir_coeffs = firwin(numtaps, normalized_cutoff, window='hamming')

# Frequency response
w, h = freqz(fir_coeffs, worN=8000, fs=fs)
magnitude_response = 20 * np.log10(np.abs(h))
phase_response = np.angle(h)

# Plotting magnitude response
plt.figure(1)
plt.plot(w, magnitude_response)
plt.title('Magnitude Response of the FIR Low Pass Filter')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Magnitude (dB)')
plt.grid(True)
plt.show()

# Plotting phase response
plt.figure(2)
plt.plot(w, phase_response)
plt.title('Phase Response of the FIR Low Pass Filter')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Phase (radians)')
plt.grid(True)
plt.show()