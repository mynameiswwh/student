#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
static int a=0;


/*  	ѧ��	*/
class student           
{
public:

		student();
		virtual ~student();
		virtual void show();
    	char name[20];   //����
		char sex[10];    //�Ա�
		int ID;          //ѧ��
		int source;      //�ɼ�
};

student::student() 
{
	
}
student::~student(){}
 void student::show()
{
	cout << "������" << name << endl;
	cout << "�Ա�" << sex << endl;
	cout << "ѧ�ţ�" << ID <<endl;
	cout << "�ɼ���" << source << endl;
}


/*	    ��ί	*/
class committee : virtual public student
{
public:
		committee();
		~committee();
		void show();
		void save_data();
		void read_data();
		void add_student();
		void init();
		void exit_d();
		int modify_student();
		int query_student();
		int delet_student();
		ifstream ifile;	
		ofstream ofile;	
		committee *Head;
		committee *End;
		committee *p;
//		student *s;

		
private:
		char position[20];
		committee *Next;
		committee *Pre;

		
};
void committee::init()
{
	Head = new committee;			
	Head->Next =new committee;
	Head->Next->Pre = Head;
	End = Head->Next;
}
void committee::exit_d()
{
	committee * t;
	int i=1;
	for(p = Head->Next;p != End;i++)
	{
		t = p;
		p=p->Next;
		delete t;
		cout << "delete OK!" << endl;
	}
	delete Head;
	delete End;
}
committee::committee()
{
//	static int a=0;cout << a << endl;a++;
//	cout << "begin" << endl;
}

