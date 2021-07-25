EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 2 2
Title "RCtoUSB QFN version"
Date ""
Rev "1.0"
Comp "Quantum Embedded Systems"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:C C?
U 1 1 610327E9
P 1000 1550
AR Path="/610327E9" Ref="C?"  Part="1" 
AR Path="/60FF3F14/610327E9" Ref="C5"  Part="1" 
F 0 "C5" H 1115 1596 50  0000 L CNN
F 1 "2.2 uF" H 1115 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1038 1400 50  0001 C CNN
F 3 "~" H 1000 1550 50  0001 C CNN
	1    1000 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 610327EF
P 2900 1550
AR Path="/610327EF" Ref="C?"  Part="1" 
AR Path="/60FF3F14/610327EF" Ref="C7"  Part="1" 
F 0 "C7" H 3015 1596 50  0000 L CNN
F 1 "1 uF" H 3015 1505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2938 1400 50  0001 C CNN
F 3 "~" H 2900 1550 50  0001 C CNN
	1    2900 1550
	1    0    0    -1  
$EndComp
$Comp
L SamacSys_Parts:AP2210N-3.3TRG1 U?
U 1 1 610327FB
P 1400 1350
AR Path="/610327FB" Ref="U?"  Part="1" 
AR Path="/60FF3F14/610327FB" Ref="U3"  Part="1" 
F 0 "U3" H 1950 1615 50  0000 C CNN
F 1 "AP2210N-3.3TRG1" H 1950 1524 50  0000 C CNN
F 2 "SamacSys_Parts:SOT95P280X145-3N" H 2350 1450 50  0001 L CNN
F 3 "" H 2350 1350 50  0001 L CNN
F 4 "DiodesZetex AP2210N-3.3TRG1, Low Noise LDO Voltage Regulator, 300mA, 3.3 V +/-2%, 2.5  13.2 Vin, 3-Pin SOT-23" H 2350 1250 50  0001 L CNN "Description"
F 5 "1.45" H 2350 1150 50  0001 L CNN "Height"
F 6 "621-AP2210N-3.3TRG1" H 2350 1050 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.co.uk/ProductDetail/Diodes-Incorporated/AP2210N-33TRG1?qs=x6A8l6qLYDCg5Ghihwjj3A%3D%3D" H 2350 950 50  0001 L CNN "Mouser Price/Stock"
F 8 "Diodes Inc." H 2350 850 50  0001 L CNN "Manufacturer_Name"
F 9 "AP2210N-3.3TRG1" H 2350 750 50  0001 L CNN "Manufacturer_Part_Number"
	1    1400 1350
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 61032801
P 2100 5050
AR Path="/61032801" Ref="R?"  Part="1" 
AR Path="/60FF3F14/61032801" Ref="R6"  Part="1" 
F 0 "R6" H 2170 5096 50  0000 L CNN
F 1 "120" H 2170 5005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2030 5050 50  0001 C CNN
F 3 "~" H 2100 5050 50  0001 C CNN
	1    2100 5050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61032807
P 2550 5050
AR Path="/61032807" Ref="R?"  Part="1" 
AR Path="/60FF3F14/61032807" Ref="R7"  Part="1" 
F 0 "R7" H 2620 5096 50  0000 L CNN
F 1 "120" H 2620 5005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2480 5050 50  0001 C CNN
F 3 "~" H 2550 5050 50  0001 C CNN
	1    2550 5050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 6103280D
P 9000 1250
AR Path="/6103280D" Ref="J?"  Part="1" 
AR Path="/60FF3F14/6103280D" Ref="J6"  Part="1" 
F 0 "J6" H 9080 1292 50  0000 L CNN
F 1 "ICSP" H 9080 1201 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9000 1250 50  0001 C CNN
F 3 "~" H 9000 1250 50  0001 C CNN
	1    9000 1250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J?
U 1 1 61032813
P 5000 5050
AR Path="/61032813" Ref="J?"  Part="1" 
AR Path="/60FF3F14/61032813" Ref="J5"  Part="1" 
F 0 "J5" H 5080 5092 50  0000 L CNN
F 1 "SAT" H 5080 5001 50  0000 L CNN
F 2 "JST-withZH:JST_ZH_B3B-ZR_1x03_P1.50mm_Vertical" H 5000 5050 50  0001 C CNN
F 3 "~" H 5000 5050 50  0001 C CNN
	1    5000 5050
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61032819
P 9650 2350
AR Path="/61032819" Ref="R?"  Part="1" 
AR Path="/60FF3F14/61032819" Ref="R10"  Part="1" 
F 0 "R10" H 9720 2396 50  0000 L CNN
F 1 "10K" H 9720 2305 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 9580 2350 50  0001 C CNN
F 3 "~" H 9650 2350 50  0001 C CNN
	1    9650 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6103281F
