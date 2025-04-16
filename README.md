# Analysis and Design of Algorithms Lab 2025 👽

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue) ![Lab](https://img.shields.io/badge/Course-ADA%20Lab%202025-green) ![License](https://img.shields.io/badge/License-MIT-yellow)

Welcome to the **Analysis and Design of Algorithms (ADA) Lab 2025** repository! This collection contains C++ implementations of various algorithms covered in the ADA lab curriculum. From sorting techniques to dynamic programming and graph algorithms, this repository serves as a comprehensive resource for students and enthusiasts to explore, learn, and experiment with algorithmic concepts. 🚀

## 📖 Table of Contents
- [Overview](#overview)
- [Algorithms Included](#algorithms-included)
- [How to Use](#how-to-use)
- [Directory Structure](#directory-structure)
- [Contributing](#contributing)
- [License](#license)

## 🌟 Overview
This repository is a curated collection of programs developed for the ADA Lab 2025. Each algorithm is implemented in C++ and organized into relevant categories (e.g., Sorting, Graph Algorithms, Dynamic Programming). The code is well-documented, and each category includes a dedicated README for detailed explanations and usage instructions.

Whether you're preparing for exams, exploring algorithmic paradigms, or brushing up on coding skills, this repository provides a hands-on way to understand and apply algorithms. 🎯

## 🛠️ Algorithms Included
Below is the index of algorithms and programs, grouped by category. Click the links to access the source code or category-specific READMEs for more details.

### Sorting Algorithms 🧩
- [Sorting README](./sorting/README.md)
- [Insertion Sort](./sorting/insertionsort.cpp)
- [Selection Sort](./sorting/selectionsort.cpp)
- [Bubble Sort](./sorting/bubblesort.cpp)
- [Merge Sort](./sorting/mergesort.cpp)
- [Quick Sort](./sorting/quicksort.cpp)
- [Iterative Quick Sort](./sorting/iterative_quicksort.cpp)

### Graph Algorithms 🌐
- [Dijkstra's Algorithm](./dijikstra/README.md)
- **Minimum Spanning Tree** ([README](./minimum_spanning_tree/README.md))
  - [Prim's Algorithm](./minimum_spanning_tree/prims.cpp)
  - [Kruskal's Algorithm](./minimum_spanning_tree/kruskal.cpp)
- [Multi-Stage Graph](./dp/multistage_graph.cpp)
- [Floyd-Warshall (All-Pairs Shortest Path)](./dp/floyd_warshall.cpp)

### Dynamic Programming 🧠
- [Dynamic Programming README](./dp/README.md)
- [0-1 Knapsack](./dp/0_1_knapsack.cpp)
- [Travelling Salesman Problem](./dp/travelling_salesman.cpp)
- [Longest Common Subsequence](./dp/longest_common_subsequence.cpp)

### Divide and Conquer ⚔️
- [Max and Min in an Array](./divide_conquer/max_min.cpp)
- [Binary Search](./divide_conquer/binary_search.cpp)
- **Matrix Multiplication** ([README](./matrix/README.md))
  - [Iterative Matrix Multiplication](./matrix/matrix_multiplication_brute_force.cpp)
  - [Divide and Conquer Matrix Multiplication](./matrix/matrix_multiplication.cpp)
  - [Strassen's Method](./matrix/strassen.cpp)

### Greedy Algorithms 💡
- [Activity Selection](./greedy/activity_selection.cpp)

### Backtracking 🔄
- [N-Queens Problem](./nqueens/README.md)

### Miscellaneous 📚
- [Magic Square](./magicsquare/README.md)
- [Peak Element](./peak/README.md)
- [Knapsack Problem](./knapsack/README.md)
- [Horner's Rule](./horner_rule/README.md)
- [Jaccard Similarity](./jaccard_similarity/README.md)
- [Cosine Similarity](./cosine_similiarity/README.md)
- [Plots](./plot/README.md)

## 🚀 How to Use
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/ada-lab-2025.git
   cd ada-lab-2025
   ```
2. **Navigate to a Category**:
   - Each folder (e.g., `sorting`, `dp`) contains a README and source code files.
   - Example: `cd sorting` to explore sorting algorithms.
3. **Compile and Run**:
   - Use a C++ compiler (e.g., `g++`) to compile the desired program:
     ```bash
     g++ filename.cpp -o output
     ./output
     ```
   - Example:
     ```bash
     g++ sorting/insertionsort.cpp -o insertionsort
     ./insertionsort
     ```
4. **Modify Inputs**:
   - Most programs include hardcoded or user-input test cases. Edit the source code to test with custom inputs.
5. **Read Documentation**:
   - Check the category-specific READMEs (e.g., `./sorting/README.md`) for algorithm explanations, time complexity, and example outputs.

## 📂 Directory Structure
```
ada-lab-2025/
├── sorting/
│   ├── README.md
│   ├── insertionsort.cpp
│   ├── selectionsort.cpp
│   └── ...
├── dp/
│   ├── README.md
│   ├── 0_1_knapsack.cpp
│   ├── travelling_salesman.cpp
│   └── ...
├── matrix/
│   ├── README.md
│   ├── matrix_multiplication_brute_force.cpp
│   └── ...
├── dijikstra/
├── greedy/
├── divide_conquer/
├── nqueens/
├── plot/
└── README.md
```

## 🤝 Contributing
Contributions are welcome! If you want to add new algorithms, fix bugs, or improve documentation:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-name`).
5. Open a Pull Request.

Please ensure your code follows the repository's style and includes appropriate documentation.

---

*Happy Learning and Coding! 🚀*
