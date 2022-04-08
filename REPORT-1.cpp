#include <iostream.h>
#include<conio.h>
#include <process.h>
#include<fstream.h>
#include<ctype.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

class report
{

private :
    int admno;
    char name[30];
    char fname[30];
    int std;
    char section;
    int sub1;  //EVS || Science || Physics || Accounts
    int sub2;  //Hindi || CS
    int sub3;  //Maths || Economics
    int sub4;  //English
    int sub5;  //Chemistry || Business || SSt
    int sub6;  //Sanskrit
    int total;
    float per;
    char grade[3];

public	:
    report ()          //ctor for giving legal initial value
    {
        sub1=sub2=sub3=sub4=sub5=sub6=0;
    }
    void main_menu();    //function to display main menu
    void search_menu();  // function to display search menu
    void report_menu( );  // function to  display report menu

    void read_data( );	  // function to read all the data members from the
    //keyboard
    void calculate();      // function to calculate total marks, per and grade

    void disp_data();	  // function to display data members on the screen

    void  add_record ();  // function to add student record in a data file
    void  del_record ();  //function to delete a record from the data file
    void modify_record( );  //	Function to modify a record in a data file

    void search_name( );   //function to read student name and search the 					  Information in the given database file, if it is
    //	  available then display student information 					   otherwise display � Name does not exist�

    void search_admno( ); // function to read student admno and search the 					  Information in the given database file, if it is
    // available then display student information 					   otherwise display � Name does not exist�

    void search_class(); // function to read student admno and search the 					  Information in the given database file, if it is
    // available then display student information 					   otherwise display � Name does not exist�
    void single_report_card();
    void report_single();  // function to show single student report card

    void report_class();     // function to show class report of a single class
    void perc_comparison();
};


/* function to show main menu ------------*/
void  report ::main_menu()
{
    int choice;
    do
        {
            system("cls");
            cout<<"\n\n\n\t\t R e p o r t  C a r d  M e n u\n\n";
            cout<<"\n\n\t\t1. Add New Student ";
            cout<<"\n\n\t\t2. Delete  Student";
            cout<<"\n\n\t\t3. Modify student";
            cout<<"\n\n\t\t4. Search Menu";
            cout<<"\n\n\t\t5. Report Menu ";
            cout<<"\n\n\t\t6. Exit ";
            cout<<"\n\n\t\t   Enter your choice (1..6) : ";
            cin>>choice;
            switch(choice)
                {
                case 1:
                    
                    add_record();// function to call add record
                    break;
                case 2:
                    
                    // function to call delete record
                    del_record();
                    break;
                case 3:
                    
                    // function to call modify record
                    modify_record();
                    break;
                case 4:
                    search_menu();
                    break;
                case 5:
                    report_menu();
                    break;
                case 6:
                    break;
                default :
                    cout<<"\n Wrong Choice.... Try agian";
                }  // end of switch
        }
    while(choice!=6);

    return;
}

/*----------- function to create report menu -----------*/

void  report ::report_menu()
{
    int choice;
    do
        {
            system("cls");
            cout<<"\n\n\n\t\t R e p o r t   M e n u\n\n";
            cout<<"\n\n\t\t1. Single Student";
            cout<<"\n\n\t\t2. Single class";
            cout<<"\n\n\t\t3. Exit ";
            cout<<"\n\n\t\t   Enter your choice (1..3) : ";
            cin>>choice;
            switch(choice)
                {
                case 1:    // function to call single student
                    report_single();
                    break;
                case 2:    // function to display class report
                    report_class();
                    break;
                case 3:
                    break;
                default :
                    cout<<"\n Wrong Choice.... Try agian";
                }  // end of switch
        }
    while(choice!=3);

    return;
}

/*------------function to create search menu---------------*/

