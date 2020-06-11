#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<process.h>

struct address
{
	char city[20];
	char state[20];
	char pin[7];
};
struct med
{
	char name[50];
	char date[50];
	int price;
};
struct student
{
	char bill[10];
	char name[20];
	char dr[20];
	char ph[10];
	char m1[20];
	char m2[20];
	char m3[20];


	int GST,tot,ma1,ma2,ma3;
	struct address add;
};
typedef struct student stu;
typedef struct med stu1;
FILE *fp,*fp2;
void password();
void mainmenu();
void addstudent();
void display();
void search();
void modify();
void dlt();
void marks();
void view();
void main2();
void medlist();
 void medsearch1();
 void viewstock();
void main()
{
	password();
	getch();
}
void password()
{
int pin=123,a,i;
char w;
//clrscr();
textcolor(8);
gotoxy(21,5);
cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Password Protected  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	 textcolor(8);
	 gotoxy(21,15);
	cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
			   gotoxy(23,10);
			   textcolor(7);
cprintf("Enter Password: ");
scanf("%d",&a);
if(pin==a)

{
gotoxy(34,12);
	textcolor(2);
	   cprintf("Password Matched");
	   gotoxy(30,13);
	   textcolor(1+BLINK);
	   cprintf("Press Any key to Unlock...");
	   getch();
	   main2();
}
else
{
gotoxy(34,12);
	textcolor(12);
	cprintf("Not Matched");
					for(i=3;i>=1;i--)
					{

						gotoxy(30,13);
						textcolor(12);
						cprintf("Exiting In %d Seconds...",i);
						delay(1000);
						}
						exit(0);




}
}
void mainmenu()
{
clrscr();

gotoxy(0,0);
textcolor(3);
	cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Main Menu  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(24,5);
	textcolor(2);

	cprintf("1.New Bill \n\n\b\b\b\b\b\b\b\b\b\b\b2.Display Details\n\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b3.Display Bill\n\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b4.Search Detailsn\n\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b5.Delete Bill\n\n\b\b\b\b\b\b\b\b\b\b\b\b\b6.Update Record\b\b\b\b\b\b\b\b\b\b\b\b\n\n\b\b\b7.Main Menu");

	textcolor(3);
	gotoxy(9,20);
	cprintf("====================================================================");

	gotoxy(24,22);
	textcolor(13);
cprintf("Enter Your Choice: ");

switch(getch())
{
 case '1':addstudent();
 break;
 case '2':display();
 break;
 case '3':view();
 break;
 case '4':search();
 break;
 case '5':dlt();
 break;
 case '6':modify();
 break;
 case '7':main2();
 break;
 default:{printf("Enter Valid Value");
 clrscr();
 mainmenu();
 }

}
}



