# include<stdio.h>
# include<stdlib.h>

struct node
{
   int data;
   struct node *next;	
};

void push(struct node **head_ref ,int a);
void split_list(struct node *head, struct node **head1_ref, struct node **head2_ref);  /*head1_ref and head2_ref are references to head nodes of 
                                                                                        the two resultant linked lists */
void display(struct node *head);

int main()
{  
    struct node *head= NULL;
    struct node *head1= NULL;
    struct node *head2= NULL;
    
    
	int i,n,a;
	printf("Enter total no. of nodes");
	scanf("%d",&n);
	
	printf("\nEnter the elements in the linked list");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		push(&head, a);
	}
	
	printf("Original Linked List is:\n");
	display(head);
	
	printf("\nNow splitting the linked list into two halves");
	split_list(head, &head1, &head2);
	
	int choice,ch;
	while(1)
	{
		printf("\n\nEnter your choice\n");
		printf("1. First half split\n");
		printf("2. Second half split\n");
		printf("\nYour choice:");
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 : printf("\nFirst half");
			         display(head1);
			         
			         ch= getchar();
			         ch= getchar();
			         break;
			         
			case 2 : printf("\nSecond half");
			         display(head2);
			         
			         ch= getchar();
			         ch= getchar();
			         break;
			
			default : printf("Invalid choice");
			         ch= getchar();
			         ch= getchar();
			         return 0;
			          break;		          
		}
	}
	return 0;
}

void push(struct node **head_ref ,int a)
{
	struct node *newnode,*temp;
	newnode = (struct node *)malloc(sizeof(struct node));
	temp= *head_ref;
	
	newnode->data = a;
	newnode->next = *head_ref;
	
	if(*head_ref !=NULL)
	{ 
	    while(temp->next != *head_ref)
		{
		temp=temp->next;
	    }
	   temp->next=newnode;  
	}
	else
	
	    {
		newnode->next = newnode;
	    }
    *head_ref = newnode;
    
    
}

void split_list(struct node *head, struct node **head1_ref, struct node **head2_ref)  /* If there are odd nodes in the circular list then
                                                                                      hare->next becomes head and for even nodes 
                                                                                    hare->next->next becomes head */
{
	struct node *tort;
	struct node *hare;
	
	tort=head;
	hare=head;
	
	if(head==NULL)
	
		return;
	
	
	while(hare->next->next != head && hare->next != head )
	{
		hare=hare->next->next;
		tort=tort->next; 
	}
	
	*head1_ref=head;
	
	*head2_ref=tort->next;
	
	
	if(hare->next->next == head)           /* If there are even elements in list then move tort */
	
	{
	hare=hare->next;
    }
	
	hare->next=tort->next;
	
	tort->next=head;
}

void display(struct node *head)
{
	struct node *temp;
	temp=head;
	if(head!=NULL)
	{
	    printf("\n");   
	    do
		{
		printf("%d ",temp->data);
		temp=temp->next;
	    }while(temp!=head);
	}
}

