#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *newNode(int  a)
{
	struct node *temp = new struct node();
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void createLL(struct node **refHead,int x)
{
	struct node *temp = newNode(x);
	if(*refHead!=NULL)
		temp->next = *refHead;
	*refHead = temp;
}

void printLL(struct node *head)
{
	if(head==NULL)
		cout<<"LL is empty\n";
	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void moveNodes(struct node **refLL3,struct node **refSource)
{
	struct node *temp = *refSource;
	*refSource = (*refSource)->next;
	temp->next = *refLL3;
	*refLL3 = temp;	
	// now we have moved the tail node to the last node, still pending is moving it to NULL node
	// this is done by refLL3 = &(*refLL3)->next; in the calling code

}

struct node *UnionofLLs(struct node *LL1,struct node *LL2)
{
	struct node *Union = NULL;
	struct node **refU = &Union;
	while(1)
	{
		if(LL1==NULL || LL2==NULL)
			break;

		if(LL1->data == LL2->data)
		{
			struct node *temp = newNode(LL1->data);
			*refU = temp;
			refU = &(*refU)->next;
			
			LL1 = LL1->next;
			LL2 = LL2->next;
		}
		else if(LL1->data < LL2->data)
			LL1 = LL1->next;
		else if(LL2->data < LL1->data)
			LL2 = LL2->next;
		
	}
	return Union;
}

struct node *IntersectionofLLs(struct node *LL1,struct node *LL2)
{
	struct node *Inter = NULL;
	struct node **refI = &Inter;
	while(1)
	{
		if(LL1==NULL || LL2==NULL)
			break;

		if(LL1->data == LL2->data)
		{
			struct node *temp = newNode(LL1->data);
			*refI = temp;
			
			LL1 = LL1->next;
			LL2 = LL2->next;
		}
		else if(LL1->data < LL2->data)
		{
			struct node *temp = newNode(LL1->data);
			*refI = temp;

			LL1 = LL1->next;
		}
		else if(LL2->data < LL1->data)
		{
			struct node *temp = newNode(LL2->data);
			*refI = temp;

			LL2 = LL2->next;
		}
		refI= &(*refI)->next;
		
	}
	struct node *LLtemp = NULL;
	if(LL1==NULL)
		LLtemp = LL2;
	if(LL2==NULL)
		LLtemp = LL1;
	while(LLtemp!=NULL)
	{
		struct node *temp = newNode(LLtemp->data);
		*refI = temp;
		refI = &(*refI)->next;
		LLtemp = LLtemp->next;
	}
	return Inter;
}

int main()
{
	int arr1[] = {5,7,10,14,16};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	struct node *LL1=NULL;
	for(int i=n1-1 ; i>=0 ; i--)
		createLL(&LL1,arr1[i]);

	int arr2[] = {5,6,11,12,14};
	int n2 = sizeof(arr2)/sizeof(arr2[0]);
	struct node *LL2 = NULL;
	for(int i=n2-1 ; i>=0 ; i--)
		createLL(&LL2,arr2[i]);

	printLL(LL1);
	printLL(LL2);

	struct node *Union = NULL;
	Union = UnionofLLs(LL1,LL2);
	printLL(Union);	

	struct node *Intersection = NULL;
	Intersection = IntersectionofLLs(LL1,LL2);
	printLL(Intersection);

	cin.get();
	cin.get();
	return 0;
}