void  report ::search_menu()
{
    int choice;
    do
        {
            system("cls");
            cout<<"\n\n\n\t\t S e a r c h   M e n u \n\n";
            cout<<"\n\n\t\t1. Admno Student";
            cout<<"\n\n\t\t2. Student Name";
            cout<<"\n\n\t\t3. Class wise";
            cout<<"\n\n\t\t4. Result Analysis";
            cout<<"\n\n\t\t5. Exit ";
            cout<<"\n\n\n\n\t\t   Enter your choice (1..5)";
            cin>>choice;
            switch(choice)
                {

                case 1:    // function to call search_admno
                    search_admno( );
                    getch();
                    break;

                case 2:    // function to call search_name
                    search_name();
                    getch();
                    break;

                case 3:    // function to call
                    search_class();
                    getch();
                    break;
                	
                case 4:
                	perc_comparison();
                	getch();
                	break;
                	
                case 5:
                	break;

                default :
                    cout<<"\n Wrong Choice.... Try agian";
                }  // end of switch
        }
    while(choice!=5);

    return;
}


/*------------function to read data members from keyboard------*/

void report:: read_data( )
{
    char ch;
    system("cls");
    cout<<"\n Enter Adm No :";
    cin>>admno;
    cout<<"\n Enter Name : ";
    gets(name);
    cin.get(ch);
    cout<<"\n Enter Father Name : ";
    cin.getline(fname,30);
    cout<<"\n Enter class : ";
    cin>>std;
    cout<<"\n Enter Section (A/B) :";
    cin>>section;
    if (std <= 5)
        {
            cout<<"\n Enter marks obtained in EVS : ";
            cin>>sub1;
            cout<<"\n Enter marks obtained in Hindi : ";
            cin>>sub2;
            cout<<"\n Enter marks obtained in Maths  : ";
            cin>>sub3;
            cout<<"\n Enter marks obtaine in English : ";
            cin>>sub4;
        }
    else if (std<=10)
        {
            cout<<"\n Enter marks obtained in Science : ";
            cin>>sub1;
            cout<<"\n Enter marks obtained in Hindi : ";
            cin>>sub2;
            cout<<"\n Enter marks obtained in Maths  : ";
            cin>>sub3;
            cout<<"\n Enter marks obtained in English : ";
            cin>>sub4;
            cout<<"\n Enter marks obtained in Social Studies : ";
            cin>>sub5;
            if(std<9)
           {  cout<<"\n Enter marks obtained in Sanskrit : ";
            cin>>sub6;}
        }
    else if (std<=12)
        {
            if (toupper(section)=='A')
                {
                    cout<<"\n Enter marks obtained in Physics : ";
                    cin>>sub1;
                    cout<<"\n Enter marks obtained in Computer Science : ";
                    cin>>sub2;
                    cout<<"\n Enter marks obtained in Maths  : ";
                    cin>>sub3;
                    cout<<"\n Enter marks obtained in English : ";
                    cin>>sub4;
                    cout<<"\n Enter marks obtained in Chemistry : ";
                    cin>>sub5;
                }
            else if (toupper(section)=='B')
                {
                    cout<<"\n Enter marks obtained in Accounts : ";
                    cin>>sub1;
                    cout<<"\n Enter marks obtained in Hindi : ";
                    cin>>sub2;
                    cout<<"\n Enter marks obtained in Economics  : ";
                    cin>>sub3;
                    cout<<"\n Enter marks obtained in English : ";
                    cin>>sub4;
                    cout<<"\n Enter marks obtained in Business : ";
                    cin>>sub5;
                }
        }
    return;
}

/*------------function to calculate total marks, per and grade-----------*/
void report::calculate()
{
    total = sub1+sub2+sub3+sub4+sub5+sub6;
    if (std<=5)
        per = total/4.0;
    else if (std <= 8)
        per = total/6.0;
    else if (std <= 12)
        per = total/5.0;


    if(per>90)
        strcpy(grade,"A1");

    else if(per>80)
    strcpy(grade,"A2");

   else if(per>70)
        strcpy(grade,"B1");

   else if(per>60)
        strcpy(grade,"B2");

    else if(per>50)
        strcpy(grade,"C");
    else
        strcpy(grade,"D");
    return;
}

