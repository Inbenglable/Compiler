import os


TEST_PATH = './test/'
TRIAL = False


if __name__ == '__main__':
    result = os.system('wsl make')
    if result != 0:
        exit(0)
    files = os.listdir(TEST_PATH)
    for file in files:
        if file.endswith('.ir') or file.endswith('.s'):
            os.remove(os.path.join(TEST_PATH, file))
    for file in files:
        if file.endswith('test_3_r02.spl'):
            print('Compiling ' + file)
            result = os.system('wsl ./bin/splc ' + os.path.join(TEST_PATH, file))
            print(result)
            if TRIAL:
                break
    os.system('wsl make clean')