#include<stdio.h>
#include<stdlib.h>

/* 1 means bucket sort can be done */
/* 0 means quick sort should be taken */

struct node{
    double num;
    struct node *next;
};

struct main_struct{
    struct node *head;
    struct node *tail;
    int size;
};


/* function to add numbers into a struct main_struct */
void add(struct main_struct *q, double num, int position){
    
    if(q[position].head == NULL){
        q[position].head = (struct node *) malloc(sizeof(struct node));
        q[position].head->num = num;
        q[position].tail = q[position].head;
        q[position].tail->next = NULL;
    }
    else{
        q[position].tail->next = (struct node*) malloc(sizeof(struct node));
        q[position].tail = q[position].tail->next;
        q[position].tail->num = num;
        q[position].tail->next = NULL;
    }
}


/* function to add numbers by one by and check less than 4 rule */
int bucketSort(struct main_struct *q,double num, int n){
    
    int position = num * (n-1);
    
    add( q, num, position);
    
    q[position].size ++;
    
    if( q[position].size <= 3 )     return 1;
    return 0;
}


/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b){
	
    int temp = a->num;
    a->num = b->num;
    b->num = temp;
}


/* function used as a part of bucket sort */
void bubbleSort(struct node *start){

    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
  
    /* checking for empty list */
    if (start == NULL)
        return;
  	
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->num > ptr1->next->num)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


/* function to copy all numbers from linked list to an array */
void colapse(struct main_struct *q, double *arr, int n){
    
    int i=0,j=0;
    
    struct main_struct *temp = q;
    
    for(i=0;i<n;i++){
        
        struct node *temp = q[i].head;
        
        while(temp != NULL){
            arr[j] = temp->num;
            j++;
            temp = temp->next;
        }
    }
}


/* function needed for compare of stdlib's */
int compareIntegers(const void* first, const void* second){
	
    double x = *((double*)first), y =  *((double*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}


/* function to print array of double */
void printArray(double arr[],int n){
	
	int i;
	for(i=0;i<n;i++)    printf("%.12lf \n",arr[i]);
}


int main(){
    
	int n,flag = 1,i=0;
    double *readed;

    scanf("%d",&n);

    readed = (double *)malloc(sizeof(double)*n);
    
    /* reads input numbers from user or file */
    for (i=0;i<n;i++)
		scanf("%lf",&readed[i]);

    struct main_struct *bucket = (struct main_struct *) malloc (n*sizeof(struct main_struct));

	/* creates linked list */
    for(i=0;i<n;i++){
    	bucket[i].head = NULL;
    	bucket[i].tail = bucket[i].head;
        bucket[i].size = 0;
    }

	/* to add all numbers to a linked list and to test bucket <=3 rule */	
    i=0;
    while( flag == 1 && i < n ){
        flag = bucketSort(bucket,readed[i],n);
        i++;
    }
    flag = 1;
    /* does sorting according to output of bucketSott function */
    if ( !flag ){
        
        qsort(readed, n, sizeof(double), &compareIntegers);    
	    printArray(readed,n);
        printf("quick");
	}
	else{
        
    	double sorted[n];
		for(i=0;i<n;i++)	bubbleSort(bucket[i].head);
		
		colapse(bucket,sorted,n);
		printArray(sorted,n);
        printf("bucket");
	}
	return 0;
}
