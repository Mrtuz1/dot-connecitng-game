#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define MAX 15   // kullanılacak max sayi
void drawBoard(int matris[][MAX], int N);
void drawBoard1(int matris[MAX][MAX][MAX], int N,int a);
void readFromFile(int matris[MAX][MAX], char *fileName);
float manuel(int matris[MAX][MAX],int N,int oyun);
void automatic(int matris[MAX][MAX],int N);
int oto(int matris[MAX][MAX],int N,int x,int y,int bitis[2],int deger,int boardmemory[MAX][MAX][MAX],int a,int baslangic[2]);


int main(){
    int i,j,matris[MAX][MAX]={{0}},option,counter,x,y,user=0,oyun=1; 
    int N,M;
    int secim;
    char fileName[20];	
    srand(time(NULL));
    char username[MAX][MAX];
    float puan[MAX]={0};
    do{
    	for(i=0;i<N;i++){
    		for(j=0;j<N;j++){
    			matris[i][j]=0;
			}
		}
    
    printf("dosya girmek icin 1 e basiniz\nrastgele dagitmak icin 2 ye basiniz\nskorlari gormek icin 3 e basiniz\noyunu kapatmak icin 4 e basiniz\n");
    
    scanf("%d",&option);
    if(option==1 || option==2){
    printf("matris buyuklugunu giriniz\n");
    scanf("%d",&N);
	}
    
    if(option==1){
    
  	printf("Dosya Adini Giriniz");
  	scanf("%s",&fileName);
	readFromFile(matris, fileName);
	drawBoard(matris,N);
	
	}
	else if(option==2){
    for(i=0;i<N;i++){
    	counter=0;
    	do{
    		x=rand()%N;
    		y=rand()%N;
    		if(matris[x][y]==0){
    			counter++;
    			matris[x][y]=i+1;
			}
		}while(counter<2);
	}
		drawBoard(matris,N);
	}
	else if(option==3){
		printf("SKORLAR\n\n");
		
		for(i=1;i<=user;i++){
		printf("%s isimli kullanicinin puani==%f\n\n",username[i],puan[i]);
		
	}
			
	}
	
	
	if(option==1 || option==2){
	printf("otomatik oynamak icin 1 e,manuel oynamak icin 2 ye ,ana menuye donmek icin 3 e basiniz\n");
	scanf("%d",&counter);
	
	
	if(counter==1){//otomatik
		
		if(user==0){
		user++;
		printf("\nKullanici ismi giriniz :\n");
		scanf("%s",username[user]);

	}
	else{
		printf("\nyeni kullanici girmek icin 1'e, devam etmek icin 2 ye basiniz");
		scanf("%d",&secim);
		if(secim==1){
			user++;
			printf("\nKullanici ismi giriniz:\n");
			scanf("%s",username[user]);
			(oyun)=1;
		}
		else{
			(oyun)++;
		}
	}
	
	automatic(matris,N);
	
	
		
		}
		
	else if(counter==2){//manuel
	
	if(user==0){
		user++;
		printf("\nKullanici ismi giriniz :\n");
		scanf("%s",username[user]);

	}
	else{
		printf("\nyeni kullanici girmek icin 1'e, devam etmek icin 2 ye basiniz");
		scanf("%d",&secim);
		if(secim==1){
			user++;
			printf("\nKullanici ismi giriniz:\n");
			scanf("%s",username[user]);
			(oyun)=1;
		}
		else{
			(oyun)++;
		}
	}
	

	puan[user]+=manuel(matris,N,oyun);
	
	
	
		}
		
				
	}
		
    }while(option!=4);
    printf("oynadiginiz icin tesekkurler");
    
    
    return 0;
}


void readFromFile(int matris[][MAX], char *fileName){
	int i,j, temp;
	FILE *data = fopen(fileName,"r");
	if(!data){
        printf("Dosya Acilamadi!");
		return;
    }
    while(!feof(data)){
        fscanf(data,"%d %d %d\n",&i,&j,&temp);  
		matris[i][j]=temp; 
    }  
  	fclose(data); 
}


void drawBoard1(int matris[MAX][MAX][MAX], int N,int a){
    int i,j,k;
    for(i=0;i<N;i++){
        printf("\n");
        for (k=0;k<N;k++)
            printf("-------");
        printf("\n");
        for(j=0;j<N;j++)
            if (matris[i][j][a]!=0)
                printf("  %d   |",matris[i][j][a]);
            else
                 printf("      |",matris[i][j][a]);
    }
    printf("\n");
}


