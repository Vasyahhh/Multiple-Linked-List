//G1A021060
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
       char nama[20];
       int jumlah;
       struct data *next;
       struct data *prev;
}*curr, *head, *tail;

int tampil()
{
       int idx = 0;
       puts("==>Daftar Barang<==\n");
       puts("-----+--------+---------");
       puts("| No | Barang | jumlah |");
       puts("-----+--------+---------");
       if(head != NULL)
       {
              curr = head;
              while(curr != NULL)
              {
                     printf("| %d | %s | %d |\n", idx+1, curr->nama, curr->jumlah);
                     curr = curr->next;
                     idx++;
              }
       }
       puts("-----+--------+---------");
       getchar();
       return idx;
}

void tambah(char nama[], int jumlah)
{
       curr = (struct data*)malloc(sizeof(struct data));
       strcpy(curr->nama, nama);
       curr->jumlah = jumlah;

       if(head == NULL)
       {
              head = tail = curr;
       }
       else
       {
              curr->next = head;
              head->prev = curr;
              head = curr;
       }
       tail->next = NULL;
       head->prev = NULL;
}

void hapus()
{
       if(curr == head)
       {
              head = head->next;
              free(curr);
              if(head != NULL)
              {
                     head->prev = NULL;
              }
       }
       else if(curr == tail)
       {
              curr = tail;
              tail = tail->prev;
              free(curr);
              tail->next = NULL;
       }
       else
       {
              struct data *temp;
              temp = head;
              while(temp->next != curr)
              {
                     temp = temp->next;
              }

              curr->next->prev = curr->prev;
              temp->next = curr->next;
              free(curr);
       }
}

int main()
{
       int pilih;

       do
       {
              do
              {
                     system("cls");
                     puts(" ===>Menu<==");
                     puts(" 1. Tampilkan Data");
                     puts(" 2. Tambah Data");
                     puts(" 3. Hapus Data");
                     puts(" 4. Exit");
                     printf("Pilih Menu: ");
                     scanf("%d", &pilih); fflush(stdin);
              }
              while(pilih < 1 || pilih > 4);
             
              system("cls");

              switch(pilih)
              {
              case 1:
                     tampil();
                     break;

              case 2:
                     char nama[20];
                     int jumlah;
                     do
                     {
                           printf(" Input Nama Barang : ");
                           scanf("%[^\n]", nama); fflush(stdin);
                     }
                     while(strlen(nama) < 3 || strlen(nama) > 30);

                     do
                     {
                           printf(" Input Jumlah Barang: ");
                           scanf("%d", &jumlah); fflush(stdin);
                     }
                     while(jumlah < 1 || jumlah > 20);
                     printf("Selesai");
                     tambah(nama, jumlah);
                     getchar();
                     break;

              case 3:
                     int posisi;
                     int semua = tampil();

                     do
                     {
                           printf("Input Data : ", semua);
                           scanf("%d", &posisi); fflush(stdin);
                     }
                     while(posisi < 1 || posisi > semua);

                     curr = head;
                     for(int i = 1 ; i < posisi ; i++)
                     {
                           curr = curr->next;
                     }

                     hapus();
                     printf("Data Dihapus");
                     getchar();
                     break;
              }
       }while(pilih != 4);
       return 0;
}
