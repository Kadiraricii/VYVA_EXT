// MEHMET KADİR ARICI
// 2420161146
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=BozfGKJpa9

#include <stdio.h>

void dizi_yazdir(int dizi[], int BOYUT) {
    
    int i;
    
    for (i = 0; i < BOYUT; i++) {
        
        printf("%3d", dizi[i]);
    }
    
    printf("\n");
    
}

void takas(int *ap, int *bp) {
    
    int gecici = *ap;
    
    *ap = *bp;
    *bp = gecici;
}



void kokteyl_sirala(int dizi[], int BOYUT) {
    int i;
    int sayac = 0;
    
    int takas_oldu;
    
    int bas_ind = 0, son_ind = BOYUT-1;
    
    

    takas_oldu = 1;
    
    while (takas_oldu == 1) {

        
        takas_oldu = 0;
        
        for (i = bas_ind; i < son_ind; i++) {
            
            if (dizi[i] > dizi[i + 1]) {
                takas(&dizi[i], &dizi[i+1]);
                takas_oldu = 1;
            }
        }
        
        if (takas_oldu == 0) {
                    break;
                }
                son_ind--;

                takas_oldu = 0;
                for (i=son_ind-1; i>=bas_ind; i--) {
                    if (dizi[i] > dizi[i+1]) {
                        takas(&dizi[i], &dizi[i+1]);
                        takas_oldu = 1;
                    }
                }
        bas_ind++;

        printf("İTERASYON %d: ", ++sayac);
        dizi_yazdir(dizi, BOYUT);
    }
}


int ikili_arama(int dizi[], int BOYUT, int ARA, int ilk_i, int son_i) {
    
    int orta_i = (ilk_i + son_i) / 2;

    if (ARA == dizi[orta_i]) {
        
        return orta_i;
        
    } else if (ARA > dizi[orta_i] && (son_i - ilk_i) > 0) {
   
        
        return ikili_arama(dizi, BOYUT, ARA, orta_i + 1, son_i);
        
    }else if (ARA < dizi[orta_i] && (son_i - ilk_i) > 0) {
    
        
        return ikili_arama(dizi, BOYUT, ARA, ilk_i, orta_i - 1);
    }
    
    else {
        
        return -1;
    }
}

int main() {
    int bul;
    int sonuc;
    
    int A[] = {72, 52, 11, 91, 6, 43, 54, 6, 53, 72, 53, 64, 42, 12, 2};
    int N = sizeof(A) / sizeof(A[0]);
    

    dizi_yazdir(A,N);
    kokteyl_sirala(A,N);
    dizi_yazdir(A,N);
    
    printf("Aramak istediginiz sayı: ");
    scanf("%d", &bul);

    sonuc = ikili_arama(A, N, bul, 0, N - 1);

    if (sonuc == -1) {
        
        printf("Aradiginiz deger %d . dizide bulunmuor \n", bul);
    } else {
        
        printf("Aradiginiz deger %d . dizinin %d. indisinde bulunyor \n", bul, sonuc);
    }
    
    return 0;

    
}