void drawBoard(int matris[MAX][MAX], int N){
    int i,j,k;
    for(i=0;i<N;i++){
        printf("\n");
        for (k=0;k<N;k++)
            printf("-------");
        printf("\n");
        for(j=0;j<N;j++)
            if (matris[i][j]!=0)
                printf("  %d   |",matris[i][j]);
            else
                 printf("      |",matris[i][j]);
    }
    printf("\n");
}

float manuel(int matris[MAX][MAX],int N,int oyun){
	int option;
	clock_t start_t,end_t;
	int counter=0,temp,counter1,undocounter=0;
	int b,h;
	int a=0;
	int i,j,k;
	int bitis[2];
	int hamle[2][MAX];
	int boardmemory[MAX][MAX][MAX];
	float puan;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			boardmemory[i][j][a]=matris[i][j];
		}
	}
	start_t=clock();
	do{
	
		printf("baslangic koordinati giriniz (bosluk olamaz)\n");
		scanf("%d %d",&hamle[0][a],&hamle[1][a]);
		b=boardmemory[hamle[0][a]][hamle[1][a]][a];
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(!(i==hamle[0][a]  &&  j==hamle[1][a])  &&  b==matris[i][j]){
					bitis[0]=i;
					bitis[1]=j;
					printf("bitis=%d %d\n\n",bitis[0],bitis[1]);	
				}
			}
		}
		do{
			
			printf("hamle yapmak icin 1 e , undo yapmak icin 2 ye ,cozulemeyecegini dusunuyorsaniz 3 e basiniz\n\n");
			scanf("%d",&option);
			if(option==1){
				
				a++;
				if(a==MAX){
	
					for(i=1;i<a;i++){
						hamle[0][i-1]=hamle[0][i];
						hamle[1][i-1]=hamle[1][i];
						for(j=0;j<N;j++){
							for(k=0;k<N;k++){
								boardmemory[j][k][i]=boardmemory[j][k][i-1];
							}
						}
					}
					a--;
				}
				for(i=0;i<N;i++){
					for(j=0;j<N;j++){
						boardmemory[i][j][a]=boardmemory[i][j][a-1];
					}
				}
				
				printf("gidilecek koordinatlari giriniz(duz yol olmali)\n");
				do{
				scanf("%d %d",&hamle[0][a],&hamle[1][a]);
				if(!((hamle[0][a]>=0 && hamle[0][a]<N) && (hamle[1][a]>=0 && hamle[1][a]<N))){
					printf("koordinatlar oyun tahtasinin disina cikamaz!!!\n");
				}
				
			}while(!((hamle[0][a]>=0 && hamle[0][a]<N) && (hamle[1][a]>=0 && hamle[1][a]<N)));
				counter1=0;
				
				
				
				
				if(hamle[0][a-1]==hamle[0][a]){
					h=fabs(hamle[1][a]-hamle[1][a-1])/(hamle[1][a]-hamle[1][a-1]);
					temp=hamle[1][a-1];
					do{
						temp+=h;
						if(boardmemory[hamle[0][a]][temp][a]==0){
							boardmemory[hamle[0][a]][temp][a]=b;
						}
						else if(boardmemory[hamle[0][a]][temp][a]!=b){
						counter1=1;
						}
					}while(!counter1 && temp!=hamle[1][a]);
					if(counter1==1){
						a--;
						printf("guzergahta sayi var!\n\n");
					}
					else if(boardmemory[hamle[0][a]][hamle[1][a]][a-1]==b){
						printf("tebrikler %d yi tamamladiniz!\n\n",b);
						
					}
					
					
					
				}
				
				else if(hamle[1][a-1]==hamle[1][a]){
					
					h=fabs(hamle[0][a]-hamle[0][a-1])/(hamle[0][a]-hamle[0][a-1]);
					temp=hamle[0][a-1];
					do{
						temp+=h;
						if(boardmemory[temp][hamle[1][a]][a]==0){
							boardmemory[temp][hamle[1][a]][a]=b;
						}
						else if(boardmemory[temp][hamle[1][a]][a]!=b){
						counter1=1;
						}
					}while(!counter1 && temp!=hamle[0][a]);
					if(counter1==1){
						a--;
						printf("guzergahta sayi var!\n");
					}
					else if(boardmemory[hamle[0][a]][hamle[1][a]][a-1]==b){
						printf("tebrikler %d yi tamamladiniz!\n",b);
						
					}
					
				}
				else{
					printf("duz yol girilmeli!\n");
					a--;
				}
				drawBoard1(boardmemory,N,a);
			}
			else if(option==2){
				a--;
				drawBoard1(boardmemory,N,a);
				undocounter++;
				
			}
			
			
		}while(!(hamle[0][a]==bitis[0]  && hamle[1][a]==bitis[1]) && option!=3);
		counter++;
		
	}while(counter<N && option!=3);
	
	end_t=clock();
	printf("oyunu bitirme suresi=%f\n",(double)(end_t-start_t)/CLOCKS_PER_SEC);
	
	puan=(N*N*N)+(N*30)-((end_t-start_t)/CLOCKS_PER_SEC)-(5*undocounter);
	puan=puan/oyun;
	if(option == 3){
	puan=0;
	}
	
	printf("kazandiginiz puan=%f\n",puan);
	return puan;
	
}

