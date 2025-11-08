
/*
 * Minimal portable implementation of memset for use in FreeRTOS port.
 *
 * Notes:
 * - Provided with a weak symbol so that if the C library supplies a
 *   more optimized version it will be used instead.
 * - This implementation is intentionally simple and conservative to
 *   avoid depending on other libraries or platform-specific intrinsics.
 */

// #include <stddef.h>

// void * __attribute__((weak)) memset(void *s, int c, size_t n)
// {
// 	unsigned char *p = (unsigned char *)s;

// 	while (n--) {
// 		*p++ = (unsigned char)c;
// 	}

// 	return s;
// }

