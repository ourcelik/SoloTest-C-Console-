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
				setlocale(LC_ALL, "Turkish");//T�rk�e Dil deste�i
				system("color 3");//ye�il renk
	int secim;
		printf("\n\t\t\t");
		printf("///////////MEN�\\\\\\\\\\\\\\\\\\\\\\");
		printf("\n \t\t\t\t 1-yeni oyun\n\t\t\t\t 2-Hakk�nda\n\t\t\t\t 3-��k��");
		printf("\n\t\t\t >>>>");
			scanf("%d",&secim);
					switch(secim){//giri� men�s�
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
int tas(char tahta[][7])//kalan ta� say�s�n� sayar.
{
int tas,kt1,kt2;//kalan ta�
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
int adim,dolu,bos,kincele,x,y,stsayi;//ad�m at�lan ba�ar�l� ad�mlar� g�sterir.
adim=0;
	char tahta [7][7];
int i,k;//d�ng� i�in
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
			int movex,movey;//hareket ettirilecek ta��n kord.
			int movex2,movey2;//hareket edecegi yerin kord.
			int son1,son2;//oyun bitimi i�in flag.
				
				while(1){//hareket sistemi
					son1=1;
					son2=1;
						for(x=0;x<7;x++)//sistemi x eksenine g�re tarayarak oynanacak ad�m olup olmad���n� kontrol eder.
						{
							for(y=0;y<7;y++)
							{
								if((tahta[x][y]=='O'&&tahta[x][y+1]=='O'&&tahta[x][y+2]=='X')||(tahta[x][y]=='X'&&tahta[x][y+1]=='O'&&tahta[x][y+2]=='O'))
									{
									son1=0;
									}
							}
						}		
								
						for(x=0;x<7;x++)//sistemi y eksenine g�re tarayarak oynanacak ad�m olup olmad���n� kontrol eder.
						{
							for(y=0;y<7;y++)
							{
								if((tahta[y][x]=='O'&&tahta[y+1][x]=='O'&&tahta[y+2][x]=='X')||(tahta[y][x]=='X'&&tahta[y+1][x]=='O'&&tahta[y+2][x]=='O'))
									{
									son2=0;
									}
							}
						}
							if(son1==1&&son2==1)//yukardaki ad�mlara girmezse oyundan ��k�� yapar.
							{
								printf("Atabilece�iniz herhangi bir ad�m kalmad� Kalan ta� say�n�za g�re dereceniz:\n Kalan ta�>>%d Derece>>",tas(tahta));
								stsayi=tas(tahta);
								if(stsayi>=9)
								printf("BECER�KS�Z");
								else if(stsayi==8)
								printf("D�KKATS�Z");
								else if(stsayi==7)
								printf("D�KKATS�Z");
								else if(stsayi==6)
								printf("TECR�BES�Z");
								else if(stsayi==5)
								printf("NORMAL");
								else if(stsayi==4)
								printf("BA�ARILI");
								else if(stsayi==3)
								printf("KURNAZ");
								else if(stsayi==2)
								printf("ZEK�");
								else if(stsayi==1)
								printf("B�LG�N");
								return 0;
													}						
					
							printf("Hareket edecek ta� kordinatlar�>>x:");
							scanf("%d",&movex);
							printf("y:");
							scanf("%d",&movey);
							printf("Hareket edece�i yerin kordinatlar�>>x:");
							scanf("%d",&movex2);
							printf("y:");
							scanf("%d",&movey2);
							if(movex==1&&movey==1||movex==1&&movey==2||movex==2&&movey==1||movex==2&&movey==2||movex==7&&movey==1||movex==7&&movey==2||movex==8&&movey==1||movex==8&&movey==2||movex==1&&movey==7||movex==1&&movey==8||movex==2&&movey==7||movex==2&&movey==8||movex==7&&movey==7||movex==7&&movey==8||movex==8&&movey==7||movex==8&&movey==8)
							{
								system("cls");
								printf("Kural d��� Bir Ad�m Att�n�z,Kurallar� tekrar incelemek ister misiniz?(Evet:1 Hay�r oyuna devam et:2)");
								scanf("%d",&kincele);
							switch(kincele)
							{
									case 1: system("cls");
									info();
									return 0;
									break;
									case 2:system("cls"); 
									printf("\t\t\t\tHarcad���n�z ba�ar�l� Ad�m Say�s�:%d\n",adim);
									printf("\t\t\t\tKalan Ta� Say�s�:%d\n",tas(tahta));
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
										printf("\t\t\t\tHarcad���n�z ba�ar�l� Ad�m Say�s�:%d\n",adim);
										printf("\t\t\t\tKalan Ta� Say�s�:%d\n",tas(tahta));
											goto TAHTA;
								}
								else if(movex2-movex==2&&tahta[movey-1][movex-1]=='O'&&tahta[movey2-1][movex2-1]=='X'&&tahta[movey2-1][movex2-2]=='O')
								{
									tahta[movey-1][movex-1]='X';
									tahta[movey2-1][movex2-1]='O';
									tahta[movey2-1][movex2-2]='X';
									adim++;
									system("cls");
										printf("\t\t\t\tHarcad���n�z ba�ar�l� Ad�m Say�s�:%d\n",adim);
										printf("\t\t\t\tKalan Ta� Say�s�:%d\n",tas(tahta));
											goto TAHTA;	
								}
								else if(movey2-movey==2&&tahta[movey-1][movex-1]=='O'&&tahta[movey2-1][movex2-1]=='X'&&tahta[movey2-2][movex2-1]=='O')
								{
									tahta[movey-1][movex-1]='X';
									tahta[movey2-1][movex2-1]='O';
									tahta[movey2-2][movex2-1]='X';
									adim++;
									system("cls");
										printf("\t\t\t\tHarcad���n�z ba�ar�l� Ad�m Say�s�:%d\n",adim);
										printf("\t\t\t\tKalan Ta� Say�s�:%d\n",tas(tahta));
											goto TAHTA;		
								}
								else if(movey-movey2==2&&tahta[movey-1][movex-1]=='O'&&tahta[movey2-1][movex2-1]=='X'&&tahta[movey2][movex2-1]=='O')
								{
									tahta[movey-1][movex-1]='X';
									tahta[movey2-1][movex2-1]='O';
									tahta[movey2][movex2-1]='X';
									adim++;
									system("cls");
										printf("\t\t\t\tHarcad���n�z ba�ar�l� Ad�m Say�s�:%d\n",adim);
										printf("\t\t\t\tKalan Ta� Say�s�:%d\n",tas(tahta));
											goto TAHTA;
								}
								else
								{
									system("cls");
									printf("Kural d��� Bir Ad�m Att�n�z,Kurallar� tekrar incelemek ister misiniz?(Evet:1 Hay�r oyuna devam et:2)");
									scanf("%d",&kincele);
								switch(kincele)
								{
									case 1: system("cls");
										info();
										return 0;
									break;
									case 2:system("cls"); 
											printf("\t\t\t\tHarcad���n�z ba�ar�l� Ad�m Say�s�:%d\n",adim);
											printf("\t\t\t\tKalan Ta� Say�s�:%d\n",tas(tahta));
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
void out(){//��k��
		system("cls");
	int i;
			printf("kapat�l�yor");
				for(i=0;i<6;i++)
				{
					printf(".");
					fordelay(100000000);
				}
}

void info(){//oyun hakk�nda bilgilendirme yapar..
	system("cls");
	system("color 2");
	printf("\t\t\t\t//////////A�IKLAMA\\\\\\\\\\\\\\\\\\\\\\\\\n");
	printf("*Solo Test ki�inin kendi kendine oynad��� bir oyundur.\n");
	printf("*32 piyonu merkezdeki deli�i bo� b�rakmak �zere t�m deliklere yerle�tirin.\n");
	printf("*Bo� deli�in �evresinde ki d�rt piyonun herhangi birinin hemen arkas�ndaki piyonu �n�ndeki \npiyonun �zerinden atlatarak deli�e yerle�tirin ve �zerinden atlad���n�z piyonu al�n.\n");
	printf("*Oyun s�resince, �n�ndeki piyonun �zerinden atlayarak hareket ettirdi�iniz herhengi bir piyonu \n bo� deli�e yerle�tirirken, �zerinden ge�ti�iniz piyonu al�n.\n");
	printf("*Oynamak istedi�iniz piyonu ileri,geri,sa�a ve sola hareket ettirebilir fakat, �apraz hareket ettiremezsiniz.\n");
	printf("*Bir piyonun, �n�ndeki veya yan�ndaki piyon �zerinden atlat�lacak ve hemen ard�ndaki bo� \ndeli�e yerle�tirecek durum yoksa oyun sona erer.\n");
	printf("\nOYUNUN �ZELL���:Oyun sonunda tek bir piyon kalmas� i�in m�cadele etmelisiniz.\n Kalacak piyon adedine g�re a�a��daki tablodan piyon say�s�n� tespit ederek \nzeka derecenizi bulun. Normal zeka 100 puan olarak kabul edilmi�tir.");
	printf("B�rakt���n�z;\n");
	printf("9 Piyon 0 Puan BEY�NS�Z\n");
	printf("8 Piyon 24 Puan Gerizekal�\n");
	printf("7 Piyon 50 Puan APTAL\n");
	printf("6 Piyon 75 Puan TECR�BES�Z\n");
	printf("5 Piyon 100 Puan NORMAL\n");
	printf("4 Piyon 125 Puan BA�ARILI\n");
	printf("3 Piyon 150 Puan KURNAZ\n");
	printf("2 Piyon 175 Puan ZEK�\n");
	printf("1 Piyon 200 Puan B�LG�N.\n");
	int choice;
	printf("yeni oyun ba�latmak i�in 1 ��k�� i�in 2'yi tu�lay�n�z: ");
	scanf("%d",&choice);
	int i,k;
	switch(choice)//geri d�n�� men�s�
	{
		case 1:system("cls");
		main();
		break;
		case 2:out();
		break;
		default: printf("yanl�� tu�lama kapat�l�yor");
		for(i=0;i<6;i++)
		{
			printf(".");
			fordelay(100000000);
		}
		system("cls");
		printf("G�R���R�Z:)");
	}
}
