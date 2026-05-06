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
   pasien* new = malloc(sizeof(pasien));

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

void view(Queue* queue, int wait[]){
   int waitAkhir = 0;
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
            waitAkhir += wait[j];
         }
      }
      printf("%d\n", waitAkhir);
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
   
   scanf("%d", &n);
   int wait[n];
   char nomor[n][5];

   Queue* queue = createQueue();

   for (int i = 0; i < n; i++){
      scanf("%s", nomor[i]);
      scanf("%d", &wait[i]);
      enQueue(queue, nomor[i]);
   }
   
   view(queue, wait);

   destroyQueue(queue);
   return 0;
}