/*---------function to display data members --------------*/

void  report::disp_data()
{

    cout<<"\n Admno               : "<<admno;
    cout<<"\n Student Name        : "<<name;
    cout<<"\n Father Name         : "<<fname;
    cout<<"\n Class & Section     : "<<std<<"-"<<section;
    if (std<=5)
        {
            cout<<"\n EVS                 : "<<sub1;
            cout<<"\n Maths               : "<<sub3;
            cout<<"\n Hindi               : "<<sub2;
            cout<<"\n English             : "<<sub4;
        }
    else if ( std<=10 )
        {
            cout<<"\n Science             : "<<sub1;
            cout<<"\n Social Science      : "<<sub5;
            cout<<"\n Maths               : "<<sub3;
            cout<<"\n Hindi               : "<<sub2;
            cout<<"\n English             : "<<sub4;
            if(std<9)
     {      cout<<"\n Sanskrit            : "<<sub6; }
        }
    else if (std<=12)
        {
            if (toupper(section)=='A')
                {
                    cout<<"\n Physics             : "<<sub1;
                    cout<<"\n Chemistry           : "<<sub5;
                    cout<<"\n Maths               : "<<sub3;
                    cout<<"\n Computer/Hindi      : "<<sub2;
                    cout<<"\n English             : "<<sub4;
                }
            else
                {
                    cout<<"\n Accounts            : "<<sub1;
                    cout<<"\n Business            : "<<sub5;
                    cout<<"\n Economics           : "<<sub3;
                    cout<<"\n Hindi               : "<<sub2;
                    cout<<"\n English             : "<<sub4;
                }
        }
    cout<<"\n Total Marks         : "<<total;
    cout<<"\n Percentage          : "<<per;
    cout<<"\n Grade               : "<<grade;

    return ;
}
/* function for the comparison of student marks ........*/
void report::perc_comparison()
  {  system("cls");
  	 ifstream fin;
  	 fin.open("report.dat",ios::in|ios::binary);
     int c1=0, c2=0, c3=0,c4=0,c5=0,c6=0,c7=0,pstd;char psec;
     cout<<"\n\nEnter the Class for result analysis : ";
     cin>>pstd;
     cout<<"\n\nEnter section of the required Class : ";
     cin>>psec;
  	while(!fin.eof())
  	  {  fin.read((char*)this,sizeof(report));
  	  	if(pstd==std && psec==section)
  	  {
  	    if(per>90)      c1++;
  	    else if(per>80) c2++;
  	    else if(per>70) c3++;
  	    else if(per>60) c4++;
  	    else if(per>50) c5++;
  	    else if(per>40) c6++;
  	    else            c7++;}
  	    }
  	    cout<<"\n\n\n\nTotal students above 90 % are      "<<c1;
  	    cout<<"\n\nTotal students between 80-90% are  "<<c2;
  	    cout<<"\n\nTotal students between 70-80% are  "<<c3;
  	    cout<<"\n\nTotal students between 60-70% are  "<<c4;
  	    cout<<"\n\nTotal students between 50-60% are  "<<c5;
  	    cout<<"\n\nTotal students between 40-50% are  "<<c6;
  	    cout<<"\n\nTotal failed students are          "<<c7;
  	  fin.close();}
/*-------------function to add record in data  file ------*/
void  report::add_record ()
{
    ofstream fout;
    fout.open("report.dat",ios::app|ios::binary);
    read_data();
    calculate();
    fout.write((char*)this, sizeof(report));
    fout.close();
}

/*--------------function to search student record name wise ------*/

