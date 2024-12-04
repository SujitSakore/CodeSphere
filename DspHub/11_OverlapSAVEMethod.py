import numpy as np
import matplotlib.pyplot as plt

def overlap_save_convolution(signal, kernel):
    M = len(kernel)
    L = M - 1  # Block size (M - 1)

    # Calculate the number of blocks needed
    num_blocks = (len(signal) + L) // L

    # Zero pad the signal to the appropriate length
    signal = np.pad(signal, (0, (num_blocks * L - len(signal))), 'constant')

    # Zero pad the kernel to the block size
    kernel = np.pad(kernel, (0, L - M + 1), 'constant')

    # Initialize the output array
    output = np.zeros(len(signal) + len(kernel) - 1)

    for i in range(num_blocks):
        # Extract the current block from the signal
        input_block = signal[i * L: (i + 1) * L]

        # Convolve the block and the kernel
        block_conv = np.convolve(input_block, kernel)

        # Add the result to the appropriate location in the output array
        output[i * L: i * L + len(block_conv)] += block_conv

    # Trim the output to the original signal length
    output = output[:len(signal) - M + 1]

    return output

# Get the size of the signal (n) from the user
n = int(input("Enter the size of x(n): "))

# Get user inputs for the signal values
signal = [float(input(f"Enter x({i}): ")) for i in range(n)]

# Get the size of the kernel from the user
m = int(input("Enter the size of the kernel: "))

# Get user inputs for the kernel values
kernel = [float(input(f"Enter h({i}): ")) for i in range(m)]

# Perform the convolution
result = overlap_save_convolution(signal, kernel)
print(result)

plt.stem(signal)
plt.show()
plt.stem(kernel)
plt.show()
plt.stem(result)
plt.show()