void addstudent()
{
int i;
   stu obj;
   clrscr();
   fp=fopen("student.txt","ab+");
	  textcolor(9);
		 gotoxy(0,1);
		 //cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Students \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	 cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Add Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
   gotoxy(5,3);
 textcolor(11);
   cprintf("Give Bill No: ");
   fflush(stdin);
   gets(obj.bill);
  gotoxy(2,4);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
   gotoxy(5,5);
   textcolor(11);
   cprintf("Enter Name: ");
   fflush(stdin);
   gets(obj.name);
   gotoxy(2,6);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
	 gotoxy(5,7);
	 textcolor(11);
	 cprintf("Enter Doctor Name: ");
   fflush(stdin);
   gets(obj.dr);
   gotoxy(2,8);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
	 gotoxy(5,9);
	 textcolor(11);
	 cprintf("Enter City: ");
   fflush(stdin);
   gets(obj.add.city);
   gotoxy(2,10);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
	 gotoxy(5,11);
	 textcolor(11);
	 cprintf("Enter state: ");
   fflush(stdin);
   gets(obj.add.state);
   gotoxy(2,12);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
	 gotoxy(5,13);
	 textcolor(11);
	 cprintf("Enter PIN: ");
   fflush(stdin);
   gets(obj.add.pin);
   gotoxy(0,14);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
	 gotoxy(5,15);
	 textcolor(11);
	 cprintf("Enter Phone Number: ");
   fflush(stdin);
   gets(obj.ph);
   gotoxy(0,16);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
	gotoxy(5,17);
	textcolor(11);
	cprintf("Enter Medicine Name: ");
   fflush(stdin);
   gets(obj.m1);
   gotoxy(0,18);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");

 gotoxy(5,19);
	textcolor(11);
	cprintf("Enter Price: ");
	fflush(stdin);
scanf("%d",&obj.ma1);
   gotoxy(0,20);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
	gotoxy(5,21);
	textcolor(11);
	cprintf("Enter Medicine Name: ");
	fflush(stdin);
	gets(obj.m2);
	gotoxy(0,22);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");gotoxy(5,19);
	textcolor(11);
	gotoxy(5,23);
	cprintf("Enter Price: ");
	fflush(stdin);
	scanf("%d",&obj.ma2);
	gotoxy(0,24);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");gotoxy(5,19);
	textcolor(11);
	gotoxy(5,25);
	cprintf("Enter Medicine Name: ");
	fflush(stdin);
	gets(obj.m3);
	gotoxy(0,26);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");gotoxy(5,19);
		clrscr();
		gotoxy(5,27);
		cprintf("Enter Price: ");
	fflush(stdin);
	scanf("%d",&obj.ma3);

	clrscr();
	obj.tot=obj.ma1+obj.ma2+obj.ma3;


	 gotoxy(0,28);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");

   fwrite(&obj,sizeof(obj),1,fp);

   //printf("\n\n%s %s %s %s %s %s %s",obj.roll,obj.name,obj.gname,obj.add.city,obj.add.state,obj.add.pin,obj.ph);

	printf("\n\n\n\Saveing Your Information....");

	delay(2000);
		gotoxy(20,22);
	  textcolor(2);
  cprintf("Inserted Sucessfully");
  gotoxy(20,24);
  textcolor(2+BLINK);
  cprintf("Enter Any key to Return Main Menu.....");
  fclose(fp);
  getch();
  mainmenu();

}




void display()
{
	stu obj;
	clrscr();
	textcolor(6);
		 //gotoxy(13,1);
		 //cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Students \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	 gotoxy(0,1);
		 //cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Students \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	 cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Display  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	fp=fopen("student.txt","ab+");
	if(fp==NULL)
	{
		printf("No Record Exist");
				  return;

	}


	textcolor(2);
	cprintf("\n\nBill No    Name      DR Name      City       State    Pin      Phone           ");
	 textcolor(14);
	 gotoxy(0,3);
	printf(" ------------------------------------------------------------------------------");
	while(fread(&obj,sizeof(obj),1,fp)==1)
	{
		textcolor(15);
	   printf("\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b  %s        %s    %s    %s     %s    %s   %s      ",obj.bill,obj.name,obj.dr,obj.add.city,obj.add.state,obj.add.pin,obj.ph);
	   textcolor(5);
	  printf("\n------------------------------------------------------------------------------");
	}
	fclose(fp);

	textcolor(4);
		 gotoxy(27,25);
	cprintf("Press Any Key to Return...");
	getch();
	mainmenu();

}

