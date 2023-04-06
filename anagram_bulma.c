#include <stdio.h>
#include <string.h>

int kontrol(char* dizi1,char* dizi2); //tan�mlanm�� bir fonksiyonun bildirimini yapt�k

int main (){
	// bu kodda kullan�c�dan 10 tane kelime al�p her bir kelimenin farkl� anagram�n� yazd�rd�k
	int i,j;
	char kelimeler[10][30];		// kullan�c�dan al�nan kelimelerin tutulaca�� iki boyutlu dizi tan�mlad�k
	// kullan�c�ya yapaca�� i�lemleri bildirdik
	printf("**********ANAGRAM BULMA**********\n");
	printf("Anagramlarinin eslestirilmesini istediginiz 10 kelimeyi giriniz!\n");
	// d�ng� kullanarak kullan�c�dan kelimeleri ald�k	
	for (i=0; i<10;i++){
		printf(">>> ");
		scanf("%s",kelimeler[i]);
	}
	printf("*********************************");
	printf("\nGirdiginiz kelimelerden birbirinin anagrami olanlar!\n");
	// bu d�ng� sayesinde her bir eleman�n anagram� bulunur
	for (i = 0; i < 9; i++) {	/* bu k�s�mda d�ng�y� son elemana kadar d�nd�r�yoruz 
								ama son eleman� kar��la�t�racak bir eleman olmad��� i�in onu alm�yoruz*/
   		for ( j = i + 1; j < 10; j++) {	/*bu k�s�mda da d�ng� ilk eleman� almayacak �ekilde ba�lar 
		   						ve onu kendinden bir �nceki elemanla kontrol eder*/
    		if (kontrol(kelimeler[i], kelimeler[j]) ){		/* if yap�s�nda kontrol fonksiyonuna elemanlar s�rayla g�nderilir 
															kontrol fonksiyonu 1 de�eri g�nderirse �al���r g�ndermezse �al��may�p d�ng�ye devam eder*/
        		printf(">>> %s %s\n", kelimeler[i], kelimeler[j]);	// fonksiyonun �al��t��� durumda onun 1 d�nd�rmesini sa�layan kelimler yazd�r�l�lr.
      		
			  }
   		 
			}
 	 }	
	return 0;
}
	// if i�inde ge�erli olmas� i�in 1 veya 0 g�nderilecek o y�zden int olarak tan�mlad�k
int kontrol(char* dizi1 , char* dizi2){		// parametre olarak kar��la�t�ralacak kelimeler tan�mlad�k
	int i;
	// her bir harfin ka� kez ge�ti�ini saymas� i�in her bir kelime i�in bir dizi tan�mlad�k 
	// bu diziler ASCII tablosunda bulunan alfabe harflerine g�re boyut ald�
	int dizi1_harfler[26] = {0};
	int dizi2_harfler[26] = {0};
	
	for(i=0 ; i< strlen(dizi1) ; i++){	// g�nderilen kelimenin uzunlu�u kadar d�ner
		int harf = dizi1[i];			// kelimenin ilk harfinin ASCII tablosundaki tam say� kar��l��� harf de�i�kenine aktar�l�r
		dizi1_harfler[ harf - 'a']++;	/* harf de�i�keninin "a" harfine uzakl��� hesaplan�p alfabedeki ka��nc� harf oldu�u bulunur
										ve o index 1 artt�r�l�r b�ylce d�ng� sonuna kadar bu dizi kelimedeki hangi harften ka� tane oldu�unu tutar*/
	}
	// yukar�daki for da yap�lan t�m i�lem g�nderilen bu ikinci kelime i�in yap�l�r ve d�ng� tamamlan�r
	for(i=0 ; i< strlen(dizi2) ; i++){	
		int harf = dizi2[i];
		dizi2_harfler[ harf - 'a']++;
	}
	
	for(i=0 ; i<26 ; i++){	
		if (dizi1_harfler[i] != dizi2_harfler[i]) /* alfabetik s�ra �eklinde her harf dola��l�r ve bunlar�n ayn� olmad��� duruma bak�l�r 
													bu durumda 0 d�nd�r�l�r ve main i�inden �a��r�ld���nda yanl�� oldu�u anla��ls�n*/
			return 0 ;
	}
	// for i�inde hi�bir e�it olmama durumu ger�ekle�medi�inde bu kelimelerin anagram oldu�u anla��l�r ve 1 de�eri d�ner 
	return 1 ;
}







