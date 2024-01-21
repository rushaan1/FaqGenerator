#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct FAQ
{
	char question[5000];
	char answer[10000];
	bool important;
};

void main()
{
	int n = 0;
	printf("How many FAQs would you like to create?\n");
	scanf("%d", &n); 
	getchar();
	struct FAQ faq[n];
	struct FAQ *ptrFaq = faq;
	char title[500];
	printf("Supply a title for the FAQs: \n");
	fgets(title, sizeof(title), stdin);
	int length4 = strlen(title);
	if (title[length4 - 1] == '\n') {
        		title[length4 - 1] = '\0';
    		}
	for (int i = 0; i<n; i++)
	{
		char input[5000]; 
		printf("Enter Question:\n ");
		fgets(input, sizeof(input), stdin);
		int length2 = strlen(input);
    		if (input[length2 - 1] == '\n') {
        		input[length2 - 1] = '\0';
    		}

		char input2[5000]; 
		printf("\nEnter Answer:\n ");
		fgets(input2, sizeof(input2), stdin);
		int length = strlen(input2);
    		if (input2[length - 1] == '\n') {
        		input2[length - 1] = '\0';
    		}

		char imp;
		printf("\nIs that important? (Y/N)\n");
		scanf("%c", &imp);
		getchar();
		if (imp=='Y')
		{ 
			(*(ptrFaq+i)).important = true;
		}
		else if (imp=='N')
		{
			(*(ptrFaq+i)).important = false;
		} 
		char cinput[5000];
		char cinput2[10000] = "A:";
		sprintf(cinput,"%d.", i+1);
		strcat(cinput,input);
		strcat(cinput2,input2);  
		strcpy((*(ptrFaq+i)).question, cinput); 
		strcpy((*(ptrFaq+i)).answer, cinput2); 
	}

	char filename[500]; 

    sprintf(filename, "%s.txt", title);

    FILE *fptr = fopen(filename, "w");

	for (int i = 0; i<n; i++)
	{
		struct FAQ ptrfaq = (*(ptrFaq+i));
		fprintf(fptr, "%s\n", ptrfaq.question);
        fprintf(fptr, "%s\n", ptrfaq.answer);
        if (ptrfaq.important) 
		{ 
			fprintf(fptr, "Important: Yes\n");
		}
		else
		{
			fprintf(fptr, "Important: No\n");
		}
        fprintf(fptr, "\n"); 
	}
    fclose(fptr);
}
