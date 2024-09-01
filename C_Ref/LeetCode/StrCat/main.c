// You are given a string s and an array of strings words. 
// All the strings of words are of the same length.

// A concatenated string is a string that exactly contains all 
// the strings of any permutation of words concatenated.
// For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef",
//  "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is
//  not a concatenated string because it is not the concatenation of any 
// permutation of words.

// Return an array of the starting indices of all the concatenated substrings
//  in s. You can return the answer in any order.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Hash table will be a fixed lenght of 256 with linked list heads at each 
// index

#define HASH_TABLE_SIZE 256   // Must be 256 or less to fit in 8 bit

typedef struct
{
    char* string;
    int index;
    int tally;
    void* next;
} node_t;

node_t* hash_table[HASH_TABLE_SIZE];
int num_hash_table_entries = 0;
int num_hash_table_unique_tallys = 0;
/*
 *
 * The Java hash, but really no-one seems to know where it came from, see
 * https://bugs.java.com/bugdatabase/view_bug.do?bug_id=4045622
 */
uint8_t h31_hash(const char* s, size_t len)
{
    uint32_t h = 0;
    while (len) {
        h = 31 * h + *s++;
        --len;
    }
    return (uint8_t) h;
}

void hash_table_init()
{
    int i;
    for(i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        hash_table[i] = NULL;
    }
}

// 1 if tally inc-ed, 0 if not
int hash_table_tally(char* chunk, size_t len)
{
    uint8_t h_index = h31_hash(chunk, len);

    // traverse linked list
    node_t* node = hash_table[h_index];
    while(node != NULL)
    {
        if(strcmp(chunk, node->string) == 0 && node->tally == 0)
        {
            node->tally = 1;
            num_hash_table_unique_tallys++;
            printf("[INFO] Tally chunk %s    Total Tallys %d\n", chunk, num_hash_table_unique_tallys);
            return 1;
        }
        node = node->next;
    }

    printf("[INFO] No Tally on chunk %s\n", chunk);
    return 0;  
}


void hash_table_insert(char* s, size_t len, int index)
{
    uint8_t h_index = h31_hash(s, len);

    // If base pointer null alloc it
    node_t* node = hash_table[h_index];
    if(node == NULL)
    {
        hash_table[h_index] = malloc(sizeof(node_t));
        hash_table[h_index]->next= NULL;
        hash_table[h_index]->string = s;
        hash_table[h_index]->index = index;
        hash_table[h_index]->tally = 0;

        num_hash_table_entries++;
        printf("[INFO] Inserted %s at Hash index of %d at LL Head\n", s, h_index);
        return;
    }

    // Get to end of linked list
    while(node->next != NULL)
    {
        node = node->next;
    }

    // Node now points end of list
    node_t* new = malloc(sizeof(node_t));
    new->next= NULL;
    new->string = s;
    new->index = index;
    new->tally = 0;

    node->next = new;
    num_hash_table_entries++;
    printf("[INFO] Inserted %s at Hash index of %d at LL Tail\n", s, h_index);
    return;
}

void hash_table_reset_tally()
{
    int i;
    node_t* node;
    for(i = 0; i < HASH_TABLE_SIZE; ++i)
    { 
        if(hash_table[i] != NULL)
        {
            node = hash_table[i];
            while(node != NULL)
            {
                node->tally = 0;
                node = node->next;
            }
        }
    }

    num_hash_table_unique_tallys = 0;
}

void print_hash_table()
{
    int i;
    node_t* node;
    for(i = 0; i < HASH_TABLE_SIZE; ++i)
    {
        if(hash_table[i] != NULL)
        {
            printf("%d | %s, ", i, hash_table[i]->string);
        }
        else
        {
            continue;
        }

        node = hash_table[i];
        while(node->next != NULL)
        {
            node = node->next;
            printf("%s, ", node->string);
        }
        printf("\n");
    }
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    // Initial Strategy to solve this:
    //  - Go over string s in chunk of size n
    //  - Use hash table to O(1) lookup if chunk is in word list
    //  - If in word list:
    //    - Put a tally in a bit vector
    //    - If tally 1-> 0 then we hit double occurance
    //      - Clear bit vector
    //    - If bit vector all 1's return indicies
    //  - Else:
    //    - Clear bit vector

    // Second Strategy: Keep a window of length num_words, noting left and right index.
    // Tally all chunks in the window. If its a success add left index to ret. Untally 
    // the left index. Move right index one to the right, tally it, if its a hit then
    // continue this. If at anypoint we hit a chunk not in the hash table, we can move 
    // our whole window to one past that point.

    int i;
    int n = strlen(words[0]);
    int num_words = wordsSize;
    int s_len = strlen(s);
    int n_chunks = s_len / n;
    char* chunk = malloc(n+1);

    *returnSize = 0;
    int alloced_size = 64;
    int* ret = malloc(alloced_size * sizeof(int));

    int left_index = 0;
    int right_index = num_words-1;

    if(right_index >= n_chunks)
    {
        return ret;
    }

    if(s_len % n != 0)
    {
        printf("[WARNING] String length not whole multiple of chunk size");
        return ret;
    }

    hash_table_init();

    // Insert the word list into the hash table
    for(i = 0; i < num_words; ++i)
    {
        hash_table_insert(words[i], n, i);
    }

    // Loop our window over all chunks, indexing on chunks not chars in s
    while(right_index < n_chunks)
    {
        for(i = left_index; i <= right_index; ++i)
        {
            strncpy(chunk, s+(i*n), n);
            chunk[n] = 0;
            hash_table_tally(chunk, n);
        }

        if(num_hash_table_unique_tallys == num_words)
        {
            ret[*returnSize] = left_index*n;
            ++(*returnSize);
        }

        hash_table_reset_tally();
        right_index++;
        left_index++;
    }

    free(chunk);
    return ret;
}

int main()
{
    char *s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    char *words[] = {"fooo","barr","wing","ding","wing"};
    int ret;

    int* list = findSubstring(s, words, 5, &ret);

    printf("\n\n");
    int i;
    for(i = 0; i < ret; ++i)
    {
        printf("%d,", list[i]);
    }
}