import numpy as np
import matplotlib.pyplot as plt

x=[1,2,3,4,5,6,7,8]
y=[1,1,1]
k=[]
b=[]
xlen=len(x)
ylen=len(y)
net=round(xlen/ylen,0)
rem=xlen%ylen
if  rem != 0:
    for  i in range (0,ylen-rem):
        x.append(0)
xlen=len(x)
net1=int(xlen/ylen)
print(net1)
z=0
for i in range(0,net1):
    k.append(tuple(x[z:(z+ylen)]))
    z=z+ylen
for i in range(0,len(k)):
    a=list(k[i])
    b.append(tuple(np.convolve(a,y)))
print(b)
m=1
for i in range(0,len(b)-1):
    l=0
    for a in range((m*ylen)-1,len(b[0])):
        b[0]=list(b[0])
        b[i+1]=list(b[i+1])
        b[0][a]=b[0][a]+b[i+1][l]
        l+=1
    if i==0:
        for o in range(-(len(b[0])-ylen),0):
            b[0].append(b[i+1][o])
    else:
        for o in range(-(len(b[i])-1),0):
            b[0].append(b[i+1][o])
    m+=1

print(b[0])
ny=np.arange(0,len(b[0]),1)

plt.stem(ny,b[0])

plt.show()
