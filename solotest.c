#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>	
int tas(char tahta[][7]);
void start();
void fordelay(int delay);
void out();
void info();
int main() {
				setlocale(LC_ALL, "Turkish");//Türkçe Dil desteði
				system("color 3");//yeþil renk
	int secim;
		printf("\n\t\t\t");
		printf("///////////MENÜ\\\\\\\\\\\\\\\\\\\\\\");
		printf("\n \t\t\t\t 1-yeni oyun\n\t\t\t\t 2-Hakkýnda\n\t\t\t\t 3-Çýkýþ");
		printf("\n\t\t\t >>>>");
			scanf("%d",&secim);
					switch(secim){//giriþ menüsü
						case 1:system("cls");
							start();
							break;
						case 2:
							info();
							break;
						case 3:
							out();
							return 0;
						break;
					}
		return 0;
}
int tas(char tahta[][7])//kalan taþ sayýsýný sayar.
{
int tas,kt1,kt2;//kalan taþ
	for(kt1=0;kt1<7;kt1++)
	{
		for(kt2=0;kt2<7;kt2++)
		{
			if(tahta[kt1][kt2]=='O')
				{
					tas++;
				}
		}
	}
return tas;
}
void start(){//oyun
int adim,dolu,bos,kincele,x,y,stsayi;//adým atýlan baþarýlý adýmlarý gösterir.
adim=0;
	char tahta [7][7];
int i,k;//döngü için
		for(i=0;i<7;i++){//atama
			for(k=0;k<7;k++)
				{	
					if(i==0&&k==0||i==0&&k==5||i==0&&k==6||i==1&&k==6||i==1&&k==5||i==0&&k==1||i==1&&k==1||i==1&&k==0||i==1&&k==5||i==1&&k==6||i==6&&k==0||i==6&&k==1||i==6&&k==6||i==6&&k==5||i==5&&k==0||i==5&&k==1||i==5&&k==5||i==5&&k==6)
						tahta[i][k]=' ';
					else if(i==3&&k==3)
					{
						tahta[i][k]='X';
					}
					else
						tahta[i][k]='O';
					}
					}
						TAHTA:
					printf("      ");
		for(i=1;i<=7;i++)
		{
					printf(" %d  ",i);
		}
					printf("\n\n");
		for(i=0;i<7;i++){
					printf(" %d- ",i+1);
					printf("||");
		for(k=0;k<7;k++)
		{
				if(i==1&&k==6||i==2&&k==6||i==3&&k==6||i==0&&k==6||i==4&&k==6||i==5&&k==6||i==6&&k==6)
					printf(" %c ",tahta[i][k]);
				else
					printf(" %c  ",tahta[i][k]);
		}
					printf("||");
					printf("\n\n");
		}
			int movex,movey;//hareket ettirilecek taþýn kord.
			int movex2,movey2;//hareket edecegi yerin kord.
			int son1,son2;//oyun bitimi için flag.
				
				while(1){//hareket sistemi
					son1=1;
					son2=1;
						for(x=0;x<7;x++)//sistemi x eksenine göre tarayarak oynanacak adým olup olmadýðýný kontrol eder.
						{
							for(y=0;y<7;y++)
							{
								if((tahta[x][y]=='O'&&tahta[x][y+1]=='O'&&tahta[x][y+2]=='X')||(tahta[x][y]=='X'&&tahta[x][y+1]=='O'&&tahta[x][y+2]=='O'))
									{
									son1=0;
									}
							}
						}		
								
						for(x=0;x<7;x++)//sistemi y eksenine göre tarayarak oynanacak adým olup olmadýðýný kontrol eder.
						{
							for(y=0;y<7;y++)
							{
								if((tahta[y][x]=='O'&&tahta[y+1][x]=='O'&&tahta[y+2][x]=='X')||(tahta[y][x]=='X'&&tahta[y+1][x]=='O'&&tahta[y+2][x]=='O'))
									{
									son2=0;
									}
							}
						}
							if(son1==1&&son2==1)//yukardaki adýmlara girmezse oyundan çýkýþ yapar.
							{
								printf("Atabileceðiniz herhangi bir adým kalmadý Kalan taþ sayýnýza göre dereceniz:\n Kalan taþ>>%d Derece>>",tas(tahta));
								stsayi=tas(tahta);
								if(stsayi>=9)
								printf("BECERÝKSÝZ");
								else if(stsayi==8)
								printf("DÝKKATSÝZ");
								else if(stsayi==7)
								printf("DÝKKATSÝZ");
								else if(stsayi==6)
								printf("TECRÜBESÝZ");
								else if(stsayi==5)
								printf("NORMAL");
								else if(stsayi==4)
								printf("BAÞARILI");
								else if(stsayi==3)
								printf("KURNAZ");
								else if(stsayi==2)
								printf("ZEKÝ");
								else if(stsayi==1)
								printf("BÝLGÝN");
								return 0;
													}						
					
							printf("Hareket edecek taþ kordinatlarý>>x:");
							scanf("%d",&movex);
							printf("y:");
							scanf("%d",&movey);
							printf("Hareket edeceði yerin kordinatlarý>>x:");
							scanf("%d",&movex2);
							printf("y:");
							scanf("%d",&movey2);
							if(movex==1&&movey==1||movex==1&&movey==2||movex==2&&movey==1||movex==2&&movey==2||movex==7&&movey==1||movex==7&&movey==2||movex==8&&movey==1||movex==8&&movey==2||movex==1&&movey==7||movex==1&&movey==8||movex==2&&movey==7||movex==2&&movey==8||movex==7&&movey==7||movex==7&&movey==8||movex==8&&movey==7||movex==8&&movey==8)
							{
								system("cls");
								printf("Kural dýþý Bir Adým Attýnýz,Kurallarý tekrar incelemek ister misiniz?(Evet:1 Hayýr oyuna devam et:2)");
								scanf("%d",&kincele);
							switch(kincele)
							{
									case 1: system("cls");
									info();
									return 0;
									break;
									case 2:system("cls"); 
									printf("\t\t\t\tHarcadýðýnýz baþarýlý Adým Sayýsý:%d\n",adim);
									printf("\t\t\t\tKalan Taþ Sayýsý:%d\n",tas(tahta));
									goto TAHTA;
									continue;
							}
							}
							else
							{	
								if(movex-movex2==2&&tahta[movey-1][movex-1]=='O'&&tahta[movey2-1][movex2-1]=='X'&&tahta[movey2-1][movex2]=='O')
								{
									tahta[movey-1][movex-1]='X';
									tahta[movey2-1][movex2-1]='O';
									tahta[movey2-1][movex2]='X';
									adim++;
									system("cls");
										printf("\t\t\t\tHarcadýðýnýz baþarýlý Adým Sayýsý:%d\n",adim);
										printf("\t\t\t\tKalan Taþ Sayýsý:%d\n",tas(tahta));
											goto TAHTA;
								}
								else if(movex2-movex==2&&tahta[movey-1][movex-1]=='O'&&tahta[movey2-1][movex2-1]=='X'&&tahta[movey2-1][movex2-2]=='O')
								{
									tahta[movey-1][movex-1]='X';
									tahta[movey2-1][movex2-1]='O';
									tahta[movey2-1][movex2-2]='X';
									adim++;
									system("cls");
										printf("\t\t\t\tHarcadýðýnýz baþarýlý Adým Sayýsý:%d\n",adim);
										printf("\t\t\t\tKalan Taþ Sayýsý:%d\n",tas(tahta));
											goto TAHTA;	
								}
								else if(movey2-movey==2&&tahta[movey-1][movex-1]=='O'&&tahta[movey2-1][movex2-1]=='X'&&tahta[movey2-2][movex2-1]=='O')
								{
									tahta[movey-1][movex-1]='X';
									tahta[movey2-1][movex2-1]='O';
									tahta[movey2-2][movex2-1]='X';
									adim++;
									system("cls");
										printf("\t\t\t\tHarcadýðýnýz baþarýlý Adým Sayýsý:%d\n",adim);
										printf("\t\t\t\tKalan Taþ Sayýsý:%d\n",tas(tahta));
											goto TAHTA;		
								}
								else if(movey-movey2==2&&tahta[movey-1][movex-1]=='O'&&tahta[movey2-1][movex2-1]=='X'&&tahta[movey2][movex2-1]=='O')
								{
									tahta[movey-1][movex-1]='X';
									tahta[movey2-1][movex2-1]='O';
									tahta[movey2][movex2-1]='X';
									adim++;
									system("cls");
										printf("\t\t\t\tHarcadýðýnýz baþarýlý Adým Sayýsý:%d\n",adim);
										printf("\t\t\t\tKalan Taþ Sayýsý:%d\n",tas(tahta));
											goto TAHTA;
								}
								else
								{
									system("cls");
									printf("Kural dýþý Bir Adým Attýnýz,Kurallarý tekrar incelemek ister misiniz?(Evet:1 Hayýr oyuna devam et:2)");
									scanf("%d",&kincele);
								switch(kincele)
								{
									case 1: system("cls");
										info();
										return 0;
									break;
									case 2:system("cls"); 
											printf("\t\t\t\tHarcadýðýnýz baþarýlý Adým Sayýsý:%d\n",adim);
											printf("\t\t\t\tKalan Taþ Sayýsý:%d\n",tas(tahta));
											goto TAHTA;
											continue;
								}	
								}
						}
							
							
								
						}	
}
void fordelay(int delay)//geciktirme ..... efekti
{
	int i,k;
	for(i=0;i<delay;i++)
	{
		k++;
	}
}
void out(){//çýkýþ
		system("cls");
	int i;
			printf("kapatýlýyor");
				for(i=0;i<6;i++)
				{
					printf(".");
					fordelay(100000000);
				}
}

