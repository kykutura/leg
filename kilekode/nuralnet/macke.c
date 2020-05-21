#include <stdio.h>
#include <math.h>

 double node_vadi_gange(double nodevadier[], int antal_noder, double nodevagte[]) {
	double node_sum = 0;
	for(int i = 0; i < antal_noder; i++){
		//printf("nodevadier[i] = %f nodevagte[i] = %f \n",nodevadier[i],nodevagte[i]);
		node_sum += nodevadier[i]*nodevagte[i];
	}
	return 1/(1+exp(-node_sum));
}

void neste_node_rake(int antal,int neaste_node_antal, int nes_nes_node_antal, double noder_og_vakt[][neaste_node_antal], double noder_og_vakt_neaste[][nes_nes_node_antal]) {
	double noden_vadi[antal];
	//printf("antal= %i \n",antal );
	
	for(int h = 0; h < antal; h++) {
		noden_vadi[h] = noder_og_vakt[h][0];
		//printf("noden_vadi[%i]=%f \n",h,noden_vadi[h]);
	}
	for(int i = 0; i < neaste_node_antal-1; i++) {
		double vaekt[neaste_node_antal];
		for(int i2 = 0; i2 < antal; i2++) {
			//printf("noder_og_vakt[i+1][i2]= %f\n",noder_og_vakt[i2][i+1]);
			vaekt[i2] = noder_og_vakt[i2][i+1];
		}
		//printf("noder_og_vakt_neaste[%i][0] =%f \n",i ,noder_og_vakt_neaste[i][0] );
		noder_og_vakt_neaste[i][0] = node_vadi_gange( noden_vadi, antal, vaekt);
	}
}

void afvilse_fejl(double resualtat[], double net_svar[],double afvilse[]) {
	lend=sizeof(resualtat)/sizeof(double);
	fot(int i = 0; i< lend; i++) {
		afvilse[i] = (resualtat[i]-net_svar[i])^2;
		//printf("afvilse[%i]= %i",i,afvilse[i]);
	}
}
double dif_sigmoud(double nodevadier[], int antal_noder, double nodevagte[],double node_kon = 0) {
	double node_sum = 0;
	for(int i = 0; i < antal_noder; i++){
		//printf("nodevadier[i] = %f nodevagte[i] = %f \n",nodevadier[i],nodevagte[i]);
		node_sum += nodevadier[i]*nodevagte[i];
	}
	node_sum += nod;
	return (exp(-node_sum)/(exp(-node_sum)^2+2*exp(-node_sum)+1);
}

void def_fejl(double resualtat[], double net_svar[],double def_afvilse[]) {
	lend=sizeof(resualtat)/sizeof(double);
	fot(int i = 0; i< lend; i++) {
		def_afvilse[i] = (resualtat[i]-net_svar[i])*2;
		//printf("afvilse[%i]= %i",i,afvilse[i]);
	}
}

double *oprathukommelse_netværk(int list[], int trening = 1;) {
	
	int len = 0;
	while(list[len]=='\0')
		len++;
	//finder lenden af listen
	
	int lengte = sizeof(double*)*len;
	double *list_neuroner = (double*)malloc(lengte)
	//laver en liste med 
	  
	for(int i = 0; i < len; i++) {
		list_neuroner[i] = (double*)malloc(sizeof(double)*list[i]*trening);
	}
	return list_neuroner;
	
}


double teaning_af_neukon_fost(double frjl[],double ) {
	
	
}

void traning(){
	
}

int main(){
	
	double netvarklag_0[3][4] = {0.2,-1,1,1,
								0.2,-1,1,1,
								0.2,-1,1,1};
	
	double netvarklag_1[3][3] = {1,1,1,
								1,1,1,
								1,1,1};
	
	double netvarklag_2[2][1] = {1,
								 1};
	
	double mider_tedi_var_0[3][4];
	double mider_tedi_var_1[3][3];
	double mider_tedi_var_2[2][1];
	
	double afvils[2];


	neste_node_rake(3,4,3,netvarklag_0,netvarklag_1);
	for(int i = 0; i < 3; i++)
		printf("%f,",netvarklag_1[i][0]);
	printf("\n");
	neste_node_rake(3,3,1,netvarklag_1,netvarklag_2);
	printf("\n");
	for(int i = 0; i < 2; i++)
		printf("%f,",netvarklag_2[i][0]);
	
	return 0;
}