P 2250 2750
AR Path="/6103281F" Ref="C?"  Part="1" 
AR Path="/60FF3F14/6103281F" Ref="C6"  Part="1" 
F 0 "C6" H 2365 2796 50  0000 L CNN
F 1 "10 uF" H 2365 2705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2288 2600 50  0001 C CNN
F 3 "~" H 2250 2750 50  0001 C CNN
	1    2250 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 1250 8400 1350
$Comp
L dk_Transistors-FETs-MOSFETs-Single:2N7002P_215 Q?
U 1 1 61032873
P 5450 5750
AR Path="/61032873" Ref="Q?"  Part="1" 
AR Path="/60FF3F14/61032873" Ref="Q2"  Part="1" 
F 0 "Q2" H 5558 5803 60  0000 L CNN
F 1 "2N7002P_215" H 5558 5697 60  0000 L CNN
F 2 "digikey-footprints:SOT-23-3" H 5650 5950 60  0001 L CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/2N7002P.pdf" H 5650 6050 60  0001 L CNN
F 4 "1727-4692-1-ND" H 5650 6150 60  0001 L CNN "Digi-Key_PN"
F 5 "2N7002P,215" H 5650 6250 60  0001 L CNN "MPN"
F 6 "Discrete Semiconductor Products" H 5650 6350 60  0001 L CNN "Category"
F 7 "Transistors - FETs, MOSFETs - Single" H 5650 6450 60  0001 L CNN "Family"
F 8 "https://assets.nexperia.com/documents/data-sheet/2N7002P.pdf" H 5650 6550 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/nexperia-usa-inc/2N7002P,215/1727-4692-1-ND/2531105" H 5650 6650 60  0001 L CNN "DK_Detail_Page"
F 10 "MOSFET N-CH 60V 0.36A SOT-23" H 5650 6750 60  0001 L CNN "Description"
F 11 "Nexperia USA Inc." H 5650 6850 60  0001 L CNN "Manufacturer"
F 12 "Active" H 5650 6950 60  0001 L CNN "Status"
	1    5450 5750
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_B_Mini J?
U 1 1 61032879
P 1650 3600
AR Path="/61032879" Ref="J?"  Part="1" 
AR Path="/60FF3F14/61032879" Ref="J4"  Part="1" 
F 0 "J4" H 1707 4067 50  0000 C CNN
F 1 "USB_B_Mini" H 1707 3976 50  0000 C CNN
F 2 "Connector_USB:USB_Mini-B_Wuerth_65100516121_Horizontal" H 1800 3550 50  0001 C CNN
F 3 "~" H 1800 3550 50  0001 C CNN
	1    1650 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 6103287F
P 9200 3200
AR Path="/6103287F" Ref="C?"  Part="1" 
AR Path="/60FF3F14/6103287F" Ref="C8"  Part="1" 
F 0 "C8" H 9315 3246 50  0000 L CNN
F 1 "0.1 uF" H 9315 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9238 3050 50  0001 C CNN
F 3 "~" H 9200 3200 50  0001 C CNN
	1    9200 3200
	1    0    0    -1  
$EndComp
$Comp
L SamacSys_Parts:FSM16JH S?
U 1 1 6103288B
P 7200 5850
AR Path="/6103288B" Ref="S?"  Part="1" 
AR Path="/60FF3F14/6103288B" Ref="S2"  Part="1" 
F 0 "S2" H 7800 6115 50  0000 C CNN
F 1 "FSM16JH" H 7800 6024 50  0000 C CNN
F 2 "SamacSys_Parts:FSM16JH" H 8250 5950 50  0001 L CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=showdoc&DocId=Customer+Drawing%7F1825910%7FC10%7Fpdf%7FEnglish%7FENG_CD_1825910_C10.pdf%7F3-1825910-1" H 8250 5850 50  0001 L CNN
F 4 "Tactile Switches 6MM TACT SWITCH" H 8250 5750 50  0001 L CNN "Description"
F 5 "17.3" H 8250 5650 50  0001 L CNN "Height"
F 6 "506-FSM16JH" H 8250 5550 50  0001 L CNN "Mouser Part Number"
F 7 "https://www.mouser.co.uk/ProductDetail/TE-Connectivity-PB/FSM16JH/?qs=eA0sQYb2Mifk48vugSh4aw%3D%3D" H 8250 5450 50  0001 L CNN "Mouser Price/Stock"
F 8 "TE Connectivity" H 8250 5350 50  0001 L CNN "Manufacturer_Name"
F 9 "FSM16JH" H 8250 5250 50  0001 L CNN "Manufacturer_Part_Number"
	1    7200 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 61032891
