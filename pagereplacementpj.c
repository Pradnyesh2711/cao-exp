#include<stdio.h>

int i,j,n,f,a[50],frame[10];

void data()
{
    printf("\nEnter the Total Number of Pages: ");
    scanf("%d",&n);
    printf("Enter the Pages: ");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("Enter the Total Number of Frames: ");
    scanf("%d",&f);
}


void fifo()
{
    int c=0,k,avail;
    for(i=0;i<f;i++)
        frame[i]= -1;
        j=0;
        printf("Page Frames\n");
    for(i=1;i<=n;i++)
    {

        avail=0;
        for(k=0;k<f;k++)
            if(frame[k]==a[i])
                avail=1;
            if (avail==0)
            {
                frame[j]=a[i];
                j=(j+1)%f;
                c++;
                for(k=0;k<f;k++)
                printf("%d\t",frame[k]);
            }
            printf("\n");
    }
    printf("The No. of Page Fault are %d\n\n",c);
}


void lru()
{
    int q[20],c=0,c1,d,k=0,r,t,b[20],c2[20];
	q[k]=a[k];
	printf("\n\t%d\n",q[k]);
	c++;
	k++;
	for(i=0;i<f;i++)
        frame[i]= -1;
	for(i=1;i<n;i++)
	{
	    c1=0;
	    for(j=0;j<f;j++)
	    {
	        if(a[i]!=q[j])
	        c1++;
	    }
	    if(c1==f)
	    {
	        c++;
	        if(k<f)
	        {
	            q[k]=a[i];
	            k++;
	            for(j=0;j<k;j++)
	                printf("\t%d",q[j]);
	                printf("\n");
	        }
	        else
	        {
	            for(r=0;r<f;r++)
	            {
	                c2[r]=0;
	                for(j=i-1;j<n;j--)
	                {
	                    if(q[r]!=a[j])
	                    	c2[r]++;
	                    else
	                    break;
	                }
	        	}
	            for(r=0;r<f;r++)
	                b[r]=c2[r];
	                for(r=0;r<f;r++)
	                {
	                    for(j=r;j<f;j++)
	                    {
	                        if(b[r]<b[j])
	                        {
	                            t=b[r];
	                            b[r]=b[j];
	                            b[j]=t;
	                        }
	                    }
	                }
	                for(r=0;r<f;r++)
	                {
	                    if(c2[r]==b[0])
	                        q[r]=a[i];
	                        printf("\t%d",q[r]);
	                }
	                printf("\n");
	        }
	    }
	}
	printf("\nThe No. of Page Faults are %d\n",c);
}

int main()
{
    printf("Enter data:\n");
    data();
    
    printf("\t\tFIFO\n");
    fifo();
 
    printf("\t\tLRU\n");
    lru();
    
    return 0;
}
