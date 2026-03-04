# Advanced Number System Converter (C++)

## Overview
A versatile number base conversion utility developed in C++. The system supports conversion between any base from 2 to 36 and handles both integer and fractional components with high precision.

The program uses a universal two-step conversion approach:
Source Base → Decimal → Target Base

This ensures compatibility and accuracy across all supported bases.

## Key Features

### Universal Base Support
- Converts between any base from 2 to 36
- Supports standard bases (Binary, Octal, Decimal, Hexadecimal)

### Fractional Number Handling
- Converts floating-point numbers across bases
- Uses repeated division (integer part)
- Uses repeated multiplication (fractional part)

### Mathematical Conversion Engine

#### toDecimal()
- Converts input string (base n) into decimal
- Uses power-of-base summation method

#### fromDecimal()
- Converts decimal into target base
- Remainder method for integers
- Fractional multiplication method for decimals

### Data Persistence
- Logs conversion history to text files
- Allows users to track previous operations

### Basic Authentication System
- Simple login mechanism
- Personalized session-based interaction

## Technical Concepts Demonstrated

- Number System Theory
- Base Arithmetic
- Floating-Point Handling
- String Manipulation
- File I/O (fstream)
- Algorithm Optimization

## Tech Stack

- C++
- fstream (File Handling)
- Mathematical Algorithms
- Dev C++


## Author
Developed to demonstrate algorithmic thinking, base arithmetic logic, and data persistence techniques in C++.