void search()
{
	stu obj;
	char roll[20];
	clrscr();
	cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Search  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	fp=fopen("student.txt","ab+");
	if(fp==NULL)
	{
		printf("No Record Found...");
		return;

	}
	textcolor(15);

	cprintf("\n\n    Give Bill No; ");

	fflush(stdin);
	gets(roll);
	clrscr();
		cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Search  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("\n\n      Bill No      Name    Doctor Name    City   State       PIN      Phone");
	printf("\n    --------------------------------------------------------------------------\n");
	while(fread(&obj,sizeof(obj),1,fp)==1)
	{
	if(strcmpi(obj.bill,roll)==0)
	{
	textcolor(7);
	   cprintf("\n\n      %s       %s      %s   %s   %s     %s    %s",obj.bill,obj.name,obj.dr,obj.add.city,obj.add.state,obj.add.pin,obj.ph);
	break;
	}
	   //	else
	//printf("No Data Found");
	}
	fclose(fp);
	textcolor(4);
		 gotoxy(27,25);
	cprintf("Press Any Key to Return...");
	getch();
	mainmenu();
}


 void modify(){
	stu obj,obj2;
	char roll[20];
	int s;
	clrscr();
	fp=fopen("STUDENT.TXT","rb+");

	printf("\n\nGive Bill No: ");
	fflush(stdin);
	gets(roll);
	//printf("\n\n Roll	Name	  Batch     Guardian Name     City    State    PIN     Phone  ");
	   printf("\n      Bill No      Name    Doctor Name    City   State       PIN      Phone");
	printf("\n    --------------------------------------------------------------------------\n");
	while(fread(&obj,sizeof(obj),1,fp)==1){
		if(strcmpi(obj.bill,roll)==0){
			   //	printf("\n\n%s     %s %s     %s	    %s    %s  %s  %s",obj.roll,obj.name,obj.batch,obj.gname,obj.add.city,obj.add.state,obj.add.pin,obj.ph);
			printf("\n\n      %s       %s      %s   %s   %s     %s    %s",obj.bill,obj.name,obj.dr,obj.add.city,obj.add.state,obj.add.pin,obj.ph);
			   getch();
			   clrscr();
			   printf("\n\nUpdate Data For Roll: %s",roll);

			   gotoxy(5,7);
			   textcolor(11);
			cprintf("Give Bill No: ");
			fflush(stdin);
			gets(obj2.bill);
			   gotoxy(2,8);
			   textcolor(14);
			  cprintf("-------------------------------------------------------------------------");

			gotoxy(5,9);
			textcolor(11);
			cprintf("Give Name:");
			fflush(stdin);
			gets(obj2.name);
			gotoxy(2,10);
			   textcolor(14);
			  cprintf("-------------------------------------------------------------------------");
			gotoxy(5,11);
			textcolor(11);
			cprintf("Enter Doctor Name: ");
			fflush(stdin);
			gets(obj2.dr);
			gotoxy(2,12);
			   textcolor(14);
			  cprintf("-------------------------------------------------------------------------");

			gotoxy(5,13);
			textcolor(11);
			cprintf("Enter City: ");
			fflush(stdin);
			gets(obj2.add.city);
			gotoxy(2,14);
			   textcolor(14);
			  cprintf("-------------------------------------------------------------------------");
			gotoxy(5,15);
			textcolor(11);
			cprintf("Enter State :");
			fflush(stdin);
			gets(obj2.add.state);
			gotoxy(2,16);
			   textcolor(14);
			  cprintf("-------------------------------------------------------------------------");
			gotoxy(5,17);
			textcolor(11);
			cprintf("Enter Pin: ");
			fflush(stdin);
			gets(obj2.add.pin);
			gotoxy(2,18);
			   textcolor(14);
			  cprintf("-------------------------------------------------------------------------");
			gotoxy(5,19);
			textcolor(11);
			cprintf("Enter Phone Number:");
			fflush(stdin);
			gets(obj2.ph);
			gotoxy(2,20);
			   textcolor(14);
			  cprintf("-------------------------------------------------------------------------");
			s=sizeof(obj2);
			fseek(fp,-s,SEEK_CUR);
			fwrite(&obj2,sizeof(obj2),1,fp);
			break;
		}
		//else
		//printf("\n\nNo Data Exist.....");
	}
	fclose(fp);
	textcolor(4);
		 gotoxy(27,25);
	cprintf("Press Any Key to Return...");
	getch();
	mainmenu();
	  }

