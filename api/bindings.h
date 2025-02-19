/* (c) 2020 Band protocol. Licensed under Apache-2.0 */

/* Generated with cbindgen:0.14.2 */

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

enum Error {
  Error_NoError = 0,
  Error_SpanTooSmallError = 1,
  Error_ValidationError = 2,
  Error_DeserializationError = 3,
  Error_SerializationError = 4,
  Error_InvalidImportsError = 5,
  Error_InvalidExportsError = 6,
  Error_BadMemorySectionError = 7,
  Error_GasCounterInjectionError = 8,
  Error_StackHeightInjectionError = 9,
  Error_InstantiationError = 10,
  Error_RuntimeError = 11,
  Error_OutOfGasError = 12,
  Error_BadEntrySignatureError = 13,
  Error_MemoryOutOfBoundError = 14,
  Error_WrongPeriodActionError = 128,
  Error_TooManyExternalDataError = 129,
  Error_DuplicateExternalIDError = 130,
  Error_BadValidatorIndexError = 131,
  Error_BadExternalIDError = 132,
  Error_UnavailableExternalDataError = 133,
  Error_RepeatSetReturnDataError = 134,
  Error_UnknownError = 255,
};
typedef int32_t Error;

/**
 * A `span` is a lightweight struct used to refer to a section of memory. The memory
 * section is not owned by the span, similar to C++'s std::span. The `span`'s creator is
 * responsible for allocating the space and freeing it afterward.
 *
 * The primary usecase of `span` is to faciliate communication between Go and Rust.
 * One side allocates space and creates a `span` for the counterpart to read or write
 * without needing to worry about memory management.
 */
typedef struct Span {
  uint8_t *ptr;
  uintptr_t len;
  uintptr_t cap;
} Span;

typedef struct env_t {
  uint8_t _private[0];
} env_t;

typedef struct EnvDispatcher {
  Error (*get_calldata)(env_t*, Span *calldata);
  Error (*set_return_data)(env_t*, Span data);
  int64_t (*get_ask_count)(env_t*);
  int64_t (*get_min_count)(env_t*);
  int64_t (*get_prepare_time)(env_t*);
  Error (*get_execute_time)(env_t*, int64_t*);
  Error (*get_ans_count)(env_t*, int64_t*);
  Error (*ask_external_data)(env_t*, int64_t eid, int64_t did, Span data);
  Error (*get_external_data_status)(env_t*, int64_t eid, int64_t vid, int64_t *status);
  Error (*get_external_data)(env_t*, int64_t eid, int64_t vid, Span *data);
} EnvDispatcher;

typedef struct Env {
  env_t *env;
  EnvDispatcher dis;
} Env;

typedef struct RunOutput {
  uint32_t gas_used;
} RunOutput;

// cache
typedef struct cache_t {

} cache_t;

Error do_compile(Span input, Span *output);

Error do_run(cache_t *cache,
             Span code,
             uint32_t gas_limit,
             int64_t span_size,
             bool is_prepare,
             Env env,
             RunOutput *output);

cache_t *init_cache(uint32_t size);

void release_cache(cache_t *cache);
