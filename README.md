# Laser Shutter Tester v2.1   
![Logo](/images/LaserShutterTesterLogo.png)
### Opis po polsku poniżej!
#### Images below PL description!
# ENG
#### Description
Laser Shutter Tester (LST) v2.1 was designed for testing camera shutters. It is based on laser beam and a photoelement (e.g. phototransistor), which measures how long the beam passes through open shutter.   
It must be noted that is a very basic version of this device, which can be further developed and upgraded in many ways.  
LST uses following modules:
1. Arduino Uno
2. Keyes KY-008 Laser
3. Vishay TEPT5600 phototransistor
4. 0.96" 128x64 ISP OLED display
5. 100kOhm resistor (or other, according to below description)  

Every one of the mentioned modules can be replaced with a right equivalent. Mentioned laser module can be exchanged, however I suggest using this exact one - it's small, easy to use and mount on the device. Laser beam can be detected by any suitable photoelement. However, you should keep in mind that too slow reaction of the element to the light change will prevent LST from measuring short exposure times. OLED display is handy in this application due to its small size and flexibility.  
All modules were mounted on a wooden frame to provide rigidity and stability of the laser beam.  
LST can be powered from any USB port: in PC, laptop, DC charger or powerbank.  
In the presented configuration, the LST can be used for measuring shutter times as short as 0.00061s (enough for speed of 1/1000s). The program is using Arduino micros() function which, combined with Arduino Uno 16MHz clock, produces resolution of 4us. The phototransistor, according to the datasheet [2] has got rise and fall time of 310us. In the worst case scenario, the total rise and fall time is 620us, measured with resolution of 4us. If a better performance is needed, a load resistor of the phototransistor should be replaced as described in [2].
The Vishay TEPT5600 phototransistor was selected as a very cheap module, easily accesible, with good documentation and reliability. It can be replaced with another phototransistor or photodiode. It is necessary to keep in mind that the photoelement has to be sensitive to the light spectre which we are using, in this case: the red laser which wavelength is about 635-670nm. The TEPT5600 is sensible to visible light with a peak sensitivity at 570nm.
It is strongly advised not to use photoresistors as their rise and fall times are usually between several up to dozens of milliseconds, not microseconds as the photodiodes and phototransistors.

