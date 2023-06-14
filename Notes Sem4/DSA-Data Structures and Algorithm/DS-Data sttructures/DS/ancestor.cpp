int ancestor(treenode *r,int data)
{
	if(r==NULL) return(0);
	if(r->data==data)	return(1);
	if(ancestor(r->left,data)||ancestor(r->right,data))
	{
		cout<<r->data<<" ";
		return(1);
	}
	return(0);
}

}