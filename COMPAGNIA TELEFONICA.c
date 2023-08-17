/*
	Name: 
	Copyright: 
	Author: Fontana Andrea 3ia
	Date: 10/07/23 18:24
	Description: Con Vodafone 25 New le chiamate sono a 25 centesimi al minuto, con scatto alla risposta di 20 centesimi, SMS a 29 centesimi l'uno e 1,20 euro al giorno per ogni GB Internet consumato.

	Con WIND3 la connessione dati viene tariffata a 0,99€ al giorno per 1 GB: tale costo viene addebitato solo in caso di effettivo utilizzo del traffico dati; WINDTRE Easy: chiamate a 30 cent/minuto, con uno scatto alla risposta di 20 cent, e sms a 30 cent l'uno.

	TIM Base New : chiamate a 23 cent/minuto, con scatto alla risposta di 20 cent, 19 cent per sms e connessione Internet a 2€ al giorno per 500 MB.

	Qual è la compagnia più conveniente dati i propri dati del traffico giornaliero?
	
	
	
	IPOTESI
	-considero il tempo di chiamate in minuti, anche con numeri decimali
	-considero il traffico dati che consuma l'utente espresso in MB, 
	-le costanti sono espresse in: cent/minuto, cent/sms, cent/GB
	-considero che l'utente inserisca al massimo 2 cifre dopo la virgola
	-ipotizzo che la durata di una chiamata sia maggiore di 0
	
	
	
	ANALISI1
	-Chiedo all'utente di scrivere i propri dati di traffico giornaliero nella forma: minuti totali di chiamate, numero chiamate, numeri di sms, MB di traffico
	-effettuo le conversioni, in modo da avere tutti i criteri con la stessa unità di misura
	-calcolo i vari costi, attraverso delle funzioni per ogni compagnia telefonica
	-comparo i vari costi, attraverso una funzione, in modo da trovare la compagnia più conveniente
	-restituisco in output la compagnia più conveniente con i costi per i vari servizi
	
	ANALISI2
	-Chiedo all'utente di scrivere i propri dati di traffico giornaliero nella forma: minuti di chiamate, numeri di sms, MB di traffico
	-effettuo le conversioni, in modo da avere tutti i criteri con la stessa unità di misura
	-calcolo i vari costi, attraverso delle funzioni per topologia di traffico (rete, chiamate, sms)
	-comparo i vari costi, attraverso una funzione, in modo da trovare la compagnia più conveniente
	-restituisco in output la compagnia più conveniente con i costi per i vari servizi
	
	
	FORMULE
	-calcolo_costo_Chiamate: (COSTO_MINUTO_GESTORE * minuti_telefonate) + (SCATTO_RISPOSTA_GESTORE*n_telefonate)
	-calcolo_costoSms: COSTO_SMS_GESTORE *n_sms
	-cambio_mb_gb: consumo_mb/1024;
	-calcolo_costo_Dati: consumo_gb * COSTO_AL_GB
	
	DATI IN
	-minuti_telefonate (float) = durata in minuti delle chiamate effetuate (es 90 sec = 1.5 min)
	-n_telefonate (float) = numero di telefonate che esegue l'utente
	-n_sms (float) = numero di sms totali che invia l'utente
	-consumo_mb (float) = consumo in MB che esegue l'utente al giorno
	
	DATI OUT
	-migliore_compagnia (stringa) = compagnia più vantaggiosa
	
	
	CONTROLLO INPUT
	-minuti_telefonate>0
	-n_telefonate>0
	-n_sms>0
	-consumo_MB>0
	
	VARIABILI DI SUPPORTO
	-costo_chiamate_gestore (float) = variabile che contiene il costo totale delle varie chiamate che l'utente effettua in un giorno
	-costo_sms_gestore (float) = variabile che contiene il costo totale per gli sms che invia l'utente al giorno
	-costo_dati_gestore (float) = variabile che contiene il costo totale per il traffico consumato dall'utente in una giornata
	
	
	COSTANTI DI SUPPORTO
	-COSTO_MINUTO_GESTORE (float): costo al minuto per una telefonata
	-SCATTO_RISPOSTA_GESTORE (float): costo dello scatto alla risposta
	-COSTO_SMS_GESTORE (float): costo per 1 sms
	-COSTO_AL_GB (float): costo al GB
	
	
	TEST
	IN					OUT
	0	0	0	0		0
	10	2	4	8		12.52 - Windtre
	
	
		
	
	
	
	
*/

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

