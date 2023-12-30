# Android-PIN-Bruteforce
Scripts made for the ATTiny85 aka DigiSpark to bruteforce Android PINs

There are two scripts one for PINs with 4 or 5 digits and one for PINs with 6 to 8 digits. The scripts are made for the ATTiny85 however the logic can be applied to any HID (Human Interface Device) that can be programmed to send keyboard inputs such as **NetHunter** devices.

## ADB Script (Python Way)

After developing the scripts I tought that there might have been people that probably dont want to spend money on a DigiSpark or dont have one lying around. So I made a script that uses ADB to bruteforce the PIN.
The process is exactly the same, the script uses ADB to input the code automatically. The only difference is that you need to have ADB installed on your computer and have USB Debugging enabled on the Android device.

```bash
python3 AdbBruteforce.py -n [4 to 9]
```


## Requirements

- DigiSpark (ATTiny85)
- OTG Cable (Micro USB or USB-C depending on your phone)
- Android Device (Tested on a Samsung Galaxy A40)
- Device with OTG capabilities (some really old android dont have it)
- Arduino IDE
- DigiSpark Arduino Library [Download here](https://raw.githubusercontent.com/digistump/arduino-boards-index/master/package_digistump_index.json)
- Digistump USB Drivers [Download here](https://github.com/digistump/DigistumpArduino/releases/download/1.6.7/Digistump.Drivers.zip)

## Warning

Suffice to say, this was made for educational purposes only. Its probably not the best idea to plug a USB  device into a strangers phone without their permission. So yeah, don't do that.

Also, I would recommend using a phone that you don't care about, as this could soft brick your phone if you enter the wrong PIN too many times (in case the erase feature on the phone is active).

## How to use

1. Download the Arduino IDE and install the Digistump USB Drivers
2. Open the Arduino IDE and go to File > Preferences and paste the following URL into the Additional Boards Manager URLs field: `https://raw.githubusercontent.com/digistump/arduino-boards-index/master/package_digistump_index.json`
3. Go to Tools > Board > Boards Manager and search for `Digistump AVR Boards` and install it
4. Go to Tools > Board and select `Digispark (Default - 16.5mhz)`
5. Open the respective script and execute it
6. Plug the DigiSpark into your computer and wait for the script to finish
7. Plug the DigiSpark into the Android device using the OTG cable
8. Wait for the script to finish and the phone should unlock
9. Profit

## Considerations

As you might expect this is not the most efficient way to bruteforce a PIN. With the timeout feature on Android devices, you can only try a PIN every 30 seconds. This means that it would take 1.5 days to bruteforce a 4 digit PIN and 12 days to bruteforce a 6 digit PIN. This is assuming that the PIN is correct and the phone unlocks. If the PIN is incorrect, the phone will lock for 30 seconds and the script will have to wait for the timeout to finish before trying the next PIN. This means that it would take 16 hours to bruteforce a 4 digit PIN and 128 hours to bruteforce a 6 digit PIN.
However this should be seen as a last resort such as: Google Find My Device, ADB, IMEI Unlock, etc. If you have access to any of these methods, you should use them instead.
There is a reason why Android Devices tell you that if you forget your PIN, you should factory reset your phone. This is because it is very difficult to bypass the PIN without the correct PIN or access to the phone.

Android 4 and 5 contain some intrinsic vulnerabilities that allow you to bypass the PIN. However, these vulnerabilities such as the removal of the features using ADB or the screen crasher method have been patched in Android 6 and above.

## Author

Fabian Nunes

## License

GNU GPLv3
