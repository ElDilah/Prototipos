#include "MAX7219.h"
struct tablasignos 

Max_init(int value){
  const char tab[5]= {0x09, 0x0A, 0x0B, 0x0C, 0x0f}
  static int i;
  static int n;
  setup_spi(SPI_MASTER | SPI_SCK_IDLE_LOW | SPI_CLK_DIV_4 | SPI_XMIT_L_TO_H | SPI_SAMPLE_AT_MIDDLE); // primero se declara el puerto en el que se usara este parametro ha de cambiarse dependiendo del Mc usado
  for (i=0;i<5;i++){
  output_low(PIN_A5);
   switch (i)
   {
   case 0:
      for (n=0;n<value;n++){
          spi_write(tab[i]);
          spi_write(0x00); // no se descodifica el valor obtenido por bus spi 
      }
          output_high(PIN_A5);
    break;
   case 1:
      for (n=0;n<value;n++)  { 
         spi_write(tab[i]);
      spi_write(0x0F);
      }
      output_high(PIN_A5);
   
    break;
    case 2:
      for (n=0;n<value;n++){
         spi_write(tab[i]);
        spi_write(0x07);
      }
        output_high(PIN_A5);
  
    break;
    case 3:
      for (n=0;n<value;n++){
         spi_write(tab[i]);
         spi_write(0x01);
      }
      output_high(PIN_A5);
    break;
    case 4:
      for (n=0;n<value;n++){
         spi_write(tab[i]);
         spi_write(0x00);
      }
      output_high(PIN_A5);
    break;
   default:
    break;
   }

}
}
void Max_print(long val){
  int n,i,j;
  long k= val;
  int ar[20]; //reservo memoria para 20 numeros maximo.
  //detectar cuantos numeros hay que pasar 
  while(k!=0){
    k=k/10;
  n++;
  }
  // lectura y posicionamientod de los valores 
  k=val;
  for (i=0;i<n;i++){
     ar[n-1-i]=k % 10;
     k=k/10;
     }
  struct signos valor[8];
//se cargas en ram los valores ded la tabla 
//valor 0
valor[0].signo[0]=0b00011000;
valor[0].signo[1]=0b00111100;
valor[0].signo[2]=0b01100110;
valor[0].signo[3]=0b01100110;
valor[0].signo[4]=0b01100110;
valor[0].signo[5]=0b01100110;
valor[0].signo[6]=0b00111100;
valor[0].signo[7]=0b00011000;
//valor 1
valor[1].signo[0]=0b00011100;
valor[1].signo[1]=0b00111100;
valor[1].signo[2]=0b01101100;
valor[1].signo[3]=0b01001100;
valor[1].signo[4]=0b00001100;
valor[1].signo[5]=0b00001100;
valor[1].signo[6]=0b00001100;
valor[1].signo[7]=0b00001100;
//val 2 

  const char tab[8]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
  for (j=0;j<8;j++){
    output_low(PIN_A5);
    spi_write(tab[j]);
    for (i=n;i==0;i--){
      spi_write(valor[arr[val]].signo[j]);
    }
    output_high(PIN_A5);
  }

}