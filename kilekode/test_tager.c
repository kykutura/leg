#include <stdio.h>
int main() {
	int inkoder[2]= {3,1};
	int rake[4]={0,2,3,1};
	int rake2[4]={1,3,2,0};
	
	int teller = 0;
	int tel_tidlig = teller;
	
	for(int i=0; i<4; i++) {
		if(inkoder[1] == rake[(i)%4] && inkoder[0] == rake[(i+1)%4])
		  teller++;
		
		if(inkoder[0] == rake[(i)%4] && inkoder[1] == rake[(i+1)%4])
		  teller--;
	printf("-- %i %i == %i %i\n",inkoder[1],inkoder[0],rake[(0-i-1)%5],rake[(0-i-2)%5]);
	printf("++ %i %i == %i %i\n",inkoder[1],inkoder[0],rake[(i)%4],rake[(i+1)%4]);
	}
	if(teller==tel_tidlig)
		teller+=1000000;
	
	printf("\n \n \n \n \n %i",teller);
	return 0;
}