P 4700 6200
AR Path="/61032891" Ref="R?"  Part="1" 
AR Path="/60FF3F14/61032891" Ref="R8"  Part="1" 
F 0 "R8" H 4770 6246 50  0000 L CNN
F 1 "10K" H 4770 6155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4630 6200 50  0001 C CNN
F 3 "~" H 4700 6200 50  0001 C CNN
	1    4700 6200
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D?
U 1 1 61032897
P 2100 5500
AR Path="/61032897" Ref="D?"  Part="1" 
AR Path="/60FF3F14/61032897" Ref="D3"  Part="1" 
F 0 "D3" V 2139 5382 50  0000 R CNN
F 1 "LED" V 2048 5382 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 2100 5500 50  0001 C CNN
F 3 "~" H 2100 5500 50  0001 C CNN
	1    2100 5500
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D?
U 1 1 6103289D
P 2550 5500
AR Path="/6103289D" Ref="D?"  Part="1" 
AR Path="/60FF3F14/6103289D" Ref="D4"  Part="1" 
F 0 "D4" V 2589 5382 50  0000 R CNN
F 1 "LED" V 2498 5382 50  0000 R CNN
F 2 "LED_SMD:LED_0805_2012Metric" H 2550 5500 50  0001 C CNN
F 3 "~" H 2550 5500 50  0001 C CNN
	1    2550 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2500 1350 2900 1350
Wire Wire Line
	2900 1350 2900 1000
Wire Wire Line
	2900 1400 2900 1350
Connection ~ 2900 1350
Wire Wire Line
	2900 1700 2900 1800
Wire Wire Line
	2900 1800 1950 1800
Wire Wire Line
	1950 1800 1950 1900
Wire Wire Line
	1400 1250 1000 1250
Wire Wire Line
	1000 1700 1000 1800
Wire Wire Line
	1000 1800 1400 1800
Connection ~ 1950 1800
Wire Wire Line
	1000 1250 1000 1400
Connection ~ 1000 1250
Wire Wire Line
	1400 1350 1400 1800
Connection ~ 1400 1800
Wire Wire Line
	1400 1800 1950 1800
Wire Wire Line
	9200 3050 8900 3050
Wire Wire Line
	2650 2800 2650 2850
Wire Wire Line
	2250 2900 2250 3050
Wire Wire Line
	8800 1150 8550 1150
Wire Wire Line
	8550 1150 8550 850 
Wire Wire Line
	8800 1250 8400 1250
Wire Wire Line
	8550 1350 8800 1350
Wire Wire Line
	8700 1450 8800 1450
Wire Wire Line
	8650 5850 8400 5850
Wire Wire Line
	8400 5950 8500 5950
Wire Wire Line
	8500 5950 8500 6150
Wire Wire Line
	7200 5850 7200 5500
Wire Wire Line
	7200 5500 8650 5500
Wire Wire Line
	8650 5500 8650 5850
Wire Wire Line
	7200 5950 7200 6150
Wire Wire Line
	3100 4550 2100 4550
Wire Wire Line
	2100 4550 2100 4900
Wire Wire Line
	3200 4750 2550 4750
Wire Wire Line
	2550 4750 2550 4900
Wire Wire Line
	2100 5200 2100 5350
Wire Wire Line
	2550 5200 2550 5350
Wire Wire Line
	2100 5650 2100 5900
Wire Wire Line
	2100 5900 2350 5900
Wire Wire Line
	2350 5900 2350 5950
Wire Wire Line
	2550 5650 2550 5900
Wire Wire Line
	2550 5900 2350 5900
Connection ~ 2350 5900
Wire Wire Line
	5200 4950 5300 4950
Wire Wire Line
	5300 4950 5300 4700
Wire Wire Line
	5200 5050 5450 5050
Wire Wire Line
	5450 5050 5450 5350
Wire Wire Line
	3350 5850 4700 5850
Wire Wire Line
	4700 6050 4700 5850
Connection ~ 4700 5850
Wire Wire Line
	4700 5850 5150 5850
Wire Wire Line
	5450 5950 5450 6350
Connection ~ 5450 6350
Wire Wire Line
	5450 6350 5450 6500
Wire Wire Line
	4700 6350 5450 6350
Wire Wire Line
	5550 4600 5550 5150
Wire Wire Line
	5550 5150 5200 5150
