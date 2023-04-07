# anagram-bulma
Yazdığım kodun amacı verilen 10 kelime arasından birbirinin anagramı olanları bulmak. Kod kelime içinde her harfin kaç kez geçtiğini bulur ve bunu diğer kelimelerle karşılaştırır.


Kodu yazarken öncelikle kullanıcıdan for içinde kelimeleri aldım sonra bu kelimeleri ikili olarak kontrol etmesi için tanımladığım fonksiyona gönderdim. Bu fonksiyon içerisinde alfabedeki harf kadar (Türkçe karakter yok ASCII tablosuna göre) elemanı olan iki dizi tanımladım bunları tek tek ayrı for içinde kullandım. For döngülerinde kelimenin eleman sayısı kadar dönerek her bir harfin sırasını bulup bir arttırıldı böylece döngü  sonunda kelimede hangi harften kaç tane olduğu bulundu. En son bu iki diziyi karşılaştırmak için tekrar for döngüsü kullanarak kontrol yapıldı ve for içinde eşit olmadıklarında 0 döngü dışına çıkarsa yani hepsi eşit  olursa 1 döndürüldü. Main içinden çağrılınca if içinde bir olursa ikili olarak yazdırıldı.

Kodun çalışmasını test ederken aynı harfler içeren kelimeler verilir ve çıktı olarak ikili olarak sıralandığı gözlemlenebilir.
