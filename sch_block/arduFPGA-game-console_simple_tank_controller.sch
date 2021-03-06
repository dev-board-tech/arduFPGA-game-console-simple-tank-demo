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
Wire Notes Line
	2750 2550 2750 5050
Wire Notes Line
	2750 5050 4250 5050
Wire Notes Line
	4250 5050 4250 2550
Wire Notes Line
	4250 2550 2750 2550
Text Notes 2900 3850 0    50   ~ 0
Freenove Three-wheeled Smart\nCar Kit for Raspberry Pi
Wire Notes Line
	1650 2550 2500 2550
Wire Notes Line
	2500 2550 2500 2900
Wire Notes Line
	2500 2900 1650 2900
Wire Notes Line
	1650 2900 1650 2550
Wire Notes Line
	1650 2950 2500 2950
Wire Notes Line
	2500 2950 2500 3300
Wire Notes Line
	2500 3300 1650 3300
Wire Notes Line
	1650 3300 1650 2950
Text Notes 1850 2750 0    50   ~ 0
Motor Right
Text Notes 1850 3150 0    50   ~ 0
Motor Left
Wire Notes Line
	1650 3350 2500 3350
Wire Notes Line
	2500 3350 2500 3650
Wire Notes Line
	2500 3650 1650 3650
Wire Notes Line
	1650 3650 1650 3350
Wire Notes Line
	1650 3700 2500 3700
Wire Notes Line
	1650 4000 2500 4000
Wire Notes Line
	2500 3700 2500 4000
Wire Notes Line
	1650 3700 1650 4000
Text Notes 1700 3550 0    50   ~ 0
Servomotor up to \n       four
Text Notes 1950 3850 0    50   ~ 0
Buzer
Wire Notes Line
	1650 4050 2500 4050
Wire Notes Line
	2500 4050 2500 4350
Wire Notes Line
	2500 4350 1650 4350
Wire Notes Line
	1650 4350 1650 4050
Wire Notes Line
	1650 4400 2500 4400
Wire Notes Line
	2500 4400 2500 4700
Wire Notes Line
	2500 4700 1650 4700
Wire Notes Line
	1650 4700 1650 4400
Text Notes 1650 4250 0    50   ~ 0
Piezo distance sensor
Text Notes 1800 4600 0    50   ~ 0
Three IO pins
Wire Notes Line
	2750 1800 4250 1800
Wire Notes Line
	4250 1800 4250 2350
Wire Notes Line
	4250 2350 2750 2350
Wire Notes Line
	2750 2350 2750 1800
Text Notes 2950 2100 0    50   ~ 0
ROBOTIS BIOLOID BLUETOOTH\n      Remote receiver
Wire Notes Line
	5250 2050 7000 2050
Wire Notes Line
	7000 2050 7000 5050
Wire Notes Line
	5250 5050 5250 2050
Wire Notes Line
	5550 2300 6700 2300
Wire Notes Line
	6700 2300 6700 2950
Wire Notes Line
	6700 2950 5550 2950
Wire Notes Line
	5550 2950 5550 2300
Wire Notes Line
	5850 3150 5850 3250
Wire Notes Line
	5850 3250 5700 3250
Wire Notes Line
	5700 3250 5700 3150
Wire Notes Line
	5700 3150 5850 3150
Wire Notes Line
	5700 3800 5700 3900
Wire Notes Line
	5700 3900 5850 3900
Wire Notes Line
	5850 3900 5850 3800
Wire Notes Line
	5850 3800 5700 3800
Wire Notes Line
	5450 3450 5450 3600
Wire Notes Line
	5450 3600 5550 3600
Wire Notes Line
	5550 3600 5550 3450
Wire Notes Line
	5550 3450 5450 3450
Wire Notes Line
	6000 3450 6000 3600
Wire Notes Line
	6000 3600 6100 3600
Wire Notes Line
	6100 3600 6100 3450
Wire Notes Line
	6100 3450 6000 3450
Wire Notes Line
	6350 3700 6350 3850
Wire Notes Line
	6350 3850 6450 3850
Wire Notes Line
	6450 3850 6450 3700
Wire Notes Line
	6450 3700 6350 3700
Wire Notes Line
	6650 3300 6650 3450
Wire Notes Line
	6650 3450 6750 3450
Wire Notes Line
	6750 3450 6750 3300
Wire Notes Line
	6750 3300 6650 3300
Wire Notes Line
	5500 5050 5500 5100
Wire Wire Line
	5600 5100 5600 5300
