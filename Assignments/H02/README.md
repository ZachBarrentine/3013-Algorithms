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

### Exercise 2: Closed Hashing (Open Addressing)
- Given the following set of keys: 5, 22, 17, 18, 35, 101, 16, 0, 8
- Hash table has a size of 10

### Exercise 3: Impact of Poor Table Sizes
- Given the following set of keys: 5, 10, 15, 20, 25, 30, 35, 40
- Hash table has a size of 10 and then a size of 11


### Exercise 4: Quadratic Probing
- Given the following set of keys: 12, 23, 34, 45, 56, 67, 78, 89

