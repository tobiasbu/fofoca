
#ifndef _FF_MACROS_H_
#define _FF_MACROS_H_

/**
 * Convert macro parameter to literal string.
 * @param X Value to be stringized
 *
 * @code
 * char a = STRINGER(3);
 * @endcode
*/
#define STRINGER(X) __DO_STRINGER(X)
#define __DO_STRINGER(X) #X



/**
 * Join two macro arguments together.
 * @param X First argument
 * @param Y Second argument
 * @return Joined values
*/
#define JOIN(X, Y) __DO_JOIN(X, Y)
#define __DO_JOIN(X, Y) __DO_JOIN2(X, Y)
#define __DO_JOIN2(X, Y) X##Y

/**
 * Compute sum of two values
 * @param X First value
 * @param Y Second value
*/
#define SUM(X, Y) ((X) + (Y))

#endif
