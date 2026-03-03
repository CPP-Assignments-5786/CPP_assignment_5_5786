/**
 * @file ComplexArray.hpp
 * @brief Header file for the ComplexArray class
 *
 * A dynamic array of Complex numbers supporting deep copy semantics.
 */

#ifndef COMPLEXARRAY_HPP
#define COMPLEXARRAY_HPP

#include "Complex.hpp"
#include <string>
#include <iostream>

namespace complex_math {

    /**
     * @brief ComplexArray class - dynamic array of Complex numbers
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
         * @brief Resize the internal array when capacity is exceeded
         */
        void resize();

    public:
        // ============ Constructors & Destructor ============

        /**
         * @brief Default constructor
         * Creates empty array with capacity 10
         */
        ComplexArray();

        /**
         * @brief Parameterized constructor
         * @param initialCapacity Initial capacity
         */
        ComplexArray(int initialCapacity);

        /**
         * @brief DEEP COPY CONSTRUCTOR
         * @param other ComplexArray to copy from
         */
        ComplexArray(const ComplexArray& other);

        /**
         * @brief Destructor
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
         * @brief Add element to end of array
         * @param value Complex number to add
         */
        void add(const Complex& value);

        /**
         * @brief Remove element at index
         * @param index Index to remove
         * @return true if successful
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

        // ============ BRACKET OPERATOR [] ============

        /**
         * @brief Access element by index (non-const)
         * @param index Index
         * @return Reference to element
         * @throws std::out_of_range if index invalid
         */
        Complex& operator[](int index);

        /**
         * @brief Access element by index (const version)
         * @param index Index
         * @return Const reference to element
         * @throws std::out_of_range if index invalid
         */
        const Complex& operator[](int index) const;

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

        // ============ COMPOUND ASSIGNMENT OPERATORS ============

        ComplexArray& operator+=(const Complex& value);
        ComplexArray& operator+=(const ComplexArray& other);
        ComplexArray& operator*=(double scalar);

        // ============ ASSIGNMENT OPERATOR (Deep Copy) ============

        /**
         * @brief Assignment operator - performs deep copy
         * Tip: check for self-assignment first!
         * @param other ComplexArray to assign from
         * @return Reference to this
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
        bool operator!=(const ComplexArray& other) const;

        // ============ STREAM OPERATOR ============

        /**
         * @brief Output stream operator
         * Format: [c1, c2, c3, ...]
         * @param os Output stream
         * @param arr Array to output
         * @return Reference to output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const ComplexArray& arr);

        // ============ Utility Method ============

        /**
         * @brief Sort by magnitude (ascending)
         */
        void sort();
    };

} // namespace complex_math

#endif // COMPLEXARRAY_HPP