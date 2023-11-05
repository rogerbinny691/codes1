#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>
  #include <sys/wait.h>
int split ( int a[ ], int lower, int upper )
{
    int i, p, q, t ;
    p = lower + 1 ;
    q = upper ;
    i = a[lower] ;
    while ( q >= p )
    {
        while ( a[p] < i )
            p++ ;

        while ( a[q] > i )
            q-- ;

        if ( q > p )
        {
            t = a[p] ;
            a[p] = a[q] ;
            a[q] = t ;
        }}
    t = a[lower] ;
    a[lower] = a[q] ;
    a[q] = t ;

    return q ;
}
void quickSort(int a[],int lower, int upper){
     int i ;
        if ( upper > lower )
        {
            i = split ( a, lower, upper ) ;
            quickSort ( a, lower, i - 1 ) ;
            quickSort ( a, i + 1, upper ) ;
        }
}
void bubblesort(int a[], int size){
int temp;
   for(int i = 0 ; i < size ; i++ ){
                        for(int j = 0 ; j < size-i-1 ; j++){
                                if(a[j] > a[j+1])
                                {
                                        temp = a[j];
                                        a[j] = a[j+1];
                                        a[j+1] = temp; }}}
}
    void display(int a[],int size){
        int i;
        for(i=0;i<size;i++){
            printf("%d\t\t",a[i]);
        }
        printf("\n");
    }
int main()
{
	 int pid, child_id;
        int size,i,status;
        //   Input the Integers to be sorted   
        printf("Enter the number of Integers to Sort::::\t");
        scanf("%d",&size);
        int a[size];
        int pArr[size];
        int cArr[size];
        for(i=0;i<size;i++)
        {
            printf("Enter number %d:",(i+1));
            scanf("%d",&a[i]);
            pArr[i]=a[i];
            cArr[i]=a[i];
        }
      printf("Your Entered Integers for Sorting\n");
        display(a,size);
       
       //Display pid
       pid=getpid();
       printf("Parent process id is %d\n",pid);
       
       //Create a child process
       printf("Child process FORKED \n");
       child_id=fork();
        if( child_id < 0){

            /* Process Creation Failed ... */
   
             printf("\nChild Process Creation Failed!!!!\n");
                    exit(-1);
            }
   	else if(child_id==0)
	{
		printf("Child process called....\n");
		printf("id of child process %d \n",getpid());
		printf("Parent of child process is %d \n",getppid());
		printf("Sorting by child process by bubble sort\n");
		bubblesort(cArr, size-1);
            	printf("The sorted List by Child::\n");
            	display(cArr,size);
            	printf("Child Process Completed ...\n");
 	}
	else
	{
        wait(NULL);
		printf("Parent process is being called\n");
		pid=getpid();
		printf("Pid of parent process %d \n",pid);
		 printf("\nparent of parent process is %d \n",getppid());
		printf("Sorting by parent process by quick sort \n");
		quickSort(pArr,0,size-1);
            	printf("The sorted List by Parent::\n");
            	display(pArr,size);
            	printf("Parant Process Completed ...\n")  ;     	//wait(10);}						
       return 0;
       }											
}