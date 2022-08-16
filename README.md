# Hybrit Sorting Algorithm

This is an implementation of a hybrid sorting algorithm, which uses Bucket Sort or Quick Sort depending on the distribution of the data, to sort a given set of double precision floating point numbers in the range [0,1]. As the  first step of the algorithm, program is going to determine whether the input set of n floating point numbers is uniformly distributed in the range [0,1]. This range will be divided into n buckets and if the maximum number of floating point numbers that fall in a single bucket is less then or equal to 3. The program is going to use Bucket Sort to sort the whole set of n numbers.  If the number of floating point numbers in at least one bucket exceeds the value of 3, the program is going to use randomized Quick Sort to sort the entire list of n numbers.

# How it is run
Before you run the program, you need to have an **input.txt** file that has the set of double precision floating point numbers in range [0,1]. When program runs, first input should be given manually. That input represents the numbers inside the **input.txt**  
```
> 4
0.234545343454
0.454364132323
0.767567575757 
0.342342423423
```
# Output example
```
0.234545343454 
0.342342423423 
0.454364132323 
0.767567575757
```

This table shows the result I got when I tested the program with 500.000 uniform and non-uniform numbers. 

| |Uniform Test Case  | Non-Uniform Test Case|
| ----: | :---: | :---: |
Quick Sort | 0.947 s | 0.154 s|
Bucket Sort | 0.161 s | 0.168 s|
Hybrit Sort | 0.171 s | 0.158 s|