#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definisi struct untuk Node linkedlist Nasabah
typedef struct Node {
    int id; // ID Nasabah
    char nama[50]; // Nama Nasabah
    struct Node*next; // Pointer untuk ke Node berikutnya
} Node;

// definisi struct untuk Node double-linkedlist Nasabah kemarin
typedef struct DoubleNode {
    int id;
    char nama[50];
    struct DoubleNode *prev;
    struct DoubleNode *next;
} DoubleNode;

// definisi struct untuk Queue
typedef struct Queue {
    Node*front;
    Node*rear;
} Queue;

// definisi struct untuk Stack
typedef struct Stack {
    Node*top;
} Stack;

// fungsi untuk membuat Node baru
Node* createNode (int id, char* nama) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> id = id;
    strcpy(newNode -> nama, nama);
    newNode -> next = NULL;

    return newNode;
} 

// fungsi initQueue
void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// fungsi enQueue - tambahkan Nasabah
void enQueue(Queue *q, int id, char *nama) {
    Node *newNode = createNode(id, nama);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Nasabah dengan ID %d dan nama %s telah ditambahkan ke antrian.\n", id, nama);
}
// definisi struct untuk Double Linked List yang menyimpan data kemarin
typedef struct DoubleLinkedList {
    DoubleNode* head;
    DoubleNode* tail;
} DoubleLinkedList;
// fungsi untuk membuat DoubleNode baru (Double Linked List)
DoubleNode* createDoubleNode(int id, char* nama) {
    DoubleNode *newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->id = id;
    strcpy(newNode->nama, nama);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// fungsi untuk inisialisasi Double Linked List
void initDoubleLinkedList(DoubleLinkedList *dll) {
    dll->head = NULL;
    dll->tail = NULL;
}

// fungsi deQueue - Nasabah selesai dilayani 

// fungsi printQueue - tampilkan antrian Nasabah

// fungsi initStack

// fungsi push Stack - memasukkan Nasabah yang selesai dilayani ke Stack

// fungsi pop Stack - menghapus data Nasabah yang selesai dilayani dari Stack

// fungsi printStack - menampilkan data Nasabah yang selesai dilayani hari ini

// data statis double-linkedlist untuk menyimpan data Nasabah kemarin.
// fungsi untuk menambah Nasabah ke Double Linked List (kemarin)
void addToDoubleLinkedList(DoubleLinkedList *dll, int id, char *nama) {
    DoubleNode *newNode = createDoubleNode(id, nama);
    if (dll->tail == NULL) {
        dll->head = dll->tail = newNode;
    } else {
        dll->tail->next = newNode;
        newNode->prev = dll->tail;
        dll->tail = newNode;
    }
    printf("Nasabah dengan ID %d dan nama %s telah ditambahkan ke riwayat kemarin.\n", id, nama);
}
//Print double LinkedList
void printDoubleLinkedList(DoubleLinkedList *dll) {
    DoubleNode *current = dll->head;
    if (current == NULL) {
        printf("Tidak ada riwayat pelayanan kemarin.\n");
        return;
    }
    while (current != NULL) {
        printf("ID: %d, Nama: %s\n", current->id, current->nama);
        current = current->next;
    }
}





// fungsi main
int main () {
    Queue q;
    DoubleLinkedList dll;

    
    int choice, id;
    char nama[50];
    // Data statis untuk transaksi kemarin
    initDoubleLinkedList(&dll);
    addToDoubleLinkedList(&dll, 101, "Andi");
    addToDoubleLinkedList(&dll, 102, "Budi");
    addToDoubleLinkedList(&dll, 103, "Charlie");
    addToDoubleLinkedList(&dll, 104, "Dewi");
    addToDoubleLinkedList(&dll, 105, "Eka");


    printf("Selamat Datang di Sistem Administrasi Teller Bank Sejahtera\n");

    do {
        printf("\n===== OPSI MENU ADMINISTRASI =====\n");
        printf("1. Tambahkan Nasabah ke antrian\n");
        printf("2. Layani Nasabah\n");
        printf("3. Tampilkan antrian Nasabah\n");
        printf("4. Tampilkan riwayat pelayanan\n");
        printf("5. Hapus riwayat pelayanan\n");
        printf("6. Keluar\n");
        printf("Silahkan masukkan pilihan Anda: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Masukkan ID Nasabah: ");
                scanf("%d", &id);
                getchar(); // menangkap newline setelah scanf
                printf("Masukkan Nama Nasabah: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0; // menghapus newline di akhir input
                enQueue(&q, id, nama);
            break;

            case 2: // Iqbal
                // dequeue + push stack
            break;

            case 3: // Wildan
                // print queue
            break;

            case 4: // Tsabit
                printf ("Silahkan pilih riwayat transaksi yang ingin ditampilkan:\n");
                printf("1. Hari ini (Stack)\n");
                printf("2. Kemarin (Double Linked List)\n");
                printf("3. Semua (Stack + Double Linked List)\n");
                int riwayatChoice;
                scanf("%d", &riwayatChoice);

                switch (riwayatChoice) {
                    case 1:
                        // printStack(&s);
                        break;
                    case 2:
                        printDoubleLinkedList(&dll);
                        break;
                    case 3:
                        // printAllHistory(&s, &dll);
                        break;
                    default:
                        printf("Pilihan tidak valid!\n");
                }
                break;
            break;

            case 5: // Rama
                // pop stack
            break;

            case 6:
                printf ("Terimakasih telah menggunakan sistem administrasi Teller\n");
            break;

            default:
                printf("Pilihan tidak ada dalam opsi!//INVALID//\n)");
        }
    } while (choice!=6);
    
    
    return 0;
}