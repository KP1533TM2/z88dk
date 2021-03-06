
// automatically generated by m4 from headers in proto subdir


#ifndef __ADT_W_ARRAY_H__
#define __ADT_W_ARRAY_H__

#include <stddef.h>

// DATA STRUCTURES

typedef struct w_array_s
{

   void       *data;
   size_t      size;
   size_t      capacity;

} w_array_t;

extern size_t __LIB__ w_array_append(w_array_t *a,void *item) __smallc;
extern size_t __LIB__ w_array_append_callee(w_array_t *a,void *item) __smallc __z88dk_callee;
#define w_array_append(a,b) w_array_append_callee(a,b)


extern size_t __LIB__ w_array_append_n(w_array_t *a,size_t n,void *item) __smallc;
extern size_t __LIB__ w_array_append_n_callee(w_array_t *a,size_t n,void *item) __smallc __z88dk_callee;
#define w_array_append_n(a,b,c) w_array_append_n_callee(a,b,c)


extern void __LIB__ *w_array_at(w_array_t *a,size_t idx) __smallc;
extern void __LIB__ *w_array_at_callee(w_array_t *a,size_t idx) __smallc __z88dk_callee;
#define w_array_at(a,b) w_array_at_callee(a,b)


extern void __LIB__ *w_array_back(w_array_t *a) __smallc __z88dk_fastcall;


extern size_t __LIB__ w_array_capacity(w_array_t *a) __smallc __z88dk_fastcall;


extern void __LIB__ w_array_clear(w_array_t *a) __smallc __z88dk_fastcall;


extern void __LIB__ *w_array_data(w_array_t *a) __smallc __z88dk_fastcall;


extern void __LIB__ w_array_destroy(w_array_t *a) __smallc __z88dk_fastcall;


extern int __LIB__ w_array_empty(w_array_t *a) __smallc __z88dk_fastcall;


extern size_t __LIB__ w_array_erase(w_array_t *a,size_t idx) __smallc;
extern size_t __LIB__ w_array_erase_callee(w_array_t *a,size_t idx) __smallc __z88dk_callee;
#define w_array_erase(a,b) w_array_erase_callee(a,b)


extern size_t __LIB__ w_array_erase_range(w_array_t *a,size_t idx_first,size_t idx_last) __smallc;
extern size_t __LIB__ w_array_erase_range_callee(w_array_t *a,size_t idx_first,size_t idx_last) __smallc __z88dk_callee;
#define w_array_erase_range(a,b,c) w_array_erase_range_callee(a,b,c)


extern void __LIB__ *w_array_front(w_array_t *a) __smallc __z88dk_fastcall;


extern w_array_t __LIB__ *w_array_init(void *p,void *data,size_t capacity) __smallc;
extern w_array_t __LIB__ *w_array_init_callee(void *p,void *data,size_t capacity) __smallc __z88dk_callee;
#define w_array_init(a,b,c) w_array_init_callee(a,b,c)


extern size_t __LIB__ w_array_insert(w_array_t *a,size_t idx,void *item) __smallc;
extern size_t __LIB__ w_array_insert_callee(w_array_t *a,size_t idx,void *item) __smallc __z88dk_callee;
#define w_array_insert(a,b,c) w_array_insert_callee(a,b,c)


extern size_t __LIB__ w_array_insert_n(w_array_t *a,size_t idx,size_t n,void *item) __smallc;
extern size_t __LIB__ w_array_insert_n_callee(w_array_t *a,size_t idx,size_t n,void *item) __smallc __z88dk_callee;
#define w_array_insert_n(a,b,c,d) w_array_insert_n_callee(a,b,c,d)


extern void __LIB__ *w_array_pop_back(w_array_t *a) __smallc __z88dk_fastcall;


extern size_t __LIB__ w_array_push_back(w_array_t *a,void *item) __smallc;
extern size_t __LIB__ w_array_push_back_callee(w_array_t *a,void *item) __smallc __z88dk_callee;
#define w_array_push_back(a,b) w_array_push_back_callee(a,b)


extern int __LIB__ w_array_resize(w_array_t *a,size_t n) __smallc;
extern int __LIB__ w_array_resize_callee(w_array_t *a,size_t n) __smallc __z88dk_callee;
#define w_array_resize(a,b) w_array_resize_callee(a,b)


extern size_t __LIB__ w_array_size(w_array_t *a) __smallc __z88dk_fastcall;



#endif
