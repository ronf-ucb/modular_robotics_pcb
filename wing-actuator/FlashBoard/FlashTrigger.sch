EESchema Schematic File Version 4
EELAYER 30 0
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
L Amplifier_Operational:LM741 U?
U 1 1 5F0E0057
P 9200 4000
F 0 "U?" H 9544 4046 50  0000 L CNN
F 1 "LM741" H 9544 3955 50  0000 L CNN
F 2 "" H 9250 4050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm741.pdf" H 9350 4150 50  0001 C CNN
	1    9200 4000
	1    0    0    -1  
$EndComp
Text Notes 9400 3850 0    50   ~ 0
MCP6281 op amp
$Comp
L power:+3V3 #PWR?
U 1 1 5F0E1CAE
P 9100 3250
F 0 "#PWR?" H 9100 3100 50  0001 C CNN
F 1 "+3V3" H 9115 3423 50  0000 C CNN
F 2 "" H 9100 3250 50  0001 C CNN
F 3 "" H 9100 3250 50  0001 C CNN
	1    9100 3250
	1    0    0    -1  
$EndComp
$Comp
L Driver_Motor:TB6612FNG U?
U 1 1 5F0E26F0
P 3950 3800
F 0 "U?" H 3950 2711 50  0000 C CNN
F 1 "TB6612FNG" H 3950 2620 50  0000 C CNN
F 2 "Package_SO:SSOP-24_5.3x8.2mm_P0.65mm" H 5250 2900 50  0001 C CNN
F 3 "https://toshiba.semicon-storage.com/us/product/linear/motordriver/detail.TB6612FNG.html" H 4400 4400 50  0001 C CNN
	1    3950 3800
	1    0    0    -1  
$EndComp
$Comp
L Transformer:ADT1.5-17 TR?
U 1 1 5F0E8F19
P 6500 3750
F 0 "TR?" H 6500 4131 50  0000 C CNN
F 1 "ADT1.5-17" H 6500 4040 50  0000 C CNN
F 2 "RF_Mini-Circuits:Mini-Circuits_CD542_H2.84mm" H 6500 3750 50  0001 C CNN
F 3 "https://www.minicircuits.com/pdfs/ADT1.5-17+.pdf" H 6500 3750 50  0001 C CNN
	1    6500 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F0EE5FA
P 9100 4550
F 0 "#PWR?" H 9100 4300 50  0001 C CNN
F 1 "GND" H 9105 4377 50  0000 C CNN
F 2 "" H 9100 4550 50  0001 C CNN
F 3 "" H 9100 4550 50  0001 C CNN
	1    9100 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F0EEECC
P 8200 3700
F 0 "R?" H 8268 3746 50  0000 L CNN
F 1 "R_US" H 8268 3655 50  0000 L CNN
F 2 "" V 8240 3690 50  0001 C CNN
F 3 "~" H 8200 3700 50  0001 C CNN
	1    8200 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R?
U 1 1 5F0F0287
P 8200 4250
F 0 "R?" H 8268 4296 50  0000 L CNN
F 1 "R_US" H 8268 4205 50  0000 L CNN
F 2 "" V 8240 4240 50  0001 C CNN
F 3 "~" H 8200 4250 50  0001 C CNN
	1    8200 4250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F0F0BC8
P 7700 3700
F 0 "C?" H 7815 3746 50  0000 L CNN
F 1 "C" H 7815 3655 50  0000 L CNN
F 2 "" H 7738 3550 50  0001 C CNN
F 3 "~" H 7700 3700 50  0001 C CNN
	1    7700 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:D D?
U 1 1 5F0F1AEC
P 7300 3550
F 0 "D?" H 7300 3333 50  0000 C CNN
F 1 "D" H 7300 3424 50  0000 C CNN
F 2 "" H 7300 3550 50  0001 C CNN
F 3 "~" H 7300 3550 50  0001 C CNN
	1    7300 3550
	-1   0    0    1   
$EndComp
Text GLabel 10300 4000 0    50   Input ~ 0
V_OUT
Text GLabel 6300 3050 0    50   Input ~ 0
PWM_IN
$Comp
L 74xGxx:74LVC2G14 U?
U 1 1 5F101B96
P 2200 4100
F 0 "U?" H 2175 4367 50  0000 C CNN
F 1 "74LVC2G14" H 2175 4276 50  0000 C CNN
F 2 "" H 2200 4100 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/sn74lvc2g14.pdf" H 2200 4100 50  0001 C CNN
	1    2200 4100
	1    0    0    -1  
$EndComp
$Comp
L 74xGxx:74LVC2G14 U?
U 2 1 5F104860
P 2200 3700
F 0 "U?" H 2175 3967 50  0000 C CNN
F 1 "74LVC2G14" H 2175 3876 50  0000 C CNN
F 2 "" H 2200 3700 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/sn74lvc2g14.pdf" H 2200 3700 50  0001 C CNN
	2    2200 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 4100 1900 4250
Wire Wire Line
	3350 4250 3350 4200
Text GLabel 1650 4100 0    50   Input ~ 0
DIR2
Text GLabel 1600 3700 0    50   Input ~ 0
DIR1
Text GLabel 1950 2900 0    50   Input ~ 0
PWMA
Text GLabel 1950 3150 0    50   Input ~ 0
PWMB
Wire Wire Line
	2750 3900 2750 3700
Wire Wire Line
	2300 3700 2450 3700
Connection ~ 2450 3700
Wire Wire Line
	2450 3700 2750 3700
Wire Wire Line
	3100 2900 3100 3600
Wire Wire Line
	3100 3600 3350 3600
Wire Wire Line
	1950 2900 3100 2900
Wire Wire Line
	2650 3150 2650 3650
Wire Wire Line
	2650 3650 3050 3650
Wire Wire Line
	3350 3650 3350 3700
Connection ~ 2650 3150
Wire Wire Line
	2650 3150 2950 3150
Wire Wire Line
	1900 4250 3350 4250
Wire Wire Line
	2450 4100 3350 4100
Wire Wire Line
	2750 3900 3350 3900
Wire Wire Line
	3350 4000 2600 4000
Wire Wire Line
	2600 4000 2600 3850
Wire Wire Line
	2600 3850 1900 3850
Wire Wire Line
	1900 3850 1900 3700
Wire Wire Line
	1600 3700 1900 3700
Connection ~ 1900 3700
Connection ~ 1900 4100
Wire Wire Line
	1650 4100 1900 4100
Wire Wire Line
	1950 3150 2650 3150
Wire Wire Line
	3350 3700 3050 3700
Wire Wire Line
	3050 3700 3050 3650
Connection ~ 3350 3700
$EndSCHEMATC
