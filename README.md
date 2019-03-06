# Laser Shutter Tester v1.0  
![Logo](/images/LaserShutterTesterLogo.png)
### Opis po polsku poniżej!
#### Images below PL description!
# ENG
#### Description
Laser Shutter Tester (LST) was designed for testing camera shutters. It is based on laser beam and a photoelement (e.g. photoresistor), which measures how long the beam passes through open shutter.   
It must be noted that is a very basic version of this device, which can be further developed and upgraded in many ways.  
LST uses following modules:
1. NodeMCU v1.0
2. Keyes KY-008 Laser
3. Keyes KY-018 photoresistor module
4. 0.96" 128x64 ISP OLED display
  
Every one of the mentioned modules can be replaced with a right equivalent. NodeMCU module was use as the main part of the project due to fact, that the author had it close at hand. Mentioned laser module can be exchanged, however I suggest using this exact one - it's small, easy to use and mount on the device. Laser beam can be detected by any suitable photoelement. However, you should keep in mind that too slow reaction of the element to the light change will prevent LST from measuring short exposure times. OLED display is handy in this application due to its small size and flexibility.  
All modules were mounted on a wooden frame to provide rigidity and stability of the laser beam.  
LST can be powered from any USB port: in PC, laptop, DC charger or powerbank.  
Accuracy of the device is 1ms, which means that it is possible to test shutter times up to 1/1000 second. Due to controller parameters it is possible to upgrade the accuracy to microseconds and test even shorter times. Such a modification requires changing the adequate part of the code and ensuring that the photoelement can react properly to such short light impulses.

#### Usage
After powering up the LST it will boot and display "Ready..." on the screen. After this the tested shutter should be placed between laser emitter and sensor (the laser's beam must be placed within the shutter area). Next the camera should be fired at preselected shutter time. The measured time will be displayed on the screen. If it will longer than 1 second, it will be displayed as a decimal fraction. If the measured time will be shorter than 1 second, it will be displayed as both decimal and proper fraction.

# PL
#### Opis
Zadaniem LST (Laser Shutter Tester, Laserowego Testera Migawki) jest sprawdzanie poprawności działania migawki aparatu fotograficznego. Jego działanie opiera się na wykorzystaniu wiązki światła laserowego, padającego na fotoelement.  
Należy podkreślić, że jest to wersja podstawowa, która może być dopracowana i ulepszona na różne sposoby.  
LST wykorzystuje następujące moduły:
1. NodeMCU v1.0
2. Laser Keyes KY-008
3. Moduł fotorezystora Keyes KY-018
4. Wyświetlacz OLED 0.96" 128x64 ISP

Każdy z wymienionych modułów może zostać zastąpiony odpowiednim zamiennikiem. Moduł NodeMCU został wykorzystany jako "serce" projektu jedynie ze względu na to, że autor akurat miał go pod ręką. Wymieniony moduł lasera może być wymieniony na inny, jednak ten sugeruję wykorzystanie właśnie tego - jest nieduży, wygodny, bezproblemowy w podłączeniu, uruchomieniu, zamocowaniu na ramie urządzenia. Wykorzystany moduł można znaleźć na aliexpress pod nazwą "arduino laser sensor". Detektorem promienia lasera może być dowolny fotoelement, jednak należy mieć na uwadze czas reakcji fotoelementu na zmianę natężenia oświetlenia - zbyt długi czas treakcji uniemożliwi pomiar krótkich czasów otwarcia migawki. Wyświetlacz OLED jest wygodny w powyższym zastosowaniu ze względu na nieduży rozmiar i możliwość elastycznego wyświetlania elementów.  
Aby zapewnić stabilność urządzenia i stałe padanie lasera na fotoelement, wszystkie elementy zostały zamocowane na ramie, skonstruowanej z listwy drewnianej i kątowników.  
LST może być zasilany z dowolnego zasilanego portu USB: w komputerze, ładowarce do telefonu, powerbanku, itp.  
Dokładność opisanego urządzenia wynosi 1ms, co oznacza, że możliwe jest testowanie czasów migawki do 1/1000 sekundy. Z punktu widzenia sterownika możliwe jest rozszerzenie dokładności działania do mikrosekund, co pozwoli na badanie krótszych czasów. Modyfikacja taka wymaga dostosowania odpowiedniego fragmentu kodu oraz sprawdzenia, jak na tak krótkie impulsy świetlne reaguje zastosowany fotoelement.
  
#### Użycie
Po włączeniu urządzenia i wyświetleniu informacji "Ready..." na wyświetlaczu, należy umieścić badany aparat na drodze wiązki (plamka lasera musi się znajdować w obrębie migawki). Następnie należy wyzwolić aparat na uprzednio ustawionym, badanym czasie. Na ekranie zostanie wyświetlony zmierzony czas. W przypadku czasu dłuższego niż 1 sekunda, czas ten będzie wyświetlony jako ułamek dziesiętny. Jeśli czas będzie krótszy od 1 sekundy, wyświetlony zostanie czas w postaci ułamka zwykłego oraz dziesiętnego.  
  
## Photos
  
_ENG: Completed device. PL: Zbudowane urządzenie._  
![ENG: Completed device. PL: Zbudowane urządzenie.](/images/LST.png)  
  
_ENG: Device scheme. PL: Schemat urządzenia._  
![ENG: Device scheme. PL: Schemat urządzenia.](/images/laser_bb.png)  

