#include<iostream>
#include<string>
using namespace std;

class student{
	private:
		string name;
		int roll;
		float gpa;
	public:
		//get data 
		void setdata(string n,int r,float g){
			name=n;
			roll=r;
			gpa=g;
		}
		//check gpa
		void checkgpa(float g){
			if(gpa>=0.0 && gpa<=4.0){
				gpa=g;
			}
			else{
				gpa=0.0;
				cout<<"Invalid GPA";
			}
		}
		string getname(){
			return name;
		}
		int getroll(){
			return roll;
		}
		float getgpa(){
			return gpa;
		}
		
		
		
		
};


int main(){
	const int MAX_students=100;
	student database[MAX_students];
	int studentcounter=0;
	
	
	int choice;
	while(true){
	    cout << "\n=========================================" << endl;
        cout << "   STUDENT RECORD MANAGEMENT SYSTEM (OOP)  " << endl;
        cout << "=========================================" << endl;
        cout << "1. Add New Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Update Student GPA" << endl;
        cout << "5. Exit" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        
	
	    switch(choice){
	    	case 1:{
				
			
	    		if(studentcounter>=MAX_students){
	    			cout<<"Error: List is full";
	    			break;
				}
				string tempname;
				int temproll;
				float tempgpa;
				cout<<"Enter Name: ";
				cin.ignore();
				getline(cin,tempname);
				cout<<"Enter Roll Number: ";
				cin>>temproll;
				cout<<"Enter GPA: ";
				cin>>tempgpa;
				
				
				database[studentcounter].setdata(tempname,temproll,tempgpa);
				studentcounter++;
				system("cls");
				cout<<"====================================="<<endl;
				cout<<"       Student added successfully"<<endl;
				cout<<"====================================="<<endl;
				break;
				
			}
				case 2:{
				system("cls");
				if(studentcounter==0){
						cout<<"List is Empty"<<endl;
					}
					cout<<"--------------------------------------------------"<<endl;
					cout<<"Roll No \t|Name\t\t\t|GPA"<<endl;
					cout<<"--------------------------------------------------"<<endl;
				for(int i=0;i<studentcounter;i++){
					cout<<database[i].getroll()<< "\t\t| " 
                         << database[i].getname() << "\t\t\t| " 
                         << database[i].getgpa() << endl;
				}
				cout<<"--------------------------------------"<<endl;
				break;
				
			}
			case 3: {
				if(studentcounter==0){
					cout<<"No Student Record in Database"<<endl;
					break;
				}
				int targetroll;
				cout<<"Enter Roll Number to Sreach: "<<endl;
				cin>>targetroll;
				
				
				int found=0;
				for(int i=0;i<studentcounter;i++){
					
					if(database[i].getroll()==targetroll){
						system("cls");
						cout << "\n--- Student Found ---" << endl;
                        cout << "Name: " << database[i].getname() << endl;
                        cout << "Roll No: " << database[i].getroll() << endl;
                        cout << "GPA: " << database[i].getgpa() << endl;
                        found = 1;
                        break; 
					}
				}
				if(found==0){
					system("cls");
					cout<<"Student Not Found"<<endl;
				}
				break;
			}
			
			case 4:{
				system("cls");
				if(studentcounter==0){
					cout<<"Database is empty"<<endl;
				}
				int targetroll;
				int found=0;
				cout<<"Enter Roll number to update GPA: ";
				cin>>targetroll;
				for(int i=0;i<=studentcounter;i++){
					if(database[i].getroll()==targetroll){
						cout<<"Current GPA for: "<<database[i].getname()<<" is: "<<database[i].getgpa()<<endl;
						found=1;
						float newgpa;
						cout<<"Enter New GPA: ";
						cin>>newgpa;
						database[i].checkgpa(newgpa);
						cout<<"GPA updated."<<endl;
					}
					
				}
				if(found==0){
					cout<<"Not Found";
					break;
				}
				
				break;
			}
			case 5:{
				return 0;
				break;
			}
			
			
			
			default:
				system("cls");
				cout<<"Invalid Choice Please between 1-5"<<endl;
			
		}
	
	
	
	
	
	
		
    }
} 








