import numpy as np
import matplotlib.pyplot as plt
def linear_convolution(x,h):
    len_x=len(x)
    len_h=len(h)
    len_y=len_x+len_h-1
    y = [0] * len_y
    for n in range(len_y):
        y[n]=0
        for k in range(len_x): 
            if(0 <= n-k < len_h): 
                y[n] += x[k] * h[n-k]
    return y
values = input("Enter integer values separated by spaces for list x: ")
# Split the string by spaces and convert each value to an integer
x = list(map(int, values.split()))

value = input("Enter integer values separated by spaces for h: ")
h = list(map(int, value.split()))
result=linear_convolution(x,h)
print(result)

plt.stem(range(len(result)), result)
plt.title('Convolution Result y[n] = x[n] * h[n]')
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.show()