void dlt()
{
	stu obj;
char r[20];
int flag=0;
clrscr();
fp=fopen("STUDENT.TXT","rb");
if(fp==NULL)
{
printf("\nNO DATA EXIST");
return;
}
fp2=fopen("STUDENT2.TXT","wb+");
printf("Enter Bill No:	: ");
fflush(stdin);
gets(r);
printf("\n\nBill No	  Name	 Doctor name   City     State      PIN      Phone\n\n");
while(fread(&obj,sizeof(obj),1,fp)==1){
if(strcmpi(obj.bill,r)==0){
printf("\n\n%s %10s %13s	  %s    %s   %s   %s",obj.bill,obj.name,obj.dr,
	obj.add.city,obj.add.state,obj.add.pin,obj.ph);
printf("\n\nTHIS RECORD IS DELETED........");
flag=1;	continue;
}
fwrite(&obj,sizeof(obj),1,fp2);
}
remove("STUDENT.TXT");
rename("STUDENT2.TXT","STUDENT.TXT");
if(flag==0)
printf("\n\nRECORD NOT EXIST........");
fcloseall();
		getch();
		printf("Press any key to Continue...");
		mainmenu();

}

void view()
{

		   stu obj;
		   int a,b;
	char roll[20];
	clrscr();
	fp=fopen("student.txt","ab+");
	if(fp==NULL)
	{
		printf("No Record Found...");
		return;

	}
	printf("Give Bill No: ");
	fflush(stdin);
	gets(roll);
	clrscr();
	gotoxy(35,2);
	textcolor(2);
	cprintf("TAX INVOICE");

	printf("\n\n\n    --------------------------------------------------------------------------\n");

	while(fread(&obj,sizeof(obj),1,fp)==1)
	{
	if(strcmpi(obj.bill,roll)==0)
	{
	gotoxy(6,4);

	printf("Patient Name: %s",obj.name);
	gotoxy(67,4);
	printf("Bill No: %s",obj.bill);
	gotoxy(12,8);
	textcolor(7);
	cprintf("%s",obj.m1);
	gotoxy(40,8);
	textcolor(7);
	cprintf(":");
	gotoxy(64,8);
	textcolor(7);
	cprintf("%d",obj.ma1);
	gotoxy(12,10);
	textcolor(7);
	cprintf("%s",obj.m2);
	gotoxy(40,10);

	textcolor(7);
	cprintf(":");
	gotoxy(64,10);
	textcolor(7);
	cprintf("%d",obj.ma2);
	gotoxy(12,12);
	textcolor(7);
	cprintf("%s",obj.m3);
	gotoxy(40,12);
	textcolor(7);
	cprintf(":");
	gotoxy(64,12);
	textcolor(7);
	cprintf("%d",obj.ma3);


	printf("\n    --------------------------------------------------------------------------\n");
	gotoxy(12,16);
	textcolor(2);
	cprintf("Total: %d",obj.tot);
	gotoxy(70,16);
	textcolor(2);
	cprintf("%");
	gotoxy(30,16);
	textcolor(2);
	cprintf("GST charge: ");
	gotoxy(64,16);
	textcolor(2);
	cprintf("GST: ");
	scanf("%d",&a);
	b=(a*obj.tot)/100;
	gotoxy(42,16);
	textcolor(7);
	cprintf("%d",b);
	gotoxy(30,18);
	textcolor(3);
	cprintf("Net Amount: %d",(obj.tot+b));


	break;
	}

	}
	fclose(fp);
	textcolor(4);
		 gotoxy(27,25);
	cprintf("Press Any Key to Return...");
	getch();
	mainmenu();
}

void main2()

