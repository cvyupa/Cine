/*
   Universidad de las Fuerzas Armadas ESPE
   Proyecto Primer Parcial
   Cine
   Integrantes:
	-Carlos Yupa
	-Mauricio Ruiz
	-Andres Sanaguano
*/

// Librerias.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include<iostream>
#include <windows.h>
#include <dos.h>
#include <cstdlib>
#include <fstream>
#include <ctime>

// Declaracion de constantes.
#define tamS 6
#define USER "mca"
#define PASS "1234"
#define ENTER 13
#define BACKSPACE 8
#define TAM 10
#define negro 0
#define azul 1
#define verde 2
#define cyan 3
#define rojo 4
#define magenta 5
#define marron 6
#define grisclaro 7
#define grisoscuro 8
#define azulclaro 9
#define verdeclaro 10
#define cyanclaro 11
#define rojoclaro 12
#define magentaclaro 13
#define amarillo 14
#define blanco 15

using namespace std;

//ESTRUCTURAS USADAS
struct backup
{
    char ba[50];
    char ba2[50];
};
struct boletos
{
    int adultos;
    int ninios;
    int TerEdad;
    int fila[5];
    int columna[5];
    float total;
};
struct horarios
{
    int hora[2];
    int minuto[2];
};
struct asientos
{
    char butaca[tamS][tamS];
    //int tipoSala;

};
struct peliculas
{
    int peli[5];
    horarios h1[2];
    char Nsala[2];
};

//LISTA DOBLE QUE MANEJA TODAS LAS DEMAS ESTRUCTURAS
struct datos
{
    char nombre[20];
    char apellido[20];
    char cedula[11];
    char codigo[20][30];
      int tipoSala;
    boletos b1;
    peliculas p1;
    datos *sig;
    datos *ant;
}*lista;

// Prototipos de las funciones.
void gotoxy(int ,int );
void t(int );
void generarCodigo(datos **); 
void printgenerarCodigo(datos **);
void cartelera();
static HWND  hConWnd;
HWND BCX_Bitmap(char*, HWND, int, int, int, int, int, int, int, int);
HWND GetConsoleWndHandle(void);
  

// Funcion para mover el cursor de la ventana de texto.
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

