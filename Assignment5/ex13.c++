#include<iostream>
using namespace std;

typedef struct tnode
{
     int data;
     struct tnode*left;
     struct tnode*right;
}tnode;

typedef struct node
{
   struct tnode*x;
   struct node *next;
}node;


class queue
{
   node *front,*rear;
   public:
queue()
{
   front=NULL;
   rear=NULL;
}

int isempty()
{
      if(front==NULL)
      return 1;
   return 0;
}
void enque(tnode *i)
{
   node *p;
   p=new node();
   p->x=i;
   p->next=NULL;
   
   if(front==NULL)
   {
     front=p;
     rear=p;
   }
   else
   {
     rear->next=p;
     rear=rear->next;
   }
}
tnode *deque()
{
  node *p;
  tnode *temp;
  p=front;
  temp=front->x;
  if(front==rear)
  {
     front=NULL;
     rear=NULL;
  }
  else
  {
     front=front->next;
  }
  delete p;
  return temp;
}
};



class tree
{
   tnode *t;
   public:
   tree()
   {
      t=NULL;
   }

tnode *insert(int x)
{
    tnode *p,*q,*r;
    
    p=new tnode();
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    
    if(t==NULL)
    return p;
    
    q=t;
    r=t;
while(r!=NULL)
{
    q=r;
    if(x<r->data)
    r=r->left;
    else
    r=r->right;
}
    if(x<q->data)
    q->left=p;
    else
    q->right=p;

    return t;
}



tnode *create()
{
int n,i,key;
cout<<" \n Enter the number of nodes - ";
cin>>n;
for(i=0;i<n;i++)
{
cout<<" \n Enter the data -";
cin>>key;
t=insert(key);
}
return t;
}

void inorder(tnode *t)
{
if(t!=NULL)
{
inorder(t->left);
cout<<"\t"<<t->data;
inorder(t->right);
}
}




void  leaf(tnode *T)
{

	if(T==NULL)
	return ;
	if(T->left==NULL && T->right==NULL)
	{	cout<<"\t"<<T->data;
			}	
  leaf(T->left);
  leaf(T->right);
	
}


void  parent(tnode *T)
{

	if(T==NULL)
	return ;
	if(T->left!=NULL && T->right==NULL)
	{	
	     cout<<"\t"<<T->data;
	     cout<<"\t"<<T->left->data;
	     cout<<"\n";
	}	
 
	if(T->left==NULL && T->right!=NULL)
	{	
	     cout<<"\t"<<T->data;
	     cout<<"\t"<<T->right->data;
	        cout<<"\n";
	}	
	
	
		if(T->left!=NULL && T->right!=NULL)
	{	
	     cout<<"\t"<<T->data;
	     cout<<"\t"<<T->left->data<<"\t"<<T->right->data;
	     cout<<"\n";
	}
	
	parent(T->left);
	parent(T->right);
}


int main()
{   
     int choice,key, cnt;
     tnode *root,*result, *rt;
     tree t;
     do
     {
      cout<<"\n Main menu "
            "\n 1.Create "
            "\n 2.Insert "
            "\n 3.create copy "
            "\n 4.Display Leaf nodes "
            "\n 5.Display parent node with child nodes "
            "\n 6.Exit \n Enter your choice - ";
      cin>>choice;
     switch(choice)
     {
      case 1:root=t.create();
                 break;
      case 2:cout<<"\n Enter the number to insert - ";
             cin>>key; 
             root=t.insert(key);
             break;

      case 3: cout<<"\n Copied tree - ";
	  		rt=t.copy(root);   
	  		t.inorder(rt);
	  		break;    
	 
	case 4:cout <<"\n Leaf nodes are  :-"<<endl;
              t.leaf(root);  
             break;   	 
	case 5:cout <<"\n Parent node with child nodes are  :-"<<endl;
              t.parent(root);  
             break;   	
             
      case 6:return 0;
      default:cout<<"\n Invalid choice !! Please enter your choice again."<<endl;
     } 
     }while(choice!=6);
}