committee::~committee()
{
/*	committee * t;
	int i=1;
	for(p = Head->Next;p != End;i++)
	{
		t = p;
		p=p->Next;
		delete t;
		cout << "delete OK!" << endl;
	}
	delete Head;
	delete End->Next;
	delete End;
*/
}
void committee::show()
{
	cout << "#########################################" << endl;
	cout << "\t\t������" << name << endl;
	cout << "\t\t�Ա�" << sex << endl;
	cout << "\t\tѧ�ţ�" << ID <<endl;
	cout << "\t\t�ɼ���" << source << endl;
	cout << "\t\tְλ��" << position << endl;
	cout << "#########################################" << endl;
}
void committee::read_data()
{
	ifile.open("data.txt",ios::in);
	if(ifile)
	{
		while(ifile.peek() != EOF)
		{
			if(0 ==a)
			{
//				Head = this;
//				End = this;
				char str[20];
				ifile >> str;
				if(str[0] != '\0')
				{
//					Head = new committee;
					strcpy(End->name,str);
					ifile  >> End->sex >> End->ID >> End->source >> End->position;
					a=1;
//					End = new committee;
//					End = Head;
				}
			}
			else

			{	End->Next = new committee;
				End->Next->Pre = End;
				End = End->Next;
				ifile >> End->name >> End->sex >> End->ID >> End->source >> End->position;
				a=2;
			}
		}

//		End = End->Pre;
//		delete End->Next;
	}
//	else
//	{   
//		Head = new committee;
//		End = new committee;
//		cout << "����һ����ϵͳ..." << endl;
//	}

	ifile.close();
}
void committee::save_data()
{
	
	ofile.open("data.txt",ios::out);
	if(ofile.is_open())
	{
		for(p=Head->Next;p!=End;p=p->Next)
		{
			ofile << p->name << "	" << p->sex << "	" << p->ID << "		" << p->source << "		" << p->position << '\n'; 
		}
//			ofile << End->name << "	" << End->sex << "	" << End->ID << "		" << End->source << "		" << End->position << '\n';
	}
	else
		printf("open data.txt failed.");
	ofile.close();
}
void committee::add_student()
{	
/*	if (0 == a)
	{
//		Head = this;
//		End = this;
	a = 1;
	cout << "������ѧ��������"; cin >> End->name;
	cout << "������ѧ���Ա�"; cin >> End->sex;
	cout << "������ѧ��ѧ�ţ�"; cin >> End->ID;
	cout << "������ѧ���ɼ���"; cin >> End->source;
	cout << "������ѧ��ְλ��"; cin >> End->position;	
	cout << "add student success ! " << endl;
	}
	else 
	{        */
//		if(2 != a)
//		{
//			End->Next = new committee;
//			End->Next->Pre = End;
//			End = End->Next;	
//			a = 2;
//		}
//		committee *t;
//		if(2 == a)
//		{			
//			t = End;
//			End = End->Pre;
//		}
//		End->Next = new committee;
//		End->Next->Pre = End;
//		End = End->Next;
		cout << "������ѧ��������"; cin >>End->name;
		cout << "������ѧ���Ա�"; cin >> End->sex;
		cout << "������ѧ��ѧ�ţ�"; cin >> End->ID;
		cout << "������ѧ���ɼ���"; cin >> End->source;
		cout << "������ѧ��ְλ��"; cin >> End->position;	
		cout << "add student success ! " << endl;
//		if(2 == a)
//		{
//			End->Next = t;
//			End->Next->Pre = End;
//			End = End->Next;
//			a=3;
//		}
			End->Next = new committee;
			End->Next->Pre = End;
			End = End->Next;

//	}
}
int committee::modify_student()
{
	cout << "1������ѧ������������" <<endl;
	cout << "2������ѧ����ѧ�Ų���" <<endl;
	int option_m;
	scanf("%d",&option_m);
	switch(option_m)
	{
		
		case 1:
				cout << "����:" << endl;
				char str[20];
				scanf("%s",str);
				for(p=Head->Next;p!=End;p=p->Next)
				{
					if(!strcmp(str,p->name))
					{
						cout << "�����������ͬѧ����Ϣ" << endl;
						cout << "������ѧ��������"; cin >>p->name;
						cout << "������ѧ���Ա�"; cin >> p->sex;
						cout << "������ѧ��ѧ�ţ�"; cin >> p->ID;
						cout << "������ѧ���ɼ���"; cin >> p->source;
						cout << "������ѧ��ְλ��"; cin >> p->position;	
						cout << "modify student success ! " << endl;
						return 0;
					}
				}
				
					cout << "û���ҵ���ѧ����" << endl;
					break;
		case 2:
				cout << "ѧ��:" << endl;
				int n;
				scanf("%d",&n);
				for(p=Head->Next;p!=End;p=p->Next)
				{
					if(n == p->ID)
					{
						cout << "�����������ͬѧ����Ϣ" << endl;
						cout << "������ѧ��������"; cin >>p->name;
						cout << "������ѧ���Ա�"; cin >> p->sex;
						cout << "������ѧ��ѧ�ţ�"; cin >> p->ID;
						cout << "������ѧ���ɼ���"; cin >> p->source;
						cout << "������ѧ��ְλ��"; cin >> p->position;	
						cout << "modify student success ! " << endl;
						return 0;
					}
				}
				    cout << "û���ҵ���ѧ����" << endl;
				    break;
		default:
				cout << "������󣡣���" << endl;
	}	
}
int committee::query_student()
{
	cout << "1������ѧ������������" <<endl;
	cout << "2������ѧ����ѧ�Ų���" <<endl;
	cout << "3����ʾȫ��ѧ����Ϣ" << endl;
	int option_q;
	scanf("%d",&option_q);
	switch(option_q)
	{
		
		case 1:
				cout << "����:";
				char str[20];
				scanf("%s",str);
				for(p=Head->Next;p!=End;p=p->Next)
				{
					if(!strcmp(str,p->name))
					{
						p->show();
						return 0;
					}
				}
				
					cout << "û���ҵ���ѧ����" << endl;
					break;
		case 2:
				cout << "ѧ��:";
				int n;
				scanf("%d",&n);
				for(p=Head->Next;p!=End;p=p->Next)
				{
					if(n == p->ID)
					{
						p->show();
						return 0;
					}
				}

				    cout << "û���ҵ���ѧ����" << endl;
				    break;
		case 3:
				for(p=Head->Next;p!=End;p=p->Next)
				{
					p->show();
				}
				break;
		default:
				cout << "������󣡣���" << endl;
				return 1;
	}
}
int committee::delet_student()
{
	cout << "������Ҫɾ��ѧ��������:";
	char str[20];
	committee * temp = NULL;
	scanf("%s",str);
	for(p=Head->Next;p!=End;p=p->Next)
	{
		if(!strcmp(str,p->name))
		{
//				temp = p;
				p->Next->Pre = p->Pre;
				p=p->Pre;
				p->Next = p->Next->Next;
				cout << "ɾ���ɹ���" << endl;
//				delete temp;
				return 0;
		}
	}
	cout << "�Ҳ�����ѧ��..." << endl;
	return 1;
}
void show_menu()
{
/*	cout << "\t############	ѧ����Ϣ����ϵͳ	############" << endl;
	cout << "\t\t1������ѧ����Ϣ" << endl;
	cout << "\t\t2���޸�ѧ����Ϣ" << endl;
	cout << "\t\t3����ѯѧ����Ϣ" << endl;
	cout << "\t\t4��ɾ��ѧ����Ϣ" << endl;
	cout << "\t\t0���˳�ϵͳ...." << endl;*/
  cout<<"********************************************************************************"<<endl;  
  cout<<"��������������������  ��   ѧ �� �� Ϣ �� �� ϵ  ͳ     ��  ��������������������"<<endl;  
  cout<<"��������������������         ��������         �������������������"<<endl;  
  cout<<"��������������������  ��          1.����ѧ����Ϣ        ��  �������������������"<<endl;  
  cout<<"��������������������  ��          2.�޸�ѧ����Ϣ        ��  �������������������"<<endl;  
  cout<<"��������������������  ��          3.��ѯѧ����Ϣ        ��  �������������������"<<endl;  
  cout<<"��������������������  ��          4.ɾ��ѧ����Ϣ        ��  �������������������"<<endl;  
  cout<<"��������������������  ��          0.�˳�����ϵͳ        ��  �������������������"<<endl;  

}


int main()
{
	int option;
	bool flag_exit = false;
	committee stud;
	stud.init();
	stud.read_data();
	while(!flag_exit)
	{
		/* ���� */
		system("cls");
		/* ��ʾ�˵� */
		show_menu();
		cout << "������ѡ��......" << endl;
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			/* ����ѧ����Ϣ */
			stud.add_student();
			cout << endl << "�밴���������..." <<endl;
			getch();
			break;
		case 2:
			/* �޸�ѧ����Ϣ */
			stud.modify_student();
			cout << endl << "�밴���������..." <<endl;
			getch();
			break;
		case 3:
			/* ��ѯѧ����Ϣ */
			stud.query_student();
			cout << endl << "�밴���������..." <<endl;
			getch();
			break;
		case 4:
			stud.delet_student();
			cout << endl << "�밴���������..." <<endl;
			getch();
			break;
		case 0: 
			flag_exit = true;
			break;
		}
//	if(1 == a)
	/* ����ѧ����Ϣ */
	stud.save_data();
	}
	stud.exit_d();
	return 0;
}
