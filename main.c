#include "cll.c"

int main()
{
    struct node *cll= NULL;
	int ch, data, pos;
	while(1)
	{
		printf("MAIN MENU");
		printf("\n1. Create list");
        printf("\n2. Display ");
        printf("\n3. Insert at beginning ");
        printf("\n4. Insert at end ");
        printf("\n5. Insert at position ");
        printf("\n6. Delete at beginning ");
        printf("\n7. Delete at end ");
        printf("\n8. Delete at pos ");
        printf("\n9. Sort list ");
        printf("\n10. Search element ");
        printf("\n11. Reverse list ");
        printf("\n12. Delete duplicate elements from list ");
        printf("\n13. Insert in a sorted list");
        printf("\n14. Count no. of nodes");
        printf("\n15. Find middle node");
        printf("\n16. Insert at middle");
        printf("\n17. Delete from middle");
        printf("\n18. Exchange first and last node");
        printf("\n19. Split the list");
        printf("\n0. EXIT\n");

		printf("Enter your choice : ");
		scanf("%d",&ch);
        printf("\n");

		switch(ch)
		{
            case 0: exit(0);    break;

			case 1:
				cll=create(cll);
				printf("\nLinked list created ");   break;

			case 2:		display(cll);			break;

			case 3:	
                printf("Enter data: ");
                scanf("%d", &data);
                cll = insertatbeg(cll, data);		break;

			case 4:		
                printf("Enter data: ");
                scanf("%d", &data);
                cll = insertatend(cll, data);		break;

			case 5:		
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                cll = insertatpos(cll, data, pos);	break;

			case 6:		cll = deleteatbeg(cll);		break;

			case 7:		cll = deleteatend(cll);		break;

			case 8:	
                printf("Enter postion: ");
                scanf("%d", &pos);	
                cll = deleteatpos(cll, pos);		break;

			case 9:		cll = sort(cll);			break;

			case 10:	
                printf("Enter data to search: ");
                scanf("%d", &data);
                pos = search(cll, data);			
                if(pos >= 0)
                    printf("%d found at %d position!", data, pos);
                else
                    printf("%d not found in the list", data);
                break;

			case 11:	cll = reverse(cll);			break;

			case 12:	cll = deleteduplicates(cll);break;
            
			case 13:	
                printf("Enter data: ");
                scanf("%d", &data);
                cll = insertsorted(cll, data);	    break;

            case 14:
                printf("%d no. of nodes present!", count(cll)); break;

            case 15:
                struct node *mid = findmid(cll);
                printf("The middle element is: %d", mid->data);
                break;

            case 16:
                printf("Enter data: ");
                scanf("%d", &data);
                cll = insertmid(cll, data);
                break;

            case 17:    cll = deletemid(cll);   break;

            case 18:    cll = exchangefirstlast(cll);   break;

            case 19:    cll = split(cll);   break;
		}

        printf("\n\n");
	}

	getch();
	return 0;
}