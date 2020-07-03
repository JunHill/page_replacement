#include <stdio.h>
//fifo
int main()
{	
	int pages[20], frames[20],np, nf, i, j, faults = 0, q ,k, temp[20] = {0};
    int matrix[20][20];
    int counter = 0, time[20] = {0};
	int flag1, flag2, flag3, pos, min, max, mini;
    int choice = 1;
	printf("---Page Replacement algorithm---\n");
	printf("1. Default reference sequence\n");
	printf("2. Manual input sequence\n");
	printf("Enter your choice: \n");
	scanf("%d", &choice);
	if(choice == 1){
	    pages[0]=1;
	    pages[1]=8;
	    pages[2]=5;
	    pages[3]=2;
	    pages[4]=0;
	    pages[5]=7;
	    pages[6]=5;
	    pages[7]=0;
	    pages[8]=0;
	    pages[9]=0;
	    pages[10]=7;
	    np = 11;
	    for(i=0;i<np;i++)
    	{
    		matrix[0][i] = pages[i];
    	}
	}
	else
    {
    	printf("Enter the no. of pages: \n");
    	scanf("%d", &np);
    	printf("Enter the pages: \n");
    	for(i=0;i<np;i++)
    	{
    		scanf("%d", &pages[i]);
    		matrix[0][i] = pages[i];
    	}
    }
    printf("---Page Replacement algorithm---\n");
    printf("Enter the no. of frames: \n");
	scanf("%d", &nf);
    //
    int Continue = 1;
    while(Continue == 1){
        printf("\n---------- Page Replacement alogrithm ----------");
        printf("\n1. FIFO algorithm\n2. OPT algorithm\n3. LRU algorithm\n");
        int ans = 0;
        printf("\nChoose your algorithm: ");
        scanf("%d", &ans);
        switch(ans){
        case 1:
            for(i=1;i<nf+2;i++)
        	    for(j=0;j<np;j++)
        	        matrix[i][j] = 0;
            faults = 0;
            for(i=0;i<20;i++)
		        frames[i] = -1;
            int x=0,y=0;
        	for(i=0; i<np; i++)
        	{
        		flag1 = 0;
        		flag2 = 0;
        		for(j=0; j<nf; j++)
        		{
        			if(frames[j] == pages[i])
        			{
        				flag1 = flag2 = 1;
        				break;
        			}
        		}
        		if(flag1 == 0)
        		{
        			for(j=0; j<nf; j++){
        			if(frames[j] == -1)
        			{
        				faults++;
        				frames[j] = pages[i];
        				matrix[nf+1][i] = 1;
        				temp[y] = j;
        				y++;
        				flag2 = 1;
        				break;
        			}
        			}
        		}
        		if(flag2 == 0)
        		{
                    frames[temp[x]] = pages[i];
                    temp[y] = temp[x];
                    x++;
                    y++;
        			faults++;
        			matrix[nf+1][i] = 1;
        		}
        		for(k=0; k<nf; k++)
        		{
        			matrix[k+1][i] = frames[k];
        		}
        	}
        	printf("FIFO ALGORITHM\n");
        	for(i = 0; i <= nf + 1; i++)
        	{
        	    for(j = 0; j < np; j++)
                {
                    if (matrix[i][j] == -1){
                        printf("    ");
                    }
                    else if (i == nf+1 && matrix[i][j] == 1){
                        printf("  * ");
                    }
                    else if (i == nf+1 && matrix[i][j] == 0){
                        printf("    ");
                    }
                    else {
                        printf("%3d ", matrix[i][j]);
                    }
                }
                printf("\n");
        	}
        	printf("Number of Page Fault: %d\n", faults);
	            break;
	    case 2:
    	    for(i=1;i<nf+2;i++)
        	    for(j=0;j<np;j++)
        	        matrix[i][j] = 0;
	        faults = 0;
            for(i=0;i<20;i++)
		        frames[i] = -1;
        	for(i=0; i<np; i++)
        	{
        		flag1 = 0;
        		flag2 = 0;
        		for(j=0; j<nf; j++)
        		{
        			if(frames[j] == pages[i])
        			{
        				flag1 = flag2 = 1;
        				break;
        			}
        		}
        		if(flag1 == 0)
        		{
        			for(j=0; j<nf; j++){
        			if(frames[j] == -1)
        			{
        				faults++;
        				frames[j] = pages[i];
        				matrix[nf+1][i] = 1;
        				flag2 = 1;
        				break;
        			}
        			}
        		}
        		if(flag2 == 0)
        		{
        			flag3 = 0;
        			for(j=0;j<nf;j++)
        			{
        				temp[j] = -1;
        				for(k = i+1; k < np; k++)
        				{
        					if(frames[j] == pages[k])
        					{
        						temp[j] = k;
        						break;
        					}
        				}
        			}
        			for(j=0; j<nf; j++){
        				if(temp[j] == -1)
        				{
        					pos = j;
        					flag3 = 1;
        					break;
        				}
        			}
        			if(flag3 == 0)
        			{
        			max = temp[0];
        			pos = 0;
        			for(q = 1; q<nf; q++)
        			{
        				if(max < temp[q])
        				{
        					max = temp[q];
        					pos = q;
        				}
        			}
        			}
        			frames[pos] = pages[i];
        			faults++;
        			matrix[nf+1][i] = 1;
        		}
        		for(k=0;k<nf;k++)
        		{
        			matrix[k+1][i] = frames[k];
        		}
        	}
        	printf("OPT ALGORITHM\n");
        	for(i = 0; i <= nf + 1; i++)
        	{
                for(j = 0; j < np; j++)
                {
                    if (matrix[i][j] == -1){
                        printf("    ");
                    }
                    else if (i == nf+1 && matrix[i][j] == 1){
                        printf("  * ");
                    }
                    else if (i == nf+1 && matrix[i][j] == 0){
                        printf("    ");
                    }
                    else {
                        printf("%3d ", matrix[i][j]);
                    }
                }
                printf("\n");
            }
        	printf("Number of Page Fault: %d\n", faults);
	            break;
	    case 3:
    	    for(i=1;i<nf+2;i++)
        	    for(j=0;j<np;j++)
        	        matrix[i][j] = 0;
	        faults = 0;
	        for(i=0;i<20;i++)
		        frames[i] = -1;
        	for(i=0; i<np; i++)
        	{
        		flag1 = 0;
        		flag2 = 0;
        		for(j=0; j<nf; j++)
        		{
        			if(frames[j] == pages[i])
        			{
        				counter++;
        				time[j] = counter;
        				flag1 = flag2 = 1;
        				break;
        			}
        		}
        		if(flag1 == 0)
        		{
        			for(j=0; j<nf; j++)
        			{
        				if(frames[j] == -1)
        				{
        					counter++;
        					faults++;
        					matrix[nf+1][i] = 1;
        					time[j] = counter;
        					frames[j] = pages[i];
        					flag2 = 1;
        					break;
        				}
        			}
        		}
        		if(flag2 == 0)
        		{	
        			mini = time[0];
        			pos = 0;
        			for(k=1;k<nf;k++)
        			{
        				if(mini > time[k]){
        					mini = time[k];
        					pos = k;
        				}
        			}
        			counter++;
        			faults++;
        			matrix[nf+1][i] = 1;
        			time[pos] = counter;
        			frames[pos] = pages[i];
        		}
        		for(q=0;q<nf;q++)
        		{
        			matrix[q+1][i] = frames[q];
        		}
        	}
        	printf("LRU ALGORITHM\n");
        	for(i = 0; i <= nf + 1; i++)
        	{
                for(j = 0; j < np; j++)
                {
                    if (matrix[i][j] == -1){
                        printf("    ");
                    }
                    else if (i == nf+1 && matrix[i][j] == 1){
                        printf("  * ");
                    }
                    else if (i == nf+1 && matrix[i][j] == 0){
                        printf("    ");
                    }
                    else {
                        printf("%3d ", matrix[i][j]);
                    }
                }
                printf("\n");
            }
        	printf("Number of Page Fault: %d\n", faults);
	            break;
        }
        printf("\n--- Continue? --- ");
        printf("\n1. Yes \n0. No\n");
        scanf("%d", &Continue);
        if(Continue == 0){
            printf("Exit");
        }
    }
	return 0;
}