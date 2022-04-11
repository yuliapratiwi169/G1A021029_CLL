// Program C++ untuk menghapus kunci yang diberikan dari Circular Linked List
//Deletion

#include <bits/stdc++.h>
using namespace std;

/* struktur untuk sebuah node */
class Node {
public:
	int data;
	Node* next;
};

/* Berfungsi untuk menyisipkan node di awal
Circular Linked List*/
void push(Node** head_ref, int data)
{
	// Buat simpul baru dan buat kepala sebagai berikutnya//
	Node* ptr1 = new Node();
	ptr1->data = data;
	ptr1->next = *head_ref;

	/* Jika daftar tertaut bukan NULL, atur
    berikutnya dari simpul terakhir*/
	if (*head_ref != NULL)
	{
		// Temukan simpul sebelum menuju dan perbarui di sebelahnya.//
		Node* temp = *head_ref;
		while (temp->next != *head_ref)
			temp = temp->next;
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1; /*For the first node */

	*head_ref = ptr1;
}

/* Berfungsi untuk mencetak node dalam suatu yang diberikan oleh
Circular Linked List */
void printList(Node* head)
{
	Node* temp = head;
	if (head != NULL) {
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}

	cout << endl;
}

/* Berfungsi untuk menghapus simpul yang diberikan dari daftar */
void deleteNode(Node** head, int key)
{
	
	// Jika linked list bernilai kosong
	if (*head == NULL)
		return;
		
	// Jika daftar hanya berisi satu node
	if((*head)->data==key && (*head)->next==*head)
	{
		free(*head);
		*head=NULL;
		return;
	}
	
	Node *last=*head,*d;
	
	//Jika kepala akan dihapus
	if((*head)->data==key)
	{
		
		// Temukan simpul terakhir dari daftar
		while(last->next!=*head)
			last=last->next;
			
		//Arahkan simpul terakhir ke kepala berikutnya, dst.
       // simpul kedua dari daftar
		last->next=(*head)->next;
		free(*head);
		*head=last->next;
	return;
	}
	
	// Entah simpul yang akan dihapus tidak ditemukan
    // atau akhir daftar tidak tercapai
	while(last->next!=*head&&last->next->data!=key)
	{
		last=last->next;
	}
	
	// Jika simpul yang akan dihapus ditemukan
	if(last->next->data==key)
	{
		d=last->next;
		last->next=d->next;
		free(d);
	}
	else
		cout<<"tidak ada kunci yang ditemukan";
	}

/* Menjalankan kode*/
int main()
{
	/* Inisialisasi daftar sebagai kosong */
	Node* head = NULL;

	/* Daftar tertaut yang dibuat akan menjadi 3->4->6->9->11*/
	push(&head, 11);
	push(&head, 9);
	push(&head, 6);
	push(&head, 4);
	push(&head, 3);

	cout << "List Sebelum Dihapus: ";
	printList(head);

	deleteNode(&head, 9);

	cout << "List Setelah Dihapus: ";
	printList(head);

	return 0;
}