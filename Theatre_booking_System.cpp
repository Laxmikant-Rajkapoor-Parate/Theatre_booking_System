#include<iostream>
using namespace std;

typedef struct node {
	char row_no;
	int seat_no,pin_no;
	char status;
	struct node *next,*prev;
}node;

class Booking {
	public:
	node *head_node;

	Booking() {
		head_node=NULL;
	}

	void create_node() {
		node *new_node,*current_node;
		int j=1;
		char c ='A';
		do {
			int i=1;
			do {
				new_node=new node();
				new_node->next=new_node->prev=NULL;
				new_node->row_no=c;
				new_node->seat_no=i;
				new_node->status='a';
				if(head_node==NULL) {
					head_node=new_node;
					new_node->next=new_node->prev=head_node;
				}
				else {
					current_node=head_node;
					while(current_node->next!=head_node)
						current_node=current_node->next;
					current_node->next=new_node;
					new_node->prev=current_node;
					new_node->next=head_node;
					head_node->prev=new_node;
				}
				i++;
			} while(i<=7);
			j++;
			c++;
		} while(j<=10);
	}

	void display_status() {
		node *current_node;
		current_node=head_node;
		cout<<"------------------------------------------------------------------\n";
		while(current_node->next!=head_node) {
			if((current_node->prev)->row_no!=current_node->row_no)
				cout<<"| ";
			cout<<current_node->row_no;
			cout<<current_node->seat_no;
			if(current_node->status=='a')
				cout << " :- a  ";
			else
				cout << " :- b  ";
			if((current_node->next)->row_no!=current_node->row_no)
				cout<<"|\n";
			current_node=current_node->next;                                                      //Traversing here
		}
		cout<<current_node->row_no;
		cout<<current_node->seat_no;
		if(current_node->status=='a')
			cout << " :- a  ";
		else
			cout << " :- b  ";
		cout<<"|\n";
		cout<<"------------------------------------------------------------------\n";
		cout<<"a :- available\nb :- booked\n\n";
	}

	void display_confirmation(node *temp[20],int n) {
		if(n!=1) {
			cout<<"------------------------------------------------------------------\n";
			cout<<"               THANK YOU!\n     YOU HAVE SUCCESFULLY BOOKED THE SEATS\n";
			for(int i=1;i<n;i++) {
				cout<<"        "<<temp[i]->row_no<<temp[i]->seat_no<<"\n";
				cout<<"ENTER 4-DIGIT PIN OF YOUR CHOICE : ";
				cin>>temp[i]->pin_no;
			}
			cout<<"                   REMEMBER PIN                  \n";
			cout<<"PINS	WILL BE ASKED WHILE ENTERING HALL AND CANCELATION\n";
			cout<<"------------------------------------------------------------------\n";
		}
	}

	void book_seat() {
		system("color D");
		node *current_node,*temp[20];
		int n,x,flag;
		char row;
		int seat;
		char ch;
		do {
			x=1;
			cout<<"\nEnter No Of Tickets u Want To Buy: ";
			cin>>n;
			cout<<"\nEnter Seat Number(s): \n";
			for(int i=1;i<=n;i++) {
				cout<<"NO "<<i<<" = "; 
				cin>>row>>seat;
				current_node=head_node;
				if(row>='A'&&row<='J') {
					while(current_node->next!=head_node) {
						if(current_node->row_no==row && current_node->seat_no==seat) {
							if(current_node->status=='a') {
								current_node->status='b';
								temp[x]=current_node;
								x++;
							}
							else {
								cout<<"INVALID CHOISE!\n";
								cout<<current_node->row_no<<current_node->seat_no<<" Seat is already reserved \n";
							}
						}
						current_node=current_node->next;                                              //Traversing here
					}
				}
			}
			display_confirmation(temp,x);
			cout<<"\n\nPRESS:-\n1. To check Seat Status\n";
			cout<<"2. To book other seat\n";
			cout<<"3. To Exit BOOKING PORTAL\n";
			cout<<"\ninput: ";
			cin>>ch;
			system("color 3");
			if(ch==1)
				display_status();
		} while(ch=='2');
	}

	void cancel_seat() {
		system("color 2");
		char row,ch;
		int seat,pin_no;
		node *current_node;
		cout<<"\n-------SEAT CANCELATION-------\n";
		do {
			ch='a';
			current_node=head_node;
			cout<<"SEAT NUMBER : ";
			cin>>row>>seat;
			cout<<"PIN : ";
			cin>>pin_no;
			if(row>='A'&&row<='J') {
				while(current_node->next!=head_node) {
					if(current_node->row_no==row && current_node->seat_no==seat && current_node->pin_no==pin_no) {
						cout<<"Are you sure u want to cancel the Seat (y/n) : ";
						char c;
						cin>>c;
						if(c=='y'||c=='Y') {
							cout<<"-------SEAT CANCELED SUCCESFULLY!--------\n";
							current_node->status='a';
						}
					}
					else if(current_node->row_no==row && current_node->seat_no==seat && current_node->pin_no!=pin_no) {
						cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
					}
					current_node=current_node->next;
				}
			}
			
			cout<<"\n\nPRESS:-\n1. To Check Seat Status\n"; 
			cout<<"2. To cancel More Tickets\n";
			cout<<"3. To Exit CANCELATION PORTAL\n";
			cout<<"\nInput: ";
			cin>>ch;
			if(ch==1)
				display_status();
		} while(ch=='2');
	}
};


int main() {
	Booking o;
	int ch;
	char c;
	system("color 6");
	cout<<"\n\n\n";
	cout<<"             WELCOME TO CINEMA HALL BOOKING SYSTEM               \n";
	cout<<"                   ------ARRANGEMENTS------                      \n";
	o.create_node();
	o.display_status();
	do {
		cout<<"\n\n\n";
		cout<<"PRESS:-\n1. BOOK TICKETS\n";
		cout<<"2. CANCEL TICKETS\n";
		cout<<"3. EXIT\n";
		cout<<"\nChoice : ";
		cin>>ch;
		switch(ch) {
			case 1:
				o.book_seat();
				o.display_status();
				break;
			case 2:
				o.cancel_seat();
				o.display_status();
				break;
		}
			if(ch!=3) {
				cout<<"\n\nPRESS:-\n1. Main Menu\n";
				cout<<"2. To Exit the system\n";
				cout<<"\ninput: ";
				cin>>c;
			}
	} while(c=='1');
	cout<<"\n\n\n";
	system("color 80");
	cout<<"            THANKS FOR USING OUR PORTAL\n";
	cout<<"                   HAVE A NICE DAY\n\n\n";
	return 0;
}
