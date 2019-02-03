EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L INA219:INA219 U1
U 1 1 5C2BCBB4
P 6900 1850
F 0 "U1" H 6900 2717 50  0000 C CNN
F 1 "INA219" H 6900 2626 50  0000 C CNN
F 2 "SOT23-8" H 6900 1850 50  0001 L BNN
F 3 "None" H 6900 1850 50  0001 L BNN
F 4 "Texas Instruments" H 6900 1850 50  0001 L BNN "Field4"
F 5 "None" H 6900 1850 50  0001 L BNN "Field5"
F 6 "the ina219 is a high-side current shunt and power monitor with an i2c interface. the ina219 monitors both shunt drop ..." H 6900 1850 50  0001 L BNN "Field6"
F 7 "Unavailable" H 6900 1850 50  0001 L BNN "Field7"
F 8 "INA219" H 6900 1850 50  0001 L BNN "Field8"
	1    6900 1850
	1    0    0    -1  
$EndComp
$Comp
L agg-kicad:DS3231MZ IC2
U 1 1 5C2BCD3E
P 3750 1900
F 0 "IC2" H 3750 2425 50  0000 C CNN
F 1 "DS3231MZ" H 3750 2334 50  0000 C CNN
F 2 "agg:SOIC-8" H 3250 1400 50  0001 L CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/DS3231M.pdf" H 3250 1300 50  0001 L CNN
F 4 "2515358" H 3250 1200 50  0001 L CNN "Farnell"
	1    3750 1900
	1    0    0    -1  
$EndComp
Text GLabel 6000 1750 0    50   Input ~ 0
WIRE_CLOCK
Text GLabel 2950 2100 0    50   Input ~ 0
WIRE_CLOCK
Wire Wire Line
	2950 2100 3150 2100
Text GLabel 6000 1850 0    50   BiDi ~ 0
WIRE_DATA
Text GLabel 2950 2000 0    50   BiDi ~ 0
WIRE_DATA
Wire Wire Line
	2950 2000 3150 2000
$Comp
L agg-kicad:R R3
U 1 1 5C2BCFD3
P 7650 1850
F 0 "R3" V 7654 1891 50  0000 L CNN
F 1 "R" V 7745 1891 50  0000 L CNN
F 2 "" H 7650 1850 50  0001 C CNN
F 3 "" H 7650 1850 50  0001 C CNN
	1    7650 1850
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 1750 7650 1750
Wire Wire Line
	7650 1750 7650 1850
Wire Wire Line
	7400 2050 7650 2050
Wire Wire Line
	7650 2050 7650 1950
$Comp
L agg-kicad:R R2
U 1 1 5C2BD102
P 6350 2100
F 0 "R2" V 6354 2141 50  0000 L CNN
F 1 "R" V 6445 2141 50  0000 L CNN
F 2 "" H 6350 2100 50  0001 C CNN
F 3 "" H 6350 2100 50  0001 C CNN
	1    6350 2100
	0    1    1    0   
$EndComp
$Comp
L agg-kicad:R R1
U 1 1 5C2BD1C8
P 6150 2200
F 0 "R1" V 6246 2159 50  0000 R CNN
F 1 "R" V 6155 2159 50  0000 R CNN
F 2 "" H 6150 2200 50  0001 C CNN
F 3 "" H 6150 2200 50  0001 C CNN
	1    6150 2200
	0    -1   -1   0   
$EndComp
Text GLabel 6000 1950 0    50   Input ~ 0
INA_219_A0
Text GLabel 6000 2050 0    50   Input ~ 0
INA219_A1
Wire Wire Line
	6000 1750 6400 1750
Wire Wire Line
	6000 1850 6400 1850
Wire Wire Line
	6000 1950 6150 1950
Wire Wire Line
	6000 2050 6350 2050
Wire Wire Line
	6150 2100 6150 1950
Connection ~ 6150 1950
Wire Wire Line
	6150 1950 6400 1950
Wire Wire Line
	6350 2100 6350 2050
Connection ~ 6350 2050
Wire Wire Line
	6350 2050 6400 2050
Wire Wire Line
	6350 2200 6350 2250
Wire Wire Line
	6350 2250 6400 2250
Wire Wire Line
	6350 2250 6250 2250
Wire Wire Line
	6150 2250 6150 2200
