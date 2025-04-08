import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV data
df = pd.read_csv('output/iterative_quicksort.csv')

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(df['size'], df['time'], marker='o', color='dodgerblue', label='Iterative QuickSort Time')
plt.title("QuickSort Time Complexity Analysis")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (nanoseconds)")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("csv/iterative_quicksort.png")
plt.show()
plt.xscale('log')
plt.yscale('log')
