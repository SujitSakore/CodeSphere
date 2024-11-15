import numpy as np
import matplotlib.pyplot as plt
import scipy.signal as sc
from math import pi

# IIR Chebyshev Filters

Fs = 7500  # sampling rate
fp = 900  # passbandfreq
fs = 1300  # stopband freq
rp = 0.29  # passband ripple maximum loss
rs = 29   # stopband ripple minimum attenuation

wp = 2*fp/Fs
ws = 2*fs/Fs
# order -n,cutoff freq - wn
[n,wn] = sc.cheb1ord(wp,ws,rp,rs,'s')

# [b,a] = sc.cheby1(n,rp,wn,btype='low',analog='s')
# [b,a] = sc.cheby1(n,rp,wn,btype='high',analog='s')
# [b,a] = sc.cheby1(n,rp,[wp,ws],btype='pass',analog='s')
[b,a] = sc.cheby1(n,rp,[wp,ws],btype='stop',analog='s')

W = np.arange(0,np.pi,.01)
[w,h] = sc.freqs(b,a,W) # instead of W we can write worN = 1024 or any Integer - window size
w_h = Fs*w/(2*pi)
h_db = 20*np.log10(abs(h))
an = np.angle(h)
plt.figure(1)
plt.xlabel('Frequency(Hz)')
plt.ylabel('Magnitude(dB) or Gain in dB')
plt.grid('on')
plt.plot(w/pi,h_db)

plt.show()
plt.figure(2)
plt.xlabel('Normalized Frequency')
plt.ylabel('Phase in radians')
plt.grid('on')
plt.plot(w/pi,an)
plt.show()