Connection ~ 6350 2250
$Comp
L agg-kicad:GND #PWR0101
U 1 1 5C2BD882
P 6250 2450
F 0 "#PWR0101" H 6120 2490 50  0001 L CNN
F 1 "GND" H 6250 2537 50  0000 C CNN
F 2 "" H 6250 2450 50  0001 C CNN
F 3 "" H 6250 2450 50  0001 C CNN
	1    6250 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 2450 6250 2250
Connection ~ 6250 2250
Wire Wire Line
	6250 2250 6150 2250
$Comp
L agg-kicad:ESP-WROOM-32 IC1
U 1 1 5C2BE017
P 3550 4950
F 0 "IC1" H 3550 6275 50  0000 C CNN
F 1 "ESP-WROOM-32" H 3550 6184 50  0000 C CNN
F 2 "agg:ESP-WROOM-32" H 2650 3650 50  0001 L CNN
F 3 "https://espressif.com/sites/default/files/documentation/esp_wroom_32_datasheet_en.pdf" H 2650 3550 50  0001 L CNN
	1    3550 4950
	1    0    0    -1  
$EndComp
Text GLabel 4800 5050 2    50   Output ~ 0
WIRE_CLOCK
Wire Wire Line
	4550 5050 4800 5050
Text GLabel 4800 5150 2    50   BiDi ~ 0
WIRE_DATA
Wire Wire Line
	4550 5150 4800 5150
$Comp
L agg-kicad:3v3 #PWR0102
U 1 1 5C2BE8B0
P 6000 1450
F 0 "#PWR0102" H 6000 1560 50  0001 L CNN
F 1 "3v3" H 6000 1574 50  0000 C CNN
F 2 "" H 6000 1450 50  0001 C CNN
F 3 "" H 6000 1450 50  0001 C CNN
	1    6000 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 1450 6000 1550
Wire Wire Line
	6000 1550 6400 1550
$Comp
L agg-kicad:GND #PWR0103
U 1 1 5C2BEC16
P 3050 2250
F 0 "#PWR0103" H 2920 2290 50  0001 L CNN
F 1 "GND" H 3050 2337 50  0000 C CNN
F 2 "" H 3050 2250 50  0001 C CNN
F 3 "" H 3050 2250 50  0001 C CNN
	1    3050 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2250 3050 1800
Wire Wire Line
	3050 1800 3150 1800
Text GLabel 4800 4350 2    50   Input ~ 0
SD_CABLE_SELECT
Text GLabel 4800 4550 2    50   Output ~ 0
SPI_MOSI
Wire Wire Line
	4550 4350 4800 4350
Wire Wire Line
	4550 4550 4800 4550
Text GLabel 4800 4450 2    50   Input ~ 0
SPI_CLOCK
Wire Wire Line
	4550 4450 4800 4450
Text GLabel 4800 3950 2    50   Input ~ 0
SPI_MISO
Wire Wire Line
	4550 3950 4800 3950
$Comp
L uSD_push-push_ebay:SD_ebay-uSD-push_push_SMD XS1
U 1 1 5C2C4E16
P 8750 3700
F 0 "XS1" H 8445 3654 50  0000 R CNN
F 1 "SD_ebay-uSD-push_push_SMD" H 8445 3745 50  0000 R CNN
F 2 "Connectors:Conn_uSDcard" H 8750 3700 10  0001 C CNN
F 3 "_" H 8750 3700 10  0001 C CNN
F 4 "_" H 8750 3700 10  0001 C CNN "Manf#"
F 5 "ebay" H 8750 3700 10  0001 C CNN "Manf"
	1    8750 3700
	-1   0    0    1   
$EndComp
Text GLabel 8050 3850 0    50   Input ~ 0
SD_CABLE_SELECT
Text GLabel 8050 4150 0    50   Input ~ 0
SPI_CLOCK
Text GLabel 8050 3400 0    50   Input ~ 0
SPI_MISO
Text GLabel 8050 4000 0    50   Output ~ 0
SPI_MOSI
Wire Wire Line
	8400 3850 8375 3850
Connection ~ 8375 3850
Wire Wire Line
	8375 3850 8050 3850
Wire Wire Line
	8400 4000 8375 4000
Connection ~ 8375 4000
Wire Wire Line
	8375 4000 8050 4000
Wire Wire Line
	8400 4150 8375 4150
Connection ~ 8375 4150
Wire Wire Line
	8375 4150 8050 4150
Wire Wire Line
	8400 3400 8375 3400
Connection ~ 8375 3400
Wire Wire Line
	8375 3400 8050 3400
$EndSCHEMATC
