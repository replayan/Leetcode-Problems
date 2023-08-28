# Bitwise Operations, MSB, LSB, Truth Tables, and Complements

## Bitwise Operations

Bitwise operations manipulate individual bits of a number, often used for low-level manipulation, optimizations, and hardware interfacing.

### 1. Bitwise AND (`&`)

- `a & b` results in a number where each bit is 1 only if both corresponding bits in `a` and `b` are 1.
- Example: `5 & 3` results in `1` (`0101 & 0011 = 0001`).

### 2. Bitwise OR (`|`)

- `a | b` results in a number where each bit is 1 if either or both corresponding bits in `a` and `b` are 1.
- Example: `5 | 3` results in `7` (`0101 | 0011 = 0111`).

### 3. Bitwise XOR (`^`)

- `a ^ b` results in a number where each bit is 1 if the corresponding bits in `a` and `b` are different.
- Example: `5 ^ 3` results in `6` (`0101 ^ 0011 = 0110`).

### 4. Bitwise NOT (`~`)

- `~a` results in a number where each bit is the complement of the corresponding bit in `a`.
- Example: `~5` results in `-6` (`~0101 = 1010` considering 2's complement).

### 5. Left Shift (`<<`) and Right Shift (`>>`)

- `a << b` shifts the bits of `a` to the left by `b` positions.
- `a >> b` shifts the bits of `a` to the right by `b` positions.

## Most Significant Bit (MSB) and Least Significant Bit (LSB)

- MSB: The leftmost bit in a binary representation.
- LSB: The rightmost bit in a binary representation.

## Truth Tables

### 1. AND Truth Table

| A | B | A & B |
|---|---|-------|
| 0 | 0 |   0   |
| 0 | 1 |   0   |
| 1 | 0 |   0   |
| 1 | 1 |   1   |

### 2. OR Truth Table

| A | B | A \| B |
|---|---|-------|
| 0 | 0 |   0   |
| 0 | 1 |   1   |
| 1 | 0 |   1   |
| 1 | 1 |   1   |

### 3. XOR Truth Table

| A | B | A ^ B |
|---|---|-------|
| 0 | 0 |   0   |
| 0 | 1 |   1   |
| 1 | 0 |   1   |
| 1 | 1 |   0   |

## 1's Complement

- The 1's complement of a binary number is obtained by flipping all its bits.
- Example: 1's complement of `1010` is `0101`.

## 2's Complement

- The 2's complement of a binary number is obtained by adding 1 to its 1's complement.
- It's used to represent negative numbers in binary.
- Example: 2's complement of `1010` is `0101` + `0001` = `0110`.

---