void info(){//oyun hakkýnda bilgilendirme yapar..
	system("cls");
	system("color 2");
	printf("\t\t\t\t//////////AÇIKLAMA\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("*Solo Test kiþinin kendi kendine oynadýðý bir oyundur.\n");
	printf("*32 piyonu merkezdeki deliði boþ býrakmak üzere tüm deliklere yerleþtirin.\n");
	printf("*Boþ deliðin çevresinde ki dört piyonun herhangi birinin hemen arkasýndaki piyonu önündeki \npiyonun üzerinden atlatarak deliðe yerleþtirin ve üzerinden atladýðýnýz piyonu alýn.\n");
	printf("*Oyun süresince, önündeki piyonun üzerinden atlayarak hareket ettirdiðiniz herhengi bir piyonu \n boþ deliðe yerleþtirirken, üzerinden geçtiðiniz piyonu alýn.\n");
	printf("*Oynamak istediðiniz piyonu ileri,geri,saða ve sola hareket ettirebilir fakat, çapraz hareket ettiremezsiniz.\n");
	printf("*Bir piyonun, önündeki veya yanýndaki piyon üzerinden atlatýlacak ve hemen ardýndaki boþ \ndeliðe yerleþtirecek durum yoksa oyun sona erer.\n");
	printf("\nOYUNUN ÖZELLÝÐÝ:Oyun sonunda tek bir piyon kalmasý için mücadele etmelisiniz.\n Kalacak piyon adedine göre aþaðýdaki tablodan piyon sayýsýný tespit ederek \nzeka derecenizi bulun. Normal zeka 100 puan olarak kabul edilmiþtir.");
	printf("Býraktýðýnýz;\n");
	printf("9 Piyon 0 Puan BEYÝNSÝZ\n");
	printf("8 Piyon 24 Puan Gerizekalý\n");
	printf("7 Piyon 50 Puan APTAL\n");
	printf("6 Piyon 75 Puan TECRÜBESÝZ\n");
	printf("5 Piyon 100 Puan NORMAL\n");
	printf("4 Piyon 125 Puan BAÞARILI\n");
	printf("3 Piyon 150 Puan KURNAZ\n");
	printf("2 Piyon 175 Puan ZEKÝ\n");
	printf("1 Piyon 200 Puan BÝLGÝN.\n");
	int choice;
	printf("yeni oyun baþlatmak için 1 çýkýþ için 2'yi tuþlayýnýz: ");
	scanf("%d",&choice);
	int i,k;
	switch(choice)//geri dönüþ menüsü
	{
		case 1:system("cls");
		main();
		break;
		case 2:out();
		break;
		default: printf("yanlýþ tuþlama kapatýlýyor");
		for(i=0;i<6;i++)
		{
			printf(".");
			fordelay(100000000);
		}
		system("cls");
		printf("GÖRÜÞÜRÜZ:)");
	}
}
