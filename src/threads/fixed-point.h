#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

typedef int fixed_t;

/* 14 bits used for the fractional part. */
#define SHIFT 14

/* Some fixed-point arithmetic operations. */
/* Convert an int value to a fixed-point value. */
#define FP_CONST(A) ((fixed_t)(A << SHIFT))
/* Add two fixed-point value. */
#define FP_ADD(A, B) (A + B)
/* Add a fixed-point value A and an int value B. */
#define FP_ADD_INT(A, B) (A + (B << SHIFT))
/* Substract two fixed-point value. */
#define FP_SUB(A, B) (A - B)
/* Substract an int value B from a fixed-point value A. */
#define FP_SUB_INT(A, B) (A - (B << SHIFT))
/* Multiply a fixed-point value A by an int value B. */
#define FP_MULT_INT(A, B) (A * B)
/* Divide a fixed-point value A by an int value B. */
#define FP_DIV_INT(A, B) (A / B)
/* Multiply two fixed-point value. */
#define FP_MULT(A, B) ((fixed_t)(((int64_t) A) * B >> SHIFT))
/* Divide two fixed-point value. */
#define FP_DIV(A, B) ((fixed_t)((((int64_t) A) << SHIFT) / B))
/* Get integer part of a fixed-point value. */
#define FP_INT_PART(A) (A >> SHIFT)
/* Get rounded integer of a fixed-point value. */
#define FP_ROUND(A) (A >= 0 ? ((A + (1 << (SHIFT - 1))) >> SHIFT) \
                                    : ((A - (1 << (SHIFT - 1))) >> SHIFT))

#endif /**< threads/fixed-point.h */