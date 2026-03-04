import pandas as pd
import matplotlib.pyplot as plt

try:
    data = pd.read_csv('output.csv')
    
    plt.figure(figsize=(10, 5))
    plt.plot(data['Time'], data['Noisy'], label='Noisy Signal (Input)', alpha=0.5, color='orange')
    plt.plot(data['Time'], data['Filtered'], label='Filtered Signal (Output)', linewidth=2, color='blue')
    
    plt.title('C-Implemented Moving Average Filter')
    plt.xlabel('Time (s)')
    plt.ylabel('Amplitude')
    plt.legend()
    plt.grid(True)
    plt.show()
except FileNotFoundError:
    print("Error: output.csv not found. Run C program first!")
