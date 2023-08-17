#include <stdio.h>

const float COSTO_MINUTO_VODAFONE = 0.25;
const float COSTO_MINUTO_WINDTRE = 0.30;
const float COSTO_MINUTO_TIM = 0.23;

const float COSTO_RISPOSTA_VODAFONE = 0.20;
const float COSTO_RISPOSTA_WINDTRE = 0.20;
const float COSTO_RISPOSTA_TIM = 0.20;

const float COSTO_SMS_VODAFONE = 0.29;
const float COSTO_SMS_WINDTRE = 0.30;
const float COSTO_SMS_TIM = 0.19;

const float COSTO_GB_VODAFONE = 1.20; 
const float COSTO_GB_WINDTRE = 0.99;
const float COSTO_GB_TIM = 4.00; //2 euro al giorno per ogni 500 mb, quindi 4 euro al GBù


//PROTOTIPO CALCOLO_CHIAMATE
float calcolo_chiamate(float,float, float, int);

//PROTOTIPO CALCOLO_SMS
float calcolo_sms(float, int);
 
//PROTOTIPO CALCOLO_DATI
float calcolo_dati(float, float);

//PROTOTIPO TOT_COSTI
float tot_costi(float, float, float);



int main () {
	float minuti_telefonate, consumo_gb;
	int n_telefonate, n_sms;
	
	float costo_chiamate_tim, costo_sms_tim, costo_dati_tim;
	float costo_chiamate_vodafone, costo_sms_vodafone, costo_dati_vodafone;
	float costo_chiamate_windtre, costo_sms_windtre, costo_dati_windtre;
	
	float tot_tim, tot_windtre, tot_vodafone;
	
	
	
	do{
		printf("Quanti minuti stai in chiamata? (possibilità di utilizzare anche le cifre decimali)\n");
		scanf("%f", &minuti_telefonate);
	}while(minuti_telefonate<0);
	
		do{
		printf("Quante telefonate fai al giorno?\n");
		scanf("%d", &n_telefonate);
	}while(n_telefonate<0);
	
		do{
		printf("Quanti messaggi invii al giorno?\n");
		scanf("%d", &n_sms);
	}while(n_sms<0);
	
		do{
		printf("quanti GB consumi al giorno? \n");
		scanf("%f", &consumo_gb);
	}while(consumo_gb<0);
	
	
	
	//ALGORITMO
	
	printf("CALCOLO TARIFFA\n\n");
	

	
	//TIM
	printf("Tariffa tim: \n");
	
	costo_chiamate_tim=calcolo_chiamate(COSTO_MINUTO_TIM, minuti_telefonate, COSTO_RISPOSTA_TIM, n_telefonate);
	printf("chiamate = %f\n", costo_chiamate_tim);
	
	costo_sms_tim=calcolo_sms(COSTO_SMS_TIM, n_sms);
	printf("sms = %f\n", costo_sms_tim);
	
	costo_dati_tim=calcolo_dati(COSTO_GB_TIM, consumo_gb);
	printf("dati = %f\n", costo_dati_tim);
	
	tot_tim=tot_costi(costo_chiamate_tim, costo_sms_tim, costo_dati_tim);
	printf("totale = %f\n", tot_tim);
	
	printf("\n\n");
	
	
	//WINDTRE
	printf("Tariffa windtre: \n");
	costo_chiamate_windtre=calcolo_chiamate(COSTO_MINUTO_WINDTRE, minuti_telefonate, COSTO_RISPOSTA_WINDTRE, n_telefonate);
	printf("chiamate =%f\n", costo_chiamate_windtre);
	
	costo_sms_windtre=calcolo_sms(COSTO_SMS_WINDTRE, n_sms);
	printf("sms = %f\n", costo_sms_windtre);
	
	costo_dati_windtre=calcolo_dati(COSTO_GB_WINDTRE, consumo_gb);
	printf("dati = %f\n", costo_dati_windtre);
	
	tot_windtre=tot_costi(costo_chiamate_windtre, costo_sms_windtre, costo_dati_windtre);
	printf("totale = %f\n", tot_windtre);
	
	printf("\n\n");
	
	//VODAFONE
	printf("Tariffa vodafone: \n");
	costo_chiamate_vodafone=calcolo_chiamate(COSTO_MINUTO_VODAFONE, minuti_telefonate, COSTO_RISPOSTA_VODAFONE, n_telefonate);
	printf("chiamate = %f\n", costo_chiamate_vodafone);
	
	costo_sms_vodafone=calcolo_sms(COSTO_SMS_VODAFONE, n_sms);
	printf("sms = %f\n", costo_sms_vodafone);
	
	costo_dati_vodafone=calcolo_dati(COSTO_GB_VODAFONE, consumo_gb);
	printf("dati = %f\n", costo_dati_vodafone);
	
	tot_vodafone=tot_costi(costo_chiamate_vodafone, costo_sms_vodafone, costo_dati_vodafone);
	printf("totale = %f\n", tot_vodafone);
	
	printf("\n\n");
	
	//OUTPUT
	if(tot_tim<tot_vodafone && tot_tim<tot_windtre){
		printf("tim e' la compagnia migliore con un costo giornaliero di %.2f euro ", tot_tim);
	}else if(tot_windtre<tot_vodafone){
		printf("windtre e' la compagnia migliore con un costo giornaliero di %.2f euro", tot_windtre);
	}else printf("vodafone e' la compagnia migliore con un costo giornaliero di %.2f euro", tot_vodafone);
}


//FUNZIONE CALCOLO CHIAMATE
float calcolo_chiamate(float costo_minuto_compagnia,float minuti_telefonate, float scatto_risposta_gestore, int n_telefonate){
	float tot=0;
	tot=(costo_minuto_compagnia * minuti_telefonate) + (scatto_risposta_gestore * n_telefonate); 
	return tot;
	
}

//FUNZIONE CALCOLCO SMS
float calcolo_sms(float costo_sms_gestore, int n_sms){
	float tot=0;
	tot=costo_sms_gestore * n_sms;
	return tot;	
}

//FUNZIONE CALCOLCO DATI
float calcolo_dati(float costo_gb_gestore, float consumo_gb){
	float tot=0;
	tot=(costo_gb_gestore * consumo_gb);
	return tot;
	
}

//FUNZIONE TOT COSTI
float tot_costi(float costo_chiamate, float costo_sms, float costo_dati){
	float tot=costo_chiamate + costo_sms + costo_dati;
	return tot;
}

