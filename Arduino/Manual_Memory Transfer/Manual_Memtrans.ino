
#define WREN 00000110
#define WRDI 00000100
#define RDSR 00000101
#define WRSR 00000001
#define READ 00000011
#define WRITE 00000010

uint32_t spi_transfer(uint32_t data){
   SPDR =data;
   while(!(SPSR &= (1<<SPIF)))
   {
    
   };
   return SPDR;
   
}


uint8_t eeprom_read(uint32_t e_addr)
{
  uint8_t read_data;
  PORTB&= ~(1<<PORTB1);
  spi_transfer(READ);
  spi_transfer((e_addr)>>8);
  spi_transfer((e_addr)&0xFF);
  read_data=spi_transfer(0x00);
  PORTB &= (1<<PORTB1);
  return read_data;    
}

void eeprom_write(uint32_t e_addr,uint8_t data)
{
  PORTB&= ~(1<<PORTB1);
  spi_transfer(WREN);
  PORTB &= (1<<PORTB2);
  PORTB&= ~(1<<PORTB2);
  spi_transfer(WRITE); 
  spi_transfer((e_addr)>>8);
  spi_transfer((e_addr)&0xFF);
  spi_transfer(data);
  PORTB &= (1<<PORTB1);
}

uint8_t sram_read(uint32_t s_addr)
{
  uint8_t read_data;
  PORTB&= ~(1<<PORTB2);
  spi_transfer(READ);
  spi_transfer((s_addr)>>8);
  spi_transfer((s_addr)&0xFF);
  read_data=spi_transfer(0x00);
  PORTB &= (1<<PORTB2);
  return read_data;    
}

void sram_write(uint32_t s_addr,uint8_t data)
{
  PORTB &= ~(1<<PORTB2);
  spi_transfer(WRITE); 
  spi_transfer((s_addr)>>8);
  spi_transfer((s_addr)&0xFF);
  spi_transfer(data);
  PORTB &= (1<<PORTB2);
}

void memory_transfer(uint32_t e_addr, uint32_t s_addr, uint8_t data)
{ 
  uint8_t temp=0;
  eeprom_write(e_addr, data);
  delay(50);
  temp = eeprom_read(e_addr);
  sram_write( s_addr,  temp);
  delay(50);
}


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 Serial.print("hi");
 SPCR &= ~(1<<DORD);
 SPCR &= (1<<SPE | 1<<MSTR);
 uint8_t out_data=0;
 uint8_t in_data=24;
 uint32_t s_addr=24;
 uint32_t e_addr=39;
 memory_transfer(s_addr,e_addr,in_data);
 out_data = sram_read(s_addr);
 Serial.println(in_data);
 Serial.print(out_data);
 
 
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
