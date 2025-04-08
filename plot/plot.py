import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV data
df = pd.read_csv('output/2d_array.csv')

# Plotting
plt.figure(figsize=(10,6))
plt.plot(df['size'], df['time'], marker='o', color='dodgerblue', label='2d Array Time')
plt.title("2d Array Time Complexity Analysis")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (nanoseconds)")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.xscale('log')
plt.yscale('log')
plt.savefig("png/2d_array.png")
plt.show()

