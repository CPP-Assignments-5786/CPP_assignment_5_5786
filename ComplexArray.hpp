/**
 * @file ComplexArray.hpp
 * @brief Header file for the ComplexArray class
 *
 * This file EMPHASIZES:
 * - DEEP COPY CONSTRUCTOR (Assignment 5 focus)
 * - Composition (ComplexArray HAS-A Complex* dynamic array)
 * - Destruct-arrays
 * - All operator overloading
 * 
 * STUDENTS:  You MUST implement proper deep copy in: 
 * - Copy constructor
 * - Assignment operator
 * And proper cleanup in:
 * - Destructor
 */

#ifndef COMPLEXARRAY_HPP
#define COMPLEXARRAY_HPP

#include "Complex.hpp"
#include <string>
#include <iostream>

namespace complex_math {

    /**
     * @brief ComplexArray class - dynamic array of Complex numbers
     * 
     * COMPOSITION: ComplexArray HAS-A Complex* array
     * 
     * CRITICAL FOR STUDENTS: 
     * This class demonstrates why deep copy is essential! 
     * - Shallow copy would copy only the pointer
     * - Deep copy must create NEW array and copy each element
     * - Destructor must delete the array properly
     */
    class ComplexArray {
    private:
        Complex* data;      // COMPOSITION: Dynamic array of Complex objects
        int size;           // Current number of elements
        int capacity;       // Maximum capacity
        
        // Static members
        static int totalArraysCreated;
        static int currentArrayCount;

        /**
         * @brief Resize the internal array
         * STUDENTS: Must create new array, copy elements, delete old array
         */
        void resize();

    public:
        // ============ Constructors & Destructor ============

        /**
         * @brief Default constructor
         * Creates empty array with capacity 10
         * STUDENTS: Allocate array: 
         *   data = new Complex[capacity];
         */
        ComplexArray();

        /**
         * @brief Parameterized constructor
         * @param initialCapacity Initial capacity
         * STUDENTS: Allocate array with given capacity
         */
        ComplexArray(int initialCapacity);

        /**
         * @brief Constructor with initial values
         * @param values Array of complex numbers
         * @param count Number of elements
         * STUDENTS: Allocate array and copy values
         */
        ComplexArray(const Complex* values, int count);

        /**
         * @brief DEEP COPY CONSTRUCTOR (CRITICAL!)
         * @param other ComplexArray to copy from
         * 
         * STUDENTS - THIS IS THE FOCUS OF ASSIGNMENT 5:
         * You MUST perform DEEP COPY: 
         * 1. Allocate NEW array: 
         *    this->data = new Complex[other. capacity];
         * 2. Copy each element individually:
         *    for(int i = 0; i < other.size; i++)
         *        this->data[i] = other.data[i];
         * 3. Copy all member variables
         * 
         * WHY DEEP COPY IS NEEDED:
         * - If you only copy the pointer (shallow copy), both objects
         *   would point to the SAME array
         * - When one object is destroyed, it would delete the array
         * - The other object would have a dangling pointer! 
         * - Modifying one would affect the other
         */
        ComplexArray(const ComplexArray& other);

        /**
         * @brief Destructor
         * STUDENTS: Must delete the dynamic array: 
         *   delete[] data;
         * This prevents memory leaks!
         */
        ~ComplexArray();

        // ============ Getters (Inline) ============

        /**
         * @brief Get size - const method
         * @return Number of elements
         */
        inline int getSize() const {
            return size;
        }

        /**
         * @brief Get capacity - const method
         * @return Maximum capacity
         */
        inline int getCapacity() const {
            return capacity;
        }

        /**
         * @brief Check if empty - const method
         * @return true if no elements
         */
        inline bool isEmpty() const {
            return size == 0;
        }

        // ============ Static Methods ============

        static int getTotalArraysCreated();
        static int getCurrentArrayCount();

        // ============ Array Operations (Outline) ============

        /**
         * @brief Add element to array
         * Demonstrates:  reference parameter, composition
         * @param value Complex number to add
         * STUDENTS: Store in array:
         *   data[size] = value;
         *   size++;
         */
        void add(const Complex& value);

        /**
         * @brief Insert element at index
         * @param index Index to insert at
         * @param value Complex number to insert
         * @return true if successful
         */
        bool insert(int index, const Complex& value);

        /**
         * @brief Remove element at index
         * @param index Index to remove
         * @return true if successful
         * STUDENTS:  Shift remaining elements down
         */
        bool remove(int index);

        /**
         * @brief Clear all elements (doesn't deallocate)
         */
        void clear();

        /**
         * @brief Find first occurrence of value
         * @param value Value to find
         * @return Index if found, -1 otherwise
         */
        int find(const Complex& value) const;

        /**
         * @brief Check if array contains value
         * @param value Value to check
         * @return true if found
         */
        bool contains(const Complex& value) const;

        // ============ Mathematical Operations ============

        /**
         * @brief Calculate sum of all elements
         * @return Sum
         */
        Complex sum() const;

        /**
         * @brief Calculate average (mean) of all elements
         * @return Average
         */
        Complex average() const;

        /**
         * @brief Find element with maximum magnitude
         * @return Complex number with max magnitude
         */
        Complex max() const;

