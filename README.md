HC-005 and NeuroSky Mindwave Mobile 2 Kablosuz EEG Ölçüm Cihazı ( Sensor Starter Kit)

AT command to pair HC-005 and NeuroSky Mindwave Mobile 2

/*
  *Configuration through AT Commands for HC-05
  *Pairing  Headset Neurosky Mindwave Mobile with Arduino
  *Commands:
  *   AT+UART=57600,0,0
  *   AT+ROLE=1
  *   AT+PSWD="0000"
  *   AT+CMODE=0
  *   AT+BIND=<Address>  ( 1234,56,ABCDEF )  2068,9D,79D995
  *   AT+IAC=9E8B33
  *   AT+CLASS=0
  *   AT+INQM=1,9,48
  *   
  *   Lozano Ramirez Angel Ivan
  *   02.07.2018
  *   NOTE: Set the Serial monitor with NL&CR and 9600 baud
*/
