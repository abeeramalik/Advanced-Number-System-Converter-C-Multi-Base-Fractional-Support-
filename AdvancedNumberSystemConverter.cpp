#include<iostream>
#include<fstream>
using namespace std;
//For calculating length of the array
int arrayLength(const char*arr)
{
    int size=0;
    while(arr[size]!='\0'){
        size++;
    }
    return size;
}

//Adding a char to a array
void addChar(char* arr,char ch,int& size) {
    for (int i=size;i>0;i--)
	{
        arr[i]=arr[i-1];
    }
    arr[0]=ch;
    arr[size+1]='\0';
    size++;
}
//Converting a num from a given base to decimal (supports fractions also)
double toDecimal(const char* number,int base){
    double decimal=0.0;
    double power=1.0;
    int length=arrayLength(number);
    int i=0;
//Converting integer part
    while (i<length&&number[i] != '.') {
        int digit;
        if(number[i] >= '0' && number[i] <= '9'){
            digit=number[i]-'0';
        } 
		else
		{
            digit=number[i]-'A'+10;
        }
        decimal=decimal*base+digit;
        i++;
    }
// Converts fractional part
    if (i<length && number[i]=='.'){
        i++;
        power= base;
        while(i<length) {
            int digit;
            if(number[i]>='0'&&number[i]<='9')
			{
                digit=number[i]-'0';
            } 
			else 
			{
                digit=number[i]-'A'+10;
            }
            decimal=decimal+digit/power;
            power=power* base;
            i++;
        }
    }
    return decimal;
}

// Converting a decimal num to a given base (supports fractions)
void fromDecimal(double number,int base,char* result,int precision=5) {
    int size = 0;
// Converts integer part
    int intPart=static_cast<int>(number);
    while (intPart>0){
        int rem=intPart % base;
      char ch;
    if(rem<10) 
	{
    ch = rem+'0';//for digits 0-9
    } else 
	{
    ch = rem-10 +'A';//for letters A-Z
    }
        addChar(result, ch, size);
        intPart=intPart/base;
    }
    if (size==0){
        addChar(result, '0', size);
    }
    result[size]='.';
    size++;
//Converts fractional part
    double fracPart=number-static_cast<int>(number);
    for (int i=0; i<precision; i++) {
        fracPart=fracPart * base;
        int digit=static_cast<int>(fracPart);
         char ch;
    if (digit < 10) 
    {
        ch = digit + '0'; // For digits 0-9
    } else {
        ch = digit - 10 + 'A'; // For letters A-Z
    }
        result[size++]=ch;
        fracPart=fracPart-digit;
    }
    result[size]='\0';
}

// Menu Display Function
int selectBase(){
    invalid_choice:
    cout<<"\n1. Binary (Base 2)" <<endl;
    cout<<"2. Decimal (Base 10)" <<endl;
    cout<<"3. Octal (Base 8)" <<endl;
    cout<<"4. Hexadecimal (Base 16)" <<endl;
    cout<<"5. User-Defined Base" <<endl;
    cout<<"Enter your choice (1-5) :";
    int choice;
    cin>>choice;
    switch (choice){
        case 1: return 2; 
        case 2: return 10;
        case 3: return 8;  
        case 4: return 16;
        case 5: {
        	  invalid_base:
            int userBase;
            cout<<"Enter user defined base (2-36) :";
            cin>>userBase;
            if(userBase>=2 && userBase<=36) 
			{
			return userBase;
            } else 
			{ 
				cout << "Invalid base. Please write the number between 2-36! "<<endl;
				goto invalid_base;
            }
        }
        default:
            cout << "Invalid choice" << endl;
            goto invalid_choice;
    }
}
bool login() {
    string username, password;
    string given_username = "user";
    string given_password = "password";

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    if (username == given_username && password == given_password) {
        cout << "Login Successful!" << endl;
        return true;
    } else {
        cout << "Invalid Username or Password. Try Again." << endl;
        return false;
    }
}

void menu() {
    ofstream file;
    file.open("ConversionResults.txt", ios::app);
    while(true){
     	cout<<"\n=== Number System Converter ==="<<endl;
     	cout<<"1. Convert a Number" << endl;
     	cout<<"2. Exit" << endl;
     	cout<<"Enter your choice ";
     	int choice;
     	cin>>choice;
     	if(choice==1) {
          	char inputNum[20];
			char outputNum[20]={0};
          	cout<<"\nSelect the base of the input number"<<endl;
			int inputBase=selectBase();
            
			cout<<"Enter the number to convert (supports fractions) :";
     		cin>>inputNum;
            
     		cout<<"\nSelect the base to convert to:"<<endl;
			int outputBase = selectBase();
            
			double decimalValue = toDecimal(inputNum,inputBase);
     		fromDecimal(decimalValue,outputBase,outputNum);
          	//showing result:
          	cout <<"The number " << inputNum << " in base " <<inputBase
               	<<", is " <<outputNum <<" in base "<<outputBase <<endl;
            	//file handeling:
            	file <<"Input: " << inputNum <<" (Base "<< inputBase << ") = "
               	<<"Output: " << outputNum <<" (Base "<< outputBase << ")\n";
     	}
		else if (choice == 2) {
          	cout <<"Exiting the program"<<endl;
            	break;
        	} 
		else{
          	cout <<"Invalid choice. Please try again" <<endl;
     	}
	}
	file.close();
}
int main(){
    cout <<"=== Welcome to the Number System Converter ===" << endl;
    while(!login());
    menu();
    return 0;
}
