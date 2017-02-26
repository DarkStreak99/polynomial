//program to add 2 polnomials

#include<stdio.h>
#include<conio.h>

//-------------------Structure Definition

	struct node
	{
	int coff,deg;
	struct node *link;
	};
	typedef struct node * NODE;

//------------------Function to inert node at begining

NODE   insbeg(NODE pres , int deg, int coeff)
	{
	NODE newnode,temp;
	newnode=(NODE)malloc(sizeof(struct node));

	newnode->deg = deg;
	newnode->coff = coeff;

	if(pres == NULL)
	{
	newnode->link=newnode;
	pres=newnode;
	return pres;
	}

	temp = pres;
	while(temp->link!=pres)
	temp=temp->link;

	temp->link=newnode;
	newnode->link=pres;
	pres=newnode;
	return pres;
	}

//------------------Function to ADD two Polynomials

NODE	add(NODE fir , NODE sec , NODE fin)
	{
	NODE newnode,temp1,temp2;

	temp1=fir;
	temp2=sec;
	
while(temp1->link != fir && temp2->link != sec)
	{
		if( temp1->deg == temp2->deg)
		{
		fin = insbeg(fin,temp1->deg,temp1->coff+temp2->coff);
		temp1 = temp1->link;
		temp2 = temp2->link;
		}

	  else  if ( temp1->deg < temp2->deg)
		{
		fin = insbeg(fin,temp1->deg,temp1->coff);
		temp1 = temp1->link;
		}
	  else
		{
		fin = insbeg(fin,temp2->deg,temp2->coff);
		temp2 = temp2->link;
		}
	}
 
	if( temp1->deg == temp2->deg)
		{
		fin = insbeg(fin,temp1->deg,temp1->coff+temp2->coff);
		temp1 = temp1->link;
		temp2 = temp2->link;
		}

	else  if( temp1->deg < temp2->deg)
		{
		fin = insbeg(fin,temp1->deg,temp1->coff);
		temp1 = temp1->link;
		}
	else
		{
		fin = insbeg(fin,temp2->deg,temp2->coff);
		temp2 = temp2->link;
		}

 //-------remaining terms in First Polynomial
	while(temp1 != fir )
	   {
	   fin = insbeg(fin,temp1->deg,temp1->coff);
	   temp1 = temp1->link;
	   }

 //--------remaining terms in Second Polynomial
	while(temp2 != sec )
	   {
	   fin = insbeg(fin,temp2->deg,temp2->coff);
	   temp2 = temp2->link;
	   }
	return fin;
	}


//---------main program

void main()
	{
	NODE fir=NULL,sec=NULL,fin=NULL,temp;
	int n,i,deg,coff;
	clrscr();

	printf(" Enter the Number of Terms in First Polynomial \n");
	scanf("%d",&n);

		for(i=0;i<n;i++)
		{
		printf(" Enter the Degree and Coefficient \n");
		scanf("%d%d",&deg,&coff);
		fir = insbeg(fir,deg,coff);
		}

	printf(" Enter the Number of Terms in Second Polynomial \n");
	scanf("%d",&n);

		for(i=0;i<n;i++)
		{
		printf(" Enter the Degree and Coefficient \n");
		scanf("%d%d",&deg,&coff);
		sec = insbeg(sec,deg,coff);
		}

		fin = add(fir,sec,fin); //addition

	printf(" The Resultant Polynomial After addition is \n");
		temp = fin;
		while(temp->link != fin)
		{
		printf("\t%d^%d+",temp->coff,temp->deg);
		temp=temp->link;
		}
		printf("\t%dX^%d",temp->coff,temp->deg);

	getch();
	}
