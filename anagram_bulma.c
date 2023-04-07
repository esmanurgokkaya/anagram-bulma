#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kontrol(char* dizi1,char* dizi2); //tanımlanmış bir fonksiyonun bildirimini yaptık

int main (){
	// bu kodda kullanıcıdan 10 tane kelime alıp her bir kelimenin farklı anagramını yazdırdık
	int i,j;
	char kelimeler[10][30];		// kullanıcıdan alınan kelimelerin tutulacağı iki boyutlu dizi tanımladık
	// kullanıcıya yapacağı işlemleri bildirdik
	printf("**********ANAGRAM BULMA**********\n");
	printf("Anagramlarinin eslestirilmesini istediginiz 10 kelimeyi giriniz!\n");
	// döngü kullanarak kullanıcıdan kelimeleri aldık	
	for (i=0; i<10;i++){
		printf(">>> ");
		scanf("%s",kelimeler[i]);
	}
	printf("*********************************");
	printf("\nGirdiginiz kelimelerden birbirinin anagrami olanlar!\n");
	// bu döngü sayesinde her bir elemanın anagramı bulunur
	for (i = 0; i < 9; i++) {	/* bu kısımda döngüyü son elemana kadar döndürüyoruz 
								ama son elemanı karşılaştıracak bir eleman olmadığı için onu almıyoruz*/
   		for ( j = i + 1; j < 10; j++) {	/*bu kısımda da döngü ilk elemanı almayacak şekilde başlar 
		   						ve onu kendinden bir önceki elemanla kontrol eder*/
    		if (kontrol(kelimeler[i], kelimeler[j]) ){		/* if yapısında kontrol fonksiyonuna elemanlar sırayla gönderilir 
															kontrol fonksiyonu 1 değeri gönderirse çalışır göndermezse çalışmayıp döngüye devam eder*/
        		printf(">>> %s %s\n", kelimeler[i], kelimeler[j]);	// fonksiyonun çalıştığı durumda onun 1 döndürmesini sağlayan kelimler yazdırılılr.
      		
			  }
   		 
			}
 	 }	
	return 0;
}
	// if içinde geçerli olması için 1 veya 0 gönderilecek o yüzden int olarak tanımladık
int kontrol(char* dizi1 , char* dizi2){		// parametre olarak karşılaştıralacak kelimeler tanımladık
	int i;
	// her bir harfin kaç kez geçtiğini sayması için her bir kelime için bir dizi tanımladık 
	// bu diziler ASCII tablosunda bulunan alfabe harflerine göre boyut aldı
	int dizi1_harfler[26] = {0};
	int dizi2_harfler[26] = {0};
	
	for(i=0 ; i< strlen(dizi1) ; i++){	// gönderilen kelimenin uzunluğu kadar döner
		int harf = dizi1[i];			// kelimenin ilk harfinin ASCII tablosundaki tam sayı karşılığı harf değişkenine aktarılır
		dizi1_harfler[ harf - 'a']++;	/* harf değişkeninin "a" harfine uzaklığı hesaplanıp alfabedeki kaçıncı harf olduğu bulunur
										ve o index 1 arttırılır böylce döngü sonuna kadar bu dizi kelimedeki hangi harften kaç tane olduğunu tutar*/
	}
	// yukarıdaki for da yapılan tüm işlem gönderilen bu ikinci kelime için yapılır ve döngü tamamlanır
	for(i=0 ; i< strlen(dizi2) ; i++){	
		int harf = dizi2[i];
		dizi2_harfler[ harf - 'a']++;
	}
	
	for(i=0 ; i<26 ; i++){	
		if (dizi1_harfler[i] != dizi2_harfler[i]) /* alfabetik sıra şeklinde her harf dolaşılır ve bunların aynı olmadığı duruma bakılır 
													bu durumda 0 döndürülür ve main içinden çağırıldığında yanlış olduğu anlaşılsın*/
			return 0 ;
	}
	// for içinde hiçbir eşit olmama durumu gerçekleşmediğinde bu kelimelerin anagram olduğu anlaşılır ve 1 değeri döner 
	return 1 ;
}







