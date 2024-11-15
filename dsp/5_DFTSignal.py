#DFT

import numpy as np
import math
import matplotlib.pyplot as plt

x = list(map(int , input("Enter the sequence x[n] : ").split()))
N = len(x)
li = []
for i in range(N):
    li.append([])
    for j in range(N):
        val = complex(math.cos((2*math.pi*j*i)/N),-math.sin((2*math.pi*j*i)/N))
        li[i].append(val)

ans = []
for i in range(N):
    sum = 0
    for j in range(N):
        sum += li[i][j]*x[j]
    ans.append(sum)
ans = np.array(ans)
plt.subplot(2,1,1)
#plt.xticks(range(N))
#plt.yticks((abs(ans)))
plt.xlabel("   Freq(Hz)   ")
plt.ylabel("  Magnitude -->  ")
plt.stem(range(N),abs(ans))
plt.subplot(2,1,2)
#plt.xticks(range(N))
#plt.yticks(np.angle(ans,deg = True))
plt.xlabel("   Freq(Hz)    ")
plt.ylabel("  phase-->  ")
plt.stem(range(N),np.angle(ans,deg=True))
plt.savefig('DFT.png')
plt.show()