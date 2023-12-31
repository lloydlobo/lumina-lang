#ifndef C8AE9E64_B750_47C2_8590_583FEDEFEBC5
#define C8AE9E64_B750_47C2_8590_583FEDEFEBC5

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define sizeof_field(t, f) (sizeof(((t *)0)->f))

// #define ERR_DBG(msg) fprintf(stderr, "--%d-- %s ", __LINE__, msg);
// #define ERR_DBG_LN(msg) fprintf(stderr, "--%d-- %s\n", __LINE__, msg);

// —————————————————————————————————————————————————————————————————————————————————————
//  types
//
//  [Source](https://github.com/rsms/compis/blob/4823a04f9466e4a1ab903a3a718ec95af7038fe9/src/colib.h#L9)

// clang-format off
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

// maybe include err.h here? or move it here? to avoid circular definition

typedef int8_t             i8;
typedef uint8_t            u8;
typedef int16_t            i16;
typedef uint16_t           u16;
typedef int32_t            i32;
typedef uint32_t           u32;
typedef signed long long   i64;
typedef unsigned long long u64;
typedef size_t             usize;
typedef ssize_t            isize;
typedef intptr_t           intptr;
typedef uintptr_t          uintptr;
typedef float              f32;
typedef double             f64;
// clang-format on

// —————————————————————————————————————————————————————————————————————————————————————
//  error codes
//
// [Source](https://github.com/rsms/compis/blob/4823a04f9466e4a1ab903a3a718ec95af7038fe9/src/colib.h#L695)

typedef int err_t;
enum err_ { // clang-format off
  ErrOk           =   0, // no error
  ErrInvalid      =  -1, // invalid data or argument
  ErrSysOp        =  -2, // invalid syscall op or syscall op data
  ErrBadfd        =  -3, // invalid file descriptor
  ErrBadName      =  -4, // invalid or misformed name
  ErrNotFound     =  -5, // resource not found
  ErrNameTooLong  =  -6, // name too long
  ErrCanceled     =  -7, // operation canceled
  ErrNotSupported =  -8, // not supported
  ErrExists       =  -9, // already exists
  ErrEnd          = -10, // end of resource
  ErrAccess       = -11, // permission denied
  ErrNoMem        = -12, // cannot allocate memory
  ErrMFault       = -13, // bad memory address
  ErrOverflow     = -14, // value too large
  ErrReadOnly     = -15, // read-only
  ErrIO           = -16, // I/O error
  ErrNotDir       = -17, // not a directory
  ErrIsDir        = -18, // is a directory
}; // clang-format on

err_t       err_errno(); // current errno value
err_t       err_errnox(int errnoval);
const char *err_str(err_t);

// —————————————————————————————————————————————————————————————————————————————————————
//  string.h
//
// [Source](https://stackoverflow.com/a/46013943)
// The functions strdup and strndup are not yet part of Standard C. They are
// standardized in Posix.1-2008 and declared in <string.h> on Posix systems.

/**
 * Duplicate S, returning an identical malloc'd string.
 */
char *strdup(const char *s) {
        size_t size = strlen(s) + 1;
        char  *ptr = (char *)malloc(size);
        if (ptr != NULL)
                memcpy(ptr, s, size);
        return ptr;
}

/**
 * Duplicate S up to a specified length, returning malloc'd string.
 */
char *strndup(const char *s, size_t n) {
        char  *ptr;
        size_t n1;
        for (n1 = 0; n1 < n && s[n1] != '\0'; n1 += 1)
                continue;
        ptr = (char *)malloc(n + 1);
        if (ptr != NULL) {
                memcpy(ptr, s, n1);
                ptr[n1] = '\0';
        }
        return ptr;
}

#endif /* C8AE9E64_B750_47C2_8590_583FEDEFEBC5 */