void automatic(int matris[MAX][MAX],int N){
	int x,y,countf=0,counter,i,j,k,deger,boardmemory[MAX][MAX][MAX],a=0,control;
	int found[N],bitis[2],baslangic[2];
	int iterasyon=0;
	for(i=0;i<N;i++)
	found[i]=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			boardmemory[i][j][a]=matris[i][j];
		}	
	}
	drawBoard1(boardmemory,N,a);

	do{	
		
	for(x=0;x<N;x++){

		for(y=0;x<N;x++){

			counter=0;
			for(k=0;k<N;k++){
				if(matris[x][y]==found[k]){
					counter=1;
				}
			}
				if(matris[x][y]!=0 && counter==0){
					baslangic[0]=x;
					baslangic[1]=y;
					deger=matris[x][y];
					found[deger-1]=matris[x][y];
					for(i=0;i<N;i++){
						for(j=0;j<N;j++){
							if(!(i==x && j==y) && matris[i][j]==matris[x][y]){
								bitis[0]=i;
								bitis[1]=j;
							}
						}
					}
					control=oto(matris,N,x,y,bitis,deger,boardmemory,a,baslangic);
					if(control==1){
						boardmemory[MAX-1][MAX-1][a]=0;
						for(i=0;i<N;i++){
							for(j=0;j<N;j++){
								boardmemory[i][j][a+1]=boardmemory[i][j][a];
							}
						}
						
						a++;
						drawBoard1(boardmemory,N,a);
						
					}
					else if(control==0){
						printf("geri alindi\n");
						countf--;
						a--;
						found[deger-1]=0;
						for(i=0;i<N;i++){
							for(j=0;j<N;j++){
								boardmemory[i][j][a+1]=boardmemory[i][j][a];
							}
						}
						drawBoard1(boardmemory,N,a);
						
					}
					
					
				}
				
				
			}
		iterasyon++;
	}
}while(countf<N && a>=0 && iterasyon<100);
}

int oto(int matris[MAX][MAX],int N,int x,int y,int bitis[2],int deger,int boardmemory[MAX][MAX][MAX],int a,int baslangic[2]){
	int i,j,m;
	int devam;
	scanf("%d",&m);

printf("\n\n ilgili koordinattaki x degeri= %d\n",boardmemory[x][y][a]);
	if( x<0 || y<0 ||  x>=N || y>=N  || ( ( boardmemory[x][y][a]!=0 ) && ( x!=bitis[0] || y!=bitis[1] ) && ( x!=baslangic[0] || y!=baslangic[1] ) ) ) {
		
		printf("kontrola\n");
		if(boardmemory[x][y][a]==deger){
			boardmemory[x][y][a]=0;
		}
		
		return 0;
		
	}
	
	if ( boardmemory[x][y][a]==deger && x==bitis[0] && y==bitis[1] ) {
		printf("kontrolb\n");
		boardmemory[MAX-1][MAX-1][a]=1;
		
		return 1;
		
	}
	
	else if ( boardmemory[MAX-1][MAX-1][a]==1 ) {
		printf("kontrolc\n");
		return 1;
		
	}
	else {
		drawBoard1(boardmemory,N,a);
		printf("\nx,y=%d %d\n",x,y);
		boardmemory[x][y][a]=deger;
		
		if(x+1<N){
			printf("kontrol x+1\n");
			devam=oto(matris,N,x+1,y,bitis,deger,boardmemory,a,baslangic);
		}
         
		if(x-1>=0){
			printf("kontrol x-1\n"); 
			oto(matris,N,x-1,y,bitis,deger,boardmemory,a,baslangic);
		}
		
		if(y+1<N){
			printf("kontrol y+1\n");
			oto(matris,N,x,y+1,bitis,deger,boardmemory,a,baslangic);
		}
		
		if(y-1>=0){
			printf("kontrol y-1\n");
			oto(matris,N,x,y-1,bitis,deger,boardmemory,a,baslangic);
		}
		
		
	}
	
}

