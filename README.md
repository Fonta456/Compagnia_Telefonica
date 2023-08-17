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