Wire Notes Line
	5250 5050 7000 5050
Wire Notes Line
	5800 5100 5800 5050
Wire Notes Line
	5500 5100 5800 5100
$Comp
L power:GND #PWR?
U 1 1 60A93401
P 5550 5850
F 0 "#PWR?" H 5550 5600 50  0001 C CNN
F 1 "GND" H 5555 5677 50  0000 C CNN
F 2 "" H 5550 5850 50  0001 C CNN
F 3 "" H 5550 5850 50  0001 C CNN
	1    5550 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 5100 5550 5850
Wire Wire Line
	5600 5300 5150 5300
Wire Wire Line
	5150 2100 4250 2100
Wire Wire Line
	5150 2100 5150 5300
Wire Wire Line
	5650 5350 5100 5350
Wire Wire Line
	5100 5350 5100 3500
Wire Wire Line
	5100 3500 4250 3500
Wire Wire Line
	5650 5100 5650 5350
Wire Wire Line
	5700 5400 5050 5400
Wire Wire Line
	5050 5400 5050 3650
Wire Wire Line
	5050 3650 4250 3650
Wire Wire Line
	5700 5100 5700 5400
Text Notes 4350 3650 0    50   ~ 0
SDA
Text Notes 4350 3500 0    50   ~ 0
SCL
Text Notes 4300 2200 0    50   ~ 0
UART RX to\n\narduFPGA
Wire Wire Line
	5750 5450 4950 5450
Wire Wire Line
	4950 5450 4950 3950
Wire Wire Line
	4950 3950 4250 3950
Wire Wire Line
	5750 5100 5750 5450
Text Notes 4250 3950 0    50   ~ 0
5V arduFPGA charge
$Comp
L power:GND #PWR?
U 1 1 60A9C1E8
P 3700 5800
F 0 "#PWR?" H 3700 5550 50  0001 C CNN
F 1 "GND" H 3705 5627 50  0000 C CNN
F 2 "" H 3700 5800 50  0001 C CNN
F 3 "" H 3700 5800 50  0001 C CNN
	1    3700 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 60A9D701
P 4450 2400
F 0 "#PWR?" H 4450 2150 50  0001 C CNN
F 1 "GND" H 4455 2227 50  0000 C CNN
F 2 "" H 4450 2400 50  0001 C CNN
F 3 "" H 4450 2400 50  0001 C CNN
	1    4450 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 2250 4450 2250
Wire Wire Line
	4450 2250 4450 2400
Wire Wire Line
	3700 5800 3700 5050
$Comp
L power:+3.3V #PWR?
U 1 1 60AA14BD
P 4450 1800
F 0 "#PWR?" H 4450 1650 50  0001 C CNN
F 1 "+3.3V" H 4465 1973 50  0000 C CNN
F 2 "" H 4450 1800 50  0001 C CNN
F 3 "" H 4450 1800 50  0001 C CNN
	1    4450 1800
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 60AA202A
P 4450 2850
F 0 "#PWR?" H 4450 2700 50  0001 C CNN
F 1 "+3.3V" H 4465 3023 50  0000 C CNN
F 2 "" H 4450 2850 50  0001 C CNN
F 3 "" H 4450 2850 50  0001 C CNN
	1    4450 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 1950 4450 1950
Wire Wire Line
	4450 1950 4450 1800
Wire Wire Line
	4250 3050 4450 3050
Wire Wire Line
	4450 3050 4450 2850
Wire Notes Line
	5300 2150 5300 2300
Wire Notes Line
	5300 2300 5400 2300
Wire Notes Line
	5400 2300 5400 2150
Wire Notes Line
	5400 2150 5300 2150
Wire Wire Line
	2500 2750 2750 2750
Wire Wire Line
	2500 3100 2750 3100
Wire Wire Line
	2500 3500 2750 3500
Wire Wire Line
	2500 3850 2750 3850
Wire Wire Line
	2500 4150 2750 4150
Wire Wire Line
	2500 4550 2750 4550
Text Notes 5200 5400 0    50   ~ 0
D-
Text Notes 5300 5350 0    50   ~ 0
D+
Text Notes 5400 5300 0    50   ~ 0
ID
Wire Wire Line
	2500 4250 2750 4250
Text Notes 2550 4150 0    50   ~ 0
Trig
Text Notes 2550 4250 0    50   ~ 0
Echo
Text Notes 2550 2750 0    50   ~ 0
PWM
Text Notes 2550 3100 0    50   ~ 0
PWM
$EndSCHEMATC
