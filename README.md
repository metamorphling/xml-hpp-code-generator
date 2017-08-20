# xml-hpp-code-generator
Example of parsing XML data into HPP header using RapidXML. Sorting output data into mappings and vectors.

Tested on Ubuntu 16 and GCC 5.4.0  
Just type "make" in shell under Debug folder.  
Program accepts header name(should be same as xml file) and list of includes.  
Example usage:  
  
:~/workspace/xml-hpp-code-generator/Debug$ ./VectorListHeader   
Enter header name:  
CommandList      
Enter includes(to stop CTRL+D):  
map  
vector  
string  
  
Starting...  

0) COMMAND_ID_START_SND = 00
1) COMMAND_ID_START_RCV = 60
2) COMMAND_ID_READ_FLAGS_SND = 01
3) COMMAND_ID_READ_FLAGS_RCV = 61
4) COMMAND_ID_WRITE_FLAGS_SND = 02
5) COMMAND_ID_WRITE_FLAGS_RCV = 62
6) COMMAND_ID_GET_RTC_SND = 03
7) COMMAND_ID_GET_RTC_RCV = 63
8) COMMAND_ID_WIFI_FREQ_CHANGE_SND = 04
9) COMMAND_ID_WIFI_FREQ_CHANGE_RCV = 64
10) COMMAND_ID_READ_MACADDRESS_SND = 05
11) COMMAND_ID_READ_MACADDRESS_RCV = 65
12) COMMAND_ID_END_SND = FE
13) COMMAND_ID_END_RCV = FE
0) COMMAND_ID_START_SND = 00
1) COMMAND_ID_START_RCV = 60
2) COMMAND_ID_READ_FLAGS_SND = 01
3) COMMAND_ID_READ_FLAGS_RCV = 61
4) COMMAND_ID_WRITE_FLAGS_SND = 02
5) COMMAND_ID_WRITE_FLAGS_RCV = 62
6) COMMAND_ID_GET_RTC_SND = 03
7) COMMAND_ID_GET_RTC_RCV = 63
8) COMMAND_ID_WIFI_FREQ_CHANGE_SND = 04
9) COMMAND_ID_WIFI_FREQ_CHANGE_RCV = 64
10) COMMAND_ID_READ_MACADDRESS_SND = 05
11) COMMAND_ID_READ_MACADDRESS_RCV = 65
12) COMMAND_ID_END_SND = FE
13) COMMAND_ID_END_RCV = FE
