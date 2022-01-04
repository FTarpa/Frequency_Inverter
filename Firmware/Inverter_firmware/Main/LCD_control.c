#include <mqx.h>
#include <bsp.h>
#include <fio.h>
#include "App.h"


/*-------------------------------------------------------------------------------------------------------------
  Запись команды
-------------------------------------------------------------------------------------------------------------*/
void LCD_wr_cmd(int cmd)
{
  int i;
  LCD_SCB(0);
  DELAY_1us;
  LCD_RS(0);
  DELAY_1us;
  for (i=0;i<8;i++)
  {
    if ( (cmd & 0x80)!=0 )
      LCD_SI(1);
    else
      LCD_SI(0);
    cmd <<=1;
    DELAY_1us;
    LCD_SCL(0);
    DELAY_1us;
    LCD_SCL(1);
    DELAY_1us;
    LCD_SCL(0);
    DELAY_1us;
  }
  LCD_SCB(1);
  LCD_SI(0);
  DELAY_30us;
}

/*-------------------------------------------------------------------------------------------------------------
  Запись команды
-------------------------------------------------------------------------------------------------------------*/
void LCD_wr_data(int data)
{
  int i;
  LCD_SCB(0);
  DELAY_1us;
  LCD_RS(1);
  DELAY_1us;
  for (i=0;i<8;i++)
  {
    if ( (data & 0x80)!=0 )
      LCD_SI(1);
    else
      LCD_SI(0);
    data <<=1;
    DELAY_1us;
    LCD_SCL(0);
    DELAY_1us;
    LCD_SCL(1);
    DELAY_1us;
    LCD_SCL(0);
    DELAY_1us;
  }
  LCD_SCB(1);
  LCD_RS(0);
  LCD_SI(0);
  DELAY_1us;
}

/*-------------------------------------------------------------------------------------------------------------
  Вывести символ в заданную позицию
-------------------------------------------------------------------------------------------------------------*/
void LCD_print_str(char *str, int x, int y)
{
  LCD_set_pos(x,y);
  while (*str)
  {
    LCD_wr_data(*str++);
  }
}

/*-------------------------------------------------------------------------------------------------------------
  Вывести символ в заданную позицию
-------------------------------------------------------------------------------------------------------------*/
void LCD_print_char(char ch, int x, int y)
{
  LCD_set_pos(x,y);
  LCD_wr_data(ch);
}

/*-------------------------------------------------------------------------------------------------------------
  Установить текущую позицию вывода
-------------------------------------------------------------------------------------------------------------*/
void LCD_set_pos(int x, int y)
{
  unsigned char addr;
  addr = y*0x40+x;
  LCD_wr_cmd(addr + 0x80);     
}

/*-------------------------------------------------------------------------------------------------------------
 
-------------------------------------------------------------------------------------------------------------*/
void LCD_clear_row(int row)
{
  int i;
  LCD_set_pos(0, row & 1);
  for (i=0;i<16;i++)
  {
    LCD_wr_data(0x20);
  }
}
/*-------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------*/
void LCD_init(void)
{
  LCD_RST(0);
  _time_delay_ticks(1);
  LCD_RST(1);
  _time_delay_ticks(8);
  LCD_wr_cmd(0x30);     //wake up
  _time_delay_ticks(1);
  LCD_wr_cmd(0x30);     //wake up
  LCD_wr_cmd(0x30);     //wake up
  LCD_wr_cmd(0x39);     //function set. 8-bit bus mode, 2-line display mode is set, display font is normal (5x8 dot), extension instruction be selected
  LCD_wr_cmd(0x14);     //internal osc frequency. bias will be 1/5 , Frame frequency ( Hz ) = 183
  LCD_wr_cmd(0x56);     //power control. ICON display off, booster circuit is turn on.
  LCD_wr_cmd(0x6D);     //internal follower circuit is turn on, 
  LCD_wr_cmd(0x70);     //contrast
  LCD_wr_cmd(0x0C);     //display on
  LCD_wr_cmd(0x06);     //entry mode
  LCD_wr_cmd(0x01);     //clear
  _time_delay_ticks(2);
}
