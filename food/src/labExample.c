struct node {
	char * value;
	struct node * next;
};
typedef struct node Node; 


Node *appendNode(Node *head)
{
	Node *add_me = createNode(); //this will be different for ours

	if (head == NULL)
	{
		return add_me; 
	}
	else //if the value of the next tmp is pointing to is null then point to that node, if not go to the next node, until temp_next is null. The last node. 
	{
		Node * tmp = head; 
		while (tmp->next != NUll)
		{
			tmp = tmp->next; 
		}
		//tmp->next = add_me; 
		return head; //return the head of the list, head is still untouched, the head of list. 
	}
}

void deleteList(Node * head)
{
//set head to the next node, this is a lagging cursor 
	Node *tmp;
	while (head != NULL)
	{
		tmp = head; 
		head = head->next;
		free(tmp->value);
		free(tmp);
	}
	return NULL;
	puts("Deleted the list");
}

void printList(Node * head)
{
	Node *tmp = jead;
	while (tmp != NULL)
	{
		
	}
}

//function to create a node. 

Node * cerateNode (char *val) {
	Node *tmp = malloc(sizeof(Node));
	tmp->value = val; 
	tmp->next = NULL; //if you don't set it to null it will be a garbage value; 
	return tmp; 
}


Node * deleteNode(Node * head)setting the head to the next and returning it. 
}



Node * removeFromFront (Node *head){    //sets the next node the head of the list, effectivly destroying the previous node
	Node * tmp;
	tmp = head;
	head = head->next;
	free(tmp);
	return head; 
}

Node * removeFromBack(Node * head) //sets the second last node's next to NULL, effectivly removing the node after it. 
{
	//Head->next = A    A->next = X   X->NULL
	//Head->next->next = x
	//Hea
	if (tmp->next->next->next == NULL)


}