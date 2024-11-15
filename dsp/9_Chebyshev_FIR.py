import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as sc
from math import pi, remainder

Fs = 9000  # sampling rate
fp = 1500  # passbandfreq
fs = 2000  # stopband freq
rp = 0.2  # passband ripple maximum loss
rs = 0.1  # stopband ripple minimum
N =31

wp = 2 * fp / Fs
ws = 2 * fs / Fs
c = 2 * 125 / Fs
# bandstopfilter
# b = sc.firwin(N, wp, pass_zero='highpass')
b = sc.firwin(N, [wp,ws], pass_zero='bandstop')
# b = sc.firwin(N,wr,pass_zero='bandpass')

[w, h] = sc.freqz(b, worN=2000)
w_h = Fs * w / (2 * pi)
h_db = 20 * np.log10(abs(h))
an = np.angle(h)
plt.figure(1)
plt.xlabel('Frequency(Hz)')
plt.ylabel('Magnitude(dB) or Gain in dB')
plt.grid('on')
plt.plot(w / pi, h_db)

plt.show()
plt.figure(2)
plt.xlabel('Normalized Frequency')
plt.ylabel('Phase in radians')
plt.grid('on')
plt.plot(w / pi, an)
plt.show()

