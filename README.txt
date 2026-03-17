# DSA PROJECT: SORTING ALGORITHMS - GROUP 3
--------------------------------
1. COMPILATION GUIDE
g++ *.cpp -std=c++17 -o Group3.exe

2. AVAILABLE SORTING ALGORITHMS
--------------------------------------------------------------------
List of algorithms:
- selection-sort
- insertion-sort
- binary-insertion-sort
- bubble-sort
- shaker-sort
- shell-sort
- heap-sort
- merge-sort
- quick-sort
- counting-sort
- radix-sort
- flash-sort

3. MAXIMUM INPUT SIZE
--------------------------------------------------------------------
Generated data with specified size, Integer (<= 1,000,000).

4. MODIFIABLE PARAMETERS (OPTIONS)
--------------------------------------------------------------------
The parameters enclosed in brackets [...] can be modified as follows:
* [Algorithm], [Algorithm_1], [Algorithm_2]: Algorithm name (choose from Section 2).
* [Input_file]: Path to user-provided data file (e.g., input.txt).
* [Input_size]: Generated data with specified size, Integer (<= 1,000,000).
* [Input_order]: Generated data with order: -sorted, -nsorted, -rev, -rand.
* [Output_parameter]: -time or -comp or -both.

4. COMMAND PROTOTYPES & DETAILED EXAMPLES
--------------------------------------------------------------------
# GENERAL PROTOTYPES:
* Command 1: .\Group3.exe -a [Algorithm] [Input_file] [Output_parameter]
* Command 2: .\Group3.exe -a [Algorithm] [Input_size] [Input_order] [Output_parameter]
* Command 3: .\Group3.exe -a [Algorithm] [Input_size] [Output_parameter]
* Command 4: .\Group3.exe [Algorithm_1] [Algorithm_2] [Input_file]
* Command 5: .\Group3.exe [Algorithm_1] [Algorithm_2] [Input_size] [Input_order]
------------------------------------------------------------------
### 1. Selection Sort. Example commands:
* Command 1: .\Group3.exe -a selection-sort input.txt -both
* Command 2: .\Group3.exe -a selection-sort 50000 -rand -time
* Command 3: .\Group3.exe -a selection-sort 70000 -comp
* Command 4: .\Group3.exe -c selection-sort merge-sort input.txt
* Command 5: .\Group3.exe -c selection-sort quick-sort 100000 -nsorted
------------------------------------------------------------------
### 2. Insertion Sort. Example commands:
* Command 1: .\Group3.exe -a insertion-sort input.txt -both
* Command 2: .\Group3.exe -a insertion-sort 50000 -sorted -time
* Command 3: .\Group3.exe -a insertion-sort 70000 -comp
* Command 4: .\Group3.exe -c insertion-sort merge-sort input.txt
* Command 5: .\Group3.exe -c insertion-sort quick-sort 100000 -rev
------------------------------------------------------------------
### 3. Binary Insertion Sort. Example commands:
* Command 1: .\Group3.exe -a binary-insertion-sort input.txt -both
* Command 2: .\Group3.exe -a binary-insertion-sort 50000 -rev -time
* Command 3: .\Group3.exe -a binary-insertion-sort 70000 -comp
* Command 4: .\Group3.exe -c binary-insertion-sort merge-sort input.txt
* Command 5: .\Group3.exe -c binary-insertion-sort quick-sort 100000 -rand
------------------------------------------------------------------
### 4. Bubble Sort. Example commands:
* Command 1: .\Group3.exe -a bubble-sort input.txt -both
* Command 2: .\Group3.exe -a bubble-sort 50000 -nsorted -time
* Command 3: .\Group3.exe -a bubble-sort 70000 -comp
* Command 4: .\Group3.exe -c bubble-sort merge-sort input.txt
* Command 5: .\Group3.exe -c bubble-sort quick-sort 100000 -sorted
------------------------------------------------------------------
### 5. Shaker Sort. Example commands:
* Command 1: .\Group3.exe -a shaker-sort input.txt -both
* Command 2: .\Group3.exe -a shaker-sort 50000 -rand -time
* Command 3: .\Group3.exe -a shaker-sort 70000 -comp
* Command 4: .\Group3.exe -c shaker-sort merge-sort input.txt
* Command 5: .\Group3.exe -c shaker-sort quick-sort 100000 -rev
------------------------------------------------------------------
### 6. Shell Sort. Example commands:
* Command 1: .\Group3.exe -a shell-sort input.txt -both
* Command 2: .\Group3.exe -a shell-sort 50000 -sorted -time
* Command 3: .\Group3.exe -a shell-sort 70000 -comp
* Command 4: .\Group3.exe -c shell-sort merge-sort input.txt
* Command 5: .\Group3.exe -c shell-sort quick-sort 100000 -nsorted
------------------------------------------------------------------
### 7. Heap Sort. Example commands:
* Command 1: .\Group3.exe -a heap-sort input.txt -both
* Command 2: .\Group3.exe -a heap-sort 50000 -rev -time
* Command 3: .\Group3.exe -a heap-sort 70000 -comp
* Command 4: .\Group3.exe -c heap-sort merge-sort input.txt
* Command 5: .\Group3.exe -c heap-sort quick-sort 100000 -rand
------------------------------------------------------------------
### 8. Merge Sort. Example commands:
* Command 1: .\Group3.exe -a merge-sort input.txt -both
* Command 2: .\Group3.exe -a merge-sort 500000 -nsorted -time
* Command 3: .\Group3.exe -a merge-sort 70000 -comp
* Command 4: .\Group3.exe -c merge-sort quick-sort input.txt
* Command 5: .\Group3.exe -c merge-sort heap-sort 500000 -sorted
------------------------------------------------------------------
### 9. Quick Sort. Example commands:
* Command 1: .\Group3.exe -a quick-sort input.txt -both
* Command 2: .\Group3.exe -a quick-sort 500000 -rand -time
* Command 3: .\Group3.exe -a quick-sort 70000 -comp
* Command 4: .\Group3.exe -c quick-sort merge-sort input.txt
* Command 5: .\Group3.exe -c quick-sort heap-sort 500000 -rev
------------------------------------------------------------------
### 10. Counting Sort. Example commands:
* Command 1: .\Group3.exe -a counting-sort input.txt -both
* Command 2: .\Group3.exe -a counting-sort 500000 -sorted -time
* Command 3: .\Group3.exe -a counting-sort 70000 -comp
* Command 4: .\Group3.exe -c counting-sort merge-sort input.txt
* Command 5: .\Group3.exe -c counting-sort radix-sort 500000 -nsorted
------------------------------------------------------------------
### 11. Radix Sort. Example commands:
* Command 1: .\Group3.exe -a radix-sort input.txt -both
* Command 2: .\Group3.exe -a radix-sort 500000 -rev -time
* Command 3: .\Group3.exe -a radix-sort 70000 -comp
* Command 4: .\Group3.exe -c radix-sort merge-sort input.txt
* Command 5: .\Group3.exe -c radix-sort counting-sort 500000 -rand
------------------------------------------------------------------
### 12. Flash Sort
* Command 1: .\Group3.exe -a flash-sort input.txt -both
* Command 2: .\Group3.exe -a flash-sort 500000 -nsorted -time
* Command 3: .\Group3.exe -a flash-sort 70000 -comp
* Command 4: .\Group3.exe -c flash-sort merge-sort input.txt
* Command 5: .\Group3.exe -c flash-sort quick-sort 500000 -rev
------------------------------------------------------------------