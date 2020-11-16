void dinsert(node_pointer node, node_pointer newnode)
{
	newnode->llink = node;
	newnode->rlink = node->rlink;
	node->rlink->llink = newnode;
	node->rlink = newnode;
}

void ddelete(node_pointer node, node_pointer deleted)
{
	if (node == newnode)
	{
		printf("Delete of head node not permitted\n");
	}
	else
	{
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
	}
}