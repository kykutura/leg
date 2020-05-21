#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>

int str_int(char h[]) {
	//får en string der kun er tal i og konvater den til int  
	int k = 0;
	for(int i = 0; h[i] != '\0' ;i++) {
		if(h[i] == ' ')
			;
		else {		
			k = k*10;
			k += (int)h[i]-(int)'0';
		}
	}
	//printf("k = %i\n",k);
	return k ;
}


int *csv_ar_int(FILE *b, int step) { 
	//h fil strømer , hukomlsen trin mengten 
	//får en strøm og læsser den føste linje og giver den som i pounter til en adrasse hvoer der er en liste at int s
	int len = 25;
	char mid[len];
	int *h = (int *)malloc((step)*sizeof(int));
	int sise = step;
	int i = 0;
	int i2 = 0;
	int ch = fgetc(b);
	for(int i8 = -1; i8 < len; i8++)
				mid[i8] = ' ';
	mid[0] = '0';
	while(ch !='\n'){
		
		if(ch==',') {
			mid[i2+1] = '\0';
			h[i]=str_int(mid);
			i++;
			for(int i3 = 0; i3 < len; i3++)
				{
				mid[i3] = ' ';
				}
			mid[len]= '\0';
			i2 = 0;
		}
		
		else{
			
			i2++;
			mid[i2]=(char)ch;
			//printf("mid = %s \n\n", mid);
		}
		
		if(i < sise){
			sise += step;
			h = (int *)realloc(h,sise*sizeof(int));
		}
		ch = fgetc(b);
	}
	
	mid[i2+1] = '\0';
	h[i]=str_int(mid);
	h[i+1] = 0;
	return h;
}



double** oprathukommelse_netvark(int list[], int trening) {
	
	int len = 0;
	while(list[len] != '\0')
		len++;
	
	//finder lenden af listen
	
	int lengte = sizeof(double *)*len;
	
	double **list_neuroner = (double **)malloc(lengte);
	
	list_neuroner[len] = '\0';
	
	//laver en liste med 
	
	int storlse = 0;
	printf("len = %i\n",len);
	
	
	for(int i = 0; i < len; i++) {
		
		if(i == len-1)
		{
			storlse = sizeof(double)*(list[i])*trening*2;
			
			*(list_neuroner+i) = (double*)malloc(storlse);
			*(*(list_neuroner+i)+((list[i]+2)*trening)) = (double)'\0';
			*(list_neuroner+i+1) = (double*)'\0';
		}
		else{
			//her opratter jeg en cubetrix vor føst ganger jeg størlsen af den doubler med en antal noder i dette led så ganges der med den væste node rakke plus en for at lave plas til forbindlsen mellem noderne. en til at slutte den så at man ved at listen er slut
			
			storlse = sizeof(double)*(list[i])*(list[i+1]+1)*trening+sizeof(double)*2;
			*(list_neuroner+i) = (double*)malloc(storlse);			
			*(*(list_neuroner+i)+(list[i])*(list[i+1]+1)*trening+1) = (double)'\0';
		}
		printf("storlse = %i\n",storlse);
	}
	return list_neuroner;
}

void print_pount_list_double_2(double **k, int rann, int list[], int trening) {
	for(int i = 0; *(k+i) != '\0'; i++) {
		for(int i2 = 0; i2 < (list[i])*(list[i+1]+1)*trening+1; i2++) {
			if(rann) {
				*(*(k+i)+i2) = (double)rand()/RAND_MAX;
			}
			else {
				printf("%f,",*(*(k+i)+i2));
			}			
		}
		printf("\n");
	}
}

int *netvwrks_liste_dupte(int list[], int trening){
	int len = 0;
	while(list[len] != '\0')
		len++;
	int *list_len = (int *)malloc(len*sizeof(int));
	for(int i = 0; i < len; i++)
		if(i==len-1)
			list[i]*trening*2;
		else 
			*(list_len+i) = (list[i])*(list[i+1]+1)*trening+1;
	return list_len;
}

