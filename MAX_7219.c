#include "MAX7219.h"
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
void Max_print(char val){

}