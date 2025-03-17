## H02 - Hashing Homework
### Zach Barrentine
### Description:

The purpose of this homework is to gain a further understanding of hash tables through open addressing and open hashing examples.

## Part A: Conceptual Questions
- A hash table is a data structure that implements an array by mapping keys to values for quick lookup time.
- **Open Hashing** contains a linked list or other data structure. The table size does not limit the number of elements capable of being stored.
- **Closed Hashing** contains elements stored within the hash table itself. The table size does limit the number of elements capable of being stored.

- **Linear Probing** searches for the next available slot sequentially when a collision occurs.
  -  Pros include easy, simple implementation and good cache performance.
  -  Cons include primary clustering conflicts.
- **Double Hashing** uses a second hash function to determine the probe interval.
  -  Pros include clustering elimination and improved unfiorm distribution.
  -  Cons include the complex implementation as a result of requiring two hash functions.
- Open hashing can handle more values than table slots because each slot is capable of containing multiple elements in its linked list.
- Open Hashing has worst case of O(n) for search, insert, and delete operations when all n elements hash to the same slot.
- Closed Hashing has worst case of O(n) for search, insert, and delete operations when probing through a nearly full table.

- The table size strongly affects the distribution of keys. Table size determines collisions, efficiency, and uniformity in distribution.
- Pitfalls of using a poor table size: _(Ex: A table size that is a round number or power of 2)_
  -  Powers of 2 can have problemts because hash functions often produce values where the lower bits have lower randomness
  -  If the hash function produces values that share common factors with the table size, systematic collisions may occur.

## Part B: Simulation and Diagram Exercises
### Exercise 1: Open Hashing (Separate Chaining)
- Given the following set of keys: 5, 22, 17, 18, 35, 101, 16, 0, 8
- Hash table has a size of 10

|  Key  | Hash Calculation | Hash Value |
| :-: | ----------- | ---------------------- |
|  5  | 5 mod 10         | 5 |
|  22  | 22 mod 10         | 2 |
|  17  | 17 mod 10         | 7 |
|  18  | 18 mod 10         | 8 |
|  35  | 35 mod 10         | 5 |
|  101  | 101 mod 10         | 1 |
|  16  | 16 mod 10         | 6 |
|  0  | 0 mod 10         | 0 |
|  8  | 8 mod 10         | 8 |

- Buckets 5 and 8 have collisions, while there are 3 empty buckets (3, 4, 9)

### Exercise 2: Closed Hashing (Open Addressing)
- Given the following set of keys: 5, 22, 17, 18, 35, 101, 16, 0, 8
- Hash table has a size of 10

1. 5: h(5) = 5, place at index 5
2. 22: h(22) = 2, place at index 2
3. 17: h(17) = 7, place at index 7
4. 18: h(18) = 8, place at index 8
5. 35: h(35) = 5, collision at index 5 → probe to index 6
6. 101: h(101) = 1, place at index 1
7. 16: h(16) = 6, collision at index 6 → probe to index 7 → collision at index 7 → probe to index 8 → collision at index 8 → probe to index 9
8. 0: h(0) = 0, place at index 0
9. 8: h(8) = 8, collision at index 8 → probe to index 9 → collision at index 9 → probe to index 0 → collision at index 0 → probe to index 1 → collision at index 1 → probe to index 2 → collision at index 2 → probe to index 3

   - There is primary clustering at positions 5-6 with keys 5 and 35, which resulted in key 17 being pushed to position 9.
   - There is a chain reaction from a collision at position 8 which pushed key 8 down to position 3.

### Exercise 3: Impact of Poor Table Sizes
- Given the following set of keys: 5, 10, 15, 20, 25, 30, 35, 40
- Hash table has a size of 10 and then a size of 11

#### Table Size = 10 Example
Hash values:
- h(5) = 5 mod 10 = 5
- h(10) = 10 mod 10 = 0
- h(15) = 15 mod 10 = 5
- h(20) = 20 mod 10 = 0
- h(25) = 25 mod 10 = 5
- h(30) = 30 mod 10 = 0
- h(35) = 35 mod 10 = 5
- h(40) = 40 mod 10 = 0

#### Table Size = 11 Example
Hash values:
- h(5) = 5 mod 11 = 5
- h(10) = 10 mod 11 = 10
- h(15) = 15 mod 11 = 4
- h(20) = 20 mod 11 = 9
- h(25) = 25 mod 11 = 3
- h(30) = 30 mod 11 = 8
- h(35) = 35 mod 11 = 2
- h(40) = 40 mod 11 = 7

  - With a table size of 10, every key ended up hashing to either 0 or 5.
  - With a table size of 11, each key mapped to a different slot.
  - The table size of 11 offered a more uniform distribution because each key was able to be placed in a unique slot.

### Exercise 4: Quadratic Probing
- Given the following set of keys: 12, 23, 34, 45, 56, 67, 78, 89