void gem_pount_list_double(double **k, int list[], int trening, FILE *b) {
	for(int i = 0; list[i] != '\0'; i++)
		fprintf(b,"%i,",list[i]); 
	fprintf(b,"\n");
	
	for(int i = 0; *(k+i) != '\0'; i++) {
		for(int i2 = 0; i2 < (list[i])*(list[i+1]+1)*trening+1; i2++) {
			fprintf(b,"%f,",*(*(k+i)+i2));
		}
		fprintf(b,"\n");
	}
	fprintf(b,"\n");
}

void lode_netverk(double **k, int *len , FILE *b){
	
	for(int i = 0; *(k+i) != '\0'; i++) {
		
		for(int i2 = 0; i2 < len[i]; i2++) {
			fscanf(b,"%f,",*(k+i)+i2);
		}
	}
	
}


int main(int argc, char *argv[]) {
	
	char agu;
	char *fil_nav_data ="";
	char *fil_nav_netverk_in = "";
	char *fil_nav_netverk_ud = "";
	int nyt_netverk = 0; 
	int log = 0;
	int antal_traning = 1000;
	int gradiend_opdat_hastihed = 10;
	
	while((agu = getopt(argc, argv,"d:u:n:lb:a:r")) != EOF)
		switch(agu) {
			default:
				fprintf(stderr, "ukendt augoment: '%s'\n", optarg);
				return 1;
				break;
			
			case 'd':
				//file stien til traningens dataen
				fil_nav_data=optarg;
				break;
				
			case 'u':
				//fil stien til vor der neuralle netværk printer 
				fil_nav_netverk_ud=optarg;
				break;
				
			case 'l':
				//lav en log fil 
				log=1;
				break;
				
			case 'n':
				//fil stien til det hedet neuralle netværk
				fil_nav_netverk_in = optarg;
				break;
			
			case 'a':
				// hvormang gange traningen skal forsætte 
				antal_traning = str_int(optarg);
				//printf("antal_traning ='%i'\n",antal_traning);
				break;
				
			case 'b':
				// størles på gradien mengten får gradint vectorns posisjon bliver opdatered 
				gradiend_opdat_hastihed = str_int(optarg);
				break;
				
			case 'r':
				// vis det ikke er et net værk der hart væred tranet tidliger på op rat nye 		
				nyt_netverk = 1;
				break;
		}
	
	printf("d = %s \n",fil_nav_data);
	printf("u = %s \n",fil_nav_netverk_ud);
	printf("n = %s \n",fil_nav_netverk_in);
	printf("a = %i \n",antal_traning);
	printf("b = %i \n",gradiend_opdat_hastihed);
	
	if(log)
		printf("log er til \n");
	if(nyt_netverk)
		printf("skalgenrager et nyt netværk \n\n\n");
	//hænde det nuralle vet værks størlser
	int ter_byp = 2;
	
	FILE *nav_netverk_in = fopen(fil_nav_netverk_in,"r");
	int *net_stor = csv_ar_int(nav_netverk_in, 10);
	int *len = netvwrks_liste_dupte(net_stor,ter_byp);
	
	for(int i6 = 0; net_stor[i6] != '\0'; i6++)
		printf("net_stor[%i]=%i\n",i6,net_stor[i6]);
	
	for(int i6 = 0; len[i6] != '\0'; i6++)
		printf("len[%i]=%i\n",i6,len[i6]);
	//opratter hukomlsen til at holde det neuralle net verk
	
	
	double** neurnetted = oprathukommelse_netvark(net_stor,ter_byp);
	
	printf("%i\n",*neurnetted);
	if(nyt_netverk){
		print_pount_list_double_2(neurnetted, 1, net_stor, ter_byp);
		print_pount_list_double_2(neurnetted, 0, net_stor, ter_byp);
	}
	else {
		lode_netverk(neurnetted , )
		print_pount_list_double_2(neurnetted, 0, net_stor, ter_byp);
	}
	
	FILE *nav_netverk_ud = fopen(fil_nav_netverk_ud,"w");
	
	
	gem_pount_list_double(neurnetted, net_stor, 2, nav_netverk_ud);
	
	printf("hej");
	
	return 0;
}


