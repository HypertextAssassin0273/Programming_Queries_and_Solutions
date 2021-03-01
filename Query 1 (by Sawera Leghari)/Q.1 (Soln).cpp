#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

#define N 3 //i.e. total empoyee objects
class Employee{
	char Name[21],Job[21];
	int No_of_Days_Worked;
	float Rate_of_Payment,Salary;

public:
	Employee(const char* Name="N.i.l",const char* Job="N.i.l",int NoDW=0,float RoP=0): //i.e. default ctor
		No_of_Days_Worked(NoDW),Rate_of_Payment(RoP),Salary(NoDW*RoP){ 
		strcpy(this->Job,Job);
		strcpy(this->Name,Name);
	}
	void Display(int Employee_No)const{
		cout<<"Employee "<<Employee_No<<":-\n"
			<<"Name: "<<Name<<endl
			<<"Job: "<<Job<<endl
			<<"No of Days Worked: "<<No_of_Days_Worked<<endl
			<<"Rate of Payment: "<<Rate_of_Payment<<endl
			<<"Salary: "<<Salary<<"\n\n";
	}
private: //i.e. no need to show this method in main
	void Enter_Employee_Details(int Employee_No){
		cout<<"Employee "<<Employee_No<<":-\n";
		cout<<"Enter Name: ";
		cin>>Name;
		cout<<"Enter Job: ";
		cin>>Job;
		cout<<"Enter No. of Days Worked: ";
		cin>>No_of_Days_Worked;
		cout<<"Enter Rate of Payment: ";
		cin>>Rate_of_Payment;
		Salary=No_of_Days_Worked*Rate_of_Payment;	
	}
public:
	void Update_Employee_Details(int Employee_No){
		ofstream fout("Employee.dat",ios::in|ios::ate|ios::binary);
		if(!fout){
			cout<<"File not Found!"<<"\n\n";
			return;
		}
		Enter_Employee_Details(Employee_No);
        fout.seekp((Employee_No-1)*sizeof(*this),ios::beg);
		fout.write((char*)this,sizeof(*this));
        fout.close();
	}
	static void Download_data_from_files(Employee *obj_arr){
		ifstream fin("Employee.dat",ios::in|ios::binary);
		if(!fin){
			cout<<"File not Found!"<<"\n\n";
			return;
		}
		for(int i=0;i<N;++i)
			fin.read((char*)&obj_arr[i],sizeof(obj_arr[i]));
        fin.close();
		cout<<"Data Retrieved from files Successfully!"<<endl;
    	system("pause");
	}
};

bool Upload_Data_to_Files(){//i.e. defined here to destroy temporary_object_array
	ofstream fout("Employee.dat",ios::out|ios::binary);
	if(!fout){
		cout<<"Error: No Data file Present!"<<endl;
		return true;
	}
	Employee temp_obj_arr[N]={Employee("Ahmed","Plumber",1000,150),//i.e. ctor's return *this ptr, hence direct assigning objects
					 Employee("Osama","Electrical Engineer",550,600),
					 Employee("Ali","I.T Expert",90,99.9)};
    for(int i=0;i<N;++i)
		fout.write((char*)&temp_obj_arr[i],sizeof(temp_obj_arr[i]));
    fout.close();
    return false;
}

int main(){
	//Note: comment these below two lines to check whether data is correctly stored in data-files or not (after storing once)
	if (Upload_Data_to_Files())
		return 0;

	Employee obj_arr[N];//i.e. object_array
    short choice;
	while(true){
		cout<<"Main-Menu:-\n^^^^^^^^^^^\n"
			  "1) Update Employee Details\n"
			  "2) Retrieve data from files\n"
			  "3) Display all Employees' Details from program's memory\n"
			  "4) Exit\n==> ";
		cin>>choice;
		cin.clear();
		cin.sync();
		system("cls");
		switch(choice){
    		case 1:
    			cout<<"Enter Employee Number (1-"<<N<<"): ";
				cin>>choice;
				obj_arr[choice-1].Update_Employee_Details(choice);//i.e. updates both file-data & object_array
    			break;
    		case 2:
    			Employee::Download_data_from_files(obj_arr);//i.e. writes data from files to object_array
    			break;
    		case 3:
    			for(int i=0;i<N;++i)
					obj_arr[i].Display(i+1);//i.e. display Employees' data saved in object_array
    			break;
			case 4:
    			return 0;
		}
	}
	return 0;
}
