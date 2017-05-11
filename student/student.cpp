#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;
static int a=0;


/*  	学生	*/
class student           
{
public:

		student();
		virtual ~student();
		virtual void show();
    	char name[20];   //姓名
		char sex[10];    //性别
		int ID;          //学号
		int source;      //成绩
};

student::student() 
{
	
}
student::~student(){}
 void student::show()
{
	cout << "姓名：" << name << endl;
	cout << "性别：" << sex << endl;
	cout << "学号：" << ID <<endl;
	cout << "成绩：" << source << endl;
}


/*	    班委	*/
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
	cout << "\t\t姓名：" << name << endl;
	cout << "\t\t性别：" << sex << endl;
	cout << "\t\t学号：" << ID <<endl;
	cout << "\t\t成绩：" << source << endl;
	cout << "\t\t职位：" << position << endl;
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
//		cout << "这是一个新系统..." << endl;
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
	cout << "请输入学生姓名："; cin >> End->name;
	cout << "请输入学生性别："; cin >> End->sex;
	cout << "请输入学生学号："; cin >> End->ID;
	cout << "请输入学生成绩："; cin >> End->source;
	cout << "请输入学生职位："; cin >> End->position;	
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
		cout << "请输入学生姓名："; cin >>End->name;
		cout << "请输入学生性别："; cin >> End->sex;
		cout << "请输入学生学号："; cin >> End->ID;
		cout << "请输入学生成绩："; cin >> End->source;
		cout << "请输入学生职位："; cin >> End->position;	
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
	cout << "1、按照学生的姓名查找" <<endl;
	cout << "2、按照学生的学号查找" <<endl;
	int option_m;
	scanf("%d",&option_m);
	switch(option_m)
	{
		
		case 1:
				cout << "姓名:" << endl;
				char str[20];
				scanf("%s",str);
				for(p=Head->Next;p!=End;p=p->Next)
				{
					if(!strcmp(str,p->name))
					{
						cout << "请重新输入该同学的信息" << endl;
						cout << "请输入学生姓名："; cin >>p->name;
						cout << "请输入学生性别："; cin >> p->sex;
						cout << "请输入学生学号："; cin >> p->ID;
						cout << "请输入学生成绩："; cin >> p->source;
						cout << "请输入学生职位："; cin >> p->position;	
						cout << "modify student success ! " << endl;
						return 0;
					}
				}
				
					cout << "没有找到该学生。" << endl;
					break;
		case 2:
				cout << "学号:" << endl;
				int n;
				scanf("%d",&n);
				for(p=Head->Next;p!=End;p=p->Next)
				{
					if(n == p->ID)
					{
						cout << "请重新输入该同学的信息" << endl;
						cout << "请输入学生姓名："; cin >>p->name;
						cout << "请输入学生性别："; cin >> p->sex;
						cout << "请输入学生学号："; cin >> p->ID;
						cout << "请输入学生成绩："; cin >> p->source;
						cout << "请输入学生职位："; cin >> p->position;	
						cout << "modify student success ! " << endl;
						return 0;
					}
				}
				    cout << "没有找到该学生。" << endl;
				    break;
		default:
				cout << "输入错误！！！" << endl;
	}	
}
int committee::query_student()
{
	cout << "1、按照学生的姓名查找" <<endl;
	cout << "2、按照学生的学号查找" <<endl;
	cout << "3、显示全部学生信息" << endl;
	int option_q;
	scanf("%d",&option_q);
	switch(option_q)
	{
		
		case 1:
				cout << "姓名:";
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
				
					cout << "没有找到该学生。" << endl;
					break;
		case 2:
				cout << "学号:";
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

				    cout << "没有找到该学生。" << endl;
				    break;
		case 3:
				for(p=Head->Next;p!=End;p=p->Next)
				{
					p->show();
				}
				break;
		default:
				cout << "输入错误！！！" << endl;
				return 1;
	}
}
int committee::delet_student()
{
	cout << "请输入要删除学生的姓名:";
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
				cout << "删除成功！" << endl;
//				delete temp;
				return 0;
		}
	}
	cout << "找不到改学生..." << endl;
	return 1;
}
void show_menu()
{
/*	cout << "\t############	学生信息管理系统	############" << endl;
	cout << "\t\t1、增加学生信息" << endl;
	cout << "\t\t2、修改学生信息" << endl;
	cout << "\t\t3、查询学生信息" << endl;
	cout << "\t\t4、删除学生信息" << endl;
	cout << "\t\t0、退出系统...." << endl;*/
  cout<<"********************************************************************************"<<endl;  
  cout<<"〓〓〓〓〓〓〓〓〓〓  ☆   学 生 信 息 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓"<<endl;  
  cout<<"〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓"<<endl;  
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生信息        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;  
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          2.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;  
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          3.查询学生信息        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;  
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          4.删除学生信息        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;  
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          0.退出管理系统        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;  

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
		/* 清屏 */
		system("cls");
		/* 显示菜单 */
		show_menu();
		cout << "请输入选项......" << endl;
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			/* 增加学生信息 */
			stud.add_student();
			cout << endl << "请按任意键继续..." <<endl;
			getch();
			break;
		case 2:
			/* 修改学生信息 */
			stud.modify_student();
			cout << endl << "请按任意键继续..." <<endl;
			getch();
			break;
		case 3:
			/* 查询学生信息 */
			stud.query_student();
			cout << endl << "请按任意键继续..." <<endl;
			getch();
			break;
		case 4:
			stud.delet_student();
			cout << endl << "请按任意键继续..." <<endl;
			getch();
			break;
		case 0: 
			flag_exit = true;
			break;
		}
//	if(1 == a)
	/* 保存学生信息 */
	stud.save_data();
	}
	stud.exit_d();
	return 0;
}
