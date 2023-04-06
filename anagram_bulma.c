#include <stdio.h>
#include <string.h>

int kontrol(char* dizi1,char* dizi2); //tanýmlanmýþ bir fonksiyonun bildirimini yaptýk

int main (){
	// bu kodda kullanýcýdan 10 tane kelime alýp her bir kelimenin farklý anagramýný yazdýrdýk
	int i,j;
	char kelimeler[10][30];		// kullanýcýdan alýnan kelimelerin tutulacaðý iki boyutlu dizi tanýmladýk
	// kullanýcýya yapacaðý iþlemleri bildirdik
	printf("**********ANAGRAM BULMA**********\n");
	printf("Anagramlarinin eslestirilmesini istediginiz 10 kelimeyi giriniz!\n");
	// döngü kullanarak kullanýcýdan kelimeleri aldýk	
	for (i=0; i<10;i++){
		printf(">>> ");
		scanf("%s",kelimeler[i]);
	}
	printf("*********************************");
	printf("\nGirdiginiz kelimelerden birbirinin anagrami olanlar!\n");
	// bu döngü sayesinde her bir elemanýn anagramý bulunur
	for (i = 0; i < 9; i++) {	/* bu kýsýmda döngüyü son elemana kadar döndürüyoruz 
								ama son elemaný karþýlaþtýracak bir eleman olmadýðý için onu almýyoruz*/
   		for ( j = i + 1; j < 10; j++) {	/*bu kýsýmda da döngü ilk elemaný almayacak þekilde baþlar 
		   						ve onu kendinden bir önceki elemanla kontrol eder*/
    		if (kontrol(kelimeler[i], kelimeler[j]) ){		/* if yapýsýnda kontrol fonksiyonuna elemanlar sýrayla gönderilir 
															kontrol fonksiyonu 1 deðeri gönderirse çalýþýr göndermezse çalýþmayýp döngüye devam eder*/
        		printf(">>> %s %s\n", kelimeler[i], kelimeler[j]);	// fonksiyonun çalýþtýðý durumda onun 1 döndürmesini saðlayan kelimler yazdýrýlýlr.
      		
			  }
   		 
			}
 	 }	
	return 0;
}
	// if içinde geçerli olmasý için 1 veya 0 gönderilecek o yüzden int olarak tanýmladýk
int kontrol(char* dizi1 , char* dizi2){		// parametre olarak karþýlaþtýralacak kelimeler tanýmladýk
	int i;
	// her bir harfin kaç kez geçtiðini saymasý için her bir kelime için bir dizi tanýmladýk 
	// bu diziler ASCII tablosunda bulunan alfabe harflerine göre boyut aldý
	int dizi1_harfler[26] = {0};
	int dizi2_harfler[26] = {0};
	
	for(i=0 ; i< strlen(dizi1) ; i++){	// gönderilen kelimenin uzunluðu kadar döner
		int harf = dizi1[i];			// kelimenin ilk harfinin ASCII tablosundaki tam sayý karþýlýðý harf deðiþkenine aktarýlýr
		dizi1_harfler[ harf - 'a']++;	/* harf deðiþkeninin "a" harfine uzaklýðý hesaplanýp alfabedeki kaçýncý harf olduðu bulunur
										ve o index 1 arttýrýlýr böylce döngü sonuna kadar bu dizi kelimedeki hangi harften kaç tane olduðunu tutar*/
	}
	// yukarýdaki for da yapýlan tüm iþlem gönderilen bu ikinci kelime için yapýlýr ve döngü tamamlanýr
	for(i=0 ; i< strlen(dizi2) ; i++){	
		int harf = dizi2[i];
		dizi2_harfler[ harf - 'a']++;
	}
	
	for(i=0 ; i<26 ; i++){	
		if (dizi1_harfler[i] != dizi2_harfler[i]) /* alfabetik sýra þeklinde her harf dolaþýlýr ve bunlarýn ayný olmadýðý duruma bakýlýr 
													bu durumda 0 döndürülür ve main içinden çaðýrýldýðýnda yanlýþ olduðu anlaþýlsýn*/
			return 0 ;
	}
	// for içinde hiçbir eþit olmama durumu gerçekleþmediðinde bu kelimelerin anagram olduðu anlaþýlýr ve 1 deðeri döner 
	return 1 ;
}







