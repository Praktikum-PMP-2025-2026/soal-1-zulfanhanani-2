/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4 – Dynamic Structures
 *   Hari dan Tanggal    : Rabu, 6 Mei 2026
 *   Nama (NIM)          : Zulfan Hanani (13224105)
 *   Nama File           : soal1rabu.c
 *   Deskripsi           : 
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pasien{
   char nomor[5];
   struct pasien* next;
}pasien;

typedef struct Queue{
   pasien* head;
   pasien* tail;
   int size;
}Queue;

bool isEmpty(Queue* queue){
   return (queue->size == 0);
}

Queue* createQueue(){
   Queue* queue = (Queue*)malloc(sizeof(Queue));
   queue->head = NULL;
   queue->tail = NULL;
   queue->size = 0;
   
   return queue;
}

void enQueue(Queue* queue, char nomor[]){
   pasien* new = malloc(sizeof(queue));

   strcpy(new->nomor, nomor);
   new->next = NULL;

   if (isEmpty(queue)){
      queue->head = new;
      queue->tail = new;
   }else{
      queue->tail->next = new;
      queue->tail = new;
   }
   queue->size++;

}

void view(Queue* queue, int tempWait[]){
   int wait = 0;
   if (isEmpty(queue)){
      printf("ORDER EMPTY\n");
   }else{
      printf("ORDER ");
      pasien* current = queue->head;
      while (current != NULL){
         printf("%s ", current->nomor);
         current = current->next;
      }
      printf("\nWAIT ");
      for (int i = 0; i < queue->size - 1; i++){
         for (int j = 0; j < queue->size - i - 1; j++){
            wait += tempWait[j];
         }
      }
      printf("%d\n", wait);
   }
   
}

void destroyQueue(Queue* queue){
    pasien* current = queue->head;
    while (current != NULL){
        pasien *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int main() {
   int n;
   char nomor[5];

   scanf("%d", &n);
   int tempWait[n];

   Queue* queue = createQueue();

   for (int i = 0; i < n; i++){
      scanf("%s", nomor);
      scanf("%d", &tempWait[i]);
      enQueue(queue, nomor);
   }
   
   view(queue, tempWait);

   destroyQueue(queue);
   return 0;
}
