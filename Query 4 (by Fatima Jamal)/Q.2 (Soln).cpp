#include "List.hpp"

int main(){
	List<int> list;
	short choice=9; int value=0;
	while(true){
		cout<<"\nSELECT YOUR CHOICE:-"
			<<"\n1. Insert value (at front)"
			<<"\n2. Insert value (at back)"
			<<"\n3. Update Value (at front)"
			<<"\n4. Update Value (at back)"
			<<"\n5. Delete value (at front)"
			<<"\n6. Delete value (at back)"
			<<"\n7. View List (ascending/FIFO order)"
			<<"\n8. View List (descending/LILO order)"
			<<"\n9. Exit\n==> ";
		cin>>choice;
		fflush(stdin);
		cin.clear();
		system("cls");
		try{
			switch (choice){
				case 1:
					cout<<"Enter value: ";
					cin>>value;
					list.push_front(value);//i.e. enqueue-front
					break;
				case 2:
					cout<<"Enter value: ";
					cin>>value;
					list.push_back(value);//i.e. enqueue-back
					break;
				case 3:
					cout<<"Enter value: ";
					cin>>list.front();
					break;
				case 4:
					cout<<"Enter value: ";
					cin>>list.back();
					break;
				case 5:
					list.pop_front();//i.e. dequeue-front
					break;
				case 6:
					list.pop_back();//i.e. dequeue-back
					break;
				case 7:
					cout<<"List: ";
					list.traverse_forward();
					break;
				case 8:
					cout<<"List: ";
					list.traverse_backward();
					break;
				case 9:
					return 0;
			}
		}
		catch(bool){}
	}
}