void report::search_name( )
{
    ifstream fin;
    fin.open("report.dat",ios::in|ios::binary);
    char tname[30];
    int flag=0;

    system("cls");
    cout<<"\n Enter Name to search :";
    cin>>tname;

    while(fin.read((char*)this,sizeof(report)))
        {
            if(strcmpi(tname,name)==0)
                {
                    system("cls");
                    cout<<"\n Student Information ";
                    cout<<"\n--------------------------------------------------------"<<endl;
                    disp_data();
                    flag=1;
                }
        }
    fin.close();
    if(flag==0)
        cout<<"\n No such name : "<<strupr(tname)<<" exist in our record... Try again";

    return;
}

/*----------function to call search class wise -------------------------------*/
void report::search_class()
{
    ifstream fin;
    fin.open("report.dat",ios::binary|ios::in);
    char tsect;
    int tstd;
    int flag=0;

    system("cls");
    cout<<"\n Enter student Class to search :";
    cin>>tstd;
    cout<<"\n Enter student section to search :";
    cin>>tsect;
    clrscr();
    cout<<"\n Class :"<<tstd<<" - "<<tsect<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    if (tstd<=5)
        cout<<"Admno\tName\tFname\t\tEVS\tMath\tHindi\tEng\tTotal \t per\n";
    else if (tstd<=10)
        cout<<"Admno\tName\tFname\tSci  S.St.  Math   Hindi   Eng    Sans\tTotal\tper\n";
    else if (tstd<=12&&tsect=='a')
        cout<<"Admno\tName\tFname\tPhy\tChem\tMath  Comp/Hin  Eng\tTotal \t per\n";
    else if (tstd<=12&&tsect=='b')
        cout<<"Admno\tName\tFname\tAcc \tBsnes \tEco \tHindi \tEng \tTotal \t per\n";
    cout<<"-------------------------------------------------------------------------------"<<endl;

    while(fin.read((char*)this, sizeof(report)))
        {
            if(tstd==std && tsect== section )
                {
                    if (std<=5)
                        cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t\t"<<sub1<<"\t"<<sub3<<"\t"<<sub2<<"\t"<<sub4<<"\t"<<total<<"\t"<<per<<endl;
                    else if (std<=10)
                        cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<sub1<<"    "<<sub5<<"     "<<sub3<<"     "<<sub2<<"      "<<sub4<<"     "<<sub6<<"    "<<total<<"  "<<per<<endl;
                    else if (std<=12&&section=='a')
                        cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<sub1<<"\t"<<sub5<<"\t"<<sub3<<"\t"<<sub2<<"\t"<<sub4<<"\t"<<total<<"\t"<<per<<endl;
                    else if (std<=12&&section=='b')
                        cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<sub1<<"\t"<<sub5<<"\t"<<sub3<<"\t"<<sub2<<"\t"<<sub4<<"\t"<<total<<"\t"<<per<<endl;
                    else ;
                    flag=1;
                }
        }
        cout<<"\n\n";
        perc_comparison();
        
    cout<<"-------------------------------------------------------------------------------"<<endl;

    fin.close();
    if(flag==0)
        cout<<"\n\n Information Not available for class :"<<tstd <<" - "<<tsect;

    return;


}

/*------------function to search record according to student admno ------------*/

void report :: search_admno( )
{
    ifstream fin;
    fin.open("report.dat",ios::in|ios::binary);

    int tadmno;
    int flag=0;

    system("cls");
    cout<<"\n Enter Admission Number to search : ";
    cin>>tadmno;

    while(fin.read((char*)this,sizeof(report)))
        {
            if(tadmno == admno)
                {
                    system("cls");
                    cout<<"\n Student Information ";
                    cout<<"\n--------------------------------------------------------"<<endl;
                    disp_data();
                    flag = 1;
                }


        }
    fin.close();

    if(flag==0)
        cout<<"\n\n Admission No : "<<tadmno <<" does not exist.... Try again";

    return;

}



/*--------function to display single report card---------*/