        /**
         * @brief Find element with minimum magnitude
         * @return Complex number with min magnitude
         */
        Complex min() const;

        /**
         * @brief Calculate magnitude of all elements as vector
         * @return Magnitude
         */
        double vectorMagnitude() const;

        // ============ BRACKET OPERATOR [] ============

        /**
         * @brief Access element by index (non-const)
         * Allows:  arr[i] = Complex(3, 4);
         * @param index Index
         * @return Reference to element
         * @throws std::out_of_range if index invalid
         * STUDENTS: Return data[index] with bounds checking
         */
        Complex& operator[](int index);

        /**
         * @brief Access element by index (const version)
         * @param index Index
         * @return Const reference to element
         * @throws std::out_of_range if index invalid
         */
        const Complex& operator[](int index) const;

        // ============ PARENTHESES OPERATOR () ============

        /**
         * @brief Get subarray [start, end)
         * @param start Start index (inclusive)
         * @param end End index (exclusive)
         * @return New ComplexArray with subarray
         */
        ComplexArray operator()(int start, int end) const;

        /**
         * @brief Get first n elements
         * @param n Number of elements
         * @return New ComplexArray with first n elements
         */
        ComplexArray operator()(int n) const;

        // ============ ARITHMETIC OPERATORS ============

        /**
         * @brief Add scalar to all elements
         * @param value Complex number to add
         * @return New array with modified elements
         */
        ComplexArray operator+(const Complex& value) const;

        /**
         * @brief Element-wise addition of two arrays
         * @param other Array to add
         * @return New array with sums
         */
        ComplexArray operator+(const ComplexArray& other) const;

        /**
         * @brief Subtract scalar from all elements
         * @param value Complex number to subtract
         * @return New array with modified elements
         */
        ComplexArray operator-(const Complex& value) const;

        /**
         * @brief Element-wise subtraction
         * @param other Array to subtract
         * @return New array with differences
         */
        ComplexArray operator-(const ComplexArray& other) const;

        /**
         * @brief Multiply all elements by scalar
         * @param value Complex number to multiply
         * @return New array with products
         */
        ComplexArray operator*(const Complex& value) const;

        /**
         * @brief Scalar multiplication
         * @param scalar Real scalar
         * @return New array scaled by scalar
         */
        ComplexArray operator*(double scalar) const;

        /**
         * @brief Divide all elements by scalar
         * @param value Complex number to divide by
         * @return New array with quotients
         */
        ComplexArray operator/(const Complex& value) const;

        // ============ COMPOUND ASSIGNMENT OPERATORS ============

        ComplexArray& operator+=(const Complex& value);
        ComplexArray& operator+=(const ComplexArray& other);
        ComplexArray& operator-=(const Complex& value);
        ComplexArray& operator*=(const Complex& value);
        ComplexArray& operator*=(double scalar);

        // ============ ASSIGNMENT OPERATOR (Deep Copy) ============

        /**
         * @brief Assignment operator - DEEP COPY
         * @param other ComplexArray to assign from
         * @return Reference to this
         * 
         * STUDENTS - CRITICAL: 
         * Must perform deep copy like copy constructor! 
         * Also must: 
         * 1. Check for self-assignment:  if(this == &other) return *this;
         * 2. Delete old array: delete[] data;
         * 3. Allocate new array and copy elements
         */
        ComplexArray& operator=(const ComplexArray& other);

        // ============ COMPARISON OPERATORS ============

        /**
         * @brief Equality comparison (element-wise)
         * @param other Array to compare
         * @return true if all elements equal
         */
        bool operator==(const ComplexArray& other) const;

        /**
         * @brief Inequality comparison
         * @param other Array to compare
         * @return true if any element differs
         */
        bool operator! =(const ComplexArray& other) const;

        // ============ STREAM OPERATORS ============

        /**
         * @brief Output stream operator
         * Format: [c1, c2, c3, ...]
         * @param os Output stream
         * @param arr Array to output
         * @return Reference to output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const ComplexArray& arr);

        /**
         * @brief Input stream operator
         * @param is Input stream
         * @param arr Array to input into
         * @return Reference to input stream
         */
        friend std::istream& operator>>(std::istream& is, ComplexArray& arr);

        // ============ FRIEND FUNCTIONS ============

        /**
         * @brief Calculate dot product of two arrays (as vectors)
         * @param arr1 First array
         * @param arr2 Second array
         * @return Dot product
         */
        friend Complex dotProduct(const ComplexArray& arr1, const ComplexArray& arr2);

        /**
         * @brief Check if arrays have same size
         * @param arr1 First array
         * @param arr2 Second array
         * @return true if same size
         */
        friend bool sameSize(const ComplexArray& arr1, const ComplexArray& arr2);

        // ============ Utility Methods ============

        /**
         * @brief Print array to output stream
         * @param os Output stream (default: std::cout)
         */
        void print(std::ostream& os = std::cout) const;

        /**
         * @brief Reverse the array in-place
         */
        void reverse();

        /**
         * @brief Sort by magnitude (ascending)
         */
        void sort();
    };

} // namespace complex_math

#endif // COMPLEXARRAY_HPP