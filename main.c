#include "cll.c"

int main()
{
    struct node *start= NULL;
	int ch;
	do
	{
		printf("\n MAIN MENU");
		printf("\n 1.Create list \n 2.display \n 3.insert at beginning \n 4.insert at end \n 5.insert at position \n 6.delete at beginning \n 7.delete at end \n 8.delete at pos \n 9.sort list \n 10.search element \n 11.reverse list \n 12.delete duplicate elements from list \n 13.Insert in a sorted list\n 14.EXIT\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				start=create(start);
				printf("\nLinked list created ");
				break;
			case 2:		start=display(start);			break;
			case 3:		start=insertatbeg(start);		break;
			case 4:		start=insertatend(start);		break;
			case 5:		start=insertatpos(start);		break;
			case 6:		start=deleteatbeg(start);		break;
			case 7:		start=deleteatend(start);		break;
			case 8:		start=deleteatpos(start);		break;
			case 9:		start=sort(start);				break;
			case 10:	start=search(start);			break;
			case 11:	start=reverse(start);			break;
			case 12:	start=deleteduplicates(start);	break;
			case 13:	start=insertsorted(start, 3);	break;
		}
	}while(ch!=14);
	getch();
	return 0;
}