void report::single_report_card()
{
    system("cls");

    cout<<"\n\t\t\t Kendriya Vidyalaya, Chhatarpur";
    cout<<"\n\t\t\t\t Session : 2018-19";
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n Admno :"<<admno;
    cout<<"\n\n Name  :"<<name <<"\t\t Father Name :"<<fname<<"\t\t class :"<<std<<"-"<<section;
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\n Subject\tMax Mark\tMin Mark\t Marks Obtained";
    cout<<"\n--------------------------------------------------------------------------------";
    if (std <=5)
        {
            cout<<"\n EVS\t\t100\t\t33\t\t\t"<<sub1;
            cout<<"\n\n Maths\t\t100\t\t33\t\t\t"<<sub3;
            cout<<"\n\n Hindi\t\t100\t\t33\t\t\t"<<sub2;
            cout<<"\n\n English\t100\t\t33\t\t\t"<<sub4;
        }
    else if (std<=10)
        {
            cout<<"\n Science\t100\t\t33\t\t\t"<<sub1;
            cout<<"\n\n Social Science\t100\t\t33\t\t\t"<<sub5;
            cout<<"\n\n Maths\t\t100\t\t33\t\t\t"<<sub3;
            cout<<"\n\n Hindi\t\t100\t\t33\t\t\t"<<sub2;
            cout<<"\n\n English\t100\t\t33\t\t\t"<<sub4;
            cout<<"\n\n Sanskrit\t100\t\t33\t\t\t"<<sub6;
        }
    else if (std<=12)
        {
            if (toupper(section)=='A')
                {
                    cout<<"\n Physics\t100\t\t33\t\t\t"<<sub1;
                    cout<<"\n\n Chemistry\t100\t\t33\t\t\t"<<sub5;
                    cout<<"\n\n Maths\t\t100\t\t33\t\t\t"<<sub3;
                    cout<<"\n\n Computer/Hindi\t100\t\t33\t\t\t"<<sub2;
                    cout<<"\n\n English\t100\t\t33\t\t\t"<<sub4;
                }
            if (toupper(section)=='B')
                {
                    cout<<"\n Accounts\t100\t\t33\t\t\t"<<sub1;
                    cout<<"\n\n Business\t100\t\t33\t\t\t"<<sub5;
                    cout<<"\n\n Economics\t100\t\t33\t\t\t"<<sub3;
                    cout<<"\n\n Hindi\t\t100\t\t33\t\t\t"<<sub2;
                    cout<<"\n\n English\t100\t\t33\t\t\t"<<sub4;
                }
        }
    cout<<"\n\n-------------------------------------------------------------------------------";
    cout<<"\n Total Marks :\t"<<total<<"\t\tPercentage : "<<per<<"\tGrade :"<<grade;
    cout<<"\n-------------------------------------------------------------------------------";

    return;
}


/*----------function to show single student report-----*/

void report:: report_single()
{
    int tadmno;
    int flag =0;
    ifstream fin;
    fin.open("report.dat",ios::binary);   //binary mode

    system("cls");
    cout<<"\n Enter admission No : ";
    cin>>tadmno;

    while(fin.read((char*)this, sizeof(report)))  // read record and check eof
        {
            if(tadmno ==admno)
                {
                    single_report_card();  // function to display single report card
                    flag =1;
                }
        }
    fin.close();
    if(flag==0)
        cout<<"\n\n Admission No :"<<tadmno <<" does not exist.... Try again";
    getch();
    return;
}


