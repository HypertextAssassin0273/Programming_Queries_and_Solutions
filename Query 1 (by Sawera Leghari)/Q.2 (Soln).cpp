#include<iostream>
using namespace std;

class Pair{
	int value,key;
public:	
	Pair(int value=0,int key=0):value(value),key(key){}
	
	friend ostream& operator<<(ostream &out,Pair const &obj){
		out<<"("<<obj.value<<", "<<obj.key<<")";
		return out;
	}
};

Pair Largest_Value_with_Index(int arr[],int N){
	int max=arr[0],index=0;
	for (int i=1;i<N;++i)
		if (arr[i]>max){
			max=arr[i];
			index=i;
		}
	return Pair(max,index);
}
int Linear_Search(int arr[],int N,int key){
    for (int i=0;i<N;++i)
        if (arr[i]==key)
            return i;
    return -1;
}
int main(){
	#define N 10
	int choice,arr[N];
	bool flag=true;
	while(true){
		cout<<"Main-Menu:-\n^^^^^^^^^^^\n"
			  "1) Fill Array\n"
			  "2) Display All elements in Array\n"
			  "3) Display Largest value in array with Index\n"
			  "4) Find element in Array by Key\n"
			  "5) Exit\n==> ";
		cin>>choice;
		cin.clear();
		cin.sync();
		system("cls");
		switch(choice){
    		case 1:
    			cout<<"Enter all Elements:\n";
    			for(int i=0;i<N;++i)
					cin>>arr[i];
				flag=false;
				cout<<endl;
    			break;
    		case 2:
    			if(flag){
    				cout<<"First fill array elements atleast once!"<<"\n\n";
    				break;
				}
    			cout<<"Array Elements: ";
    			for(int i=0;i<N;++i)
					cout<<arr[i]<<" ";
				cout<<"\n\n";
    			break;
    		case 3:
    			if(flag){
    				cout<<"First fill array elements atleast once!"<<"\n\n";
    				break;
				}
    			cout<<"Largest value in given array along with its index: "<<Largest_Value_with_Index(arr,N)<<"\n\n";
    			break;
    		case 4:
    			if(flag){
    				cout<<"First fill array elements atleast once!"<<"\n\n";
    				break;
				}
    			cout<<"Enter Key to search element in array: ";
    			cin>>choice;
    			choice=Linear_Search(arr,N,choice);
    			if(choice!=-1)
    				cout<<"Element Position: "<<choice+1<<endl;
    			else
    				cout<<"Element not found!"<<endl;
				break;
			case 5:
    			return 0;
		}
	}
	return 0;
}