$Comp
L Device:R R?
U 1 1 61032912
P 6400 5800
AR Path="/61032912" Ref="R?"  Part="1" 
AR Path="/60FF3F14/61032912" Ref="R9"  Part="1" 
F 0 "R9" H 6470 5846 50  0000 L CNN
F 1 "0R" H 6470 5755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 6330 5800 50  0001 C CNN
F 3 "~" H 6400 5800 50  0001 C CNN
	1    6400 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 5650 6400 5350
Wire Wire Line
	6400 5350 5450 5350
Connection ~ 5450 5350
Wire Wire Line
	5450 5350 5450 5550
Wire Wire Line
	6400 5950 6400 6350
Wire Wire Line
	6400 6350 5450 6350
Text GLabel 3550 3950 2    50   BiDi ~ 0
Vusb2
Text GLabel 2900 1000 2    50   BiDi ~ 0
Vusb2
Wire Wire Line
	7200 6150 7800 6150
$Comp
L power:GND2 #PWR017
U 1 1 6103B76F
P 1950 1900
F 0 "#PWR017" H 1950 1650 50  0001 C CNN
F 1 "GND2" H 1955 1727 50  0000 C CNN
F 2 "" H 1950 1900 50  0001 C CNN
F 3 "" H 1950 1900 50  0001 C CNN
	1    1950 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR018
U 1 1 6103BF00
P 2250 3050
F 0 "#PWR018" H 2250 2800 50  0001 C CNN
F 1 "GND2" H 2255 2877 50  0000 C CNN
F 2 "" H 2250 3050 50  0001 C CNN
F 3 "" H 2250 3050 50  0001 C CNN
	1    2250 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR020
U 1 1 6103CABD
P 2650 2850
F 0 "#PWR020" H 2650 2600 50  0001 C CNN
F 1 "GND2" H 2655 2677 50  0000 C CNN
F 2 "" H 2650 2850 50  0001 C CNN
F 3 "" H 2650 2850 50  0001 C CNN
	1    2650 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR019
U 1 1 6103F8C2
P 2350 5950
F 0 "#PWR019" H 2350 5700 50  0001 C CNN
F 1 "GND2" H 2355 5777 50  0000 C CNN
F 2 "" H 2350 5950 50  0001 C CNN
F 3 "" H 2350 5950 50  0001 C CNN
	1    2350 5950
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR022
U 1 1 61042607
P 5450 6500
F 0 "#PWR022" H 5450 6250 50  0001 C CNN
F 1 "GND2" H 5455 6327 50  0000 C CNN
F 2 "" H 5450 6500 50  0001 C CNN
F 3 "" H 5450 6500 50  0001 C CNN
	1    5450 6500
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR024
U 1 1 61045168
P 7800 6150
F 0 "#PWR024" H 7800 5900 50  0001 C CNN
F 1 "GND2" H 7805 5977 50  0000 C CNN
F 2 "" H 7800 6150 50  0001 C CNN
F 3 "" H 7800 6150 50  0001 C CNN
	1    7800 6150
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR016
U 1 1 61047DC4
P 1550 4200
F 0 "#PWR016" H 1550 3950 50  0001 C CNN
F 1 "GND2" H 1555 4027 50  0000 C CNN
F 2 "" H 1550 4200 50  0001 C CNN
F 3 "" H 1550 4200 50  0001 C CNN
	1    1550 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR028
U 1 1 6104A9AD
P 9200 3800
F 0 "#PWR028" H 9200 3550 50  0001 C CNN
F 1 "GND2" H 9205 3627 50  0000 C CNN
F 2 "" H 9200 3800 50  0001 C CNN
F 3 "" H 9200 3800 50  0001 C CNN
	1    9200 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND2 #PWR025
U 1 1 6104D52B
P 8400 1350
F 0 "#PWR025" H 8400 1100 50  0001 C CNN
F 1 "GND2" H 8405 1177 50  0000 C CNN
F 2 "" H 8400 1350 50  0001 C CNN
F 3 "" H 8400 1350 50  0001 C CNN
	1    8400 1350
	1    0    0    -1  
$EndComp
Connection ~ 7800 6150
Wire Wire Line
	7800 6150 8500 6150