/*-------------function to display class wise report card------------*/
void report:: report_class()
{

    int tstd;
    char tsect;
    ifstream  fin;
    fin.open("report.dat");

    system("cls");

    cout<<"\n\n Enter Class (1..12)  :";
    cin>>tstd;
    cout<<"\n Enter section(A/B) :";
    cin>>tsect;

    system("cls");

    cout<<"\n\t\t\t Kendriya Vidyalaya Chhatarpur";
    cout<<"\n\t\t Class :"<<tstd<<"-"<<tsect<<"\t\t Session : 2018-19"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    if (tstd<=5)
        cout<<"Admno\tName\tFname\t\tEVS\tMath\tHindi\tEng\tTotal \t per\n";
    else if (tstd<=10)
        cout<<"Admno\tName\tFname\tSci  S.St.  Math   Hindi   Eng    Sans\tTotal\tper\n";
    else if (tstd<=12&&tsect=='a')
        cout<<"Admno\tName\tFname\tPhy\tChem\tMath  Comp/Hin  Eng\tTotal \t per\n";
    else if (tstd<=12&&tsect=='b')
        cout<<"Admno\tName\tFname\tAcc \tBsnes \tEco \tHindi \tEng \tTotal \t per\n";
    cout<<"-------------------------------------------------------------------------------"<<endl;

    while(fin.read((char*)this, sizeof(report)))
        {
            if(tstd==std && tsect== section )
                {
                    if (std<=5)
                        cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t\t"<<sub1<<"\t"<<sub3<<"\t"<<sub2<<"\t"<<sub4<<"\t"<<total<<"\t"<<per<<endl;
                    else if (std<=10)
                        cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<sub1<<"    "<<sub5<<"     "<<sub3<<"     "<<sub2<<"      "<<sub4<<"     "<<sub6<<"    "<<total<<"  "<<per<<endl;
                    else if (std<=12&&section=='a')
                        cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<sub1<<"\t"<<sub5<<"\t"<<sub3<<"\t"<<sub2<<"\t"<<sub4<<"\t"<<total<<"\t"<<per<<endl;
                    else if (std<=12&&section=='b')
                        cout<<admno<<"\t"<<name<<"\t"<<fname<<"\t"<<sub1<<"\t"<<sub5<<"\t"<<sub3<<"\t"<<sub2<<"\t"<<sub4<<"\t"<<total<<"\t"<<per<<endl;
                }
        }
    fin.close();
    cout<<"-------------------------------------------------------------------------------"<<endl;
    cout<<"\n Report prepared By  :"<<" NOWGONG GROUP (WAALE) ";
    getch();
    return ;

}

/*------------function to delete single record from binay file report.dat------*/

void  report::del_record ()
{

    ifstream fin;
    ofstream fout;
    int tadmno;
    int flag =0;
    system("cls");
    cout<<"\n Enter admno to delete :";
    cin>>tadmno;

    fin.open("report.dat",ios::binary);
    fout.open("temp.dat");

    while(fin.read((char*)this, sizeof(report)))
        {
            if(tadmno!=admno)
                fout.write((char*)this,sizeof(report));
            else
                flag=1;

        }
    fin.close();
    fout.close();

    remove("report.dat");  // function from stdio.h header file
    rename("temp.dat","report.dat"); // function from stdio.h header file

    if(flag==1)
        cout<<"\n\n Record Sucessfully removed ";
    else
        cout<<"\n Admission No :"<<tadmno <<" does not exist...Try again";
    getch();
    return;
}


/*---------function to modify student information-----------------------*/

void report:: modify_record( )
{

    ifstream fin;
    ofstream fout;
    int tadmno;
    int flag =0;
    system("cls");
    cout<<"\n Enter Admno to Modify :";
    cin>>tadmno;

    fin.open("report.dat",ios::binary);
    fout.open("temp.dat");

    while(fin.read((char*)this, sizeof(report)))
        {
            if(tadmno == admno)
                {
                    read_data();
                    calculate();
                    flag=1;
                }

            fout.write((char*)this,sizeof(report));

        }
    fin.close();
    fout.close();

    remove("report.dat");  // function from stdio.h header file
    rename("temp.dat","report.dat"); // function from stdio.h header file

    if(flag==1)
        cout<<"\n\n Record Sucessfully modified ";
    else
        cout<<"\n Admission No :"<<tadmno <<" does not exist...Try again";
    getch();
    return;

}


/*-----------main function to implement report class ------------*/

int main()
{
    report r;
    r.main_menu();

    return 0;
}


















