import numpy as np
import matplotlib.pyplot as plt
def circular_convolution(x, h):
    # Lengths of the input arrays
    len_x = len(x)
    len_h = len(h)
    
    # Ensure both sequences have the same length by zero-padding the shorter one
    if len_x != len_h:
        if len_x < len_h:
            x = x + [0] * (len_h - len_x)
        else:
            h = h + [0] * (len_x - len_h)
    
    # Initialize the output array with zeros
    len_y = len(x)  # After padding, len(x) == len(h)
    y = [0] * len_y
    
    # Perform the circular convolution operation
    for i in range(len_y):
        for j in range(len_y):
            y[i] += x[j] * h[(i - j) % len_y]
    
    return y

# Take user input for sequences x and h
x = list(map(float, input("Enter the first sequence (space-separated values): ").split()))
h = list(map(float, input("Enter the second sequence (space-separated values): ").split()))

# Compute the circular convolution
y = circular_convolution(x, h)

# Display the result
print("Circular Convolution result:",y)

plt.stem(range(len(y)), y)
plt.title('Convolution Result y[n] = x[n] * h[n]')
plt.xlabel('n')
plt.ylabel('Amplitude')
plt.show() 