{
	   int i;
	   clrscr();
textcolor(15);
gotoxy(0,0);
	cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
	   textcolor(14+BLINK);

	   cprintf("Medical Shop");
	   textcolor(15);
	   cprintf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


										textcolor(5);
		gotoxy(30,10);
		cprintf("1. Open Stock");
		gotoxy(30,12);
		textcolor(5);
		cprintf("2. Open Billing section");
		textcolor(5);
		gotoxy(30,14);
		cprintf("3.Exit");
		textcolor(15);

		cprintf("\n\n\b\b\b\b\b\b\b\b\\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b================================================================================");
	  gotoxy(30,18);
	  cprintf("Option Please: ");
	  switch(getch())
	  {
		case '1':{
		clrscr();
		gotoxy(30,11);
		printf("1. Stock Register");
		gotoxy(30,13);
		printf("2. Stock Viewer");
		gotoxy(30,15);
		printf("3. Main Menu");
		gotoxy(13,17);
		printf("===================================================");
		gotoxy(25,19);
		printf("Enter Your Option: ");
		switch(getch())
		{
		  case '1':medlist();
		  break;
		  case '2':viewstock();
		  break;
		  case '3':main2();
		  break;
		  default:{
					textcolor(12);
					gotoxy(43,19);
		  cprintf("Enter Valid Choice...");
		  getch();
					main2();
		  }
		}
		}
		break;
		case '2':mainmenu();
		break;
		case '3':{

					clrscr();
					int f=0;
					for(i=3;i>=1;i--)
					{

						clrscr();
						gotoxy(30,13);
						textcolor(15);
						cprintf("Exiting In %d Seconds...",i);
						delay(1000);




					}
					clrscr();
					gotoxy(36,13);
					printf("Thank You");
					delay(1000);
					exit(0);

		}
		}

}



void medlist()
{
char i;
do{
   stu1 obj;
   clrscr();
   fp=fopen("med.txt","ab+");
	  textcolor(9);
		 gotoxy(0,1);
		 //cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Students \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	 cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Add Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
   gotoxy(5,3);
 textcolor(11);
   cprintf("Give Medicine Name: ");
   fflush(stdin);
   gets(obj.name);
  gotoxy(2,4);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
   gotoxy(5,5);
   textcolor(11);
   cprintf("Enter date: ");
   fflush(stdin);
   gets(obj.date);
   gotoxy(2,6);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");
	 gotoxy(5,7);
	 textcolor(11);
	 cprintf("Enter Price: ");
   scanf("%d",&obj.price);
   gotoxy(2,8);
   textcolor(14);
	  cprintf("-------------------------------------------------------------------------");

   fwrite(&obj,sizeof(obj),1,fp);

 //  printf("\n\n%s %s %d",obj.add2.name,obj.add2.date,obj.add2.price);
   fclose(fp);
   gotoxy(30,20);
	printf("Another Entry(Y/N): ") ;
   scanf("%s",&i);
   }while(i=='y'||i=='Y');

	 main2();
}


void viewstock()
{
	stu1 obj;
	clrscr();
	textcolor(6);
		 //gotoxy(13,1);
		 //cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Students \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	 gotoxy(0,1);
		 //cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Students \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	 cprintf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	fp=fopen("med.txt","ab+");
	if(fp==NULL)
	{
		printf("No Record Exist");
				  return;

	}


	textcolor(2);
	cprintf("\n\n                    Medicine Name     Date      Price     ");
	 textcolor(14);

	printf("\n------------------------------------------------------------------------------");
	while(fread(&obj,sizeof(obj),1,fp)==1)
	{
		textcolor(15);
	  // printf("\n\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b  %s        %s     %d      ",obj.add2.name,obj.add2.date,obj.add2.price);
		printf("\n\n                     %s            %s      %d",obj.name,obj.date,obj.price);
	   textcolor(5);
	  printf("\n------------------------------------------------------------------------------");
	}
	fclose(fp);

	textcolor(4);
		 gotoxy(27,25);
	cprintf("Press Any Key to Return...");
	getch();
	main2();

}