$Comp
L power:+3V3 #PWR026
U 1 1 61051B9C
P 8550 850
F 0 "#PWR026" H 8550 700 50  0001 C CNN
F 1 "+3V3" H 8565 1023 50  0000 C CNN
F 2 "" H 8550 850 50  0001 C CNN
F 3 "" H 8550 850 50  0001 C CNN
	1    8550 850 
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR021
U 1 1 61052C70
P 5300 4700
F 0 "#PWR021" H 5300 4550 50  0001 C CNN
F 1 "+3V3" H 5315 4873 50  0000 C CNN
F 2 "" H 5300 4700 50  0001 C CNN
F 3 "" H 5300 4700 50  0001 C CNN
	1    5300 4700
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR015
U 1 1 61053682
P 1000 1100
F 0 "#PWR015" H 1000 950 50  0001 C CNN
F 1 "+3V3" H 1015 1273 50  0000 C CNN
F 2 "" H 1000 1100 50  0001 C CNN
F 3 "" H 1000 1100 50  0001 C CNN
	1    1000 1100
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR029
U 1 1 61054199
P 9650 2200
F 0 "#PWR029" H 9650 2050 50  0001 C CNN
F 1 "+3V3" H 9665 2373 50  0000 C CNN
F 2 "" H 9650 2200 50  0001 C CNN
F 3 "" H 9650 2200 50  0001 C CNN
	1    9650 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 1100 1000 1250
$Comp
L PIC18F27J53-QFN:pic18lf27j53-i_ml U4
U 1 1 6105EB0F
P 3900 2400
F 0 "U4" H 5925 2787 60  0000 C CNN
F 1 "pic18lf27j53-i_ml" H 5925 2681 60  0000 C CNN
F 2 "PIC18-QFN:pic18lf27j53-i&slash_ml" H 7700 2640 60  0001 C CNN
F 3 "" H 3900 2400 60  0000 C CNN
	1    3900 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 2600 3900 2600
Wire Wire Line
	2650 2800 3900 2800
Wire Wire Line
	3350 3100 3900 3100
Wire Wire Line
	3100 3200 3900 3200
Wire Wire Line
	3100 3200 3100 4550
Wire Wire Line
	3200 4750 3200 3300
Wire Wire Line
	3200 3300 3900 3300
Wire Wire Line
	3350 3100 3350 5850
Wire Wire Line
	9200 3350 9200 3700
Wire Wire Line
	7950 3500 8650 3500
Wire Wire Line
	8650 3500 8650 5500
Connection ~ 8650 5500
Wire Wire Line
	7950 3600 8900 3600
Wire Wire Line
	8900 3050 8900 3600
Wire Wire Line
	7950 3700 9200 3700
Connection ~ 9200 3700
Wire Wire Line
	9200 3700 9200 3800
Wire Wire Line
	9650 2500 9650 2700
Wire Wire Line
	7950 2700 8150 2700
$Comp
L power:+3V3 #PWR027
U 1 1 61052632
P 8900 3050
F 0 "#PWR027" H 8900 2900 50  0001 C CNN
F 1 "+3V3" H 8915 3223 50  0000 C CNN
F 2 "" H 8900 3050 50  0001 C CNN
F 3 "" H 8900 3050 50  0001 C CNN
	1    8900 3050
	1    0    0    -1  
$EndComp
Connection ~ 8900 3050
Wire Wire Line
	8800 1050 8150 1050
Wire Wire Line
	8150 1050 8150 2700
Connection ~ 8150 2700
Wire Wire Line
	8150 2700 9650 2700
Wire Wire Line
	7950 2800 8550 2800
Wire Wire Line
	8550 2800 8550 1350
Wire Wire Line
	7950 2900 8700 2900
Wire Wire Line
	8700 2900 8700 1450
Wire Wire Line
	7950 4600 7950 3800
Wire Wire Line
	5550 4600 7950 4600
$Comp
L power:GND2 #PWR023
U 1 1 610C3873
P 7500 1900
F 0 "#PWR023" H 7500 1650 50  0001 C CNN
F 1 "GND2" V 7505 1772 50  0000 R CNN
F 2 "" H 7500 1900 50  0001 C CNN
F 3 "" H 7500 1900 50  0001 C CNN
	1    7500 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	7950 2400 7950 1900
Wire Wire Line
	7950 1900 7500 1900
Wire Wire Line
	1950 3600 3900 3600
Wire Wire Line
	1950 3700 2500 3700
Wire Wire Line
	2500 3700 2500 3500
Wire Wire Line
	2500 3500 3900 3500
Wire Wire Line
	1950 3800 1950 4200
Wire Wire Line
	1950 4200 1650 4200
Wire Wire Line
	1650 4000 1650 4200
Connection ~ 1650 4200
Wire Wire Line
	1650 4200 1550 4200
Wire Wire Line
	1550 4000 1550 4200
Connection ~ 1550 4200
Wire Wire Line
	1950 3400 3550 3400
Wire Wire Line
	3550 3950 3550 3400
Connection ~ 3550 3400
Wire Wire Line
	3550 3400 3900 3400
$EndSCHEMATC