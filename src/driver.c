#include "rbtree.h"
// #include "rbtree.c"
// #include <stdio.h>
// #include <stdlib.h>

// static int comp(const void *p1, const void *p2) {
//   const key_t *e1 = (const key_t *)p1;
//   const key_t *e2 = (const key_t *)p2;
//   if (*e1 < *e2) {
//     return -1;
//   } else if (*e1 > *e2) {
//     return 1;
//   } else {
//     return 0;
//   }
// };

// static void insert_arr(rbtree *t, const key_t *arr, const size_t n) {
//   for (size_t i = 0; i < n; i++) {
//     rbtree_insert(t, arr[i]);
//   }
// }

int main(int argc, char *argv[]) {
    // rbtree *p = new_rbtree();
    // p->root = rbtree_insert(p, 50);
    // rbtree_insert(p, 20);
    // rbtree_insert(p, 60);
    // // insert 확인
    // if(p->root->key == 50 && p->root->left->key == 20 && p->root->right->key == 60) {
    //     printf("root key: %d\n", p->root -> key);
    //     printf("left key: %d\n", p->root -> left -> key);
    //     printf("right key: %d\n", p->root -> right -> key);
    // } else {
    //     printf("잘못된 값!\n");
    // }
    // rbtree_insert(p, 55);

    // // insert case 1 확인
    // printf("\ncase1\n");
    // if(p->root->color == 1 && p->root->left->color == 1 && p->root->right->color == 1) {
    //     printf("root color: Black!\n");
    //     printf("left color: Black!\n");
    //     printf("right color: Black!\n");
    // } else {
    //     printf("잘못된 색!\n");
    // }

    // delete_rbtree(p);
    // p = new_rbtree();
    // p->root = rbtree_insert(p, 50);
    // rbtree_insert(p, 20);
    // rbtree_insert(p, 40);

    // // insert case 2, 3 확인
    // printf("\ncase2, 3\n");
    // if(p->root->key == 40 && p->root->left->key == 20 && p->root->right->key == 50) {
    //     printf("root key: %d\n", p->root -> key);
    //     printf("left key: %d\n", p->root -> left -> key);
    //     printf("right key: %d\n", p->root -> right -> key);
    // } else {
    //     printf("잘못된 값!\n");
    // }

    // if(p->root->color == 1 && p->root->left->color == 0 && p->root->right->color == 0) {
    //     printf("root color: Black!\n");
    //     printf("left color: Red!\n");
    //     printf("right color: Red!\n");
    // } else {
    //     printf("잘못된 색!\n");
    // }

    // printf("min: %d\nmax: %d\n", rbtree_min(p)->key, rbtree_max(p)->key);

    // rbtree_insert(p, 2000);
    // rbtree_insert(p, 5);
    // printf("\ninsert 5, 2000\n");
    // printf("min: %d\nmax: %d\n", rbtree_min(p)->key, rbtree_max(p)->key);

    // rbtree_erase(p, p->root->right->right);
    // printf("\nerase 2000\n");
    // printf("min: %d\nmax: %d\n", rbtree_min(p)->key, rbtree_max(p)->key);


    // to array start..


    // rbtree *t1 = new_rbtree();
    // // assert(t1 != NULL);

    // key_t arr1[] = {10, 5, 8, 34, 67, 23, 156, 24, 2, 12, 24, 36, 990, 25};
    // const size_t n1 = sizeof(arr1) / sizeof(arr1[0]);
    // insert_arr(t1, arr1, n1);
    // qsort((void *)arr1, n1, sizeof(key_t), comp);

    // key_t *res1 = calloc(n1, sizeof(key_t));
    // rbtree_to_array(t1, res1, n1);

    // free(res1);
    // delete_rbtree(t1);


    // to array end..


    // printf("%d\n", root -> key);
    // printf("%d\n", root -> left -> key);
    // printf("%d\n", root -> right -> key);
    // printf("%d\n", rbtree_find(p, 10)->key);
}