// Funcion para agregar color al texto.
void t(int n){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

// Funcion para generar el codigo QR.
void generarCodigo(datos **e){
   for(int i=0;i<20;i++){
      for(int j=0;j<30;j++){
         (*e)->codigo[i][j]='\0';
      }
   }
   int y,z=0,b=219;
   srand(time(NULL));
   y=rand()%12;
   for(int i=0;i<20;i++){
      for(int j=0;j<30;j++){
         if((i==0||i==19)&&(j<0||j<=8)){
            (*e)->codigo[i][j]=b;
         }
         if((i==0)&&(j>=21&&j<=29)){
            (*e)->codigo[i][j]=b;
         }
         if((i>0&&i<=5)&&(j==0||j==8))
            (*e)->codigo[i][j]=b;
         if((i==5)&&(j>=0&&j<=8))
            (*e)->codigo[i][j]=b;
         if((i>14&&i<=19)&&(j==0||j==8))
            (*e)->codigo[i][j]=b;
         if((i==14)&&(j>=0&&j<=8))
            (*e)->codigo[i][j]=b;
         if((i>0&&i<=5)&&(j==21||j==29))
            (*e)->codigo[i][j]=b;
         if((i==5)&&(j>=21&&j<=29))
            (*e)->codigo[i][j]=b;
         if((i>1&&i<=3)&&(j>=3&&j<=5))
            (*e)->codigo[i][j]=b;
         if((i>15&&i<=17)&&(j>=3&&j<=5))
            (*e)->codigo[i][j]=b;
         if((i>1&&i<=3)&&(j>=24&&j<=26))
            (*e)->codigo[i][j]=b;
         for(int k=i+1;k<y;k++){
            srand(time(NULL));
            y=rand()%29;
            x[k][y]=b;
         }
         if(i>6&&i<13){
            y=rand()%10;
            if(y%2==0){
               y=b;
            }else{
               y='\0';
            }
            (*e)->codigo[i][j]=y;
         }
         if((i<=6&&i>=0)&&(j>9&&j<20)){
            y=rand()%10;
            if(y%2==0){
               y=b;
            }else{
               y='\0';
            }
            (*e)->codigo[i][j]=y;
         }
         if((i>13&&i<=20)&&(j>9&&j<=30)){
            y=rand()%10;
            if(y%2==0){
               y=b;
            }else{
               y='\0';
            }
            (*e)->codigo[i][j]=y;
         }
         if(i==13&&(j>9&&j<=30)){
            y=rand()%10;
            if(y%2==0){
               y=b;
               }else{
                  y='\0';
               }
            (*e)->codigo[i][j]=y;
         }
      }
   }
}

// Funcion para imprimir en pantalla el codigo QR.
void printgenerarCodigo(datos **e){
   for(int i=0;i<20;i++){
      for(int j=0;j<30;j++){
         printf("%c",(*e)->codigo[i][j]);         
      }
      printf("\n");
   }
}
void menu()
{
	
do{

   for(i=0;i<130;i++)
   {
        for(j=0;j<40;j++)
        {
           t(120);gotoxy(0+i,2+j);printf("%c",219);
        }

   }



    for(i=0;i<100;i++)
   {
        for(j=0;j<10;j++)
        {
           t(241);gotoxy(0+i,1+j);printf("%c",219);
        }

   }

//linea verde
   for(i=0;i<60;i++)
   {
        for(j=0;j<2;j++)
        {
           t(250);gotoxy(70+i,10+j);printf("%c",219);
        }

   }

    for(i=0;i<40;i++)
   {
        for(j=0;j<20;j++)
        {
           t(0);gotoxy(70+i,15+j);printf("%c",219);
        }

   }

 for(j=0;j<41;j++)
        {
           t(0);gotoxy(0,1+j);printf("%c",219);
        }
t(30);
gotoxy(3,2);printf("   ______   _                   ____    ____   ______       _       ");
gotoxy(3,3);printf(" .' ___  | (_)                 |_   *  /   _|.' ___  |     / *      ");
gotoxy(3,4);printf("/ .'   *_| __   _ .--.  .---.    |   */   | / .'   *_|    / _ *     ");
gotoxy(3,5);printf("| |       [  | [ `.-. |/ /__**   | |*  /| | | |          / ___ *    ");
gotoxy(3,6);printf("* `.___.'* | |  | | | || *__.,  _| |_*/_| |_* `.___.'* _/ /   * *_  ");
gotoxy(3,7);printf(" `.____ .'[___][___||__]'.__.' |_____||_____|`.____ .'|____| |____| ");



       do{

        co=241;
        gotoxy(cox,coy);t(co);printf("                                      ");
      gotoxy(cox,coy+1);t(co);printf("    Cartelera                         ");
      gotoxy(cox,coy+2);t(co);printf("                                      ");



      gotoxy(cox,coy+4);t(co);printf("                                      ");
      gotoxy(cox,coy+5);t(co);printf("    Compra de Boletos                 ");
      gotoxy(cox,coy+6);t(co);printf("                                      ");




      gotoxy(cox,coy+8);t(co);printf("                                      ");
      gotoxy(cox,coy+9);t(co);printf("    Facturacion                       ");
     gotoxy(cox,coy+10);t(co);printf("                                      ");

      gotoxy(cox,coy+12);t(co);printf("                                      ");
      gotoxy(cox,coy+13);t(co);printf("    Informacion                       ");
      gotoxy(cox,coy+14);t(co);printf("                                      ");

      gotoxy(cox,coy+16);t(co);printf("                                      ");
      gotoxy(cox,coy+17);t(co);printf("    Salir                             ");
      gotoxy(cox,coy+18);t(co);printf("                                      ");

//t(240);gotoxy(5,17);printf("                                        ");
co=10;
  switch(op)
  {

case 1 : t(co);
      gotoxy(cox,coy);t(co);printf("                                      ");
      gotoxy(cox,coy+1);t(co);printf("    Cartelera                         ");
      gotoxy(cox,coy+2);t(co);printf("                                      ");

      t(10);
gotoxy(imx,imy+1);printf(" .----------------. ");
gotoxy(imx,imy+2);printf("| .--------------. |");
gotoxy(imx,imy+3);printf("| |  __________  | |");
gotoxy(imx,imy+4);printf("| | |>>>>>>>>>>| | |");
gotoxy(imx,imy+5);printf("| | |----------| | |");
gotoxy(imx,imy+6);printf("| | |          | | |");
gotoxy(imx,imy+7);printf("| | |          | | |");
gotoxy(imx,imy+8);printf("| | |__________| | |");
gotoxy(imx,imy+9);printf("| |              | |");
gotoxy(imx,imy+10);printf("| '--------------' |");
gotoxy(imx,imy+11);printf(" '----------------' ");
      break;

      case 2 : t(co);
       gotoxy(cox,coy+4);t(co);printf("                                      ");
      gotoxy(cox,coy+5);t(co);printf("    Compra de Boletos                 ");
      gotoxy(cox,coy+6);t(co);printf("                                      ");
        t(10);
gotoxy(imx,imy+1);printf(" .----------------. ");
gotoxy(imx,imy+2);printf("| .--------------. |");
gotoxy(imx,imy+3);printf("| |    __||___   | |");
gotoxy(imx,imy+4);printf("| |   /  ___  |  | |");
gotoxy(imx,imy+5);printf("| |  |  (__ *_|  | |");
gotoxy(imx,imy+6);printf("| |   '.___`-.   | |");
gotoxy(imx,imy+7);printf("| |  |`*____) |  | |");
gotoxy(imx,imy+8);printf("| |  |_______.'  | |");
gotoxy(imx,imy+9);printf("| |       ||     | |");
gotoxy(imx,imy+10);printf("| '--------------' |");
gotoxy(imx,imy+11);printf(" '----------------' ");
break;
case 3: t(co);
      gotoxy(cox,coy+8);t(co);printf("                                      ");
      gotoxy(cox,coy+9);t(co);printf("    Facturacion                       ");
     gotoxy(cox,coy+10);t(co);printf("                                      ");

gotoxy(imx,imy+1);printf(" .----------------. ");
gotoxy(imx,imy+2);printf("| .--------------. |");
gotoxy(imx,imy+3);printf("| |  _________   | |");
gotoxy(imx,imy+4);printf("| | |_   ___  |  | |");
gotoxy(imx,imy+5);printf("| |   | |_  *_|  | |");
gotoxy(imx,imy+6);printf("| |   |  _|      | |");
gotoxy(imx,imy+7);printf("| |  _| |_       | |");
gotoxy(imx,imy+8);printf("| | |_____|      | |");
gotoxy(imx,imy+9);printf("| |              | |");
gotoxy(imx,imy+10);printf("| '--------------' |");
gotoxy(imx,imy+11);printf(" '----------------' ");
break;
case 4 : t(co);
      gotoxy(cox,coy+12);t(co);printf("                                      ");
      gotoxy(cox,coy+13);t(co);printf("    Informacion                       ");
      gotoxy(cox,coy+14);t(co);printf("                                      ");

gotoxy(imx,imy+1);printf(" .----------------. ");
gotoxy(imx,imy+2);printf("| .--------------. |");
gotoxy(imx,imy+3);printf("| |     _____    | |");
gotoxy(imx,imy+4);printf("| |    |_   _|   | |");
gotoxy(imx,imy+5);printf("| |      | |     | |");
gotoxy(imx,imy+6);printf("| |      | |     | |");
gotoxy(imx,imy+7);printf("| |     _| |_    | |");
gotoxy(imx,imy+8);printf("| |    |_____|   | |");
gotoxy(imx,imy+9);printf("| |              | |");
gotoxy(imx,imy+10);printf("| '--------------' |");
gotoxy(imx,imy+11);printf(" '----------------' ");
break;
case 5 : t(co);
      gotoxy(cox,coy+16);t(co);printf("                                      ");
      gotoxy(cox,coy+17);t(12);printf("    Salir                             ");
      gotoxy(cox,coy+18);t(co);printf("                                      ");
t(10);
gotoxy(imx,imy+1);printf(" .----------------. ");
gotoxy(imx,imy+2);printf("| .--------------. |");
gotoxy(imx,imy+3);printf("| |  ____  ____  | |");
gotoxy(imx,imy+4);printf("| | |_  _||_  _| | |");
gotoxy(imx,imy+5);printf("| |   \ \  / /   | |");
gotoxy(imx,imy+6);printf("| |    > `' <    | |");
gotoxy(imx,imy+7);printf("| |  _/ /'`\ \_  | |");
gotoxy(imx,imy+8);printf("| | |____||____| | |");
gotoxy(imx,imy+9);printf("| |              | |");
gotoxy(imx,imy+10);printf("| '--------------' |");
gotoxy(imx,imy+11);printf(" '----------------' ");
break;

  }



   do{
      tecla=getch();
      }while(tecla!=72 && tecla!=80 && tecla!=80 && tecla!=13 );
//tecla 13 enter

      if(tecla==72)
      {

       if(op>0)
       {
       op--;
       }
       }
       if(tecla==80)
      {

       if(op<6)
       {
       op++;
       }
       }
if(op==6)
       {
       op=1;
       }
       if(op==0)
       {
       op=5;
       }
       }while(tecla!=13);

}

// Funcion para imprimir en pantalla la cartelera.
void cartelera(){
   int tecla, op=1,i;
   int opc;
   do{
      marcos();
      do{
         t(10);gotoxy(40,12);printf("Peliculas Disponibles");
         t(10);gotoxy(40,14);printf("Mi villano favorito 3");
         t(10);gotoxy(40,15);printf("Bay watch");
         t(10);gotoxy(40,16);printf("Cars3");
         t(10);gotoxy(40,17);printf("El circulo");
         t(10);gotoxy(40,18); printf("No toques dos veces");
         t(10);gotoxy(40,19); printf("Volver al menu");
         switch(op){
         case 1:
            t(14);gotoxy(40,14);printf("Mi villano favorito 3");break;
         case 2:
            t(14);gotoxy(40,15);printf("Bay watch");break;
         case 3:
            t(14);gotoxy(40,16);printf("Cars3");break;
         case 4:
            t(14);gotoxy(40,17);printf("El circulo");break;
         case 5:
            t(14);gotoxy(40,18);printf("No toques dos veces");break;
         case 6:
            t(14);gotoxy(40,19); printf("Volver al menu");
         }
         do{
            tecla=getch();
         }while(tecla!=72 && tecla!=80 && tecla!=80 && tecla!=13 );
         if(tecla==72){
            if(op>0){
               op--;
            }
         }
         if(tecla==80){
            if(op<7){
               op++;
            }
         }
         if(op==7){
            op=1;  
         }
         if(op==0){
            op=6;
         }
      }while(tecla!=13);
      switch(op){
         case 1:
         {
            gotoxy(40,25);printf("\nSinopsis : Mi villano favorito\n");
            printf("\nNuevas aventuras de Gru, Lucy, sus adorables hijas\nMargo, Edith y Agnes y por supuesto los Minions. En\nesta ocasión veremos como el gemelo de Gru,\ndesparecido hace muchísimos años, emerge, lo que\nocasionará una enorme rivalidad entre hermanos.");
            system("pause");
         }break;
         case 2:
         {
            gotoxy(2,25);printf("Sinopsis : Bay watch\n");
            printf("\nNarra la historia del esforzado socorrista Mitch\nBuchannon y su choque de personalidades con un\nbravucón socorrista novato. Juntos, descubren una\ntrama delictiva local que amenaza el futuro de la\nBahía.");
            system("pause");
         }break;
         case 3:
         {
            gotoxy(2,25);printf("Sinopsis : Cars 3");
            printf("\nSorprendido por una nueva generación de\ncorredores ultrarrápidos, el legendario Rayo\nMcQueen queda relegado repentinamente del\ndeporte que tanto ama. Para retomar su carrera, va\na necesitar la ayuda de una joven mecánica de\ncarreras, Cruz Ramírez, que tiene su propio plan para\nganar, además de la inspiración del fallecido\nFabuloso Hudson Hornet y un par de giros\ninesperados. ¡Y para probar que el nº95 no está ni\nmucho menos acabado, el campeón tendrá que\nponer a prueba su valía en el gran circuito de la\nCopa Pistón!");
            system("pause");
         }break;
         case 4:
         {
            gotoxy(2,25);printf("Sinopsis : El circulo\n");
            printf("\nEl día que Mae Holland es contratada para trabajar\nen el Círculo, la empresa de internet más influyente\ndel mundo, sabe que se le ha concedido la\noportunidad de su vida. A través de un innovador\nsistema operativo, el Círculo unifica direcciones de\nemail, perfiles de redes sociales, operaciones\nbancarias y contraseñas de usuarios dando lugar a\nuna única identidad virtual y veraz, en pos de una\nnueva era marcada por la transparencia.");
            system("pause");
         }break;
         case 5:
         {
            gotoxy(2,25);printf("Sinopsis : No toques dos veces\n");
            printf("Jess, es una mujer que está intentando reestablecer\nsu relación con su problemática hija, Chloe, quien\nuna noche toca la puerta de una casa abandonada\ny libera a un terrible demonio que la atormentará a\nella y a su madre. Ahora ambas se verán obligadas\na confiar la una en la otra para librarse del horror de\nesta leyenda urbana que dice: “Toca una vez para\nlevantarla de su cama, toca dos veces para\nlevantarla de la muerte…");
            system("pause");
         }break;
         case 6:
               opc=6;break;
      }
      system("cls");
   }while(opc!=6);
}

// Funcion para imprimir en pantalla una imagen.
HWND BCX_Bitmap(char* Text, HWND hWnd, int id, int X, int Y, int W, int H, int Res, int Style, int Exstyle)
{
	HWND A;
	HBITMAP hBitmap;
	// set default style
	if (!Style) Style = WS_CLIPSIBLINGS | WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_TABSTOP;
	// form for the image
	A = CreateWindowEx(Exstyle, "static", NULL, Style, X, Y, 0, 0, hWnd, (HMENU)id, GetModuleHandle(0), NULL);
	// Text contains filename
	hBitmap = (HBITMAP)LoadImage(0, Text, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	// auto-adjust width and height
	if (W || H) hBitmap = (HBITMAP)CopyImage(hBitmap, IMAGE_BITMAP, W, H, LR_COPYRETURNORG);
	SendMessage(A, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hBitmap);
	if (W || H) SetWindowPos(A, HWND_TOP, X, Y, W, H, SWP_DRAWFRAME);
	return A;
}

HWND GetConsoleWndHandle(void)
{
	HWND hConWnd;
	OSVERSIONINFO os;
	char szTempTitle[64], szClassName[128], szOriginalTitle[1024];
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	if (os.dwPlatformId == VER_PLATFORM_WIN32s) return 0;
	GetConsoleTitle(szOriginalTitle, sizeof(szOriginalTitle));
	sprintf(szTempTitle, "%u - %u", GetTickCount(), GetCurrentProcessId());
	SetConsoleTitle(szTempTitle);
	Sleep(60);
	hConWnd = FindWindow(NULL, szTempTitle);
	SetConsoleTitle(szOriginalTitle);
	if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
	{
		hConWnd = GetWindow(hConWnd, GW_CHILD);
		if (hConWnd == NULL) return 0;
		GetClassName(hConWnd, szClassName, sizeof(szClassName));
		while (strcmp(szClassName, "ttyGrab") != 0)
		{
			hConWnd = GetNextWindow(hConWnd, GW_HWNDNEXT);
			if (hConWnd == NULL) return 0;
			GetClassName(hConWnd, szClassName, sizeof(szClassName));
		}
	}
	return hConWnd;
}

// Funcion para validar el ingreso de solo letras.
void validar_letras (char *p){
   int i;
   char tecla;
   i = 0;
   p[0] = '\0';
   do{
      tecla = getch ();
      if ( i > 0 && tecla == 8 ){
         printf ( "\b \b" );
         p[--i] = '\0';
      }else{
         if((tecla >= 65 && tecla <= 95) || (tecla >= 97 && tecla <= 122) || tecla == 32 ){
            printf ( "%c", tecla );
            p[i++] = tecla;
         }
      }
   }while((tecla != 13 || p[0] == '\0') && i < TAM);
   p[i] = '\0';
   return ;
}

// Funcion para validar el ingreso de solo numeros.
void validar_numeros(char *p){
   char i;
   int tecla;
   i = 0;
   p[0] = '\0';
   do{
      tecla = getch ();
      if ( i > 0 && tecla == 8 ){
         printf ( "\b \b" );
         p[--i] = '\0';
      }else{
         if((tecla >= 48 && tecla <= 57) || tecla == 32){
            printf ( "%c", tecla );
            p[i++] = tecla;
         }
      }
   }while((tecla != 13 || p[0] == '\0') && i < TAM);
   p[i] = '\0';
   return ;
}

// Funcion para validar el ingreso una cedula de ciudadania.
int validarcedula(long ci){
   long coc;
   int res,sumpar,sumimpar,cont,dv,mul,st;
   sumpar=sumimpar=0;
   cont=1;
   dv=ci%10;
   ci=ci/10;
   do{
      coc=ci/10;
      res=ci%10;
      if(cont==1){
         mul=res*2;
         if(mul>9)
         mul=mul-9;
         sumimpar+=mul;
         cont=2;
      }else{
         sumpar+=res;
         cont=1;
      }
      ci=coc;
   }while(coc!=0);
   st=sumpar+sumimpar;
   res=10-(st%10);
   if(res==10)
      res=0;
   if(res==dv){
      printf("\nSu digito verificador es : %d\n",dv);
      t(14);printf("\nEl numero de cedula es valido \n");t(10);
      return 1;
   }else{
      t(12);printf("\nEl numero de cedula ingresado es invalido");t(10);
      return 0;
   }
}


 void Lista() //Funcion para insertar un primer elemento en la lista
 {

     datos * p= new datos;
     fflush(stdin);
     printf("Ingrese el nombre\n");
     gets(p->nombre);

     printf("Ingrese el apellido\n");
     gets(p->apellido);

      printf("Ingrese el numero de cedula\n");
     gets(p->cedula);
     fflush(stdin);

     lista = p;
    lista->ant=NULL;
    lista->sig=NULL;


 }

void imprimirDatos(datos *c) //Funcion para imprimir la lista
{
    datos *k;
    k=c;
    do{
        printf("\t\tDATOS DE FACTURACION\n");
        printf("Nombre: ");
        puts(k->nombre);
        printf("Apellido: ");
        puts(k->apellido);
        printf("Cedula: ");
        puts(k->cedula);
        printf("%d\n",k->b1.adultos);
         printf("%d\n",k->b1.ninios);
         printf("%d\n",k->b1.TerEdad);
         printf("%.2f\n",k->b1.total);
        k=k->sig;

    }while(k!=NULL);
}


int main()
{
   printf("Cine");
    return 0;
}
