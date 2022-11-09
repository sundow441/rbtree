#include "rbtree.h"

#include <stdlib.h>
#include <stdio.h>

rbtree *new_rbtree(void) {
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  // TODO: initialize struct if needed
  node_t* nil_node = (node_t *)calloc(1, sizeof(node_t));

  nil_node->color = RBTREE_BLACK;
  p->nil = nil_node;
  p->root = p->nil;

  return p;
}

void free_node(rbtree *t, node_t *x) {
  if(x->left != t->nil) free_node(t, x->left);
  if(x->right != t->nil) free_node(t, x->right);
  free(x);
  x = NULL;
}

void delete_rbtree(rbtree *t) {
  // TODO: reclaim the tree nodes's memory
  if(t->root != t->nil) free_node(t, t->root);
  free(t->nil);
  free(t);
  t = NULL;
}

void left_rotation(rbtree *t, node_t *x) {
  //RBTree fix를 위한 회전 함수
  node_t *y = x->right;
  x->right = y->left;

  if(y->left != t->nil) y->left->parent = x;
  y->parent = x->parent;

  if(x->parent == t->nil) t->root = y;
  else if(x->parent->left == x) x->parent->left = y;
  else x->parent->right = y;

  y->left = x;
  x->parent = y;
}

void right_rotation(rbtree *t, node_t *x) {
  //RBTree fix를 위한 회전 함수
  node_t *y = x->left;
  x->left = y->right;

  if(y->right != t->nil) y->right->parent = x;
  y->parent = x->parent;

  if(x->parent == t->nil) t->root = y;
  else if(x->parent->right == x) x->parent->right = y;
  else x->parent->left = y;

  y->right = x;
  x->parent = y;
}

void rbtree_insert_fixup(rbtree *t,node_t *z) {
  // TODO:
  node_t *y;
  while (z->parent->color == RBTREE_RED)
  {
    if(z->parent == z->parent->parent->left){
      y = z->parent->parent->right;
      // insert case 1
      if (y->color == RBTREE_RED)
      {
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      } else{
        // insert case 2
        if (z == z->parent->right)
        {
          z = z->parent;
          left_rotation(t, z);
        }
        // insert case 3
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        right_rotation(t, z->parent->parent);
      }
    } else{
      y = z->parent->parent->left;
      // insert case 4
      if (y->color == RBTREE_RED)
      {
        z->parent->color = RBTREE_BLACK;
        y->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
      } else{
        // insert case 5
        if (z == z->parent->left)
        {
          z = z->parent;
          right_rotation(t, z);
        }
        // insert case 6
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        left_rotation(t, z->parent->parent);
      }
    }
  }
  t->root->color = RBTREE_BLACK;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {
  // TODO: implement insert
  node_t *y = t->nil;
  node_t *x = t->root;
  node_t *z = (node_t *)calloc(1, sizeof(node_t));
  
  z->key = key;

  while(x != t->nil){
    y = x;
    if(z->key < x->key)
    {
      x = x->left;
    } else{
      x= x->right;
    }
  }

  z->parent = y;

  if(y == t->nil) t->root = z;
  else if(z->key < y->key) y->left = z;
  else y->right = z;

  z->left = t->nil;
  z->right = t->nil;
  z->color = RBTREE_RED;

  rbtree_insert_fixup(t, z);
  
  return z;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {
  // TODO: implement find
  node_t* current = t->root;
  while(current != t->nil) {
    if(current->key == key) return current;
    else if(current->key < key) current = current->right;
    else current = current->left;
  }
  return NULL;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  node_t* current = t->root;
  while(current->left != t->nil) {
    current = current->left;
  }
  return current;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  node_t* current = t->root;
  while(current->right != t->nil) {
    current = current->right;
  }
  return current;
}

void transplant(rbtree *t, node_t *u, node_t *v) {
  if(u->parent == t->nil) t->root = v;
  else if(u == u->parent->left) u->parent->left = v;
  else u->parent->right = v;
  v->parent = u->parent;
}

void rbtree_delete_fixup(rbtree *t,node_t *z) {
  while (z != t->root && z->color == RBTREE_BLACK)
  {
    if (z == z->parent->left)
    {
      node_t *w = z->parent->right;
      // delete case 1
      if (w->color == RBTREE_RED)
      {
        w->color = RBTREE_BLACK;
        z->parent->color = RBTREE_RED;
        left_rotation(t, z->parent);
        w = z->parent->right;
      }
      // delete case 2
      if (w->left->color == RBTREE_BLACK && w->right->color == RBTREE_BLACK)
      {
        w->color = RBTREE_RED;
        z = z->parent;
      }
      else
      {
        // delete case 3
        if (w->right->color == RBTREE_BLACK)
        {
          w->left->color = RBTREE_BLACK;
          w->color = RBTREE_RED;
          right_rotation(t, w);
          w = z->parent->right;
        }
        // delete case 4
        w->color = z->parent->color;
        z->parent->color = RBTREE_BLACK;
        w->right->color = RBTREE_BLACK;
        left_rotation(t, z->parent);
        z = t->root;
      }
    }
    // 좌우 대칭
    else
    {
      node_t *w = z->parent->left;
      // delete case 5
      if (w->color == RBTREE_RED)
      {
        w->color = RBTREE_BLACK;
        z->parent->color = RBTREE_RED;
        right_rotation(t, z->parent);
        w = z->parent->left;
      }
      // delete case 6
      if (w->right->color == RBTREE_BLACK && w->left->color == RBTREE_BLACK)
      {
        w->color = RBTREE_RED;
        z = z->parent;
      }
      else
      {
        // delete case 7
        if (w->left->color == RBTREE_BLACK)
        {
          w->right->color = RBTREE_BLACK;
          w->color = RBTREE_RED;
          left_rotation(t, w);
          w = z->parent->left;
        }
        // delete case 8
        w->color = z->parent->color;
        z->parent->color = RBTREE_BLACK;
        w->left->color = RBTREE_BLACK;
        right_rotation(t, z->parent);
        z = t->root;
      }
    }
  }
  z->color = RBTREE_BLACK;
}

int rbtree_erase(rbtree *t, node_t *p) {
  // TODO: implement erase
  node_t *y;
  node_t *x;
  color_t y_original_color;

  y = p;
  y_original_color = y->color;

  if(p->left == t->nil)
  {
    x = p->right;
    transplant(t, p, p->right);
  }
  else if(p->right == t->nil)
  {
    x = p->left;
    transplant(t, p, p->left);
  } 
  else
  {
    y = p->right;
    while(y->left != t->nil)
    {
      y = y->left;
    }
    y_original_color = y->color;
    x = y->right;
    if(y->parent == p)
    {
      x->parent = y;
    }
    else 
    {
      transplant(t, y, y->right);
      y->right = p->right;
      y->right->parent = y;
    }
    transplant(t, p, y);
    y->left = p->left;
    y->left->parent = y;
    y->color = p->color;
  }
  if(y_original_color == RBTREE_BLACK)
  {
    rbtree_delete_fixup(t, x);
  }
  free(p);
  return 0;
}

int find_node(const rbtree *t, node_t *x, key_t *arr, const size_t n, int i) {
  if (i < n)
  {
    if(x->left != t->nil) i = find_node(t, x->left, arr, n, i);
    arr[i] = x->key;
    i++;
    if(x->right != t->nil) i = find_node(t, x->right, arr, n, i);

    return i;
  }
  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {
  // TODO: implement to_array
  node_t *a = t->root;
  find_node(t, a, arr, n, 0);
  
  return 0;
}
