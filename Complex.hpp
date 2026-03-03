/**
 * @file Complex.hpp
 * @brief Header file for the Complex class
 *
 * Complex numbers can be represented as:
 * - Rectangular form: a + bi
 * - Magnitude: |z| = √(a² + b²)
 * - String: "a+bi"
 */

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <string>
#include <iostream>
#include <cmath>

namespace complex_math {

    /**
     * @brief Complex class representing a complex number in rectangular form
     * z = a + bi where a is real part, b is imaginary part
     */
    class Complex {
    private:
        double real;      // Real part (a)
        double imag;      // Imaginary part (b)
        
        // Static members
        static int totalComplexCreated;
        static int currentComplexCount;

    public:
        // ============ Constructors & Destructor ============
        
        /**
         * @brief Default constructor - creates 0 + 0i
         */
        Complex();

        /**
         * @brief Parameterized constructor (real only)
         * Creates a + 0i (real number)
         * @param real Real part
         */
        Complex(double real);

        /**
         * @brief Parameterized constructor (real and imaginary)
         * Creates a + bi
         * @param real Real part
         * @param imag Imaginary part
         */
        Complex(double real, double imag);

        /**
         * @brief Copy constructor
         * @param other Complex number to copy from
         */
        Complex(const Complex& other);

        /**
         * @brief Destructor
         */
        ~Complex();

        // ============ Getters & Setters (Inline) ============

        /**
         * @brief Get real part - const method
         * @return Real part
         */
        inline double getReal() const {
            return real;
        }

        /**
         * @brief Get imaginary part - const method
         * @return Imaginary part
         */
        inline double getImag() const {
            return imag;
        }

        /**
         * @brief Set real part
         * @param r New real part
         */
        inline void setReal(double r) {
            this->real = r;
        }

        /**
         * @brief Set imaginary part
         * @param i New imaginary part
         */
        inline void setImag(double i) {
            this->imag = i;
        }

        // ============ Complex Number Properties (Outline) ============

        /**
         * @brief Calculate magnitude (modulus) |z| = √(a² + b²)
         * @return Magnitude
         */
        double magnitude() const;

        /**
         * @brief Get complex conjugate:  if z = a+bi, then z* = a-bi
         * @return Conjugate complex number
         */
        Complex conjugate() const;

        /**
         * @brief Check if complex number is zero
         * @return true if both real and imag are near zero
         */
        bool isZero() const;

        /**
         * @brief Check if complex number is real (imag ≈ 0)
         * @return true if imaginary part is near zero
         */
        bool isReal() const;

        // ============ Static Methods ============

        static int getTotalComplexCreated();
        static int getCurrentComplexCount();

        /**
         * @brief Create complex number from polar form
         * Uses: a = r * cos(θ),  b = r * sin(θ)
         * @param magnitude Magnitude r
         * @param phase Phase θ in radians
         * @return Complex number in rectangular form
         */
        static Complex fromPolar(double magnitude, double phase);

        // ============ CONVERSION OPERATORS (Assignment 5 Focus) ============

        /**
         * @brief Convert to double (returns magnitude)
         * Use explicit cast: double d = (double)c;
         * @return Magnitude of complex number
         */
        explicit operator double() const;

        /**
         * @brief Convert to bool (check if non-zero)
         * Works implicitly in boolean contexts: if (c) { ... }
         * @return true if complex number is not zero
         */
        explicit operator bool() const;

        /**
         * @brief Convert to string in rectangular form "a+bi"
         * Use explicit cast: std::string s = (std::string)c;
         * @return String representation
         */
        explicit operator std::string() const;

        // ============ String Representations ============

        /**
         * @brief Get string in rectangular form "a+bi" or "a-bi"
         * @return String in rectangular form
         */
        std::string toRectangularString() const;

        // ============ ARITHMETIC OPERATORS ============

        /**
         * @brief Addition:  (a+bi) + (c+di) = (a+c) + (b+d)i
         * @param other Complex number to add
         * @return Sum
         */
        Complex operator+(const Complex& other) const;

        /**
         * @brief Add real number
         * @param val Real number to add
         * @return Sum
         */
        Complex operator+(double val) const;

        /**
         * @brief Subtraction: (a+bi) - (c+di) = (a-c) + (b-d)i
         * @param other Complex number to subtract
         * @return Difference
         */
        Complex operator-(const Complex& other) const;

        /**
         * @brief Multiplication:  (a+bi) * (c+di) = (ac-bd) + (ad+bc)i
         * @param other Complex number to multiply
         * @return Product
         */
        Complex operator*(const Complex& other) const;

        /**
         * @brief Multiply by real number
         * @param val Real number to multiply
         * @return Product
         */
        Complex operator*(double val) const;

        /**
         * @brief Division: (a+bi) / (c+di) = [(ac+bd) + (bc-ad)i] / (c²+d²)
         * @param other Complex number to divide by
         * @return Quotient
         * @throws std::invalid_argument if dividing by zero
         */
        Complex operator/(const Complex& other) const;

        /**
         * @brief Unary negation: -(a+bi) = -a-bi
         * @return Negated complex number
         */
        Complex operator-() const;

        // ============ COMPOUND ASSIGNMENT OPERATORS ============

        Complex& operator+=(const Complex& other);
        Complex& operator+=(double val);
        Complex& operator-=(const Complex& other);
        Complex& operator*=(const Complex& other);
        Complex& operator*=(double val);

        // ============ INCREMENT/DECREMENT (Prefix) OPERATORS ============

        /**
         * @brief Prefix increment (++z) - increments real part by 1
         * @return Reference to this (after increment)
         */
        Complex& operator++();

        /**
         * @brief Prefix decrement (--z) - decrements real part by 1
         * @return Reference to this (after decrement)
         */
        Complex& operator--();

        // ============ COMPARISON OPERATORS ============

        /**
         * @brief Equality comparison (compares both real and imag parts)
         * @param other Complex number to compare
         * @return true if equal (within epsilon)
         */
        bool operator==(const Complex& other) const;

        /**
         * @brief Inequality comparison
         * @param other Complex number to compare
         * @return true if not equal
         */
        bool operator!=(const Complex& other) const;

        /**
         * @brief Less than comparison (compares magnitudes)
         * @param other Complex number to compare
         * @return true if |this| < |other|
         */
        bool operator<(const Complex& other) const;

        /**
         * @brief Greater than comparison (compares magnitudes)
         * @param other Complex number to compare
         * @return true if |this| > |other|
         */
        bool operator>(const Complex& other) const;

        // ============ ASSIGNMENT OPERATOR ============

        /**
         * @brief Assignment operator
         * Tip: check for self-assignment first!
         * @param other Complex number to assign from
         * @return Reference to this
         */
        Complex& operator=(const Complex& other);

        // ============ STREAM OPERATOR ============

        /**
         * @brief Output stream operator
         * Format: "a+bi" or "a-bi"
         * @param os Output stream
         * @param c Complex number to output
         * @return Reference to output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Complex& c);

        // ============ NON-MEMBER ARITHMETIC OPERATOR ============

        /**
         * @brief Add real number to complex (reverse order): val + c
         * @param val Real number
         * @param c Complex number
         * @return Sum
         */
        friend Complex operator+(double val, const Complex& c);

        // ============ FRIEND FUNCTION ============

        /**
         * @brief Calculate distance between two complex numbers
         * distance = |c1 - c2| = √((a1-a2)² + (b1-b2)²)
         * @param c1 First complex number
         * @param c2 Second complex number
         * @return Distance
         */
        friend double distance(const Complex& c1, const Complex& c2);
    };

} // namespace complex_math

#endif // COMPLEX_HPP