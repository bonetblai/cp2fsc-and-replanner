#ifndef PTR_TABLE_H
#define PTR_TABLE_H

#include <vector>
#include <cstddef>

#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wpragmas"

#pragma GCC diagnostic ignored "-Wunused-private-field"
class ptr_table {
    void *_key;
    ptr_table *_left;
    ptr_table *_right;
    ptr_table *_up;
    ptr_table *_prev;
    ptr_table *_next;
    size_t    _count;

  public:
    void* val;

  private:
    ptr_table(void *k, ptr_table *u, ptr_table *p)
      : _key(k), _left(0), _right(0), _up(u), _prev(p), _next(0), _count(1), val(0) {
    }

  public:
    struct key_vec : public std::vector<void*> { };
    struct value_vec : public std::vector<void*> { };

    ptr_table()
      : _key(0), _left(0), _right(0), _up(0), _prev(0), _next(0), _count(0), val(0) {
    }
    ~ptr_table();

    ptr_table* insert(void *k);
    ptr_table* insert_next(void *k);
    ptr_table* insert(void **k, size_t l);
    ptr_table* insert(key_vec &k);
    ptr_table* find(void *k);
    ptr_table* find_next(void *k);
    ptr_table* find(void **k, size_t l);
    ptr_table* find(key_vec &k);
    bool contains(void *k) { return find(k) != 0; }
    bool contains(void **k, size_t l) { return find(k) != 0; }
    bool contains(key_vec &k) { return find(k) != 0; }
    void set(void *k, void *v) { insert(k)->val = v; }
    void set(void **k, size_t l, void *v) { insert(k,l)->val = v; }
    void set(key_vec &k, void *v) { insert(k)->val = v; }
    void* find_val(void **k, size_t l) { ptr_table *a = find(k, l); return a ? a->val : 0; }
    void* find_val(key_vec& k) { ptr_table *a = find(k); return a ? a->val : 0; }

    void*& operator[](void *k) { ptr_table *a = insert(k); return a->val; }
    void*& operator[](key_vec& k) { ptr_table *a = insert(k); return a->val; }

    size_t count_keys();
    void dump_keys(key_vec& vec);
    key_vec* keys();
    size_t count_values();
    void dump_values(value_vec& vec);
    value_vec* values();
};
#pragma GCC diagnostic warning "-Wunused-private-field"

#endif