#### Usage
After powering up the LST it will boot and display "Ready..." on the screen. Afterwards, the tested shutter should be placed between laser emitter and sensor (the laser's beam must be placed within the shutter area). Next the camera should be fired at preselected shutter time. The measured time will be displayed on the screen. If it will longer than 1 second, it will be displayed as a decimal fraction. If the measured time will be shorter than 1 second, it will be displayed as both decimal and proper fraction.
  
#### Code description
The used code is self explanatory, with addition of the inline comments.
The libraries used in the code are:
1. built-in Arduino Wire.h library
2. Adafruit GFX library: https://github.com/adafruit/Adafruit-GFX-Library
3. Adafruit SSD1306 library: https://github.com/adafruit/Adafruit_SSD1306  
  
#### Schematic
![ENG: Device schematic. PL: Schemat urządzenia.](/images/laser2_bb.png) 
  
#### Resources
[1] Vishay TEPT5600 datasheet: https://www.vishay.com/docs/84768/tept5600.pdf
[2] Vishay phototransistors information: https://www.vishay.com/docs/84154/appnotesensors.pdf

# PL
#### Opis
Zadaniem LST (Laser Shutter Tester, Laserowego Testera Migawki) jest sprawdzanie poprawności działania migawki aparatu fotograficznego. Jego działanie opiera się na wykorzystaniu wiązki światła laserowego, padającego na fotoelement.  
Należy podkreślić, że jest to wersja podstawowa, która może być dopracowana i ulepszona na różne sposoby.  
LST wykorzystuje następujące moduły:
1. Arduino Uno
2. Laser Keyes KY-008
3. Fototranzystor Vishay TEPT5600
4. Wyświetlacz OLED 0.96" 128x64 ISP

Każdy z wymienionych modułów może zostać zastąpiony odpowiednim zamiennikiem. Wymieniony moduł lasera może być wymieniony na inny, jednak ten sugeruję wykorzystanie właśnie tego - jest nieduży, wygodny, bezproblemowy w podłączeniu, uruchomieniu, zamocowaniu na ramie urządzenia. Wykorzystany moduł można znaleźć na aliexpress pod nazwą "arduino laser sensor". Detektorem promienia lasera może być dowolny fotoelement, jednak należy mieć na uwadze czas reakcji fotoelementu na zmianę natężenia oświetlenia - zbyt długi czas treakcji uniemożliwi pomiar krótkich czasów otwarcia migawki. Wyświetlacz OLED jest wygodny w powyższym zastosowaniu ze względu na nieduży rozmiar i możliwość elastycznego wyświetlania elementów.  
Aby zapewnić stabilność urządzenia i stałe padanie lasera na fotoelement, wszystkie elementy zostały zamocowane na ramie, skonstruowanej z listwy drewnianej i kątowników.  
LST może być zasilany z dowolnego zasilanego portu USB: w komputerze, ładowarce do telefonu, powerbanku, itp.  
W prezentowanej konfiguracji, LST może służyć do mierzenia czasów od 0.00061s (co jest wartością wystarczającą dla czasów migawki do 1/1000s włącznie). Program dla mikrokontrolera Arduino wykorzystuje funkcję micros(), która w połączeniu z 16-megahercowym zegarem Arduino Uno, zapewnia rozdzielczość 4us. Fototranzystor, zgodnie z dokumentacją [2] cechuje się czasami narastania i opadania o długości 310us. W najgorszym przypadku, całkowity czas narastania i opadania może wynosić więc 620us, mierzone z rozdzielczością 4us. Jeśli konieczna jest wyższa dokładność, rezystor w układzie fototranzystora powinien zostać zmieniony, zgodnie z dokumentacją [2].
Fototranzystor Vishay TEPT5600 został wybrany jako bardzo tani, łatwo dostępny, pewny moduł, którego producent oferuje zadodwalającą dokumentację. Może być on zastąpiony innym fototranzystorem lub fotodiodą. Należy jednak mieć na uwadze spektrum światła, jakie będzie używane - w tym przypadku, światło czerwonego lasera o długości między 635 a 670nm. Fototranzystor TEPT5600 jest uczulony na światło widzialne, ze szczytem wrażliwości dla fal o długości 570nm.
Wysoce zalecane jest nieużywanie fotorezystorów, ze względu na ich czasu narastania i opadania, liczne zazwyczaj w milisekundach, nie zaś mikrosekundach, jak w przypadku fotodiod oraz fototranzystorów.
  
#### Użycie
Po włączeniu urządzenia i wyświetleniu informacji "Ready..." na wyświetlaczu, należy umieścić badany aparat na drodze wiązki (plamka lasera musi się znajdować w obrębie migawki). Następnie należy wyzwolić aparat na uprzednio ustawionym, badanym czasie. Na ekranie zostanie wyświetlony zmierzony czas. W przypadku czasu dłuższego niż 1 sekunda, czas ten będzie wyświetlony jako ułamek dziesiętny. Jeśli czas będzie krótszy od 1 sekundy, wyświetlony zostanie czas w postaci ułamka zwykłego oraz dziesiętnego.  
  
#### Opis kodu
W kodzie programu wykorzystano następujące biblioteki:
1. Wbudowaną bibliotekę Arduino Wire.h
2. Bibliotekę Adafruit GFX: https://github.com/adafruit/Adafruit-GFX-Library
3. Bibliotekę Adafruit SSD1306: https://github.com/adafruit/Adafruit_SSD1306
  
#### Materiały
[1] Dokumentacja Vishay TEPT5600: https://www.vishay.com/docs/84768/tept5600.pdf
[2] Informacje o fototranzysotrach Vishay: https://www.vishay.com/docs/84154/appnotesensors.pdf
  
## Photos
  
_ENG: Completed device. PL: Zbudowane urządzenie._  
![ENG: Completed device. PL: Zbudowane urządzenie.](/images/LST.png)  
  
_ENG: Device scheme. PL: Schemat urządzenia._  
![ENG: Device scheme. PL: Schemat urządzenia.](/images/laser_bb.png)  

