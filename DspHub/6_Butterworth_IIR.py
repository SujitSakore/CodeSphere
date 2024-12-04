#IIR butterworth

import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as sc
from math import pi

# IIR Butterworth  Filters
# inputs
Fs = 10000  # sampling rate
fp = 1500  # passbandfreq
fs = 3000  # stopband freq
rp = 0.15  # passband ripple maximum loss
rs = 60  # stopband ripple minimum attenuation
# normalized freq
wp = 2 * fp / Fs
ws = 2 * fs / Fs
# order of filter- n,cutoff freq- wn
[n, wn] = sc.buttord(wp, ws, rp, rs, 's')
# way 1 for b,a
# [z,p,k] = sc.butter(n,wn,btype='high',analog=True,output='zpk')
# [b,a] = sc.zpk2tf(z,p,k)
# or way 2 for b,a
# [b, a] = sc.butter(n, wn, btype='low', analog=True)
# [b,a] = sc.butter(n,wn,btype='high',analog=True)
# [b,a] = sc.butter(n,[wp,ws],btype='pass',analog=True)
[b,a] = sc.butter(n,[wp,ws],btype='stop',analog=True)
#W = np.arange(0,np.pi,.01)
[w, h] = sc.freqs(b, a, worN=1000)
w_h = Fs * w / (2 * pi)  #frequency in hz
h_db = 20 * np.log10(abs(h))  #frequency response in db
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
